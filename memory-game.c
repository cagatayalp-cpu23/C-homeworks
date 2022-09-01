#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(char matrix[][100],int n);
void tablo(int ,char [][100],int [][100],int [] );
int main(int argc, char *argv[]) 
{
	char matrix[100][100];
	int matrix2[100][100],pcmem[100];
	int i,j,k=0,array[]={0},temp,num1,num2,m=0,n,mem,choice,control=0,guessofpc=0,guessofuser=0;
	int prev=-1,user=0,pc=0,c=0,a,b;
	printf("Press 1 for easy mode, press 2 for medium mode, or press 3 for hard mode:");
	scanf("%d",&choice);
	if(choice==1)
	{
		n=4;
		mem=2;
	}
    else if(choice==2)
	{
		n=6;
		mem=6;
	}
	else if(choice==3)
	{
		n=8;
		mem=16;
	}

   tablo(n,matrix,matrix2,array);
   while((user+pc!=((n*n)/2))&&user<=n&&pc<=n)
   {
   	
       
       	
	   
        	if(c%2==0)
        	{
        		while(k==0&&user<=n&&(user+pc!=n*n/2))
              {
        		printf("\nusers turn");
        		
        		do
        		{
        			printf("\nEnter the row and column of the 1st card\n");
        			scanf("%d %d",&num1,&num2);
				}
				
				while(matrix[num1][num2]!='*');
	   	    	matrix[num1][num2]=matrix2[num1][num2];
  	    		printf("\nThe value of the %dx%d:%d\n ",num1,num2,matrix[num1][num2]);
   	       	    menu(matrix,n);
	      		prev=matrix[num1][num2];
	      		do
	      		{
	      				printf("\nEnter the row and column of the 2nd card\n");
	   	            	scanf("%d %d",&a,&b);
				  }while(num1==a&&num2==b||(matrix[a][b]!='*'));
				  
	            if(m<(mem*3))
	            {
	            	
	            	
	            	
	            	pcmem[m]=num1;
	            	m++;
	            	pcmem[m]=num2;
	            	m++;   
					pcmem[m]=prev;
					m++;             
	            	pcmem[m]=a;
					m++;     
	            	pcmem[m]=b;                
					m++;       
	            	pcmem[m]=matrix2[a][b];    
					m++;            
	            	            
	            	            
				}      
				matrix[a][b]=matrix2[a][b];
			   printf("\nThe value of the %dx%d:%d\n",a,b,matrix[a][b]);
	   	    	    
	   	    	    
	   	       	menu(matrix,n);
	   	       	
	   	       	
	   	       	if(prev==matrix[a][b])
	     		{ 
	     		
	     		printf("\nuser is correct!\n");
			    user++;
	   			matrix[num1][num2]='-';
	   			matrix[a][b]='-';
			   }
			   else
			   {
			   	k=1;
			   	printf("\n*****************you didn't find it right***************\n");
			   	matrix[num1][num2]='*';
	   			matrix[a][b]='*';
			   }
			   guessofuser++;
			  printf("\n");
	   		menu(matrix,n);
	   		printf("\nusers score: %d",user);
	   	   printf("\ncomputers score: %d",pc);
			}
		}
			else
			{
				while(k==1&&pc<=n&&user+pc!=(n*n)/2)
				{
				
				printf("\ntap for computer's turn:\n");
				getch();
				printf("\ncomputers turn\n");
				
				do
				{
					num1=rand()%n+1;
			    	num2=rand()%n+1;
				}while(matrix[num1][num2]!='*');
				
				
				matrix[num1][num2]=matrix2[num1][num2];
				printf("\n%dx%d is already opened the value is: %d\n",num1,num2,matrix[num1][num2]);
				//getch();
   	       	    menu(matrix,n);
	      		prev=matrix[num1][num2];
				printf("\n");
				i=2;
				control=0;
			    while(i<m&&control==0)
				{
					if(pcmem[i]==prev&&(pcmem[i-2]!=num1||pcmem[i-1]!=num2))
					{
						
						a=pcmem[i-2];
						b=pcmem[i-1];
						control++;
					}
					i+=3;
					
					
				}
				if(control==0)
					{
						do{
							a=rand()%n+1;
					    	b=rand()%n+1;
						}while(matrix[a][b]!='*');
						
					}
				
			
				
					matrix[a][b]=matrix2[a][b];
					if(m<(mem*3))
	            {
	            	
	            	
	            	
	            	pcmem[m]=num1;
	            	m++;
	            	pcmem[m]=num2;
	            	m++;   
					pcmem[m]=prev;
					m++;             
	            	pcmem[m]=a;
					m++;     
	            	pcmem[m]=b;                
					m++;       
	            	pcmem[m]=matrix[a][b];    
					m++;            
	            	            
	            	            
				}      
				
				
				printf("\n%dx%d is already opened the value is: %d\n",a,b,matrix[a][b]);
				
	   	       	menu(matrix,n);
	   	       	printf("\npress any key to continue:\n");
				getch();
				if(prev==matrix[a][b])
	   	    	{
	   	    
	   	    		printf("pc is correct!\n");
				   pc++; 
				   matrix[num1][num2]='-';
	   	    		matrix[a][b]='-';
	   	        }
	   	        
			   else
			   {
			   	printf("\n*****************you didnt find it right***************\n");
			   	matrix[num1][num2]='*';
	   			matrix[a][b]='*';
	   			k=0;
			   }
			   guessofpc++;
			  printf("\n");
	   		menu(matrix,n);
				 printf("\nusers score: %d",user);
	   	   printf("\n pc's score: %d",pc);
	   }
			}
   	         
	   		   			
	   		
	   		c++;
	   		
        
   
   }
   if(user<pc)
   {
   	printf("\ncomputer win, total guess count:%d",guessofpc*2);
   }
   else if(user>pc)
   {
   	printf("\nuser win, total guess count:%d",guessofuser*2);
   }
   else
   {
   	printf("\ndraw, total guess count::%d",(guessofuser+guessofpc)*2);
   }
        
  
	return 0;
}
void tablo(int n,char matrix[][100],int matrix2[][100],int array[])
{
	int i,j,temp;
	srand(time(NULL));
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			matrix[i][j]='*';
		}
	}
	menu(matrix,n);
	for(i=1;i<n+1;i++)
	{
        for(j=1;j<n+1;j++)
	   	{
	   		temp=rand()%(n*n/2)+1;
	   	if(i<(n/2)+1)
	   	{
	        
	   		if(array[temp]<2)
	   		{
	   			
	   			matrix2[i][j]=temp;
	   			array[temp]++;
			}
			else
			{
				
				while(array[temp]==2)
				{
					temp=rand()%(n*n/2)+1;
				}
				matrix2[i][j]=temp;
				array[temp]++;
			}
		}
		else
		{
			while(array[temp]==2)
			{
		    	temp=rand()%(n*n/2)+1;

			}
			matrix2[i][j]=temp;
			array[temp]++;

		}
			
	   		
	   	}
	  
	   	
	   	
   }
}

void menu(char matrix[100][100],int n)
{
	int i,j;
	
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(i==0)
			{
				if(j==0)
				{
					printf("Coordinates ");
				}
				else
				{
					
					printf("%d ",j);
				}
			}
			else if(j==0)
			{
				printf("\n%d",i);
			}
			else if(j==1)
			{
				if(matrix[i][j]!='*'&&matrix[i][j]!='-')
				{
					printf("            %d ",matrix[i][j]);
				}
				else
				{
					printf("            %c ",matrix[i][j]);
				}
				
				
			}
			else
			{
				if(matrix[i][j]!='*'&&matrix[i][j]!='-')
				{
					printf("%d ",matrix[i][j]);
				}
				else
				{
						printf("%c ",matrix[i][j]);
				}
			
			}
			
			
		}
	}
}
