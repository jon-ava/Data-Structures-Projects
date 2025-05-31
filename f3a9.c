#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define QueueLimit 3
#define QueueLimitW 21

typedef char QueueElementType[25];

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef struct {
    char number[10];
    QueueElementType name;
    int code;
} QueueElementTypeW;

typedef struct {
	int Front, Rear;
	QueueElementTypeW Element[QueueLimitW];
} QueueTypeW;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void CreateQW(QueueTypeW *Queue);
boolean EmptyQW(QueueTypeW Queue);
boolean FullQW(QueueTypeW Queue);
void RemoveQW(QueueTypeW *q, QueueElementTypeW t);
void AddQW(QueueTypeW *q, QueueElementTypeW t);

void TraverseQ(QueueType Queue);
void newAppointment(int code, QueueType *q, QueueTypeW *w);
void showWaitingQ(QueueTypeW Queue);
void showQ(QueueType Queue,int c);

int main(){
    QueueType q[5];
    QueueTypeW w;
    int i,j,x,y;
    char a;
    srand(54);
    for(i=0;i<5;i++)
        CreateQ(&q[i]);
    CreateQW(&w);



    do{
        i=rand()%5;
        newAppointment(i,&q[i],&w);
        printf("Continue Y/N (Y=Yes, N=No): ");
        scanf(" %c",&a);
    }while(tolower(a)=='y');

    for(i=0;i<5;i++)
        showQ(q[i],i);
    showWaitingQ(w);


}

void newAppointment(int code, QueueType *q, QueueTypeW *w){
    QueueElementType name;
    printf("Give your name: ");
    scanf(" %s",name);
    if(FullQ(*q)){
        QueueElementTypeW t;
        strcpy(t.name,name);
        printf("You are in a waiting list\n");
        printf("Give your phone number: ");
        scanf(" %s",t.number);
        t.code = code;
        AddQW(w,t);
    }else{
        AddQ(q,name);
        printf("Successful appointment for clinic %d\n",code);
    }
}

void showWaitingQ(QueueTypeW Queue) {
	int current;
	if (!EmptyQW(Queue)) {
        printf("Waiting list:\n");
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s, %d, %s\n", Queue.Element[current].name,Queue.Element[current].code,Queue.Element[current].number);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
}

void showQ(QueueType Queue,int c) {
    printf("Appointments of clinic %d\n",c);
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s\n", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
}


void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s ", Queue.Element[current]);
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

void RemoveQ(QueueType *Queue, QueueElementType Item)
{
	if(!EmptyQ(*Queue))
	{
		strcpy(Item,Queue ->Element[Queue -> Front]);
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		strcpy(Queue ->Element[Queue ->Rear],Item);
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void CreateQW(QueueTypeW *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQW(QueueTypeW Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQW(QueueTypeW Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQW(QueueTypeW *q, QueueElementTypeW t)
{
	if(!EmptyQW(*q))
	{
	    t.code = q ->Element[q ->Front].code;
	    strcpy(t.name,q->Element[q->Front].name);
	    strcpy(t.number,q->Element[q->Front].number);
		q->Front = (q->Front+1)%QueueLimitW;
	}
	else
		printf("Empty Queue\n");
}

void AddQW(QueueTypeW *q, QueueElementTypeW t)
{
	if(!FullQW(*q))
	{
        q->Element[q->Rear].code = t.code;
	    strcpy(q->Element[q->Rear].name, t.name);
	    strcpy(q->Element[q->Rear].number, t.number);
		q->Rear = (q->Rear+1)%QueueLimitW;
	}
	else
		printf("Full Queue\n");
}





