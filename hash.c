#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node *createNode(int key,char *name);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct hash{
	struct node *head;
	int count;
};
struct node{
	int key;
	char name[50];
	struct node *next;
};
struct hash* hashTable=NULL;
int Horner(char name[]){
	int i, sonuc=0;
	
	int length = strlen(name);
	
	for(i=0;i<length;i++){
		sonuc+=name[i]*pow(31,length-i-1);
	}
	sonuc=sonuc%97;
	return sonuc;
}
void InsertToHash(int key,char name[])
{
	
   	
   	
   
	int hashIndex;
	hashIndex=key;
	struct node *newNode=createNode(key,name);
	
	if(!hashTable[hashIndex].head)
	{
		hashTable[hashIndex].head=newNode;
		hashTable[hashIndex].count=1;
		return;
	}
    
  
	newNode->next=hashTable[hashIndex].head;
	hashTable[hashIndex].head=newNode;
	hashTable[hashIndex].count++;
	return;
}
struct node *createNode(int key,char *name)
{
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
 
	newNode->key=key;
	strcpy(newNode->name,name);
	newNode->next=NULL;
	return newNode;
}
void hashFunc(char matrix[50][50])
{
	
	int matris[50][1];
	int i,k=0;
	for(i=0;i<42;i++)
	{
		if(i%2==0)
		{
			
			k++;
			InsertToHash(Horner(matrix[i]),matrix[i]);
			
		}
		else
		{
		
		}
		
	}
}
void search()
{
	 
	char aranacak[50];
	int i;
	printf("aranacak kelimeyi giriniz:");
	scanf("%s",aranacak);
	
	int a=strlen(aranacak);
    aranacak[a]='\n';
    aranacak[a+1]='\0';
    int index=Horner(aranacak);	
    	
	
	
	printf("%s",hashTable[index].head->name);
	
	
}

void Oku(char matrix[50][50])
{
	int i=0;
	FILE *fl;
	fl=fopen("Sample.txt","r");
	while(fgets(matrix[i],50,fl)!=NULL)
	{
		i++;	
	}

}

int main() {
    char s[50][50];
     Oku(s);
   hashTable=(struct hash*)calloc(50,sizeof(struct hash));
    int i;
    int key;
    hashFunc(s);
   
   	search();
	
   
    
    
   
    
    
    
    return 0;
}
