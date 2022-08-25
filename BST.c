#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct bst{
	char word[100];
	struct bst *right;
	struct bst *left;
	
}BST;
BST* create(BST *root,char str[100]);
void print(BST *root,int space);
int Search(BST *root,char ch[100]);
BST* Min(BST* root);
BST* deleteword(BST *root,char ch[50]);
int main(int argc, char *argv[]) 
{
	int k;
	BST *root=NULL;
	char word[100][100];
	char ch[100];
	int i=0,t,choice;
	BST *str;
	char filename[50];
	FILE *file;
   int n =1;
   while(n)
   {
   
	printf("press 1 to add file, 2 to search, 3 to print, 4 to delete, 5 to exit:");
	scanf("%d",&choice);
    if(choice==1)
    {
    	printf("file name to add(.txt): ");
    scanf("%s",filename);
    file=fopen(filename,"a");
     if (file == NULL) {
        printf("file can't be opened \n");
    }
    printf("how many word will you add: ");
    
    scanf("%d",&t);
    
 
    int a=t;
    k=0;
    for(t=i;t<i+a;t++)
    {
    	printf("enter the word %d:",t);
    	scanf("%s",word[t]);
    	while(k<t&&strcmp(word[t],word[k])!=0)
    	{
    		k++;
		}
		if(k==t)
		{
			fprintf(file,"%s",word[t]);
			
		}
		else
		{
			printf("\nit's the same '\n");
			t--;
		}
    	
    	
	}

	for(t=i;t<i+a;t++)
 {
 	root=create(root,word[t]);
 }
	}
	if(choice==2)
    {
    	printf("what word do you want to search?: ");
    	scanf("%s",ch);
    	Search(root,ch);
	}
	if(choice==3)
    {
    	print(root,0);
	}
	if(choice==4)
	{
		printf("what word do you want to delete?");
		scanf("%s",ch);
		if(Search(root,ch))
		{
			root=deleteword(root,ch);
		}
		else
		{
			printf("there is no such word");
		}
		
		
	}
	else if(choice==5)
	{
		n=0;
	}
}

   
    
    
	 
    
	fclose(file);
	return 0;
}

BST* deleteword(BST *root,char ch[50])
{
	if((root)==NULL)
	{
		return (root);
	}
	   
	else if(strcmp(ch,(root)->word)<0) root->left=deleteword(root->left,ch);
	else if(strcmp(ch,(root)->word)>0) root->right=deleteword(root->right,ch);
	else //found deleted number
	{
		// case1:no child
		if((root)->left==NULL && (root)->right==NULL)
		{
		BST* t=(root);
		(root)=NULL;
		free(t);				
		}
		//case2: one child
		else if((root)->left==NULL)
		{
		BST* t=(root);
		(root)=(root)->right;
		free(t);	
		}
		else if((root)->right==NULL)
	    {
		BST* t=(root);
		(root)=(root)->left;
		free(t);		
		}
		//case3: 2 children
		else
		{
			BST *t=Min(root->right);
			strcpy(root->word,t->word);
			(root)->right=deleteword((root)->right,t->word);
		}
	}
	return root;
}

BST* Min(BST* root)
{
	if(root && root->left)
	    return Min(root->left);
	else 
	    return root;
} 
int Search(BST *root,char ch[100])
{

	if(root==NULL)
	{
		printf("not found\n");
		return 0;
	}
	if(strcmp(ch,root->word)==0)
	{
		printf("found\n");
		return 1;
	}
	else if(strcmp(ch,root->word)>0)
	{
		Search(root->right,ch);
	}
	else
	{
		Search(root->left,ch);
	}
	
}
void print(BST *root,int space)
{
	
	
	int i=0;
	
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", root->word);
 
    // Process left child
    print(root->left, space);

		
	

	


}
BST* create(BST *root,char str[100])
{
	int i=0;
	BST *curr=root;
	BST *parent;
	BST *t=(BST*)malloc(sizeof(BST));
	strcpy(t->word,str);
	t->left=NULL;
	t->right=NULL;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		while(curr)
		{
			i=0;
			parent=curr;
			if(t->word[i]>curr->word[i])
			{
				curr=curr->right;
			}
			else if(str[i]==t->word[i])
			{
				while(curr->word[i]==t->word[i])
				{
					i++;
				}
				if(curr->word[i]>t->word[i])
				{
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
			else
			{
				curr=curr->left;
			}
		}
		if(parent->word[i]>str[i])
		{
			parent->left=t;
		}
		else
		{
			parent->right=t;
		}
	}
	return root;
}
