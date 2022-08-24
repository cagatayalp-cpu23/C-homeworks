#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 500
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

      
            

int isempty(int *top) {

   if(*top == -1)
      return 1;
   else
      return 0;
}
   
int isfull(int *top) {

   if(*top == MAXSIZE)
      return 1;
   else
      return 0;
}



char pop(char stack[],int *top) {
   char data;
	
   if(!isempty(top)) {
      data = stack[(*top)];
      *top = *top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(char data,char stack[],int *top) {

   if(!isfull(top)) {
      *top = *top + 1;   
      stack[(*top)] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
int iseightbit(int number)
{
	int us=pow(2,8);
	while(number>=256)
	{
		if(number==256)
		{
			return 1;
		}
		number=number/us;
		
	}
	return 0;
	
}
int  dectobinary(int number,int i,int *l,int m,char stack[],int *top,int p,char array[])
{
	int k=1,count=0,t=0;
	
	
	if(number==0)
	{
		return 0;
	}
	
	while(k<number)
	{
		
		if(count>=(*l))
		{
			(*l)*=2;
		//	m+=1;
		}
		count++;
		k*=2;
		
	}
	if(m==0&&k==number&&iseightbit(number))
	{
		(*l)*=2;
		count++;
	}
    else if(k==number)
    {
    	count++;
    	
    	
	}
	else
	{
		k/=2;
	}
		while(i<(*l)&&t==0)
		{
			
			if(i==(*l)-count)
			{
				array[p]='1';
				p++;
				
				if(k!=number)
				{
					t=1;
				}
				
				if(isempty(top)||stack[(*top)]=='1')
				{
					push('1',stack,top);			
				}
				else
				{
					pop(stack,top);
				}
				
				
				
				
					
			}
			else
			{
				array[p]='0';
				p++;
				if(isempty(top)||stack[*top]=='0')
				{
					push('0',stack,top);			
				}
				else
				{
					pop(stack,top);
				}
			}
			i++;
		}
	

		
		number=number-k;
		dectobinary(number,(*l)-count+1,l,m+1,stack,top,p,array);
		
	
	
		
}
int main(int argc, char *argv[]) 
{
	int number,x=7,top=-1,i=0;
	char stack[100];
	char array[100];

	printf("enter the number to convert:");
	scanf("%d",&number);
	
	if(number<0)
	{
		number=-1*number;
		while(number>pow(2,x))
		{
			x=x*2+1;
		}
		number=pow(2,x+1)-number;
	}
    x=8;
  
	
	dectobinary(number,0,&x,0,stack,&top,i,array);
	i=0;
	printf("binary format:");
	for(i=0;i<x;i++)
	{
		printf("%c",array[i]);
	}

	
	printf("\n");
	if(isempty(&top))
	{
		printf("\number of 0's and 1's is equal");
	}
	else if(pop(stack,&top)=='0')
	{
		printf("\n number of 0s is %d more than number of 1s.",top+2);
	
		
	}
	else
	{
		printf("\n number of 1s is %d more than number of 0s.",top+2);
	
		
	}
	return 0;
}
