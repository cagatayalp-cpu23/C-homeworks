#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,j,tmp,k=0,t;
	
	char array[100],pattern[50];
		printf("enter the string:");
	scanf("%s",array);
		printf("enter the pattern:");
	scanf("%s",pattern);
	int last=strlen(pattern)-1;tmp=last;

		k=last;


	
	t=0;
	while(t==0)
	{
		if(k>strlen(array))
		{
			printf("not found");
			t=1;
		
		}
		tmp=k;
		i=last;
		if(pattern[last]==array[tmp])
		{
			
			
			while(i>=0&&pattern[i]==array[tmp])
			{
				i--;
				tmp--;
			}
			if(i==-1)
			{
				printf("found");
				t=1;
			}
			else
			{
				t=0;
				j=tmp;
				while(i>=0&&t==0)
				{
					if(pattern[i]==array[j])
					{
						t=1;
					}
					i--;
				}
				if(t==1)
				{
					k+=last-i;
				}
				else
				{
					k+=strlen(pattern);
				}
				
			}
			
		}
		else
			{
				
				j=tmp;
				while(i>=0&&pattern[i]!=array[j])
				{
					
					i--;
				}
				if(i!=-1)
				{
					
					k+=last-i;
					
				}
				else
				{
					k+=strlen(pattern);
				}
				
				
			}
	}

	
	return 0;
}
