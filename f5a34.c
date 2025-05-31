
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

typedef BinTreePointer StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;



void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);


void NonRecTraversal(BinTreePointer r);

int main(){
    BinTreePointer r1,r2;
    CreateBST(&r1);
    CreateBST(&r2);
    char w[9]="ALGORITHM";
    int i;
    for(i=0;i<9;i++){
        BSTInsert(&r1,w[i]);
        BSTInsert(&r2,w[8-i]);
    }
    printf("First tree\n");
    NonRecTraversal(r1);
    printf("Second tree\n");
    NonRecTraversal(r2);
}


void NonRecTraversal(BinTreePointer r){
    StackPointer s;
    StackElementType t;
    CreateStack(&s);
    Push(&s,r);

    while(!EmptyStack(s)){
        Pop(&s,&t);
        printf("%c ",t->Data);
        if(t->RChild!=NULL)
            Push(&s,t->RChild);
        if(t->LChild!=NULL)
            Push(&s,t->LChild);
    }
    printf("\n");
}

void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root){
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("Element is already in the Tree\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr){

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue > (*LocPtr)->Data)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent){
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue){

   BinTreePointer
   n,
   Parent,
   nNext,
   SubTree;
   boolean Found;

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("Element not found in the Tree\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }

                n->Data = nNext->Data;
                n = nNext;
          }
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root){
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%c ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}



void CreateStack(StackPointer *Stack){
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack){
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item){
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item){
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}





