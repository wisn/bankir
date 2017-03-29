#ifndef CUSTOMER_HEADER_INCLUDED
#define CUSTOMER_HEADER_INCLUDED

#include <iostream>
using namespace std;

void createCustomerList(customerList &LC)
{
  first(LC) = Nil;
  last(LC)  = Nil;
}

addrCustomer allocateCustomer(infoTypeCustomer x)
{
  addrCustomer P = new elmListCustomer;
  info(P)        = x;

  return P;
}

void deallocateCustomer(addrCustomer &P)
{
  delete P;
}

bool isEmptyCustomer(customerList LC)
{
  if (not (found (first(LC)))) return true;
  else return false;
}

/*addrCustomer findElmCustomer(customerList LC, infoTypeCustomer x)
{
  addrCustomer P = first(LC);
  while (found (P) && info(P) != x) P = next(P);

  return P;
}*/

addrCustomer getPrecAddrCustomer(customerList LC, addrCustomer Prec)
{
  addrCustomer P = first(LC);
  while (found (P) && P != Prec) P = next(P);

  return P;
}

void insertEmptyCustomer(customerList &LC, addrCustomer P)
{
  if (isEmptyCustomer(LC))
  {
    first(LC) = P;
    last(LC)  = P;
    next(P)   = Nil;
    prev(P)   = Nil;
  }
}

void insertFirstCustomer(customerList &LC, addrCustomer P)
{
  if (isEmptyCustomer(LC)) insertEmptyCustomer(LC, P);
  else
  {
    next(P)   = first(LC);
    prev(P)   = Nil;
    first(LC) = P;
  }
}

void insertLastCustomer(customerList &LC, addrCustomer P)
{
  if (isEmptyCustomer(LC)) insertEmptyCustomer(LC, P);
  else
  {
    next(P)        = Nil;
    prev(P)        = last(LC);
    next(last(LC)) = P;
    last(LC)       = P;
  }
}

void insertAfterCustomer(customerList &LC, addrCustomer Prec, addrCustomer P)
{
  if (not isEmptyCustomer(LC))
  {
    addrCustomer Q = getPrecAddrCustomer(LC, Prec);
    if (found (Q))
    {
      next(P)       = next(Q);
      prev(P)       = Q;
      prev(next(Q)) = P;
      next(Q)       = P;
    }
  }
}

void deleteSingleCustomer(customerList &LC, addrCustomer &P)
{
  if (not isEmptyCustomer(LC) && single (LC))
  {
    P         = first(LC);
    first(LC) = Nil;
    last(LC)  = Nil;
    deallocateCustomer(P);
  }
}

void deleteFirstCustomer(customerList &LC, addrCustomer &P)
{
  if (not isEmptyCustomer(LC))
  {
    if (single (LC)) deleteSingleCustomer(LC, P);
    else
    {
      P               = first(LC);
      first(LC)       = next(P);
      prev(first(LC)) = Nil;
      next(P)         = Nil;
      deallocateCustomer(P);
    }
  }
}

void deleteLastCustomer(customerList &LC, addrCustomer &P)
{
  if (not isEmptyCustomer(LC))
  {
    if (single (LC)) deleteSingleCustomer(LC, P);
    else
    {
      P              = last(LC);
      last(LC)       = prev(P);
      next(last(LC)) = Nil;
      prev(P)        = Nil;
      deallocateCustomer(P);
    }
  }
}

void deleteAfterCustomer(customerList &LC, addrCustomer Prec, addrCustomer &P)
{
  if (not isEmptyCustomer(LC))
  {
    P = getPrecAddrCustomer(LC, Prec);
    if (found (P) && next(P) != Nil)
    {
      P             = next(P);
      prev(next(P)) = prev(P);
      next(prev(P)) = next(P);
      next(P)       = Nil;
      prev(P)       = Nil;
      deallocateCustomer(P);
    }
  }
}

#endif
