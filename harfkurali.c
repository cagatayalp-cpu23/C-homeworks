#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i=0;
	char cumle[100];
	printf("Cumleyi giriniz\n");
	gets(cumle);
		while(cumle[i]==' ')
    	{
    		i++;
		}
		cumle[i]=cumle[i]-'a'+'A';
	
	while(cumle[i]!='\0')
	{
	
    
		if(cumle[i]=='.' &&(cumle[i+1]>='a'&&cumle[i+1]<='z'))
		{
			cumle[i+1]=cumle[i+1]-'a'+'A';
			
		}
		
		else if((cumle[i]=='.'&&cumle[i+1]==' ')&&(cumle[i+2]>='a'&&cumle[i+2]<='z'))
		{
			cumle[i+2]=cumle[i+2]-'a'+'A';
		}
		i++;
	}
	puts(cumle);
	return 0;
}
