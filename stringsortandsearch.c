#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char matrix[100][100];
	char tmp[100][100];
	int count[100];
	printf("how many words do you want to add?:");
	int N;
	scanf("%d",&N);
	printf("enter the words:\n");
	int i=0;
	int j=1;
	int adimsayisi=1;
	int K=0;
	int t=0;
	int I=0;
	int adim;
	int num3;
	for(i=0;i<N;i++)
	{
		printf("enter the word %d:\n",i+1);
		scanf("%s",&matrix[i]);
	}
	for(i=0;i<N;i++)
	{
	    int i1=0;
		while(matrix[i][i1]!=0)
		{
			
			if(matrix[i][i1]>='a'&&matrix[i][i1]<='z')
			{
				matrix[i][i1]=matrix[i][i1]+'A'-'a';
				
			}
			i1++;
		}
	}
	int Y;

	int Z;
	int a;
	for(a=0;a<N-1;a++)
	{
	    for(I=0;I<N-1;I++)
    	{
	    	if(matrix[I][0]>matrix[I+1][0])
        	{
	        	for(Y=0;Y<20;Y++)
         	{
	     	  count[Y]=0;
        	}
	        for(Z=0;Z<N;Z++)
	        {
		    	int J=0;
	        	while(matrix[Z][J]!=0)
	        	{
	        		
	        		count[t]=count[t]+1;
	        		J=J+1;
				}
				t=t+1;
			}
			t=0;
		    if(count[I]>=count[I+1])
		    {
			  int A=count[I];
			  for(K=0;K<A;K++)
			  {
				tmp[I][K]=matrix[I][K];
				matrix[I][K]=matrix[I+1][K];
				matrix[I+1][K]=tmp[I][K];
						
			  }
		   }
		    else if(count[I]<count[I+1])
		    {
			  int B=count[I+1];
			  for(K=0;K<B;K++)
			  {
				tmp[I][K]=matrix[I][K];
                 matrix[I][K]=matrix[I+1][K];
				matrix[I+1][K]=tmp[I][K];
			  }
	       }
	    	}
	    	else if(matrix[I][0]==matrix[I+1][0])
	    	{
	    	    
	    	    int r=1;
	    	    
	    	        
	    	            while(matrix[I][r]==matrix[I+1][r])
	    	            {
	    	                r++;
	    	                
	    	            }
	    	            if(matrix[I][r]>matrix[I+1][r])
	    	            {
	    	                for(Y=0;Y<20;Y++)
         	{
	     	  count[Y]=0;
        	}
	        for(Z=0;Z<N;Z++)
	        {
		    	int J=0;
	        	while(matrix[Z][J]!=0)
	        	{
	        		
	        		count[t]=count[t]+1;
	        		J=J+1;
				}
				t++;
			}
			t=0;
		    if(count[I]>=count[I+1])
		    {
			  int A=count[I];
			  for(K=0;K<A;K++)
			  {
				tmp[I][K]=matrix[I][K];
				matrix[I][K]=matrix[I+1][K];
				matrix[I+1][K]=tmp[I][K];
						
			  }
		   }
		   else if(count[I]<count[I+1])
		    {
			  int B=count[I+1];
			  for(K=0;K<B;K++)
			  {
				tmp[I][K]=matrix[I][K];
                 matrix[I][K]=matrix[I+1][K];
				matrix[I+1][K]=tmp[I][K];
			  }
	       }
	    	                
	    	            }
	    	                
	    	            
	    	              	    
	    	}
	    	
       }
	}
	for(Y=0;Y<20;Y++)
         	{
	     	  count[Y]=0;
        	}
	
	for(Z=0;Z<N;Z++)
	        {
		    	int J=0;
	        	while(matrix[Z][J]!=0)
	        	{
	        		
	        		count[t]=count[t]+1;
	        		J=J+1;
				}
				t++;
			}
			int v=0;
			int counter[26][26];
			char ch='A';
			for(i=0;i<2;i++)
			{
				
				for(j=0;j<26;j++)
				{
					switch(i)
					{
						case 0:
							
				         	counter[i][j]=ch;
				        	ch++;
				        	break;
				        case 1:
				        	counter[i][j]=0;
				        	break;	
					}
					
				}
			}
		int w=0;
		for(i=0;i<N;i++)
		{
			int o=0;
			int g=0;
			while(matrix[i][g]>counter[w][o]&&o<26)
			{
				o=o+1;
			}
			if(matrix[i][g]==counter[w][o])
			{
				counter[w+1][o]=counter[w+1][o]+1;
			}
		}
		printf("count of each word:\n");
		for(i=0;i<2;i++)
			{
				
				for(j=0;j<26;j++)
				{
					if(i==0){printf("%c",counter[i][j]);
					}
					
					if(i==1){printf("%d",counter[i][j]);
					}
				
				}	
				printf("\n");
			}
	
	printf("sorted:\n");
	for(i=0;i<N;i++)
	{
		printf("%s\n",matrix[i]);
	}
	char aranacak[50];
	int h=0;
	
	printf("enter the word to be searched(UPPERCASE):\n");
	scanf("%s",&aranacak);
	while(matrix[h][0]<aranacak[0]&&h<N-1)
	{
	    h++;
	}
	int num=0;
	if(matrix[h][0]==aranacak[0])
	{
		
		int c=0;
	    while(matrix[h][0]!=counter[0][c])
	    {
	    	c++;
		}
		int wn;
		int num1= h+counter[1][c];
		for(wn=h;wn<num1;wn++)
		{   
		    adimsayisi++;
			int p=1;
			while(matrix[wn][p]==aranacak[p]&&p<count[wn])
	       {
	       	  
	          p++;
	       }
	       
	       
	       	
		   
	       
	       if(p==count[wn])
	       {
	       	   adim=adimsayisi-1;
	           printf("%s exist in the dictionary\n",aranacak);
	           num=num+10;
	           num3=1;
	           
	       }
		}	
	    
	    
	    
	    if(num<10)
	    {
	        printf("%s does not exist in the dictionary\n",aranacak);
	    }
	   
	}
	else
	{
	    printf("%s does not exist in the dictionary\n",aranacak);
	}
	printf("number of operation:\n");
	if(num3==1)
	{
		printf("%d\n",adim);
	}
	else
	{
		printf("%d\n",adimsayisi);
	}
		
	return 0; 
}
