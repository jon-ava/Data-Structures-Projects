#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 10

typedef int QueueElementType;
typedef struct {
	int Front, Rear,Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void menu(int *choice);
void TraverseQ(QueueType Queue);
void dob(QueueType *q);
void doc(QueueType *q);

int main(){
    QueueElementType t;
    QueueType q;
    CreateQ(&q);
    int i;
    for(i=1;i<=10;i++)
        AddQ(&q,3*i);
    printf("(a)\n");
    TraverseQ(q);


    printf("(b)\n");
    dob(&q);

    printf("(c)\n");
    doc(&q);

    printf("(d)\n");
    dob(&q);
    dob(&q);



    printf("(e)\n");
    while(!EmptyQ(q)){
        doc(&q);
    }



}

void dob(QueueType *q){
    QueueElementType t;
    do{
        printf("Give a number:");
        scanf("%d",&t);
        if(t%3==0)
            break;
        printf("Give a multiple of 3\n");
    }while(1);
    AddQ(q,t);
    TraverseQ(*q);
}

void doc(QueueType *q){
    QueueElementType t;
    RemoveQ(q,&t);
    TraverseQ(*q);
    printf("Removed item=%d\n",t);
}

void TraverseQ(QueueType Queue) {
    printf("Queue: ");
	int current;
	if (!EmptyQ(Queue)) {
        int i;
        current = Queue.Front;
	    for(i=0;i<Queue.Count;i++){
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);
}


void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (!Queue.Count);
}

boolean FullQ(QueueType Queue)
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue->Count-=1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue->Count+=1;
	}
	else
		printf("Full Queue\n");
}





