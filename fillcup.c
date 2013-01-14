#include<stdlib.h>
#include<stdio.h>

/*


Cups are arranged in following format

		 		 						 					 |_|
       			                |_|    |_|
                         |_|   |_|   |_|
                      |_|   |_|    |_|  |_|
                    |_|  |_|   |_|   |_|  |_|

Each cup has capacity C and once a cup gets full, it drops half extra amount to left child and half extra amount to right child

for Eg : let' first cups get 2C amount of liquid then extra amount C(2C-C) will be divided equally to left and right child cup of next level

i.e. C/2 to left child and C/2 to right child

Write a function which takes input parameter as amount of liquid poured at top (L) and height of particular cup (h) index of that cup (i) and it should return amount of liquid absorbed in that cup.

*/

#define CAP 1.0f
#define MAXHEIGHT 9

void print_cups(float cups[MAXHEIGHT][MAXHEIGHT], int height)
{
	int i,j;
	for(i=0;i<height;i++)
	{
		for(j=0;j<=(62-(8*i))/2;j++)
		{
			printf(" ", cups[i][j]);
		}
		for(j=0;j<=i;j++)
		{
			printf("%f ", cups[i][j]);
		}
		printf("\n\n");
	}
}

float filledcup(float load, int height, int index)
{
	
	int i, j; /* counters */
	float cups_filled[MAXHEIGHT][MAXHEIGHT]; /* DP table for cups */
	float overflow;
	
	for(i=0;i<MAXHEIGHT;i++) /* initialise all cups to 0 */
	{
		for(j=0;j<=i;j++)
		{
			cups_filled[i][j] = 0.0f;
		}
	}
	
	/* fill first cup */
	cups_filled[0][0] = load;
	
	i=0;
	while(load > 0.0f && i < MAXHEIGHT-1)
	{
		for(j = 0;j<=i;j++)
		{
			if(cups_filled[i][j] > CAP)
			{
			 overflow = (cups_filled[i][j] - CAP)/2;
			 cups_filled[i][j] = CAP;
			 
			 /* flow to next layer */
			 cups_filled[i+1][j] += overflow;	
			 cups_filled[i+1][j+1] += overflow;
			}
		}
		i++;
	}
	
	print_cups(cups_filled, MAXHEIGHT);
	
	return cups_filled[height][index];

}

int main(int argc, char *argv[])
{
	int h, i;
	
	h = 2;
	i = 1;
	printf("Cup at %d, %d filled with %f water.\n",h, i, filledcup(25.0f, h, i));
	return 0;
}
