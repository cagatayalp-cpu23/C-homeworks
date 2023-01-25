#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 13
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 

void ele(int matrix[SIZE][SIZE])
{
	int i,j,count,k=1,M;
	printf("M degerini giriniz");
	scanf("%d",&M);
	while(k==1)
	{
		k=0;
		for(i=0;i<SIZE;i++)
    	{
		
		    count=0;
	    	for(j=0;j<SIZE;j++)
	    	{
	    		if(matrix[j][i]==1)
	    		{
	     			count++;
	     		}
	    	}
	    	if(count<M&&count!=0)
	    	{
		     	k=1;
		    	for(j=0;j<SIZE;j++)
	        	{
		            matrix[j][i]=0;
		            matrix[i][j]=0;
	         	}
		    
	    	}
    	}
	}
	
} 
void DFS(int startNode, int *visited, int matrix[SIZE][SIZE]) {
  
 
  int i;
  
  visited[startNode] = 1;
  
  for(i=0;i<SIZE;i++)
  if (matrix[startNode][i]==1 && visited[i]==0) {
		DFS(i,visited,matrix);
  }
}

void yazdir(int matrix[SIZE][SIZE],int K[SIZE],char ch[50][50],int mod)
{
	int i,j,count;
	for(i=1;i<SIZE;i++)
	{
		count=0;
		for(j=1;j<SIZE;j++)
		{
			if(matrix[j][i]==1)
			{
				count++;
			}
		}
	       if(mod==2)
	       {
	       	if(count>0)
	       	{
	       		printf("%d in ismi:%s takipcileri %d tanedir\n",i,ch[i],count);
			   }
	       	
		   }
			
			K[i]=count;

	}
}
void readFile(int matrix[SIZE][SIZE],char chmat[50][50])
{
	int num1,num2,num3,l=0;
	
	int ID[SIZE]={0};
	FILE *fp = fopen("socialNet.txt", "r");
  num3=0;
   int i=0;
  // Read the lines of the file
  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL) {
  	
  	if(i%2==0)
  	{
  		
  	
  	char *token = strtok(line, ",");
    int id = atoi(token);
    ID[l]=id;
    l++;
    
    char *first = strtok(NULL, ",");
    char *last = strtok(NULL, ",\n");
    strcat(first,last);
    strcpy(chmat[id],first);
    
     
  //  printf("ID: %d, Name: %s %s\n", id, first, last);
    
	  }

	  i++;
   
    
  }
  
  rewind(fp);
  i=0,l=0;
  while(fgets(line, sizeof(line), fp) != NULL)
  {
  	   if(i%2!=0)
  	   {
  	   	     char* str=strtok(line, ",");
  	   	     while(str!=NULL)
  	   	     {
  	   	     	int n1=atoi(str);
  	   	     	if(n1!=0)
  	   	     	{
  	   	     		matrix[ID[l]][n1]=1;
			   }
  	   	     	
  	   	 //    	printf("%d ",n1);
  	   	    
  	   	     	str=strtok(NULL,",");
  	   	     	
			  }
//			  printf("\n");
			  l++;
		 }
		 
		 i++;
  }

  // Close the file
  fclose(fp);
}






int main(int argc, char *argv[]) 
{
	int i,j,baglanti,count=0,M,visited[SIZE][SIZE],komsu[SIZE]={0},x,y,K[SIZE],mod;
	char ch[50][50];
	
	int matrix[SIZE][SIZE]={0};
	printf("normal mod:1 detay mod:2 :");
	scanf("%d",&mod);
/*	int matrix[SIZE][SIZE]={{0,0,0,0,0,0,0,0,0,0,0,0,0},
	                    {0,0,1,1,0,1,0,0,0,0,0,0,0},
						{0,1,0,1,0,0,0,0,0,0,0,0,0},
						{0,1,1,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,1,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,1,1,1,0},
						{0,0,0,0,1,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,1,0,0,0,1},
						{0,0,0,0,0,0,0,0,0,0,0,0,1},
						{0,0,0,0,0,0,0,0,1,0,1,1,0}  };*/
	

	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
			visited[i][j]=0;
		komsu[i]=0;
	}

	readFile(matrix,ch);
	if(mod==2)
	{
		
	
	yazdir(matrix,K,ch,mod);
	ele(matrix);
	yazdir(matrix,K,ch,mod);
	printf("x ve y yi girin:\n");
	scanf("%d %d",&x,&y);
	for(i=0;i<SIZE;i++){
		DFS(i,visited[i],matrix);	
	}

	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
			komsu[j]+=visited[i][j];
	}
	
	for(i=1;i<SIZE;i++)
	{
		if(komsu[i]>1)
		{
			printf("\n%d. kisi ismi:%s ve dolayli baglanti sayisi    %d ",i,ch[i],komsu[i]-1);
		}
		
	}
	printf("\nInfluencers\n");
	for(i=0;i<SIZE;i++)
	{
		
		if(komsu[i]>=y&&K[i]>=x)
		printf("\n%d.kisi ismi %s takipci sayisi ve baglanti sayisi %d %d",i,ch[i],K[i],komsu[i]-1);
	}
}
if(mod==1)
{
	yazdir(matrix,K,ch,mod);
	printf("x ve y yi girin:\n");
	scanf("%d %d",&x,&y);
	ele(matrix);
	for(i=0;i<SIZE;i++){
		DFS(i,visited[i],matrix);	
	}

	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
			komsu[j]+=visited[i][j];
	}
		printf("\nInfluencers\n");
	for(i=0;i<SIZE;i++)
	{
		
		if(komsu[i]>=y&&K[i]>=x)
		printf("\n%d.kisi ismi %s takipci sayisi ve baglanti sayisi %d %d",i,ch[i],K[i],komsu[i]-1);
	}
}
	
	
	return 0;
	
	
}
