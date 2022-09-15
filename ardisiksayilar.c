#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int i,dizi[MAX],N;
	printf("kac elemanli oldugunu giriniz\n");
	scanf("%d",&N);
	printf("sayilari giriniz\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&dizi[i]);
	}
	i=0;
	while(dizi[i+1]==dizi[i]+1 && i<N-1)
	{
		i++;
	}
	if(i<N-1)
	{
	    printf("kurala uymaz ");
	
		printf("uymayan sayi:%d",dizi[i]+1);
	}
	else
	{
		printf("kurala uyar");
	}
	return 0;
}
