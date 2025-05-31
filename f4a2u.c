
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

void delete_list_after_n(ListPointer *List, int n);

int main()
{
    ListPointer l,pp;
    ListElementType item;
    int n;

    CreateList(&l);
    printf("Give number of elements for list : ");
    scanf("%d",&n);
    for(n;n>0;n--){
        printf("Give number to be inserted a the beginning of list: ");
        scanf("%d",&item);
        LinkedInsert(&l,item,NULL);
    }
    printf("Initial list\n");
    LinkedTraverse(l);
    printf("Give position after which elements will be deleted: ");
    scanf("%d",&n);
    delete_list_after_n(&l,n);
    printf("Final list\n");
    LinkedTraverse(l);

}

void delete_list_after_n(ListPointer *List, int n) {
    if (EmptyList(*List)) {
        printf("EMPTY LIST\n");
    } else {
        ListPointer curr,pre,temp;
        curr = *List;
        int i = 0;
        while (i < n && curr != NULL) {
            pre=curr;
            curr = curr->Next;
            i++;
        }
        if (i < n) {
            printf("Invalid n value\n");
        } else {
            while (pre->Next != NULL) {
                LinkedDelete(List, pre);
            }
        }
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


