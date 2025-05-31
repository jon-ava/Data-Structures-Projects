
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define max_size 26

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean set_type[max_size];
typedef int set_el;

void Create(set_type s);
void Universal(set_type s);
void InsertElement(set_el el, set_type s);
void DeleteElement(set_el el, set_type s);
boolean InSet(set_el el, set_type s);
boolean EmptySet(set_type s);
boolean EqualSets(set_type s1, set_type s2);
boolean Sebset(set_type s1, set_type s2);
void Union(set_type s1, set_type s2, set_type union_set);
void Intersection(set_type s1, set_type s2, set_type inters);
void Subtraction(set_type s1, set_type s2, set_type subtr);
void displayset(set_type s);
void YesNo(boolean x,char s[]);

int main()
{
    set_el i;
    set_type K, S, T, intr, un,dif;

    Universal(K);
    displayset(K);

    Create(S);
    for(i=0;i<4;i++)
        InsertElement(i,S);
    displayset(S);

    Create(T);
    for(i=0;i<5;i++)
        InsertElement(i*2,T);
    displayset(T);

    YesNo(EqualSets(S,T),"Equal sets");
    YesNo(Sebset(S,T),"S subset of T");
    YesNo(Sebset(T,S),"T subset of S");

    Union(S,T,un);
    displayset(un);
    Intersection(S,T,intr);
    displayset(intr);
    Subtraction(S,T,dif);
    displayset(dif);
}


void displayset(set_type set)
{
	set_el i;

	for (i=0;i < max_size;i++)
	{
		if(InSet(i,set))
			printf(" %c",i+'A');
	}
	printf("\n");
}

void YesNo(boolean x,char s[]){
    if(x)
        printf("%s\n",s);
    else
        printf("NOT %s\n",s);
}


//Creates empty set
void Create(set_type s)
{
    set_el i;

    for (i = 0; i < max_size; i++)
        s[i] = FALSE;
}

//Creates a universal set
void Universal(set_type s)
{
    set_el i;

    for (i = 0; i < max_size; i++)
        s[i] = TRUE;
}

//Adds an element to a set
void InsertElement(set_el el, set_type s)
{
    s[el] = TRUE;
}

//Deletes and element from a set
void DeleteElement(set_el el, set_type s)
{
    s[el] = FALSE;
}

//Checks if an element is in a set
boolean InSet(set_el el, set_type s)
{
    return s[el];
}

//Checks if a set is empty
boolean EmptySet(set_type s)
{
    set_el i;
    boolean empty;

    empty=TRUE;
    i = 0;

    while (i < max_size  && empty) {
        if (InSet(i, s))
            empty = FALSE;
        else
            i++;
    }
    return empty;
}

//Checks if two sets are equal
boolean EqualSets(set_type s1, set_type s2)
{
    set_el i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < max_size && isa)
        if (InSet(i,s1) != InSet(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

//Checks if s1 is a subset of s2
boolean Sebset(set_type s1, set_type s2)
{
    set_el i;
    boolean subs;

    subs = TRUE;
    i=0;
    while (i < max_size && subs)
        if (InSet(i, s1) && !InSet(i, s2))
            subs = FALSE;
        else
            i++;
    return subs;
}

//Creates union of s1 and s2
void Union(set_type s1, set_type s2, set_type union_set)
{
    set_el i;

    for (i = 0; i < max_size; i++)
        union_set[i] = InSet(i, s1) || InSet(i, s2);
}

//Creates the intersection of s1 and s2
void Intersection(set_type s1, set_type s2, set_type inters)
{
    set_el i;

    for (i = 0; i < max_size; i++)
        inters[i] = InSet(i, s1) && InSet(i, s2);
}

//Creates s3 = s1-s2
void Subtraction(set_type s1, set_type s2, set_type s3)
{
    set_el i;

    for (i = 0; i < max_size; i++)
        s3[i] = InSet(i, s1) && (!InSet(i, s2));
}




