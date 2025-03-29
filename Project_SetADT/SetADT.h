// * Filename: setADT.h

#define max_size 10          //max number of elements in set

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
void menu(int *choice);
void displayset(set_type s);

