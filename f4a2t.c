
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void dif(ListPointer a, ListPointer b, ListPointer *f);

int main()
{
    ListPointer List,BList,FList,PredPtr;
    int i,s;
    ListElementType item,t;
    boolean Found;

    CreateList(&List);
    CreateList(&BList);
    CreateList(&FList);


    printf("Give number of elements for list 1: ");
    scanf("%d",&s);
    for(s;s>0;s--){
        printf("Give number to be inserted a the beginning of list 1: ");
        scanf("%d",&item);
        LinkedInsert(&List,item,NULL);
    }
    printf("Give number of elements for list 2: ");
    scanf("%d",&s);
    for(s;s>0;s--){
        printf("Give number to be inserted a the beginning of list 2: ");
        scanf("%d",&item);
        LinkedInsert(&BList,item,NULL);
    }
    printf("First list\n");
    LinkedTraverse(List);
    printf("Second list\n");
    LinkedTraverse(BList);

    dif(List,BList,&FList);

    printf("Final list\n");
    LinkedTraverse(FList);



}

void dif(ListPointer a, ListPointer b, ListPointer *f){
    ListPointer cpa,cpb,pp;
    boolean bol;
    cpa = a;
    while(cpa!=NULL){
        cpb = b;
        bol = TRUE;
        while(cpb!=NULL && bol){
            if(cpa->Data==cpb->Data)
                bol=FALSE;
            else
                cpb = cpb->Next;
        }
        if(bol){
            LinearSearch(*f,cpa->Data,&pp,&bol);
            if(!bol)
                LinkedInsert(f,cpa->Data,NULL);
        }
        cpa = cpa->Next;
    }
}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


