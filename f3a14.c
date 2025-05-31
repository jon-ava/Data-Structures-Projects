#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 21

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);

void GetNthElementValueA (QueueType *q, int n, QueueElementType *item);
void GetNthElementValueB (QueueType q, int n, QueueElementType *item);


int main(){
    QueueType q;
    QueueElementType t;
    CreateQ(&q);
    int n;

    for(n=1;n<21;n++)
        AddQ(&q,n*5);
    TraverseQ(q);

    do{
        printf("Give n: ");
        scanf("%d",&n);
    }while(n>(q.Rear-q.Front+QueueLimit)%QueueLimit);
    GetNthElementValueA(&q,n,&t);
    printf("ValueA: %d\n",t);
    GetNthElementValueB(q,n,&t);
    printf("ValueB: %d\n",t);
    TraverseQ(q);

}

void GetNthElementValueA (QueueType *q, int n, QueueElementType *item){
    QueueType temp;
    CreateQ(&temp);
    QueueElementType t;
    while(!EmptyQ(*q)){
        n--;
        if(n==0){
            RemoveQ(q,item);
            AddQ(&temp,*item);
        }
        RemoveQ(q,&t);
        AddQ(&temp,t);
    }
    while(!EmptyQ(temp)){
        RemoveQ(&temp,&t);
        AddQ(q,t);
    }
}

void GetNthElementValueB (QueueType q, int n, QueueElementType *item){
    *item = q.Element[(q.Front+n-1)%QueueLimit];
}

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}


void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
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
	}
	else
		printf("Full Queue\n");
}





