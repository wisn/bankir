#ifndef ACCOUNT_HEADER_INCLUDED
#define ACCOUNT_HEADER_INCLUDED

#include <iostream>
using namespace std;

void createAccountList(accountList &LA)
{
  first(LA) = Nil;
  last(LA)  = Nil;
}

addrAccount allocateAccount(infoTypeAccount x)
{
  addrAccount P = new elmListAccount;
  info(P)       = x;

  return P;
}

void deallocateAccount(addrAccount &P)
{
  delete P;
}

bool isEmptyAccount(accountList LA)
{
  if (not (found (first(LA)))) return true;
  else return false;
}

addrAccount findAccountByID(accountList LA, unsigned long int id)
{
  addrAccount P = first(LA);
  while (found (P) && info(P).id != id) P = next(P);

  return P;
}

/*addrAccount findElmAccount(accountList LA, infoTypeAccount x)
{
  addrAccount P = first(LA);
  while (found (P) && info(P) != x) P = next(P);

  return P;
}*/

addrAccount getPrecAddrAccount(accountList LA, addrAccount Prec)
{
  addrAccount P = first(LA);
  while (found (P) && P != Prec) P = next(P);

  return P;
}

void insertEmptyAccount(accountList &LA, addrAccount P)
{
  if (isEmptyAccount(LA))
  {
    first(LA) = P;
    last(LA)  = P;
    next(P)   = Nil;
    prev(P)   = Nil;
  }
}

void insertFirstAccount(accountList &LA, addrAccount P)
{
  if (isEmptyAccount(LA)) insertEmptyAccount(LA, P);
  else
  {
    next(P)   = first(LA);
    prev(P)   = Nil;
    first(LA) = P;
  }
}

void insertLastAccount(accountList &LA, addrAccount P)
{
  if (isEmptyAccount(LA)) insertEmptyAccount(LA, P);
  else
  {
    next(P)        = Nil;
    prev(P)        = last(LA);
    next(last(LA)) = P;
    last(LA)       = P;
  }
}

void insertAfterAccount(accountList &LA, addrAccount Prec, addrAccount P)
{
  if (not isEmptyAccount(LA))
  {
    addrAccount Q = getPrecAddrAccount(LA, Prec);
    if (found (Q))
    {
      next(P)       = next(Q);
      prev(P)       = Q;
      prev(next(Q)) = P;
      next(Q)       = P;
    }
  }
}

void deleteSingleAccount(accountList &LA, addrAccount &P)
{
  if (not isEmptyAccount(LA) && single (LA))
  {
    P         = first(LA);
    first(LA) = Nil;
    last(LA)  = Nil;
    deallocateAccount(P);
  }
}

void deleteFirstAccount(accountList &LA, addrAccount &P)
{
  if (not isEmptyAccount(LA))
  {
    if (single (LA)) deleteSingleAccount(LA, P);
    else
    {
      P               = first(LA);
      first(LA)       = next(P);
      prev(first(LA)) = Nil;
      next(P)         = Nil;
      deallocateAccount(P);
    }
  }
}

void deleteLastAccount(accountList &LA, addrAccount &P)
{
  if (not isEmptyAccount(LA))
  {
    if (single (LA)) deleteSingleAccount(LA, P);
    else
    {
      P              = last(LA);
      last(LA)       = prev(P);
      next(last(LA)) = Nil;
      prev(P)        = Nil;
      deallocateAccount(P);
    }
  }
}

void deleteAfterAccount(accountList &LA, addrAccount Prec, addrAccount &P)
{
  if (not isEmptyAccount(LA))
  {
    P = getPrecAddrAccount(LA, Prec);
    if (found (P) && next(P) != Nil)
    {
      P             = next(P);
      prev(next(P)) = prev(P);
      next(prev(P)) = next(P);
      next(P)       = Nil;
      prev(P)       = Nil;
      deallocateAccount(P);
    }
  }
}

void showAccount(addrAccount P)
{
  cout << "ID: "      << info(P).id << endl
       << "Balance: " << info(P).balance << endl;
}

void showAllAccount(accountList LA)
{
  addrAccount P = first(LA);
  while (found (P))
  {
    cout << "ID: "      << info(P).id << endl
         << "Balance: " << info(P).balance << endl;
    P = next(P);
  }
}

#endif
