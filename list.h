#ifndef LIST_HEADER_INCLUDED
#define LIST_HEADER_INCLUDED

#include <iostream>
using namespace std;

void createList(List &L)
{
  first(L) = Nil;
  last(L)  = Nil;
}

address allocate(infotype x)
{
  address P = new elmList;
  info(P)   = x;

  return P;
}

void deallocate(address P)
{
  delete P;
}

bool isEmpty(List L)
{
  if (not found (first(L))) return true;
  else return false;
}



#endif
