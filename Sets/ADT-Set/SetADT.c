// * Filename: setadt.c

#include <stdio.h>
#include <stdlib.h>
#include "SetADT.h"

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

