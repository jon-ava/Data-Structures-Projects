#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 20
#define NilValue -1

typedef struct {
    int id;
    float grade;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
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


int main(){
    ListPointer l;
    NodeType n[NumberOfNodes];
    ListPointer fp,pp;
    ListElementType t;
    int s;

    InitializeStoragePool(n,&fp);
    CreateList(&l);

    printf("Give number of students: ");
    scanf("%d",&s);
    for(s;s>0;s--){
        printf("Give ID to be added to the list: ");
        scanf("%d",&t.id);
        printf("Give grade to be added to the list: ");
        scanf("%f",&t.grade);
        Insert(&l,n,&fp,NilValue,t);
        TraverseLinked(l,n);
    }

    printf("Give position of previous element for removal: ");
    scanf("%d",&pp);
    Delete(&l,n,&fp,pp);
    TraverseLinked(l,n);

    for(s=0;s<2;s++){
        printf("Give ID to be added to the list: ");
        scanf("%d",&t.id);
        printf("Give grade to be added to the list: ");
        scanf("%f",&t.grade);
        printf("Give position after which the element will be added: ");
        scanf("%d",&pp);
        Insert(&l,n,&fp,pp,t);
        TraverseLinked(l,n);
    }

}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.id=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.id=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
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
  Node[P].Data.id = -1;
  Node[P].Data.grade = -1;

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

  if (!EmptyList(List))
  {
      CurrPtr =List;
      int c=0;
      while (CurrPtr != NilValue){
        CurrPtr=Node[CurrPtr].Next;
        c++;
      }
      printf("\nNumber of elements in the list %d\n",c);
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("[%d: (%d,%g)->%d] ",CurrPtr,Node[CurrPtr].Data.id, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
