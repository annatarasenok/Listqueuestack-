#include <stdlib.h>
#include "lib.h"


void Display( LIST *L ) 
{ 
  if (L == NULL) 
  { 
    printf("<empty>\n"); 
    return; 
  } 
  while (L != NULL) 
  { 
    printf("%i", L->Data); 
    printf((L = L->Next) == NULL ? "\n" : ", "); 
  } 
} 

void ClearList( LIST **L ) 
{ 
  LIST *OldEl; 

  while (*L != NULL) 
  { 
    OldEl = *L; 
    *L = (*L)->Next; 
    free(OldEl); 
  } 
}

int AddToListFront( LIST **L, int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;

  NewElement->Data = NewData;
  NewElement->Next = *L;
  *L = NewElement;
  return 1;
}

int AddToListBack( LIST **L, int NewData )
{
  LIST *NewElement, *ptr = *L;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;
  if (*L == NULL)
  {
    NewElement->Data = NewData;
    NewElement->Next = NULL;
    *L = NewElement;
    return 1;
  }
  while (ptr->Next != NULL) 
    ptr = ptr->Next;
  ptr->Next = NewElement;
  NewElement->Data = NewData;
  NewElement->Next = NULL;
  return 1;
}

int AddToListByPos( LIST **L, int NewData, int Pos )
{
  LIST *NewElement, *ptr = *L;
  int i = 1;
                                                                     
  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;
  while (ptr->Next != NULL && i != (Pos - 1)) 
    ptr = ptr->Next, i++;
  NewElement->Next = ptr->Next;
  ptr->Next = NewElement;
  NewElement->Data = NewData;
  return 1;
}

int DelFromListBack( LIST **L, int *OldData )
{          
  if (*L == NULL)
    return 0;

  while ((*L)->Next != NULL)
    L = &(*L)->Next;
  if (OldData != NULL)
    *OldData = (*L)->Data;
  free(*L);
  *L = NULL;
  return 1;
}

int DelFromListByPos( LIST **L, int *OldData, int Pos )
{ 
  LIST *ptr = *L, *ptr1;
  int i = 1;

  if (*L == NULL)
    return 0;

  while (ptr->Next != NULL && i != (Pos - 1)) 
    ptr = ptr->Next, i++;

  if (ptr->Next == NULL)
  return 0;
  ptr1 = ptr->Next;
  if (OldData != NULL)
    *OldData = ptr1->Data;
  ptr->Next = ptr1->Next;
  free(ptr1);
  return 1;
}

int Put( QUEUE *Q,  int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;

  NewElement -> Data = NewData;
  NewElement -> Next = NULL;

  if (Q -> Head == NULL)
    Q -> Head = Q -> Tail = NewElement;
  else
  {
    Q -> Tail -> Next = NewElement;
    Q -> Tail = NewElement;
  }
  return 1;
}

int Get( QUEUE *Q, int *OldData )
{
  LIST *OldElement;

  if (Q -> Head == NULL)
    return 0;
  OldElement = Q -> Head;
  if (OldData != NULL)
    *OldData = Q -> Head -> Data;
  Q -> Head = Q -> Head -> Next;
  free(OldElement);
  return 1;
}

int DelFromListFront( LIST **L, int *OldData ) 
{ 
  LIST *OldElement; 

  if (*L == NULL) 
    return 0; 
  OldElement = *L; 

  if (OldData != NULL) 
    *OldData = (*L)->Data; 

  *L = (*L)->Next; 
  free(OldElement); 
  return 1; 
} 

int Push( STACK *S, int NewData )
{
  LIST *NewElement;

  if((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;

  NewElement -> Data = NewData;
  NewElement -> Next = S -> Top;
  S -> Top = NewElement;
  return 1;
}

int Pop( STACK *S, int *OldData )
{
  if(!DelFromListFront(&S -> Top, OldData))
    return 0;
  return 1;
}

void DisplayQueue( QUEUE *Q )
{
  Display(Q -> Head);
}

void DisplayStack( STACK *S )
{
  Display(S -> Top);
}

void ClearQueue( QUEUE *Q )
{
  ClearList(&Q -> Head);
}

void ClearStack( STACK *S )
{
  ClearList(&S -> Top);
}
