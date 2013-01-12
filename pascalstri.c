#include<stdlib.h>
#include<stdio.h>

#define TRISIZE 15

/* Build pascals triangle */
void build_tri(int tridata[][TRISIZE])
{
	int i, j;
	
	/* Intialize column 0 and diagonal to 1 */
	for(i=0;i<TRISIZE;i++)
	{
		tridata[i][0] = 1;
		tridata[i][i] = 1;
	}
	
	/* Fill in the triangle in a way which means nothing is done twice */
	for(i=2;i<TRISIZE;i++)
	{
		for(j=1;j<i;j++)
		{
			tridata[i][j] = tridata[i-1][j-1] + tridata[i-1][j];
		}
	}
	
}

/* print pascals triangle */
void print_tri(int tridata[][TRISIZE])
{
	int i,j;
	
	for(i=0;i<TRISIZE;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ", tridata[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int tridata[TRISIZE][TRISIZE];
	
	build_tri(tridata);
	
	print_tri(tridata);
	
	return 0;
}
