#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	char matrix[100][100];
	char tmp[100][100];
	int count[100];
	printf("how many words do you want to sort:");
	int N;
	scanf("%d",&N);
	printf("enter the strings:\n");
	int i=0;
	int j=1;
	
	int K=0;
	int t=0;
	int I=0;
	for(i=0;i<N;i++)
	{
		scanf("%s",&matrix[i]);
	}
	int Y;

	int Z;
	int a;
	for(a=0;a<N-1;a++)
	{
	    for(I=0;I<N-1;I++)
    	{
	    	while(matrix[I][0]<=matrix[I+1][0]&&I<N-1)
        	{
	        	I=I+1;
	    	}
	    	for(Y=0;Y<20;Y++)
         	{
	     	  count[Y]=0;
        	}
	        for(Z=0;Z<N-1;Z++)
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
	}
	

	 


	printf("sorted:\n");
	for(i=0;i<N;i++)
	{
		printf("%s\n",matrix[i]);
	}
	

	
	
	
	return 0; 
	
}
