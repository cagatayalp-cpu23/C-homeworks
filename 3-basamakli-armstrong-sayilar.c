#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,a,b,c;
	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=i%100/10;
		c=i/100;
		if(a*a*a+b*b*b+c*c*c==i)
		{
			printf("%d armstrongtur\n",i);
			
		}
		
	}
	return 0;
}
