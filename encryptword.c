#include <stdio.h>
int main()
{
	char abc[1000];
	char str[1000];
	char str1[1000];
	int i;
	int x,R;
	int t=0;
	printf("word to be encrypted:");
	gets(str);
	printf("shift count:\n");
	scanf("  %d",&R);
	
	printf("for right shift press 1 for left shift press 2\n");
	scanf("%d",&x);

	
	switch(x)
	{
		case 1:
		
		while(str[i]!=0&&R<26)
		{
		
	     	   
	    	    if(str[i]==' ')
	        	{
		    	  abc[i]=' ';
		    	  i++;
	        	}
		      
				abc[i]=str[i]+R;
					
				
		    	i++;		
	       
			   
	         	
		}
		printf("encrypted word\n");
		
		puts(abc);
	break;
		case 2:
		while(str[i]!=0&&R<26)
		{
		   
	    	
    	   		if(str[i]==' ')
	        	{
		    	  abc[i]=' ';
		    	  i++;
	        	}
			abc[i]=str[i]-R;
			i++;
    	   
		
			
		}
		printf("encrypted word\n");
		puts(abc);
	break;
	}
	
		if(x==2)
		{
			while(abc[t]!=0&&R<26)
	    	{
			
			
	         	if(abc[t]==' ')
	        	{
		    	  str1[t]=' ';
		    	  t++;
	        	}
		      
		    	str1[t]=abc[t]+R;
					
				
		    	t++;
	    	}
		  		
			printf("decrypted word\n");
		
	    	puts(str1);
			
		}		
	
		else if(x==1)
		{
			while(abc[t]!=0&&R<26)
	    	{
		    	if(abc[t]==' ')
	         	{
		    	  str1[t]=' ';
		    	  t++;
	        	}
		    	str1[t]=abc[t]-R;
		    	t++;
			
	    	}
		printf("decrypted word\n");
		puts(str1);
		}	
		return 0;
}
            
