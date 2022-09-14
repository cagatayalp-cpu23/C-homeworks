	#include <stdio.h>
#include <stdlib.h>
#include "MAKRO.h"
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	printf("POPULATION SIZE %d\n",POPULASYON);
	printf("ITERATION %d\n",ITERASYON);
	 srand(time(0));
	 int i=0,j,sayi[100],min[100],min1;
     for(j=0;j<ITERASYON+1;j++)
     {
     	for(i=0;i<POPULASYON;i++)
        {
         	sayi[i]=(rand()%50+1);
    	 }
    	 printf("ITERATION %d POPULATION\n",j);
    	 for(i=0;i<POPULASYON;i++)
        {
         	printf("%d\t",sayi[i]);
    	 }
     	 min[j]=sayi[0];
    	 for(i=1;i<POPULASYON;i++)
    	 {
	     	if(min[j]>sayi[i])
	    	{
	    		min[j]=sayi[i];
	    	 }
    	 }
    	 printf("Best Cost in iteration %d= %d\n",j,COST(min[j]));
	 }
	 j=j-1;
	 min1=min[j];
	 for(j=0;j<ITERASYON+1;j++)
	 {
	 	if(min1>min[j])
	 	{
	 		min1=min[j];
		 }
	 	
	 }
	 printf("Best Cost in all iterations %d",COST(min1));

	
	
	return 0;
}

