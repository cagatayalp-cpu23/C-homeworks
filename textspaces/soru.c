#include <stdio.h>
#include <stdlib.h>
#define N 5000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
int i,j=0,kelime=1,c=0;
	FILE *fp;
char text[N];
fp = fopen ("soru.txt", "r");

if (fp == NULL) {
printf("Dosya acma hatasi!");
return 1;
}
fgets(text, N-1, fp);

	printf("%s\n",text);
	while(text[c]!='\0')//textin uzunlu�unu �l�t�m
	{
		c++;
	}
	if(text[c-1]==' ')//en sonda bo�lukla biterse kelime saymamas� i�in 1 azaltt�m
	{
		kelime--;
	}
while(j<c)
{
	while(text[j]!=' ' && j<c)
	{
		j++;
	}


    if((text[j+1]==' '||j==0))
	{
			
			for(i=j;i<c;i++)//bo�luktan bitene kadar sola kayd�rd�m
			{
				text[i]=text[i+1];
				

			}
			c--;
	
		}
		else if(j<c){
		j++;
		kelime++;
		
		}
	
	
}
 printf("kelime sayisi:%d\n", kelime);
/*

*/
printf("%s",text);
/********* kod blo�u ************/
/********* kod blo�u sonu ************/
// Dosyay� kapama
fclose(fp);
return 0;
	
}
