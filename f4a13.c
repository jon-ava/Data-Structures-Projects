#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct{
    char name[9],file[13];
}QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void TraverseQ(QueueType Queue);

int main(){
    QueueType q1,q2;
    QueueElementType t;

    CreateQ(&q1);
    CreateQ(&q2);

    FILE *f;

    f = fopen("i13f4.dat","r");
    if(f==NULL){
        printf("ERROR");
        exit(-1);
    }

    while (!feof(f)) {
        fgets(t.name, 9, f);
        fgets(t.file, 13, f);
        t.name[strcspn(t.name, "\n")] = '\0';
        t.file[strcspn(t.file, "\n")] = '\0';
        if(!strncmp(t.name,"USER",4) || !strncmp(t.name,"FORT",4)){
            AddQ(&q1,t);
        }else
            AddQ(&q2,t);
    }

    while(!EmptyQ(q2)){
        RemoveQ(&q2,&t);
        printf("Printing the job of %s, %s\n",t.name,t.file);
        printf("Press enter to continue");
        scanf("%c");
    }

    while(!EmptyQ(q1)){
        RemoveQ(&q1,&t);
        printf("Printing the job of %s, %s\n",t.name,t.file);
        printf("Press enter to continue");
        scanf("%c");
    }
    printf("There are no jobs in the printing queue");

    fclose(f);
}


void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}


void CreateQ(QueueType *Queue){
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue){
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item){
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}




