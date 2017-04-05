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

void deallocate(address &P)
{
  delete P;
}

bool isEmpty(List L)
{
  if (not (found (first(L)))) return true;
  else return false;
}

address findListByID(List L, unsigned long int id)
{
  address R = first(L);
  while (found (R) && info(R).id != id) R = next(R);

  return R;
}

/*address findElm(List L, infotype x)
{
  address P = first(L);
  while (found (P) && info(P) != x) P = next(P);

  return P;
}*/

address getPrecAddr(List L, address Prec)
{
  address P = first(L);
  while (found (P) && P != Prec) P = next(P);

  return P;
}

void insertEmpty(List &L, address P)
{
  if (isEmpty(L))
  {
    first(L) = P;
    last(L)  = P;
    next(P)  = Nil;
    prev(P)  = Nil;
  }
}

void insertFirst(List &L, address P)
{
  if (isEmpty(L)) insertEmpty(L, P);
  else
  {
    next(P)  = first(L);
    prev(P)  = Nil;
    first(L) = P;
  }
}

void insertLast(List &L, address P)
{
  if (isEmpty(L)) insertEmpty(L, P);
  else
  {
    next(P)       = Nil;
    prev(P)       = last(L);
    next(last(L)) = P;
    last(L)       = P;
  }
}

void insertAfter(List &L, address Prec, address P)
{
  if (not isEmpty(L))
  {
    address Q = getPrecAddr(L, Prec);
    if (found (Q))
    {
      next(P)       = next(Q);
      prev(P)       = Q;
      prev(next(Q)) = P;
      next(Q)       = P;
    }
  }
}

void deleteSingle(List &L, address &P)
{
  if (not isEmpty(L) && single (L))
  {
    P        = first(L);
    first(L) = Nil;
    last(L)  = Nil;
    deallocate(P);
  }
}

void deleteFirst(List &L, address &P)
{
  if (not isEmpty(L))
  {
    if (single (L)) deleteSingle(L, P);
    else
    {
      P              = first(L);
      first(L)       = next(P);
      prev(first(L)) = Nil;
      next(P)        = Nil;
      deallocate(P);
    }
  }
}

void deleteLast(List &L, address &P)
{
  if (not isEmpty(L))
  {
    if (single (L)) deleteSingle(L, P);
    else
    {
      P             = last(L);
      last(L)       = prev(P);
      next(last(L)) = Nil;
      prev(P)       = Nil;
      deallocate(P);
    }
  }
}

void deleteAfter(List &L, address Prec, address &P)
{
  if (not isEmpty(L))
  {
    P = getPrecAddr(L, Prec);
    if (found (P) && next(P) != Nil)
    {
      P             = next(P);
      prev(next(P)) = prev(P);
      next(prev(P)) = next(P);
      next(P)       = Nil;
      prev(P)       = Nil;
      deallocate(P);
    }
  }
}

void deleteListByAddress(List &L, address &P)
{
  if      (single (L))           deleteSingle(L, P);
  else if (first(L) == P)        deleteFirst(L, P);
  else if (not (found(next(P)))) deleteLast(L, P);
  else
  {
    address      R = P;
    prev(next(P))  = prev(R);
    next(prev(P))  = next(R);
    next(P)        = Nil;
    prev(P)        = Nil;
    deallocate(P);
  }
}

void showAllList(List L)
{
  address P = first(L);
  unsigned long int i, n;
  cout << endl;
  while (found (P))
  {
    cout << " Customer ID : " << info(customer(P)).id << endl
         << " Age         : " << info(customer(P)).age << endl
         << " Name        : " << info(customer(P)).name << endl;

    n = account(P).size();
    for (i = 0; i < n; i++)
    {
      cout << "   Account ID : " << info(account(P).at(i)).id << endl
           << "   Balance    : " << info(account(P).at(i)).balance << endl;
    }

    cout << endl;
    P = next(P);
  }
  cout << endl;
}

#endif
