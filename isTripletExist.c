#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int calculate(int sum,int count,int bulbcount,int values[100],int expectedvalue,int i);
int main(int argc, char *argv[]) 
{
	int bulbcount,i,j,sumoftwo,expectedvalue;
	int values[100];
	printf("how many bulb do you want to use?");
	scanf("%d",&bulbcount);
	printf("enter the values\n");
	for(i=0;i<bulbcount;i++)
	{
		scanf("%d",&values[i]);
	}
	printf("enter the expected value");
	scanf("%d",&expectedvalue);
	
	calculate(0,0,bulbcount,values,expectedvalue,0);
	
	
	return 0;
}
int calculate(int sum,int count,int bulbcount,int values[100],int expectedvalue,int i)
{
	if(count>=bulbcount)
	{
		return 0;
	}
	if(count!=3)
	{
		calculate(sum+values[i],count+1,bulbcount,values,expectedvalue,i+1)|| calculate(sum,count,bulbcount,values,expectedvalue,i+1);
	}
	else{
		if(sum==expectedvalue)
		{
			printf("found the triplet");
			return 1;
		}
		else
		{
			return 0;
		}
	}
		
	
	
	
	
}
