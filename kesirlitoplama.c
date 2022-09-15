#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void get_fraction(int *a,int *b,int *c,int *d)
{
	do{
		printf("1. icin pay ve payda girin\n");
    	scanf("%d %d",a,b);
	}while((*b)==0);
	do
	{
		printf("2. icin pay ve payda girin\n");
    	scanf("%d %d",c,d);
	}while((*d)==0);
	
}
void get_operator(char *ch)
{
	printf("operatoru girin");
	scanf(" %c",ch);
}
void print_fraction(int a,int b,int c,int d,char ch)
{
	printf("%d / %d [%c] %d / %d  =",a,b,ch,c,d);
}
void calculate(int a,int b,int c,int d,int *x,int *y,char ch)
{
	if(ch=='+')
	{
		(*x)=a*d+b*c;
		(*y)=b*d;
	}
	if(ch=='-')
	{
		(*x)=a*d-b*c;
		(*y)=b*d;
	}
	if(ch=='*')
	{
		(*x)=a*c;
		(*y)=b*d;
	}
	if(ch=='/')
	{
		(*x)=a*d;
		(*y)=b*c;
	}
	
	
}
void refine(int *x,int *y)
{
	
	if((*x)>(*y))
	{
	    int a=(*y);
		while((*x)%a!=0||(*y)%a!=0)
		{
			a--;
		}
		(*x)=(*x)/a;
		(*y)=(*y)/a;
		
		
		
	}
	if((*y)>(*x))
	{    
	    int a=(*x);
		while((*y)%a!=0||(*x)%a!=0)
		{
			a--;
		}
		(*x)=(*x)/a;
		(*y)=(*y)/a;
		
		
		
	}
	printf("%d / %d",*x,*y);
	
	
}
int main(int argc, char *argv[]) 
{
	char ch;
	int a,b,c,d,x,y;
	get_fraction(&a,&b,&c,&d);
	get_operator(&ch);
	print_fraction(a,b,c,d,ch);
	calculate(a,b,c,d,&x,&y,ch);
	printf("\n%d / %d\n",x,y);
	refine(&x,&y);
	return 0;
}
