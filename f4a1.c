#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);

int main(){

    ListPointer l;
    NodeType n[NumberOfNodes];
    ListPointer fp,pp;
    ListElementType t;
    boolean f;
    char c;
    int i;

    InitializeStoragePool(n,&fp);
    CreateList(&l);

    printf("Question C\n");
    printAll(l,fp,n);


    printf("Question D\n");
    TraverseLinked(l,n);


    printf("Question E\n");
    do{
        printf("Give a number: ");
        scanf("%d",&t);
        f=Search(fp,l,n,t,&pp);
        Insert(&l,n,&fp,pp,t);
        printf("\nContinue Y/N: ");
        do{
            scanf("%c",&c);
        }while(tolower(c)!='y'&&tolower(c)!='n');
    }while(tolower(c)=='y');


    printf("Question F\n");
    printAll(l,fp,n);


    printf("Question G\n");
    TraverseLinked(l,n);


    printf("Question H\n");
    if(EmptyList(l))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");



    printf("Question I\n");
    if(FullList(l))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    printf("Question J\nSearch for a number\n");
    for(i=0;i<2;i++){
        printf("Give a number ");
        scanf("%d",&t);
        f=Search(fp,l,n,t,&pp);
        if(f)
            printf("The number is in the list and its predecessor is in position %d\n",pp);
        else
            printf("The number is not in the list");
    }


}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr){

    *PredPtr = NilValue;
    if(EmptyList(List))
        return FALSE;
    ListPointer curr = List;

    while(curr!=NilValue){
        if(Node[curr].Data==Item)
            return TRUE;
        if(Node[curr].Data>Item)
            return FALSE;
        *PredPtr = curr;
        curr = Node[curr].Next;
    }
    return FALSE;
}


void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("Storage pool\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1;

  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
  ListPointer CurrPtr;
  printf("Linked list\n");

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
