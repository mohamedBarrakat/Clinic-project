#ifndef LINKED_HEADER
#define LINKED_HEADER
struct node  //NODE
{
	u32 ID;
	u8 name[50];
	u32  age; 
	u8 gender[10];
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;
typedef struct //LIST
{
	NODE *start;
	NODE *end;	
}LIST;

NODE* CREATE_NODE(void);
void APPEND_NODE(LIST *L,NODE *N);
NODE* SEARCH_NODE(u32 ID,LIST L);
void EDIT_NODE(LIST L1,NODE *N);
void DELETE_NODE(LIST *L,u32 ID);
void RESERVATION();
void CANCEL_RES();
void PAT_REC();
void RES_LIST();
#endif