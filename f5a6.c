
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


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
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

int BSTDepth(BinTreePointer r);

int main(){
    BinTreePointer r;
    CreateBST(&r);
    RecBSTInsert(&r,'P');
    RecBSTInsert(&r,'R');
    RecBSTInsert(&r,'O');
    RecBSTInsert(&r,'C');
    RecBSTInsert(&r,'E');
    RecBSTInsert(&r,'D');
    RecBSTInsert(&r,'U');
    RecBSTInsert(&r,'R');
    RecBSTInsert(&r,'E');

    printf("Depth of Tree is: %d",BSTDepth(r));

}

int BSTDepth(BinTreePointer r){
    int ld,rd;

    if(BSTEmpty(r))
        return 0;
    ld = BSTDepth(r->LChild);
    rd = BSTDepth(r->RChild);
    if(rd>ld)
        return rd+1;
    return ld+1;
}

void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root){
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("Element is already in the Tree\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr){
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue < Root->Data)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue > Root->Data)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue){

   BinTreePointer TempPtr;

    if (BSTEmpty(*Root))
        printf("Element not found in the Tree\n");
     else
          if (KeyValue < (*Root)->Data)
             RecBSTDelete(&((*Root)->LChild), KeyValue);
          else
            if (KeyValue > (*Root)->Data)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);
            else
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;
                        free(TempPtr);
                   }
                   else
                   {
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

//LUR
void RecBSTInorder(BinTreePointer Root){
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("%c ",Root->Data);
        RecBSTInorder(Root->RChild);
    }
}

//ULR
void RecBSTPreorder(BinTreePointer Root){
    if (Root!=NULL) {
        printf("%c ",Root->Data);
        RecBSTPreorder(Root->LChild);
        RecBSTPreorder(Root->RChild);
    }
}

//LRU
void RecBSTPostorder(BinTreePointer Root){
    if (Root!=NULL) {
        RecBSTPostorder(Root->LChild);
        RecBSTPostorder(Root->RChild);
        printf("%c ",Root->Data);
    }
}




