#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);


void TraverseStack(StackPointer Stack);

int main(){
    StackPointer a;
    StackElementType t;
    boolean f = TRUE;
    char s[40];
    int i;

    CreateStack(&a);

    printf("Insert expression: ");
    scanf("%s",s);

    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            Push(&a,s[i]);
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(EmptyStack(a)){
                f=FALSE;
                break;
            }
            Pop(&a,&t);
            if((s[i]==')'&&t!='(')||(s[i]==']'&&t!='[')||(s[i]=='}'&&t!='{')){
                f=FALSE;
                break;
            }
        }
    }

    if(f&&EmptyStack(a))
        printf("CORRECT\n");
    else
        printf("WRONG\n");

}


void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
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



