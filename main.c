#include <stdio.h>
#include "lib.c"

#include <conio.h>


void main( void ) 
{  
  int run = 1, a, newd, oldd, pos;
  LIST *L = NULL;
  QUEUE Q = {NULL, NULL};
  STACK S = {NULL};
 
  while (run == 1) 
  {  
    printf("List: ");
    Display(L);
    printf("\nQueue: ");
    DisplayQueue(&Q);
    printf("\nStack: ");
    DisplayStack(&S);
    printf("0 - exit\n" 
           "a - put\n" 
           "b - get\n" 
           "c - push\n" 
           "d - pop\n"
           "e - add to list front\n"
           "f - add to list back\n"
           "g - del from list front\n"
           "h - del from list back\n"
           "i - add to list by position\n"
           "j - del from list by position\n"
           "k - clear list\n"
           "l - clear queue\n"
           "m - clead stack\n"
           "n - clear all\n"
      ); 
    switch(getch()) 
    { 
      case '0':
        ClearList(&L);
        ClearStack(&S);
        ClearQueue(&Q);
        run = 0; 
        break; 
      case 'a': 
        printf("Input number: "); 
        scanf("%i", &a); 
        if (!Put(&Q, a)) 
          printf("Not enough memory\n"); 
        else 
          printf("Number added\n"); 
        break; 
      case 'b': 
        if (Get(&Q, &a)) 
          printf("From queue: %i\n", a); 
        else 
          printf("Queue is empty\n"); 
        break; 
      case 'c': 
        printf("Input number: "); 
        scanf("%i", &a); 
        if (!Push(&S, a)) 
          printf("Not enough memory\n"); 
        else 
          printf("Number added\n"); 
        break; 
      case 'd': 
        if (Pop(&S, &a)) 
          printf("From stack: %i\n", a); 
        else 
          printf("Stack is empty\n"); 
        break;
      case 'e':    
        printf("Input data:");
        scanf("%i", &newd);
        AddToListFront(&L, newd);
        break;
      case 'g':      
        if(!DelFromListFront(&L, &oldd))
          printf("ERROR");
        else
          printf("deleted data is %i\n", oldd);
        break;
      case 'f':
        printf("Input data:");
        scanf("%i", &newd);
        AddToListBack(&L, newd);
        break;
      case 'h':
        if(!DelFromListBack(&L, &oldd))
          printf("ERROR");
        else
          printf("Deleted data is %i\n", oldd);
        break;
      case 'i':
        printf("Input data:");
        scanf("%i", &newd);
        printf("Input position:");
        scanf("%i", &pos);
        AddToListByPos(&L, newd, pos);
        break;
      case 'j':
        printf("Input position:");
        scanf("%i", &pos);
        if(!DelFromListByPos(&L, &oldd, pos))
          printf("<ERROR : NOT ENOUGH ELEMENTS>\n");
        else
          printf("deleted data is %i\n", oldd);
        break;
      case 'k':
        ClearList(&L);
        break;
      case 'l':
        ClearQueue(&Q);
        break;
      case 'm':
        ClearStack(&S);
        break;
      case 'n':
        ClearList(&L);
        ClearQueue(&Q);
        ClearStack(&S);
        break;
      default:
        printf("Incorrect option\n");
        break;
    }
  } 
}  
