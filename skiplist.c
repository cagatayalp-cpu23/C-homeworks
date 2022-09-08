#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node
{
	struct node *next;
	struct node *down;
	int data;
	
	
}NODE;
void print(NODE **address,int k);
int add(NODE **address);
void delete(NODE **address);
void search(NODE **address,int k);

void create(NODE **address,int length);
int createsub(NODE **address,int k);


int main(int argc, char *argv[]) 
{
	NODE *address[100];
	srand(time(NULL));
	int length;
		
	printf("how many number do you want to add?");
	scanf("%d",&length);
	create(address,length);
	int k=0,t=1,choice;
	k=createsub(address,k);
   
	print(address,k);
	
	while(t)
	{
		printf("press 1 to add value, press 2 to delete value press 3 to search value press 4 to exit");
		scanf("%d",&choice);
		if(choice==1)
		{
			int control=add(address);
		    if(control==1)
		    {
		    	k=createsub(address,0);
            	
			}
			print(address,k);
			
		}
		if(choice==2)
		{
			delete(address);
		
			k=createsub(address,0);
        	print(address,k);
		}
		if(choice==3)
		{
			search(address,k);
		}
		if(choice==4)
		{
			t=0;
		}
	}
	
	return 0;
}
void search(NODE **address,int k)
{
	int value;
	printf("enter the value to be searched:");
	scanf("%d",&value);
	NODE *temp=address[k];
	int t=0;
	while(t==0)
	{
		
		if(temp==NULL)
		{
			printf("not found");
			t=1;
		}
		else if(value>temp->data)
    	{
		if(temp->next==NULL||temp->next->data>value)
		{
		temp=temp->down;
		k--;
	//	temp=address[k];	
		}
		else if(value==temp->next->data)
		{
			printf("\nfound in level %d\n",k);
			t=1;
		}
		else
		{
			temp=temp->next;
		}
		
    	}
    	else if(value<temp->data)
    	{
		
		k--;
		temp=address[k];	
		
    	}
    	else
    	{
    		printf("\nfound in level %d\n",k);
			t=1;
		}
	}
	
	
}
void delete(NODE **address)
{
	int value;
	NODE *head=address[0];
	NODE *prev;
	printf("enter the value to be deleted");
	scanf("%d",&value);
	while(head!=NULL&&head->data<value)
	{
		prev=head;
		head=head->next;
	}
	if(head->data!=value)
	{
		printf("not found");
	}
	else
	{
		prev->next=head->next;
		free(head);
	}
}
int add(NODE **address)
{
	
	int value;
	NODE *node=(NODE*)malloc(sizeof(NODE));
	NODE *head=address[0];
	NODE *temp=address[0];
	printf("enter the value:(sorted)");
	scanf("%d",&value);
	while(temp!=NULL&&temp->data!=value)
	{
		temp=temp->next;
	}
	
	
	node->data=value;
	
	NODE *prev;
if(temp==NULL)
	{
		
	
	while(head!=NULL&&head->data<value)
	{
		prev=head;
		head=head->next;
	}
	if(head==NULL)
	{
		prev->next=node;
		node->next=NULL;
	}
	else if(head==address[0])
	{
		address[0]=node;
		node->next=head;
	}
	else
	{
		prev->next=node;
		node->next=head;
	}
	return 1;
   }
else{
   	printf("you cant add the same value");
   	return 0;
   }
}
void print(NODE **address,int k)
{
	printf("\n\n");
	while(k!=-1)
	{
		NODE *head=address[k];
	    
		while(head!=NULL)
		{
			printf("%d  ",head->data);
			head=head->next;
		}
		k--;
		printf("\n");
	
		
		
	}
}
void create(NODE **address,int length){
	
	int i=0;
	NODE *prev;
	printf("\nenter the numbers:\n");//?
	for(i=0;i<length;i++)
	{
		NODE *node=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&(node->data));
		node->next=NULL;
		node->down=NULL;
		if(i==0)
		{
		
			address[0]=node;
			
		}
		else
		{
			prev->next=node;
		}
		prev=node;
		
	}
	
	
	
	
	
}
int createsub(NODE **address,int k)
{
//	HEED *temp=head;
    NODE *head=address[k];
	NODE *prev;

	int i=0;
        while(head!=NULL)
		{
			 

        	if(rand()%2==0)
        	{
        		
        		NODE *node=(NODE*)malloc(sizeof(NODE));
        		node->data=head->data;
        		node->down=head;
        		node->next=NULL;
        		if(i==0)
        		{
        			k++;
        			address[k]=node;
					
					
				}
				else
				{
					prev->next=node;
				}
				prev=node;
				i++;
            	

			}
			
			    
				head=head->next;
			
			
			
  
        	
		}
		if(i==0||i==1)
		{
			
			return k;
		}
		createsub(address,k);
}

