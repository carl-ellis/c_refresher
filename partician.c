#include<stdlib.h>
#include<stdio.h>

#define MAXN 15
#define MAXK 5
#define MAXINT 99999

void print_data(int s[], int start, int end);
void reconstruct_partician(int s[], int d[MAXN+1][MAXK+1], int n, int k);
void partician(int s[], int n, int k);
int max(int x, int y);

void partician(int s[], int n, int k)
{
	int m[MAXN+1][MAXK+1];  /* DP table for values */
	int d[MAXN+1][MAXK+1];  /* DP table for dividers*/
	int p[MAXN+1];						/* Prefix sums array */
	int cost;								/* Test split costs */
	int i,j,x;							/* counters */
	int p[MAXN+1];          /* Prefix sums array */
	int cost;               /* Test split costs */
	int i,j,x;              /* counters */
	
	p[0] = 0;               /* construct prefix sums - sums from 0 - i 
                          in the matrix */
	for(i=1;i<=n;i++) 
	{
		p[i] = p[i-1] + s[i];
		m[i][1] = p[i];       /* initialise boundaries */
	}
	for(j=1;j<=k;j++) m[1][j] = s[1];
	
	for(i=2; i<=n;i++)      /* Evaluate main occurance */
	{
		for(j=2;j<=k;j++)
		{
			m[i][j] = MAXINT;		/* Initial cost very high */
			for(x=1;x<=(i-1);x++) /* Check best partician costs of ranges 
                            (range=0+x,particians=j-1)(range=n-x,particians=1) 
                            and chose best fit */
			{
				cost = max(m[x][j-1], p[i]-p[x]);
				if (m[i][j] > cost)
				{
					m[i][j] = cost;
					d[i][j] = x;
				}
			}
		}
	}
	
	reconstruct_partician(s, d, n, k);
}

/* Recursive functrion to print out ata based on partition table */
void reconstruct_partician(int s[], int d[MAXN+1][MAXK+1], int n, int k)
{
	if(k==1)
	{
		print_data(s, 1, n);
	}
	else
	{
		reconstruct_partician(s, d, d[n][k], k-1);
		print_data(s, d[n][k]+1,n);
	}
}

/*print a given sub set of data */
void print_data(int s[], int start, int end)
{
	int i;
	
	for(i=start;i<=end;i++) printf(" %d ", s[i]);
	printf("\n");
}

/* Get the max of two values */
int max(int x, int y)
{
	if(x >= y)
	{
		return x;
	} 
	else
	{
		return y;
	}
}

int main(int argc, char *argv[])
{
	int s[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	
	partician(s, 14, 3);
	
	return 0;
}
