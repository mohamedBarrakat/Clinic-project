#include"stdtypes.h"
#include"LinkedHeader.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


extern LIST L1;
extern NODE *temp;



u32 time[5]={-1,-1,-1,-1,-1},i,id;
/*
struct node  //NODE
{
	u8 ID;
	u32 name[50];
	u8  age; 
	u8 gender;//M/F
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;
typedef struct //LIST
{
	NODE *start;
	NODE *end;	
}LIST;
*/
NODE* CREATE_NODE(void) //Create Node
{
	return (NODE*) malloc(sizeof(NODE));
}

void APPEND_NODE(LIST *L,NODE *N) //Add to the linked list 
{
	if (L->start==NULL)
	{
		L->start=N;
		L->end=N;
		N->next=NULL;
		N->prev=NULL;
	}
	else
	{
		N->prev=L->end;
		N->prev->next=N;
		L->end=N;
		N->next=NULL;
	}
}

NODE* SEARCH_NODE(u32 ID,LIST L1) //Searching NODE
{
	NODE *temp=L1.start;
	
		while((temp) && ((temp->ID)!=ID))
		{
			temp=temp->next;
		}
	
	return temp;
}

void EDIT_NODE(LIST L1,NODE *N) //Edit Nodes
{	
	u32 ID,answer=1,choice,x=0,exit_flag=0;
	NODE* temp;
	temp=N;
	while(temp==NULL && exit_flag==0 )
	{
		if (temp==NULL)
		{
			printf("ID doesn't exist.\n");
			printf("Do you want to search for another ID ?\n1)yes.\n2)no.\n");
			scanf("%d",&x);
			if (x==1)
			{
				printf("Enter patient ID: ");
				scanf("%d",&ID);
				temp=SEARCH_NODE(ID,L1);
			}else if(x==2);
			{
				exit_flag=1;
			}
		 /*while (temp==NULL)
		 {
			printf("Wrong ID,Try Again: ");
			scanf("%d",&ID);	
			temp=SEARCH_NODE(ID,L1);
		 }*/
		}
	}
	if (exit_flag!=1)
	{
		printf("ID was Found,You Can Edit Patient information:-\n\n");
		while (answer!=2)
		{
		printf("1)Name: ");
		printf(temp->name);
		printf("\n");
		printf("2)Age: %d\n",temp->age);//%d->%c
		printf("3)Gender: ");
		printf(temp->gender);
		printf("\n");
		printf("Choose 1,2 or 3 to Edit: ");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
				{
				//temp=N;
				printf("New name: ");
				scanf(" %[^\n]",temp->name);
				printf("Information was edited successfully!\n");
				break;
				}
				case 2:
				{
				//temp=N;
				printf("New Age: ");
				scanf("%d",&temp->age);//%d->%c
				printf("Information was edited successfully!\n");
				break;
				}
				case 3:
				{
				//temp=N;
				printf("New Gender(Male/Female): ");
				scanf(" %[^\n]",temp->gender);	
				printf("Information was edited successfully!\n");
				break;
				}
				default:
				printf("Wrong option,choose again.\n");
			}
			
		printf("\nDo you want to edit another information?\n1)yes\n2)no\n");
		scanf("%d",&answer);
		}
	}	
}
	


void DELETE_NODE(LIST *L,u32 ID) //Delete NOTE
{
	NODE *temp=SEARCH_NODE(ID,L1);
	if(temp==NULL)
	{
		printf("ID doesn't exist\n");
	}
	else 
	{
		if (L->start==L->end)
		{
			L->start=NULL;
			L->end=NULL;
			free(temp);
			printf("Patient record was deleted successfully.\n");
		}else if(temp==L->start)
			{
				L->start=temp->next;
				L->start->prev=NULL;
				free(temp);
				printf("Patient record was deleted successfully.\n");
			}
		 else if(temp==L->end)
			{
				L->end=temp->prev;
				L->end->next=NULL;	
				free(temp);
				printf("Patient record was deleted successfully.\n");
			}
		else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
				printf("ID was deleted successfully.");
			}
	}
	
}

void RESERVATION()//Reserve time
{
	NODE *node;
	u32 choice,id;
	for(i=0;i<5;i++)
	{
		switch (i)
		{
			case 0:
			if(time[i]!=-1)
			break;
			else printf("1)2pm    to 2:30pm is available\n"); break;
			case 1:
			if(time[i]!=-1)
			break;
			else printf("2)2:30pm to 3pm is available\n"); break;
			case 2:
			if(time[i]!=-1)
			break;
			else printf("3)3pm    to 3:30pm is available\n"); break;
			case 3:
			if(time[i]!=-1)
			break;
			else printf("4)4pm    to 4:30pm is available\n"); break;
			case 4:
			if(time[i]!=-1)
			break;
			else printf("5)4:30pm to 5pm is available\n"); break;
		}
	}
	/*CHECK IF THE SLOT IS AVAILABE OR NOT*/
	printf("\nYour choice: ");
	scanf("%d",&choice);
	printf("Enter patient ID: ");
	scanf("%d",&id);
	node=SEARCH_NODE(id,L1);
	if (node!=NULL)
	{
		time[choice-1]=id;
		printf("Reservation completed!\n\n");
	}
	else
		printf("ID doesn't exist.\n");
}

void CANCEL_RES()//Cancel reservation
{
	u8 i;
	u32 flag=0,id;
	NODE *node;
	printf("Enter patient ID: ");
	scanf("%d",&id);
	for(i=0;i<5;i++)
		{
		 if(time[i]==id)
		 {
			time[i]=-1;
			printf("Cancellation completed!\n");
			flag=1;
		 }
		}
	if(flag==0)
		printf("ID doesn't exist.");
}

void PAT_REC()//Patient record
{
	NODE *N;
	printf("Enter patient ID: ");
	scanf("%d",&id);
	N=SEARCH_NODE(id,L1);
	if(N!=NULL)
	{
		printf("Patient record:-\n\n"); //add printf ID
		printf("Name: ");
		printf(N->name);
		printf("\n");
		printf("Age: %d\n",N->age);
		printf("Gender: ");	
		printf(N->gender);
		printf("\n");
	}
	else printf("\nID doesn't exist.\n");
}

void RES_LIST()//reservation list
{
	u8 counter=0;
	
	for(i=0;i<5;i++)
	{
		if (time[i]!=-1)
			counter++;
	}
	if(counter==0)
	{
		printf("There are no reservations\n\n");
	}
	else
	{
		for(i=0;i<5;i++)
		{
			switch (i)
			{
				case 0:
				if(time[i]==-1)
				break;
				else printf("2pm to 2:30pm is reserved by ID: %d\n",time[i]); break;
				case 1:
				if(time[i]==-1)
				break;
				else printf("2:30pm to 3pm is reserved by ID: %d\n",time[i]); break;
				case 2:
				if(time[i]==-1)
				break;
				else printf("3pm to 3:30pm is reserved by ID: %d\n",time[i]); break;
				case 3:
				if(time[i]==-1)
				break;
				else printf("4pm to 4:30pm is reserved by ID: %d\n",time[i]); break;
				case 4:
				if(time[i]==-1)
				break;
				else printf("4:30pm to 5pm is reserved by ID: %d\n",time[i]); break;
			}
		}
	}
}



