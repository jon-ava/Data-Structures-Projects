#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define StackLimit 8

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
StackElementType minELement(StackType *s);
StackElementType maxELement(StackType *s);


int main(){
    StackType s;
    StackElementType item,max,min;
    CreateStack(&s);
    int i;
    for(i=0;i<StackLimit;i++){
        printf("Give next element: ");
        scanf("%d",&item);
        Push(&s,item);
    }
    TraverseStack(s);

    printf("Min: %d\n",minELement(&s));
    printf("Max: %d\n",maxELement(&s));
    TraverseStack(s);

}

StackElementType minELement(StackType *s){
    StackType temp;
    CreateStack(&temp);
    StackElementType item,min;
    Pop(s,&min);
    Push(&temp,min);
    while(!EmptyStack(*s)){
        Pop(s,&item);
        if(item<min)
            min=item;
        Push(&temp,item);
    }
    while(!EmptyStack(temp)){
        Pop(&temp,&item);
        if(item!=min)
            Push(s,item);
    }
    return min;
}

StackElementType maxELement(StackType *s){
    StackType temp;
    CreateStack(&temp);
    StackElementType item,max;
    Pop(s,&max);
    Push(&temp,max);
    while(!EmptyStack(*s)){
        Pop(s,&item);
        if(item>max)
            max=item;
        Push(&temp,item);
    }
    while(!EmptyStack(temp)){
        Pop(&temp,&item);
        if(item!=max)
            Push(s,item);
    }
    return max;
}


void TraverseStack(StackType Stack)
{
    int i;
    printf("\nNumber of elements in stack %d\n",Stack.Top+1);

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


