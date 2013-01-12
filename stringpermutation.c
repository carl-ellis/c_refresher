#include<stdio.h>
#include<string.h>

/* Swap characters */
void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* a -> string, s -> startindex, n -> endindex */
void permute(char * a, int s, int n)
{
	/* loop vrs */
	int j;
	
	for(j=s;j<=n;j++)
	{
		/* backtrack after each branch */
		swap(a+s, a+j);
		permute(a, s+1, n);
		swap(a+s, a+j);
	}
	
	/* output permutation */
	if(s==n)
	{
	  printf("%s\n", a);
	}
	
	
}

int main(int argc, char *argv[])
{
	char a[] = "ABCDEF";
	int n = strlen(a)-1;
	
	if(argc > 1)
	{
		n = strlen(argv[1])-1;
		permute(argv[1], 0, n);
	}
	else 
	{
		permute(a, 0, n);
	}
	
	
	return 0;
}
