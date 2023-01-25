#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int max(int x, int y) {
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
 
int maximum_sum(int Blocks[], int low, int high)
{
    if (high <= low) {
        return Blocks[low];
    }
   int i;
    int mid = (low + high) / 2;
 
    
    int left_max = INT_MIN;
    int sum = 0;
    for ( i = mid; i >= low; i--)
    {
        sum += Blocks[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }
 
    
    
    int right_max = INT_MIN;
    sum = 0;    
    for ( i = mid + 1; i <= high; i++)
    {
        sum += Blocks[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }
 
   
    int max_left_right = max(maximum_sum(Blocks, low, mid),
                            maximum_sum(Blocks, mid + 1, high));
 
    return max(max_left_right, left_max + right_max);
}
int main(int argc, char *argv[]) 
{
	int N,i,*Blocks,array[100],sum=0,max,max2,j,tmp,tmp2,choice;
	printf("enter the number of blocks:");
	scanf("%d",&N);
	Blocks=(int*)malloc(N*sizeof(int));
	printf("Enter the cost of blocks:");
	for(i=0;i<N;i++)
	{
		scanf("%d",&Blocks[i]);
	}
	printf("press 1 for brute force press 2 to divide and conquer:");
	scanf("%d",&choice);
	if(choice==2)
	{
		int result=maximum_sum(Blocks,0, N-1);
		printf("result is %d",result);
	}
	
	else if(choice==1)
	{
		
	
	max=0;
	max2=0;
	for(i=0;i<N;i++)
	{
		max=0;
		sum=0;
		for(j=i;j<N;j++)
		{
			sum=sum+Blocks[j];
			if(max<sum)
			{
				max=sum;
				tmp2=j;

			}
			
		}
		if(max>max2)
		{
			tmp=i;
			
			max2=max;
			
		}
	}
	printf("%d-%d result is  %d",tmp,tmp2,max2);
}
	return 0;
}
