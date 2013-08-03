# include <stdio.h>
# include <limits.h>

#define N 2
#define K 91

void print_floors(int dFloor[N+1][K+1], int n, int k)
{
	if(k == 0)
	{
		printf("Drop at: %d\n", K-k);
		return;
	}
	else
	{
		if(k != K)
				 printf("Drop at: %d\n", K-k);
		print_floors(dFloor, n, dFloor[n][k]);
	}
}
 
// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }
 
/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop()
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    int eggFloor[N+1][K+1];
    int dFloor[N+1][K+1];
    int res;
    int i, j, x;
 
    // We need one trial for one floor and0 trials for 0 floors
    for (i = 1; i <= N; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
        dFloor[i][0] = 0;
    }
 
    // We always need j trials for one egg and j floors.
    for (j = 1; j <= K; j++)
    {
        eggFloor[1][j] = j;
        dFloor[1][j] = 0;
        dFloor[0][j] = 0;
    }  
 
    // Fill rest of the entries in table using optimal substructure
    // property
    for (i = 2; i <= N; i++)
    {
        for (j = 2; j <= K; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if (res < eggFloor[i][j])
                {
        	   		 	 eggFloor[i][j] = res;
        	   		 	 dFloor[i][j] = j-x;
                }
                 
            }
        }
    }
    
    print_floors(dFloor, N, K);
 
    // eggFloor[n][k] holds the result
    return eggFloor[N][K];
}


 
/* Driver program to test to pront printDups*/
int main()
{
    //int n = 2, k = 20;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", N, K, eggDrop());
    return 0;
}
