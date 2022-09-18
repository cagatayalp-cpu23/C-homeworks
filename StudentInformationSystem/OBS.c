#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct class
{
	int Code;
	int Credit;
	char Name[20];
	int Capacity;
	struct class *next;
	int *studentNumbers;
	int numberofStudents;
}CLASS;
typedef struct student
{
	int number;
	char Name[20];
	char SurName[20];
	int classCount;
	int numberOfCredits;
	struct student *next;
	struct student *prev;
}STUDENT;
typedef struct studentclass{
	int ID;
	int classcode;
	int studentnumber;
	struct studentclass *next;
	
}STUDENTCLASS;
CLASS *addClass(CLASS *head);
CLASS *removeClass(CLASS *head);
STUDENT *addStudent(STUDENT *head);
void printStudent(STUDENT *head);
STUDENT *removeStudent(STUDENT *head);
void saveToFile(CLASS *head);
void savetoFileForStudentClass(STUDENTCLASS*);
CLASS* readFromFile(CLASS *head);
STUDENT* readFromFileforStudent(STUDENT *head);
void saveToFileforStudent(STUDENT *head);
STUDENTCLASS *readFromFileForStudentClass(STUDENTCLASS *head);
void PrintStudentsTakingTheClass(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc);
void PrintClassesforStudent(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc);
STUDENTCLASS* addClasstoStudent(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc,int,int,int);

CLASS *addClass(CLASS *head){
	CLASS *prev=head;
	CLASS *temp=head;
	CLASS *cls=(CLASS*)malloc(sizeof(CLASS));
	printf("enter the code:");
	scanf("%d",&cls->Code);
	printf("enter the credit:");
	scanf("%d",&cls->Credit);
	printf("enter the name:");
	scanf("%s",cls->Name);
	printf("enter the Capacity:");
	scanf("%d",&cls->Capacity);
	cls->numberofStudents=0;
	if(head==NULL)
	{
		head=cls;
		cls->next=NULL;
	}
	else
	{
		if(cls->Code>temp->Code)
		{
			while(temp!=NULL&&cls->Code>temp->Code)
	    	{
	     		prev=temp;
	    		temp=temp->next;
	    	}
	    	if(temp!=NULL&&cls->Code==temp->Code)
	    	{
	    		printf("\nsame class code added before\n");
			}
			else
			{
				prev->next=cls;
	        cls->next=temp;
			}
	    	
		}
		else if(cls->Code<temp->Code)
		{
			head=cls;
			cls->next=temp;
		}
		else
		{
			printf("\nsame class code added before\n");
		}
		
	}
	return head;
	
	
}



STUDENT *addStudent(STUDENT *head){
	STUDENT *prev=head;
	STUDENT *temp=head;
	STUDENT *std=(STUDENT*)malloc(sizeof(STUDENT));
	printf("enter the number:");
	scanf("%d",&std->number);
	printf("enter the Name:");
	scanf("%s",std->Name);
	printf("enter the surname:");
	scanf("%s",std->SurName);
	std->classCount=0;
	std->numberOfCredits=0;
	
	if(head==NULL)
	{
		head=std;
		std->next=NULL;
		std->prev=head;
	}
	else
	{
		if(std->number>temp->number)
		{
			while(temp!=NULL&&std->number>temp->number)
	    	{
	     		prev=temp;
	    		temp=temp->next;
	    	}
	    	if(temp!=NULL&&std->number==temp->number)
	    	{
	    		printf("\nsame number added before\n");
			}
			else
			{
				prev->next=std;
				std->prev=prev;
	        std->next=temp;
			}
	    	
		}
		else if(std->number<temp->number)
		{
			head=std;
			std->next=temp;
			std->prev=head;
		}
		else
		{
			printf("\nsame class code added before\n");
		}
		
	}
	return head;
	
	
}
CLASS *removeClass(CLASS *head)
{
	CLASS *temp=head;
	CLASS *prev;
	int code;
	printf("enter the code of the class to be removed: ");
	scanf("%d",&code);
	if(temp!=NULL&&temp->Code<code)
	{
		while(temp!=NULL&&temp->Code<code)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("\nthis class code  doesnt exit\n");
		}
		else if(temp->Code==code)
		{
			prev->next=temp->next;
			free(temp);
			printf("\nremoved!\n");
		}
	}
	else if(temp!=NULL&&temp->Code>code)
	{
		printf("\nthis class code  doesnt exit\n");
	}
	else if(temp!=NULL&&temp->Code==code)
	{
		head=temp->next;
		free(temp);
		printf("\nremoved!\n");
	}
	return head;
	
	
}





STUDENT *removeStudent(STUDENT *head)
{
	STUDENT *temp=head;
	STUDENT *prev;
	int number;
	printf("enter the number of the student to be removed: ");
	scanf("%d",&number);
	if(temp!=NULL&&temp->number<number)
	{
		while(temp!=NULL&&temp->number<number)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("\nthis student number  doesnt exit\n");
		}
		else if(temp->number==number)
		{
			prev->next=temp->next;
			if(temp->next!=NULL)
			{
				temp->next->prev=prev;
			}
			
			free(temp);
			printf("\nremoved!\n");
		}
	
	}
	else if(temp!=NULL&&temp->number>number)
	{
		printf("\nthis student number  doesnt exit\n");
	}
	else if(temp!=NULL&&temp->number==number)
	{
		head=temp->next;
		if(temp->next!=NULL)
			{
				temp->next->prev=head;
			}
		
		free(temp);
		printf("\nremoved!\n");
	}
	return head;
	
	
}






void print(CLASS *head)
{
	CLASS *temp=head;
	while(temp!=NULL)
	{
		printf("\ncode :%d credit:%d name:%s capacity:%d total number of students:%d\n ",temp->Code,temp->Credit,temp->Name,temp->Capacity,temp->numberofStudents);
		temp=temp->next;
	}
}
void printStudent(STUDENT *head)
{
	STUDENT *temp=head;
	while(temp!=NULL)
	{
		printf("\n number :%d name:%s surname:%s total number of credit:%d total number of class:%d\n ",temp->number,temp->Name,temp->SurName,temp->numberOfCredits,temp->classCount);
		temp=temp->next;
	}
}
void saveToFileforStudent(STUDENT *head)
{
	FILE* fp;
	STUDENT *temp=head;
	fp=fopen("student.txt","w");
	while(temp!=NULL)
	{
		fprintf(fp,"%d %s %s %d %d\n",temp->number,temp->Name,temp->SurName,temp->numberOfCredits,temp->classCount);
		temp=temp->next;
	}
	fclose(fp);
}

void saveToFile(CLASS *head)
{
	FILE* fp;
	CLASS *temp=head;
	fp=fopen("class.txt","w");
	while(temp!=NULL)
	{
		fprintf(fp,"%d %d %s %d %d\n",temp->Code,temp->Credit,temp->Name,temp->Capacity,temp->numberofStudents);
		temp=temp->next;
	}
	fclose(fp);
}

void savetoFileForStudentClass(STUDENTCLASS *headsc){
	FILE* fp;
	STUDENTCLASS *temp=headsc;
	fp=fopen("studentclass.txt","w");
	while(temp!=NULL)
	{
		fprintf(fp,"%d %d %d\n",temp->ID,temp->classcode,temp->studentnumber);
		temp=temp->next;
	}
	fclose(fp);
	
	
	
	
	
	
}


CLASS *readFromFile(CLASS *head)
{
	FILE * fp;
	CLASS *temp=(CLASS*)malloc(sizeof(CLASS));
	fp=fopen("class.txt","r");
	while(fscanf(fp,"%d %d %s %d %d",&temp->Code,&temp->Credit,temp->Name,&temp->Capacity,&temp->numberofStudents)==5)
	{
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
		}
		else
		{
			CLASS *tmp=head;
			while(tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			tmp->next=temp;
			temp->next=NULL;
		}
		temp=(CLASS*)malloc(sizeof(CLASS));
	}
	return head;
}



STUDENTCLASS *readFromFileForStudentClass(STUDENTCLASS *head)
{
	FILE * fp;
	STUDENTCLASS *temp=(STUDENTCLASS*)malloc(sizeof(STUDENTCLASS));
	fp=fopen("STUDENTCLASS.txt","r");
	while(fscanf(fp,"%d %d %d",&temp->ID,&temp->classcode,&temp->studentnumber)==3)
	{
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
		}
		else
		{
			STUDENTCLASS *tmp=head;
			while(tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			tmp->next=temp;
			temp->next=NULL;
		}
		temp=(STUDENTCLASS*)malloc(sizeof(STUDENTCLASS));
	}
	return head;
}



STUDENT *readFromFileforStudent(STUDENT *head)
{
	FILE * fp;
	STUDENT *temp=(STUDENT*)malloc(sizeof(STUDENT));
	fp=fopen("student.txt","r");
	while(fscanf(fp,"%d %s %s %d %d\n",&temp->number,temp->Name,temp->SurName,&temp->numberOfCredits,&temp->classCount)==5)
	{
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
			temp->prev=head;
		}
		else
		{
			STUDENT *tmp=head;
			while(tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			tmp->next=temp;
			temp->prev=tmp;
			temp->next=NULL;
		}
		temp=(STUDENT*)malloc(sizeof(STUDENT));
	}
	return head;
}
void PrintStudentsTakingTheClass(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc)
{
	int classcode;
	STUDENTCLASS *tempforsc=headsc;
	printf("enter the class code:");
	scanf("%d",&classcode);
	CLASS *tmp=headClass;
	CLASS *findClass=NULL;
	CLASS *prev;
  		while(tmp!=NULL&&tmp->Code<classcode)
		{
			prev=tmp;
			tmp=tmp->next;
		}
		if(tmp==NULL||tmp->Code>classcode)
		{
			printf("\nthis class code  doesnt exit\n");
		}
		else if(tmp->Code==classcode)
		{
			findClass=tmp;
		}
		printf("studens taking that class:\n");
		while(tempforsc!=NULL)
		{
			if(tempforsc->classcode==classcode)
			{
				printf("%d\n",tempforsc->studentnumber);
			}
			tempforsc=tempforsc->next;
		}
		
		 
	
}
void PrintClassesforStudent(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc)
{
	int number;
	STUDENTCLASS *tempforsc=headsc;
	printf("enter the student number:");
	scanf("%d",&number);
	STUDENT *tmp=headStudent;
	STUDENT *findStudent=NULL;
	STUDENT *prev;
  		while(tmp!=NULL&&tmp->number<number)
		{
			prev=tmp;
			tmp=tmp->next;
		}
		if(tmp==NULL||tmp->number>number)
		{
			printf("\nthis number  doesnt exit\n");
		}
		else if(tmp->number==number)
		{
			findStudent=tmp;
		}
		printf("studens taking that class:\n");
		while(tempforsc!=NULL)
		{
			if(tempforsc->studentnumber==number)
			{
				printf("%d\n",tempforsc->classcode);
			}
			tempforsc=tempforsc->next;
		}
		
		 
	
}
STUDENTCLASS* addClasstoStudent(STUDENT *headStudent,CLASS *headClass,STUDENTCLASS *headsc,int k,int maxclasscount,int maxcredit)
{
	CLASS *prev;
	int number,classcode;
    STUDENT *temp=headStudent;
    STUDENT* findStudent=NULL;
    CLASS *tmp=headClass;
    CLASS *findClass=NULL;
	printf("which student number do you want to add class to:");
	scanf("%d",&number);
	printf("which class code do you want to add to a student:");
	scanf("%d",&classcode);
	
	

		while(tmp!=NULL&&tmp->Code<classcode)
		{
			prev=tmp;
			tmp=tmp->next;
		}
		if(tmp==NULL||tmp->Code>classcode)
		{
			printf("\nthis class code  doesnt exit\n");
		}
		else if(tmp->Code==classcode)
		{
			findClass=tmp;
		}
	

		while(temp!=NULL&&temp->number<number)
		{
			temp=temp->next;
		}
		if(temp==NULL||temp->number>number)
		{
			printf("\nnot found!\n");
		}
		else if(temp->number==number)
		{
			if(findClass->numberofStudents==0)
			{
				findClass->studentNumbers=(int*)(calloc(findClass->Capacity,sizeof(int)));
				
			}
			int tempcredit=temp->numberOfCredits+=findClass->Credit;
			if(tempcredit<maxcredit)
			{
				
			
		    if(temp->classCount<maxclasscount)
		    {
		    	
			
			if(findClass->numberofStudents<findClass->Capacity)
			{
				STUDENTCLASS *sc=(STUDENTCLASS*)(malloc)(sizeof(STUDENTCLASS));
				STUDENTCLASS *tp;
				findClass->studentNumbers[findClass->numberofStudents]=temp->number;
				temp->numberOfCredits+=findClass->Credit;
				temp->classCount++;
				findClass->numberofStudents++;
				sc->classcode=findClass->Code;
				sc->studentnumber=temp->number;
				sc->ID=k;
				if(headsc==NULL)
				{
					headsc=sc;
					headsc->next=NULL;
				}
				else
				{
					tp=headsc;
					while(tp->next!=NULL)
					{
						tp=tp->next;
					}
					tp->next=sc;
					sc->next=NULL;
				}
				
			}
			else
			{
				printf("\ncapacity is full!");
			}
		}
			else
		{
			printf("\nyou can't take classes more than %d",maxclasscount);
		}
	}
	else
	{
		printf("\nyou cant take more than %d credit",maxcredit);
	}
	
			
			
			

		}
		return headsc;
	
}

int main(int argc, char *argv[]) 
{
	
	
	
	int choice,t=1,maxclasscount,maxcredit;
	int ID=1000;
	CLASS *head=NULL;
	STUDENT *headStudent=NULL;
	STUDENTCLASS *headsc=NULL;
   head= readFromFile(head);
   int k=0;
   headStudent=readFromFileforStudent(headStudent);
   headsc=readFromFileForStudentClass(headsc);
	printf("enter the number of classes that student can take:");
	scanf("%d",&maxclasscount);
	printf("enter the number of credits that student can take:");
	scanf("%d",&maxcredit);
	while(t)
	{
			printf("press 1 to add class\n press 2 to remove class\n press 3 to print classes\n press 4 to add student\n press 5 to print student\n press 6 to remove student\n press 7 to add class to student\n press 8 to print students taking specific class\n press 9 toprint classes that student takes\n press 10 to exit:\n");
	
        	scanf("%d",&choice);
		if(choice==1)
		{
			head=addClass(head);
			 saveToFile(head);
		}
	    else if(choice==2)
		{
			head=removeClass(head);
			saveToFile(head);
		}
		else if(choice==3)
		{
			print(head);
		}
		else if(choice==4)
		{
			headStudent=addStudent(headStudent);
			 saveToFileforStudent(headStudent);
		}
		else if(choice==5)
		{
			printStudent(headStudent);
		}
		else if(choice==6)
		{
			headStudent=removeStudent(headStudent);
			saveToFileforStudent(headStudent);
		}
		else if(choice==7)
		{
		headsc=	addClasstoStudent(headStudent,head,headsc,ID,maxclasscount,maxcredit);
		ID++;
			saveToFileforStudent(headStudent);
			saveToFile(head);
			savetoFileForStudentClass(headsc);
			k++;
		}
		else if(choice==8)
		{
			PrintStudentsTakingTheClass(headStudent,head,headsc);
		}
		else if(choice==9)
		{
			PrintClassesforStudent(headStudent,head,headsc);

		}
		else if(choice==10)
		{
			t=0;
		}
	}
	
	
	
	return 0;
}
