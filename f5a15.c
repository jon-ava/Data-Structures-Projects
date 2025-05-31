
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef int BinTreeElementType;

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

int RightNodeCount(BinTreePointer Root);

int main(){
    int s;
    BinTreePointer a;
    BinTreeElementType x;
    CreateBST(&a);
    printf("Enter number of elements for the tree: ");
    scanf("%d",&s);
    for(s;s>0;s--){
        printf("Enter number: ");
        scanf("%d",&x);
        RecBSTInsert(&a,x);
    }
    printf("Elements of BST in increasing order\n");
    RecBSTInorder(a);
    printf("\nRightNodeCount = %d",RightNodeCount(a));
}


void CreateBST(BinTreePointer *Root){
    *Root = NULL;
}

int RightNodeCount(BinTreePointer Root){
    int lc,rc;
    lc=rc=0;
    if(BSTEmpty(Root))
        return 0;
    if(Root->LChild!=NULL)
        lc = RightNodeCount(Root->LChild);
    if(Root->RChild!=NULL)
        rc = 1 + RightNodeCount(Root->RChild);
    return lc+rc;
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
        printf("%d ",Root->Data);
        RecBSTInorder(Root->RChild);
    }
}

//ULR
void RecBSTPreorder(BinTreePointer Root){
    if (Root!=NULL) {
        printf("%d ",Root->Data);
        RecBSTPreorder(Root->LChild);
        RecBSTPreorder(Root->RChild);
    }
}

//LRU
void RecBSTPostorder(BinTreePointer Root){
    if (Root!=NULL) {
        RecBSTPostorder(Root->LChild);
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
}




