#include <iostream>
#include "bankir.h"
#include "customer.h"
#include "account.h"
#include "list.h"
#include "functionallity.h"
using namespace std;

int main()
{
  customerList LC;
  createCustomerList(LC);

  accountList LA;
  createAccountList(LA);

  List L;
  createList(L);

  cout << "Hello, World!" << endl;
  return 0;
}
