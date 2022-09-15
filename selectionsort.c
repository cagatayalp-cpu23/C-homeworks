#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int N,i,j,tmp,A[100],min;
	printf("dizi kac elemanli");
	scanf("%d",&N);
	printf("elemanlari girin\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++)
	{
		min=i;
		for(j=i+1;j<N;j++)
		{
			if(A[min]>A[j])
			{
				min=j;
			}
		}
		
		tmp=A[min];
		A[min]=A[i];
		A[i]=tmp;
		
		
	}
	printf("...\n");
	for(i=0;i<N;i++)
	{
		printf("%d",A[i]);
	}
	return 0;
}
