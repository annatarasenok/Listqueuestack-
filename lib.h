#ifndef __lib_h
#define __lib_h

#define MAX 1000

typedef struct tagLIST LIST; 
struct tagLIST 
{ 
  int Data; 
  LIST *Next; 
};

typedef struct
{
  LIST
    *Head,
    *Tail;
} QUEUE;

typedef struct
{
  LIST
    *Top;
} STACK;


void Display( LIST *L );
void ClearList( LIST **L );
int DelFromListFront( LIST **L, int *OldData );
int AddToListFront( LIST **L, int NewData );
int AddToListBack( LIST **L, int NewData );
int AddToListByPos( LIST **L, int NewData, int Pos );
int DelFromListBack( LIST **L, int *OldData );
int DelFromListByPos( LIST **L, int *OldData, int Pos );

int Put( QUEUE *Q,  int NewData );
int Get( QUEUE *Q, int *OldData );
void DisplayQueue( QUEUE *Q );
void ClearQueue( QUEUE *Q );

int Push( STACK *S, int NewData );
int Pop( STACK *S, int *OldData );
void DisplayStack( STACK *S );
void ClearStack( STACK *S );

#endif
