#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define NilValue -1

#define StackLimit 10

typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void TraverseStack(StackType Stack);





typedef struct {
    int id;
    float grade;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;


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
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main(){

    ListPointer l;
    NodeType n[NumberOfNodes];
    ListPointer fp;
    ListElementType t;
    int i;
    StackType s;
    StackElementType st;
    float min;

    InitializeStoragePool(n,&fp);
    CreateList(&l);

    printf("Question C\n");
    printAll(l,fp,n);


    printf("Question D\n");
    TraverseLinked(l,n);


    printf("Question E\n");
    for(i=0;i<5;i++){
        printf("Give ID to be added to the list: ");
        scanf("%d",&t.id);
        printf("Give grade to be added to the list: ");
        scanf("%f",&t.grade);
        Insert(&l,n,&fp,NilValue,t);
    }


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



    printf("Question J\n");
    min=FindMins(l,n,&s);
    printf("Min value=%.1f\n",min);
    printf("AM with min grade are: ");
    while(!EmptyStack(s)){
        Pop(&s,&st);
        printf("%d ",st);
    }
    printf("\n");


    printf("Question K\n");
    TraverseStack(s);


    printf("Question L\n");
    printAll(l,fp,n);


    printf("Question M\n");
    TraverseLinked(l,n);

}



float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){
    float min;
    ListPointer c;
    CreateStack(Stack);
    StackElementType t;
    if(!EmptyList(List)){
        c=List;
        min=Node[c].Data.grade;
        while(c!=NilValue){
            if(Node[c].Data.grade<=min){
                if(Node[c].Data.grade<min){
                    while(!EmptyStack(*Stack))
                        Pop(Stack,&t);
                    min = Node[c].Data.grade;
                }
                Push(Stack,Node[c].Data.id);
            }
            c=Node[c].Next;
        }
    }else printf("Empty List ...\n");
    return min;

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
  printf("Linked list\n");
  if (!EmptyList(List))
  {

      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d|<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.id, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("Storage pool\n");
    printf("1st Element of List = %d, 1st free position = %d\n", List, FreePtr);
    printf("Elements in the storage pool:\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d|<%d,%.1f> ->%d) ",i,Node[i].Data.id,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}




void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}



void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}



