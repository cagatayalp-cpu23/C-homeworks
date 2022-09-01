#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct list
{
	int value;
	struct list *next;
	struct list *down;
	
}LIST;
LIST **Print(int seviye,LIST**);
void olustur(LIST *head,int N,int *seviye,LIST **array,int ilk);
void Search(LIST **head,int seviye);
void insert(LIST **head,int seviye);

int main(int argc, char *argv[]) 
{
	
	srand(time(NULL));
	int N,i,value,seviye=0,ilk;
	LIST *head=NULL;
    LIST **array;
	LIST **head2;
	printf("how many elements will you create a list");
	scanf("%d",&N);
		
		array=(LIST**)malloc(N*sizeof(LIST*));
		ilk=N;
    olustur(head,N,&seviye,array,ilk);
	
    
	head2=Print(seviye,array);
	
	
	LIST **tmp=(LIST**)malloc(seviye*sizeof(LIST*));
	
	seviye--;
	for(i=0;i<seviye;i++)
	{
		tmp[i]=array[i];
		
		
		
		
	}
	
	
	
	
	

	
		Search(head2,seviye);
	
    
    
    
	
	
	
	


	return 0;
}
void olustur(LIST *head,int N,int *seviye,LIST **array,int ilk)
{
	
    int value,i,number,k=0,count=0,gecici;
	LIST *prev=NULL,*prev2=NULL,*ilkadres;
	LIST *temp;
	prev2=NULL;
	gecici=count;//
	for(i=0;i<N;i++)
	{
	//	array=(LIST**)(realloc(array,(*seviye)+2));
		number=rand()%100;
		if(N==ilk)
		{
		temp=NULL;
	    temp=(LIST*)(malloc(sizeof(LIST)));
	    if(i==0)
			{
				array[(*seviye)]=temp;
				(*seviye)++;
				
				
			}
	    
		printf("enter the value:");
		scanf("%d",&value);
       temp->value=value;
       temp->next=NULL;
       temp->down=NULL;
       if(prev!=NULL)
       {
        	prev->next=temp;
	   }
          prev=temp;
		}
		
		if(N-1>gecici){
	   if(number%2==0)
	   {
	   	    LIST *tmp=NULL;
	   	    tmp=(LIST*)(malloc(sizeof(LIST)));
	   	    if(N==ilk)
	   	    {
	   	    	tmp->value=value;
	   	    tmp->down=temp;
	   	    	
	   	    	
			   }
			   else
			   {
			   	tmp->value=head->value;
			   	tmp->down=head;
			   	
			   }
	   	    
	   	    tmp->next=NULL;
	   	    if(prev2!=NULL)
	   	    {
	   	    	prev2->next=tmp;
		    }
		    prev2=tmp;
		    if(k==0)
		    {
		    	k++;
		    	ilkadres=tmp;
		    	array[*seviye]=ilkadres;
		    	(*seviye)++;
			}
		    
	   	     
	   	    gecici++;
	   	    
	     
	   }
	   if(ilk!=N&&head!=NULL)
	   {
	   	head=head->next;
	   }
	  
	   
	     
	   
	   
	}}
//	if(gecici==1)
//	{
//		gecici=0;
//	}
	 if(gecici==count)
	   {
	   	    array[*seviye]=ilkadres;
		    	(*seviye)++;
		    	return;
	   }
	   else
	   {
	   	
	   	olustur(ilkadres,gecici,seviye,array,ilk);
	   }
	

    	
}



void insert(LIST **head,int seviye)
{
	    LIST **tmp,*deger2;
    	tmp=head;
    	int i=seviye-1,value;
    	printf("\nenter the value to be added:");
    	scanf("%d",&value);
    	
    while(i!=-1)
    {
    
			while(tmp[i]->next!=NULL && tmp[i]->value<value)
		{
			tmp[i]=tmp[i]->next;
		}
         if(i==1)
		{
			deger2=(LIST*)malloc(sizeof(LIST));
			deger2->next=tmp[i]->next;
            tmp[i]->next=deger2;
			i=-1;
			return;
		}

		tmp[i]=tmp[i]->down;	
		i--;	
	
	}
}
	
	
void Search(LIST **head,int seviye)
{
     	LIST **tmp;
    	tmp=head;
    	int i=seviye-1;
    	int value;
    	printf("enter the value to search for :");
    	scanf("%d",&value);
    	
    while(i!=-1)
    {
    	
    	while(tmp[i]->next!=NULL && tmp[i]->value<value)
		{
			tmp[i]=tmp[i]->next;
		}
		if(tmp[i]->value==value)
		{
			printf("finded level: %d\n",i+1);
			printf("found!");
			i=-1;
			return;
		}
		else if(i==-1)
		{
			printf("not found!");
			i=-1;
			return;
		}
		else
		{
		tmp[i]=tmp[i]->down;	
		i--;	
		}	
	}
				
		
}

LIST **Print(int seviye,LIST **array)
{
    
	int i=0;
	LIST **tmp=(LIST**)malloc(seviye*sizeof(LIST*));
	
	seviye--;
	for(i=0;i<seviye;i++)
	{
		tmp[i]=array[i];
		while(array[i]!=NULL)
		{
			printf("%d  ",array[i]->value);
	    	array[i]=array[i]->next;
		}
		
		printf("\n");
		
	}
	return tmp;
	
	
}
