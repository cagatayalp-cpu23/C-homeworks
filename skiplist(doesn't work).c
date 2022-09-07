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
typedef struct heed{
	NODE *node;
	struct heed *below;
	
}HEED;
void print(HEED *head);
HEED* create(HEED* head,int length);
HEED *createsub(HEED *head);


int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int length;
		HEED *head=(HEED*)malloc(sizeof(HEED));
		head->node=(NODE*)malloc(sizeof(NODE));
		
	HEED *head2=(HEED*)malloc(sizeof(HEED));
	head2->node=(NODE*)malloc(sizeof(NODE));
	printf("how many number do you want to add?");
	scanf("%d",&length);
	head=create(head,length);
	head2=createsub(head);

	print(head2);
	
	return 0;
}
void print(HEED *head)
{
	while(head!=NULL)
	{
		NODE *temp;
		temp=head->node;
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
		head=head->below;
		printf("\n");
	
		
		
	}
}
HEED* create(HEED* head,int length){
	
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
		
			head->node=node;
			head->below=NULL;
		}
		else
		{
			prev->next=node;
		}
		prev=node;
		
	}
	
	return head;
	
	
	
}
HEED *createsub(HEED *head)
{
//	HEED *temp=head;
  //  NODE *temp=head->node;
	NODE *prev;
	HEED *head2=(HEED*)malloc(sizeof(HEED));
	head2->node=(NODE*)malloc(sizeof(NODE));
	int i=0;
        while(head->node!=NULL)
		{
			 

        	if(rand()%2==0)
        	{
        		
        		NODE *node=(NODE*)malloc(sizeof(NODE));
        		node->data=head->node->data;
        		node->down=head->node;
        		node->next=NULL;
        		if(i==0)
        		{
        			head2->below=head;
					head2->node=node;
				}
				else
				{
					prev->next=node;
				}
				prev=node;
				i++;
            	

			}
			
			    
				head->node=head->node->next;
			
			
			
  
        	
		}
		if(i==0||i==1)
		{
			
			return head2;
		}
		createsub(head2);
}

