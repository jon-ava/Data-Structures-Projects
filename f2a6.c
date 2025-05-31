#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define StackLimit 30

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
StackElementType GetTopElementA(StackType s);
StackElementType GetTopElementB(StackType s);

int main(){
    StackType s;
    CreateStack(&s);
    int i;
    for(i=0;i<StackLimit;i++)
        Push(&s,(i+1)*2);
    TraverseStack(s);
    printf("Top with GetTopElementA = %d", GetTopElementA(s));
    TraverseStack(s);
    printf("Top with GetTopElementB = %d", GetTopElementB(s));
    TraverseStack(s);

}

StackElementType GetTopElementA(StackType s){
    StackElementType x;
    Pop(&s,&x);
    Push(&s,x);
    return x;
}

StackElementType GetTopElementB(StackType s){
    return s.Element[s.Top];
}


void TraverseStack(StackType Stack)
{
    int i;
    printf("\nAmount of elements in the stack %d\n",Stack.Top+1);

    for (i=0;i<=Stack.Top;i++) {
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


