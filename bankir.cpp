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
    else cout << "Can't recognize \"" << command << "\" command!" << endl;
    cout << "(main)>> ";
  }
  return 0;
}
