#include <iostream>
#include <vector>
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

  addrAccount P, Q;

  /* Testing! */
  infoTypeAccount x;
  x.id = 1;
  x.balance = 10000;
  x.pointed = 0;

  P = allocateAccount(x);
  insertFirstAccount(LA, P);

  x.id = 2;
  x.balance = 20000;
  x.pointed = 0;

  P = allocateAccount(x);
  insertLastAccount(LA, P);
  
  showAllAccount(LA);

  cout << endl;

  infoTypeCustomer y;
  y.id = 1;
  y.age = 17;
  y.name = "A";

  addrCustomer S, T;
  S = allocateCustomer(y);
  insertFirstCustomer(LC, S);

  y.id = 2;
  y.age = 37;
  y.name = "B";

  S = allocateCustomer(y);
  insertLastCustomer(LC, S);

  showAllCustomer(LC);

  cout << endl;

  infotype z;
  z.id = 1;
  z.customer = first(LC);
  
  z.account.insert(z.account.end(), first(LA));
  z.account.insert(z.account.end(), P);

  address U;
  U = allocate(z);
  insertLast(L, U);

  showAllList(L);

  cout << endl;
  /* End Testing */

  cout << "Bankir 1.0 - Telkom University. ";
  cout << "Type \"help\" for more information." << endl << endl;

  string input, command;
  vector <string> arguments;

  cout << "(main)>> ";
  while (getline(cin, input) && input != "exit")
  {
    parse(input, command, arguments);

    if      (command == "help")   showHelp();
    else if (command == "info")   showInfo();
    else if (command == "insert") doInsert();
    else if (command == "delete") doDelete();
    else if (command == "update") doUpdate();
    else if (command == "show")   doShow();
    else if (command != "") cout << "Can't recognize \"" << command << "\" command!" << endl;
    cout << "(main)>> ";
  }
  return 0;
}
