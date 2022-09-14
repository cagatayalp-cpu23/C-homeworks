#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	srand(time(0));
	int N,**dizi,i,j,toplam,toplam2,toplam3;
	printf("enter the N:");
	scanf("%d",&N);
	dizi=(int**)malloc(N*sizeof(int*));
	if(dizi == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	for(i = 0; i < N; i++)
	{
		dizi[i] = (int*)malloc(N*sizeof(int));
		if(dizi[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			dizi[i][j]=rand()%100;
		}
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%4d   ", dizi[i][j]);
		}
		printf("\n");
	}
	
	
	
	dizi=(int**)realloc(dizi,(N+1)*sizeof(int*));
	if(dizi == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	for(i = 0; i < N+1; i++)
	{
		if(i==N)
		{
			dizi[i] = (int*)calloc(N+1,sizeof(int));
		}
		else
		{
			dizi[i] = (int*)realloc(dizi[i],(N+1)*sizeof(int));
		}
		
		if(dizi[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
	
		
	for(i=0;i<N;i++)
	{
		toplam=0;
		toplam2=0;
		for(j=0;j<N;j++)
		{
			toplam=toplam+dizi[i][j];
			toplam2=toplam2+dizi[j][i];
			toplam3=toplam3+dizi[i][j]+dizi[j][i];
		}
		dizi[i][N]=toplam;
		dizi[N][i]=toplam2;
	}
	
	dizi[N][N]=toplam3;
	printf("\n\n");
	for(i = 0; i < N+1; i++)
	{
		for(j = 0; j < N+1; j++)
		{
			printf("%4d   ", dizi[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	for(i = 0; i < N+1; i++)
		free(dizi[i]);
	free(dizi);	
	
	
	
	return 0;
}
