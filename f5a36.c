#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define  MaxElements 8
typedef char HeapElementType;
typedef  struct {
    HeapElementType key;
} HeapNode;


typedef struct {
    int Size;
    HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);

void PrintHeap(HeapType Heap);

boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right);

int main(){
    HeapType h;
    HeapNode n;
    HeapElementType t;
    CreateMaxHeap(&h);
    int i,l,r;


    for(i=0;i<MaxElements;i++){
        printf("Enter a letter : ");
        scanf("%c",&n.key);
        getchar();
        InsertMaxHeap(&h,n);
    }
    PrintHeap(h);


    for(i=0;i<4;i++){
        printf("Enter a letter : ");
        scanf("%c",&t);
        getchar();
        if(Search(h,t,&l,&r)){
            printf("L=%d, R=%d\n",l,r);
            if(l!=-1)
                printf("%c ",h.Element[l].key);
            if(r!=-1)
                printf("%c ",h.Element[r].key);
            printf("\n");
        }else{
            printf("Not found\n");
        }
    }
}


boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right){
    int i=0;
    *left=*right=-1;
    while(i<Heap.Size){
        i++;
        if(ArgKey==Heap.Element[i].key){
            if(2*i<=Heap.Size)
                *left=2*i;
            if(2*i+1<=Heap.Size)
                *right=2*i+1;
            return TRUE;
        }
    }
    return FALSE;
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%c, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%c, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%c \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%c ",Heap.Element[i].key);
    printf(" \n");
}



void CreateMaxHeap(HeapType *Heap){
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap){
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap){
  return (Heap.Size==MaxElements);
}

void InsertMaxHeap(HeapType *Heap, HeapNode Item){
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMaxHeap(HeapType *Heap, HeapNode *Item){
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key < (*Heap).Element[child+1].key)
                    child++;
            if (last.key >= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}


