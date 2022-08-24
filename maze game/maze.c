#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct lab{
	char *array;
	struct lab *next;
}LAB;
int main(int argc, char *argv[]) 
{
	unsigned int microseconds=1;
	int score=0;
	int bx,by,cx,cy;
	FILE *fl;
	char matrix[31][45];
	int i=0;
	int j=0,k;
	

	fl=fopen("maze.txt","r");
	while(fgets(matrix[i],100,fl)!=NULL)
	{
		i++;	
	}
	int length=strlen(matrix[0]);
	
	srand(time(NULL));
	for(k=0;k<i;k++)
	{
		for(j=0;j<length;j++)
		{
			if(matrix[k][j]==' ')
			{
				
				if((rand()%500)%8==0)
					matrix[k][j]='O';
				
			}
		
			
		}
	}
	
	for(j=0;j<i;j++)
	{
		for(k=0;k<strlen(matrix[j]);k++)
		{
			if(matrix[j][k]=='b')
			{
				bx=j;
				by=k;
			}
			else if(matrix[j][k]=='c')
			{
				cx=j;
				cy=k;
			}
		}
		printf("%s",matrix[j]);
	}
	
	LAB *head=NULL;
	LAB *tmp=(LAB*)malloc(sizeof(LAB));
	
	tmp->array=&(matrix[bx][by]);
	tmp->next=NULL;
	head=tmp;
	while(matrix[cx][cy]!='b')
	{
		sleep(microseconds);

		LAB *tmp=(LAB*)malloc(sizeof(LAB));
		

		if(*(head->array+length+1)==' '||*(head->array+length+1)=='c'||*(head->array+length+1)=='O')
		{
			if(*(head->array+length+1)=='O')
			{
				score+=10;
			}
			*(head->array+length+1)='b';
			*(head->array)='*';
			(tmp->array)=(head->array+length+1);
			tmp->next=head;
			head=tmp;
	
	
			
		}
		else if(*(head->array-length-1)==' '||*(head->array-length-1)=='c'||*(head->array-length-1)=='O')
		{
			if(*(head->array-length-1)=='O')
			{
				score+=10;
			}
			*(head->array-length-1)='b';
			*(head->array)='*';
			(tmp->array)=(head->array-length-1);
			tmp->next=head;
			head=tmp;
		
				
	
		}
		else if(*(head->array+1)==' '||*(head->array+1)=='c'||*(head->array+1)=='O')
		{
			if(*(head->array+1)=='O')
			{
				score+=10;
			}
			*(head->array+1)='b';
			*(head->array)='*';
			(tmp->array)=(head->array+1);
			tmp->next=head;
			head=tmp;
	
				
		}
		else if(*(head->array-1)==' '||*(head->array-1)=='c'||*(head->array-1)=='O')
		{
			
			if(*(head->array-1)=='O')
			{
				score+=10;
			}
			*(head->array-1)='b';
			*(head->array)='*';
			(tmp->array)=(head->array-1);
			tmp->next=head;
			head=tmp;
	
				
		}
		else
		{
			score-=5;
			if(*(head->array)=='c')
			{
				score+=5;
			}
			while((*(head->array-1)!=' '&&*(head->array-length-1)!=' '&&*(head->array+length+1)!=' '&&*(head->array+1)!=' ')&&*(head->array)!='c')
			{
				LAB *temp=head;
			*(temp->array)='*';
	    	
		
		
			head=head->next;
			free(temp);
			}
			*(head->array)='b';
			
			
		}
		for(j=0;j<i;j++)
	{
		
		printf("%s",matrix[j]);
		
	}
			
		
	
	printf("\n--------------------------------------SCORE:%d-----------------------\n",score);
	}
	
	
     
		
		
	return 0;
}
