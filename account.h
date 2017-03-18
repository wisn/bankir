#ifndef ACCOUNT_HEADER_INCLUDED
#define ACCOUNT_HEADER_INCLUDED

#include <iostream>
using namespace std;

void createAccountList(accountList &LA)
{
  first(LA) = Nil;
  last(LA)  = Nil;
}

#endif
