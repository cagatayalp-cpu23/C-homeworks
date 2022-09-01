#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void push(int array[],int *top,int value)
{
	if(!isfull(top))
	{
		(*top)++;
		array[*top]=value;
	}
}
int isfull(int *top)
{
	if((*top)==MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop(int array[],int *top)
{
	int tmp;
	if(!isempty(top))
	{
		tmp=array[(*top)];
		(*top)--;
		return tmp;
	}
	else
	{
		return 0;
	}
	
	
}
int isempty(int *top)
{
	if((*top)==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int peek(int *top,int array[])
{
	return array[*top];
}
int change(int array[100],int value,int matrix[9][9],int x,int y,int *top)
{
	int i=0,max=value,a,b;
	while(i!=((*top)-1))
	{
		if(matrix[array[i]][array[i+1]]>max)
		{
			max=matrix[array[i]][array[i+1]];
			a=array[i];
			b=array[i+1];
		}
		i++;
	}
	
	if(max==value)
	{
		printf("\ncant added\n");
	}
	
	else
	{
	     
		matrix[a][b]=0;
		matrix[x][y]=value;
	}
	
}

void print(int matrix[9][9])
{
	int i,j,array[9][3],k=0,min,a,b,c;
	for (i = 1; i < 9; i++) {
                for (j = i; j < 9; j++) {
           if(matrix[i][j]!=0)
		   {
		   	
		  array[k][0]=matrix[i][j];
		  array[k][1]=i;
		  array[k][2]=j;
		  k++;
				}     
			}
				
			   }
		min=array[0][0];
		for(j=1;j<8;j++)
		{
			
			   	   
	for(i=0;i<8;i++)
	{
		if(array[i][0]!=0&&min>array[i][0])
		{
			min=array[i][0];
			a=array[i][1];
			b=array[i][2];
			c=i;
		}
	}
	printf("%d %d %d\n",min,a,b);
	min=array[c][0]=999;
}
}
int savetoarray(int matrix[9][9],int value,int *top,int x,int y,int selected[9],int array[])
{
	
	int j=0,count;
	
	while(x!=y)
	{
		selected[x]=1;
		
		count=0;
		for(j=1;j<9;j++)
		{
			if(!selected[j]&&matrix[x][j])
			{
				if(matrix[x][y]!=0)
				{
					int t=peek(top,array);
					push(array,top,y);
				return	savetoarray(matrix,value,top,t,y,selected,array);
					
				}
				count++;
				push(array,top,j);
			return	savetoarray(matrix,value,top,j,y,selected,array);
			}
		}
		if(count==0)
		{
			pop(array,top);
		return	savetoarray(matrix,value,top,peek(top,array),y,selected,array);
			
		}
	}
	return 0;
}
int main(int argc, char *argv[]) 
{
	int value,N1,N2,top=-1;
	int matrix[9][9]={{0,0,0,0,0,0,0,0,0},
	                {0,0,2,0,0,0,0,0,0},
					{0,2,0,3,0,0,6,0,0},
	                {0,0,3,0,0,0,0,0,0},
	                {0,0,0,0,0,5,0,0,0},
	                {0,0,0,0,5,0,0,1,0},
	                {0,0,6,0,0,0,0,6,0},
	                {0,0,0,0,0,1,6,0,12},
					{0,0,0,0,0,0,0,12,0}
					};
	                
    int array[100];
  
    print(matrix);
    int t=1,secim;
    while(t)
    {
	printf("press  1 to add value and press 0 to exit : ");
	scanf("%d",&secim);
	if(secim==1)
	{
	
	printf("enter the value to be added:");
	scanf("%d",&value);
	do
	{
		printf("enter the node 1");
		scanf("%d",&N1);
	}while(N1!=1&&N1!=2&&N1!=3&&N1!=4&&N1!=5&&N1!=6&&N1!=7&&N1!=8);
	int selected[9]={0};
	
	
	
	do
	{
		printf("enter the node 2");
		scanf("%d",&N2);
	}while(N2!=1&&N2!=2&&N2!=3&&N2!=4&&N2!=5&&N2!=6&&N2!=7&&N2!=8);
	push(array,&top,N1);
	
	savetoarray(matrix,value,&top,N1,N2,selected,array);
	change(array,value,matrix,N1,N2,&top);
		print(matrix);
	}
	else
	{
		t=0;
	}
}

	
	
	

	return 0;
}
