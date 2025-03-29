#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SetADT.h"

int main()
{
    set_el AnItem;
    int choice, x;
    set_type s, set1, set2, inters, union_set, subtr;
    char ch;

    do
   {
   	    menu(&choice);
        switch(choice)
        {
      	     case 1: Create(set1);
      	             printf("\nset1\n");
                     displayset(set1);
      	             Create(set2);
      	             printf("\nset2\n");
      	             displayset(set2);
      	             break;
             case 2: Universal(s);
                     printf("\nUneversal set:\n");
      	             displayset(s);
      	             break;
     	     case 3: printf("\nChoose set 1 or 2 ");
      	             scanf("%d",&x);
                     do
                     {
   	                    printf("Chose number to be added to the set: ");
                        scanf("%d", &AnItem);
                        if (x==1)
                            InsertElement(AnItem,set1);
                        else
                            InsertElement(AnItem,set2);
                        printf("\nAdd more? Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                    } while (toupper(ch)!='N');
                    if (x==1){
                        printf("set1:\n");
                        displayset(set1);
                    }

                    else{
                        printf("set2:\n");
                        displayset(set2);
                    }
                    break;
      	     case 4: printf("\nset1: ");
                     displayset(set1);
                     printf("\nset2: ");
                     displayset(set2);
                     printf("\nChoose set 1 or 2 ");
      	             scanf("%d",&x);
      	             printf("\nChoose an element to be deleted: ");
      	             scanf("%d",&AnItem);
      	             if (x==1) {
                        DeleteElement(AnItem, set1);
                        printf("\nset1 after deletion of element %d : ",AnItem );
                        displayset(set1);
                     }
                     else {
                        DeleteElement(AnItem, set2);
                        printf("\nset2 after deletion of element %d : ",AnItem );
                        displayset(set2);
                     }
      	             break;
      	     case 5: printf("\nChoose an element ");
      	             scanf("%d",&AnItem);
      	             printf("\nChoose set 1 or 2 ");
      	             scanf("%d",&x);
      	             if (x==1)
                        if (InSet(AnItem, set1))
                            printf("%d is part of set1\n",AnItem);
                        else printf("%d is not part of set1\n",AnItem);
                     else
                        if (InSet(AnItem, set2))
                            printf("%d is part of set2\n",AnItem);
                        else printf("%d is not part of set2\n",AnItem);
      	             break;
      	     case 6: printf("\nChoose set 1 or 2 ");
      	             scanf("%d",&x);
      	             if (x==1)
                        if (EmptySet(set1))
      	                     printf("set1 is empty\n");
      	                else printf("set1 is not empty\n");
      	             else
                        if (EmptySet(set2))
                            printf("set2 is empty\n");
      	                else printf("set2 is not empty\n");
      	             break;
      	     case 7: if (EqualSets(set1,set2))
      	                 printf("s1 = s2\n");
      	             else printf("s1 != s2\n");
      	             break;
             case 8: printf("\nChoose set 1 or 2 ");
      	             scanf("%d",&x);
      	             if (x==1)
                        if (Sebset(set1,set2))
      	                 printf("set1 is a subset of set2\n");
      	                 else printf("set1 is not a subset of set2\n");
      	             else if (Sebset(set2,set1))
      	                 printf("set2 is a subset of set2 \n");
      	                 else printf("set2 is a subset of set1\n");
      	             break;
             case 9: Union(set1,set2,union_set);
                     printf("Union:\n");
                     displayset(union_set);
      	             break;
             case 10: Intersection(set1,set2,inters);
                      printf("Intersection:\n");
                      displayset(inters);
      	             break;
             case 11: Subtraction(set1,set2,subtr);
                      printf("s1 - s2:\n");
                      displayset(subtr);
      	              break;
        }
        } while (choice!=12);
        return 0;
        system("PAUSE");
}




