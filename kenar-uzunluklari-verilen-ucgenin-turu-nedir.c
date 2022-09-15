#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int a,b,c;
	printf("ucgenin kenarlarini girin:\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>=c)
	{
		if(a+c>=b)
		{
			if(c+b>=a)
			{
				if(a==b)
	{
		if(a==c)
		{
			printf("eskenar ucgen");
		}
		else
		{
			if(a*a+b*b==c*c)
			{
				printf("ikizkenar dik ucgen");
			}
			else
			{
				printf("ikizkenar ucgen");
			}
			
		}
	}
	else if(b==c)
	{
		if(b*b+c*c==a*a)
		{
			printf("ikizkenar dik ucgen");
		}
		else
		{
			printf("ikizkenar ucgen");
		}
		
		
	}
	else if(a==c)
	{
		if(a*a+c*c==b*b)
		{
			printf("ikizkenar dik ucgen");
		}
		else
		{
			printf("ikizkenar ucgen");
		}
		
	}
	else
	{
		if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
		{
			printf("dik ucgen");
		}
	else
	{
		printf("cesitkenar ucgen");
	}
		
	}
			}
			else
			{
				printf("ucgen degil");
			}
			
		}
		else
			{
				printf("ucgen degil");
			}
	}
	else
			{
				printf("ucgen degil");
			}
	printf("\n");
	main();
	
	
	return 0;
}
