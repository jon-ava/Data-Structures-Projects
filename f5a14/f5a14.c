
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct{
    char name[20],phone[10];
    int code;
}BinTreeElementType;

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

void BuildBST(BinTreePointer *r);
void RecBSTSearchBySubject(BinTreePointer Root, int x);


int main(){
    BinTreePointer a,r;
    CreateBST(&a);
    BinTreeElementType t;
    boolean f;
    char c;
    int i;



    //1
    BuildBST(&a);


    //2
    printf("Print teachers data\n");
    RecBSTInorder(a);

    //3
    for(i=0;i<2;i++){
        printf("\nGive teacher full name: ");
        gets(t.name);
        printf("Give teacher phone number: ");
        gets(t.phone);
        printf("Give teacher code: ");
        scanf("%d",&t.code);
        getchar();
        RecBSTInsert(&a,t);
    }

    //4
    printf("\nGive teacher full name to search: ");
    gets(t.name);
    RecBSTSearch(a,t,&f,&r);
    if(f)
        printf("%s, %s, %d\n",r->Data.name,r->Data.phone,r->Data.code);
    else
        printf("Teacher not found\n");

    //5
    printf("\nGive code to search: ");
    scanf("%d",&i);
    getchar();
    RecBSTSearchBySubject(a,i);

    //6
    printf("\nGive teacher full name to delete: ");
    gets(t.name);
    RecBSTDelete(&a,t);

    //7
    printf("\nPrint teachers data\n");
    RecBSTInorder(a);


}

void BuildBST(BinTreePointer *r){
    FILE *f;
    BinTreeElementType t;
    int x;
    char c;

    f = fopen("I14F5.TXT","r");
    if(f==NULL){
        printf("ERROR");
        exit(-1);
    }

    while(1){
        x = fscanf(f,"%20[^,],%c%10[^,],%c%d%c",&t.name,&c,&t.phone,&c,&t.code,&c);
        if(x == EOF)break;
        if(x!=6 || c!='\n'){
            printf("ERROR");
            printf("\n%d,%d",x,c);
            exit(-1);
        }
        RecBSTInsert(r,t);
    }

    fclose(f);
}


void RecBSTSearchBySubject(BinTreePointer Root, int x){
    if(Root!=NULL) {
        RecBSTSearchBySubject(Root->LChild,x);
        if(Root->Data.code==x)
            printf("%s, %s, %d\n",Root->Data.name,Root->Data.phone,Root->Data.code);
        RecBSTSearchBySubject(Root->RChild,x);
    }
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
        if (strcmp(Item.name,(*Root) ->Data.name)<0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.name,(*Root) ->Data.name)>0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("Element is already in the Tree\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr){
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.name,Root->Data.name)<0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.name,Root->Data.name)>0)
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
          if (strcmp(KeyValue.name,(*Root) ->Data.name)<0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);
          else
            if (strcmp(KeyValue.name,(*Root) ->Data.name)>0)
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
        printf("%s, %s, %d\n",Root->Data.name,Root->Data.phone,Root->Data.code);
        RecBSTInorder(Root->RChild);
    }
}

//ULR
void RecBSTPreorder(BinTreePointer Root){
    if (Root!=NULL) {
        printf("%s, %s, %d\n ",Root->Data.name,Root->Data.phone,Root->Data.code);
        RecBSTPreorder(Root->LChild);
        RecBSTPreorder(Root->RChild);
    }
}

//LRU
void RecBSTPostorder(BinTreePointer Root){
    if (Root!=NULL) {
        RecBSTPostorder(Root->LChild);
        RecBSTPostorder(Root->RChild);
        printf("%s, %s, %d\n ",Root->Data.name,Root->Data.phone,Root->Data.code);
    }
}




