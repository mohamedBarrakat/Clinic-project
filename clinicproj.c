#include"stdtypes.h"
#include"LinkedHeader.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

LIST L1={NULL,NULL};
NODE *temp=NULL;

void main(void)
{
	u8 mode,i,exit_flag=1;
	u32 pw,id,selection1,selection2;
	NODE *N,*idcheck;
	printf("\n\n\n\t\t\t\t*******************************************\n\t\t\t\t***** Simple Clinic Management System *****\n\t\t\t\t*******************************************\n\n\n\n\n");
	while(exit_flag)
	{
		u8 ans1=1,ans2=1,idflag=0,flag=0;
		printf("\n1)For Admin Mode Press\n2)For User Mode Press\n3)To Exit Press\n");
		printf("Your choice: ");
		scanf("%d",&mode);
		if (mode==1)
		{
			printf("\n\n\t\t\t\t****** Admin Mode was Selected ******\n\n");
			printf("Please Enter your Password: ");
			scanf("%d",&pw);
			if (pw==1234)
			 {
				flag=1;
			 }
			 else
			 {
				 for (i=1;i<3;i++)
				{
					printf("Wrong Password,Try again: ");
					scanf("%d",&pw);
					if(pw==1234)
					{
						flag = 1;
						break;
					}
				}
			 }
			if (flag==1)
			{
					while(ans1!=2)
					{
						printf("\n\n****** In Admin Mode ******\n\n");
						printf("1)Add new patient.\n2)Edit existed patient info.\n3)Reserve an appointment with the doctor.\n4)Cancel reservation.\n5)Delete patient record.");
						printf("\nYour Selection: ");
						scanf("%d",&selection1);
						printf("\n");
						switch(selection1)
						{
							case 1: N=CREATE_NODE(); //add patient
									APPEND_NODE(&L1,N);
									printf("Enter ID:");
									scanf("%d",&id);
									idcheck=SEARCH_NODE(id,L1);
									if(idcheck!=NULL)
									{
									  if (idcheck->ID==id)
									  {
										 idflag=1;
									  }
									}
									
										//printf("This ID Already exist.");
									if (idflag==0)
									{
									N->ID=id;
									//scanf("%d",&N->ID);
									printf("Enter The Name: ");
									scanf(" %[^\n]",N->name); //kant " %[^\n]%*c"
									printf("Enter The Age: ");
									scanf("%d",&N->age);
									printf("Enter The Gender: ");
									scanf(" %[^\n]",N->gender);
									printf("Patient was Added successfully!\n\n");
									}
									else if (idflag==1)
									{
										printf("\nThis ID Already exist.\n");
									}
									break;
							case 2: printf("Enter patient ID: ");
									scanf("%d",&id);
									N=SEARCH_NODE(id,L1);
									EDIT_NODE(L1,N);
									break;
							case 3: RESERVATION();
									break;
							case 4:CANCEL_RES();
									break;
							case 5: printf("Enter patient ID: ");
									scanf("%d",&id);
									DELETE_NODE(&L1,id);
									break;
							default: printf("Wrong input.\n");
						}
						printf("\n1)back to Admin mode\n2)Back to Main Menu\n");
						printf("Your Choice: ");
						scanf("%d",&ans1);
						
					}
			}
			else
			{
				printf("You have enterd the password wrong for 3 times,softwere terminating.");
				exit_flag=0;//EXIT FLAG DON'T FORGET
			}
		}
		else if (mode==2)
		{
			while(ans2!=2)
			{
				printf("\n\n\t\t\t\t****** User Mode was Selected ******\n\n");
				printf("1)Patient Record.\n2)Reservation List.\n");
				printf("Your choice: ");
				scanf("%d",&selection2);
				switch (selection2)
				{
					case 1: printf("\n");
							PAT_REC();
					break;
					
					case 2: printf("\n");
							RES_LIST();
					break;
					
					default : printf("Wrong selection.\n");
				}
				printf("\n1)back to User mode\n2)Back to Main Menu\n");
				printf("Your Choice: ");
				scanf("%d",&ans2);
			}
		}
		else if (mode==3)
		{
			exit_flag=0;
		}
		else
			printf("Wrong input\n\n");
	}
	if(exit_flag==0)
	printf("GoodBye!");
}