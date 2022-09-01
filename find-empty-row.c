#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int N,M,matris[100][100],i,j,k=0,dizi[100];
	printf("enter the number of rows and columns:\n");
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("[%d][%d] (only 0's or 1's):",i+1,j+1);
			scanf("%d",&matris[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%d ",matris[i][j]);
			
		}
		printf("\n");
	}
	for(i=0;i<N;i++)
	{
		j=0;
		while(j<M&&matris[i][j]==0)
		{
			j++;
		}
		if(j==M)
		{
			dizi[k]=i+1;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		printf("row %d is empty\n",dizi[i]);
	}
	return 0;
}
