#include <stdio.h>
#define N 5
void sagakaydir(int dizi[N],int matris[N][N],int mod)
{
	
	int temp = dizi[N - 1];
	int i,j;
	
	
	  
 	 for (i=N-1;i>0;i--) 
	{
 		   dizi[i] = dizi[i-1];
 	 }
	  dizi[0] = temp;
	  if(mod==2)
	  {
	    for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d",matris[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	  }
	  
	  
}
	
	

int kontrol(int matris[N][N],int i,int flag,int l,int mod)
{
	int j,k;
	
	if(i==N)
	{
		return 0;
	}
    if(l>2*N+1)
	{
		printf("duzenlenemiyor");
		exit(0);
	}	
		for(j=0;j<N;j++)
		{
			if(matris[i][j]==matris[i-1][j])
	    	{
	    		flag=1;
				sagakaydir(matris[i],matris,mod);
	     		kontrol(matris,i,0,l+1,mod);
	     		
	     	}
	     	k=i-2;
	     	while(k>=0)
	     	{
	     		
	     		if(matris[i][j]==matris[k][j])
	     		{
	     			flag=1;
			    	sagakaydir(matris[i],matris,mod);
	     	    	kontrol(matris,i,0,l+1,mod);
				 }
				 else
				 {
				 	k--;
				 }
			 }
	     	
		}
		if(flag==0)
		{
			kontrol(matris,i+1,0,l+1,mod);
		}
		
		
	return 0;
}
int main()
{
	int i,j,mod;
	int matris[N][N]={
	   				  {0,1,2,3,4},
	   				  {0,1,2,3,4},
	   				  {0,1,2,3,4},
	   				  {0,1,2,3,4},
	   				  {0,1,2,3,4}

	   				  
					  
					  
					  
					  	          
									 }	;
		printf("matrisin ilk hali:\n");
	    for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d",matris[i][j]);
			}
			printf("\n");
		}



	
	printf("normal mod icin 1 detay mod icin 2ye basin ");
	scanf("%d",&mod);
	
	
    int ret=	kontrol(matris,1,0,0,mod);
	
	if(ret==0&&mod==1)
	{
		printf("\n\n\nduzenlenmis matris:\n");
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
					printf("%d",matris[i][j]);
				}
				printf("\n");
			}
	}
	else if(ret==-1)
	{
		printf("duzenlenemiyor");
	}
	
	
    return 0;
	
}
