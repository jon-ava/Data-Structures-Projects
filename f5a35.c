
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


BinTreePointer LCANode(BinTreePointer Root, BinTreePointer node1,BinTreePointer node2);

int main(){
    int s;
    BinTreePointer a,n1,n2;
    BinTreeElementType x,y;
    boolean f;

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

    do{
        printf("\nGive first element of BST:");
        scanf("%d",&x);
        printf("Give second element of BST:");
        scanf("%d",&y);
        RecBSTSearch(a,x,&f,&n1);
        if(f)
            RecBSTSearch(a,y,&f,&n2);
    }while(!f);

    printf("LCA node of %d and %d is node with element %d",x,y,LCANode(a,n1,n2)->Data);

}

BinTreePointer LCANode(BinTreePointer Root, BinTreePointer node1,BinTreePointer node2){
    if(Root->Data > node1->Data && Root->Data > node2->Data)
        return LCANode(Root->LChild,node1,node2);
    if( Root->Data < node1->Data && Root->Data < node2->Data)
        return LCANode(Root->RChild,node1,node2);
    return Root;
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




