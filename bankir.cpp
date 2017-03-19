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

  cout << "Bankir 1.0 - Telkom University. ";
  cout << "Type \"help\" for more information." << endl << endl;

  string command;
  cout << "(main)>> ";
  while (getline(cin, command) && command != "exit")
  {
    if (command == "help") showHelp();
    cout << "(main)>> ";
  }
  return 0;
}
