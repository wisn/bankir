#include <iostream>
#include <vector>
#include "bankir.h"
#include "customer.h"
#include "account.h"
#include "list.h"
#include "functionallity.cpp"
using namespace std;

int main()
{
  customerList LC;
  createCustomerList(LC);

  accountList LA;
  createAccountList(LA);

  List L;
  createList(L);

  addrAccount  PA;
  addrCustomer PC;
  address      P;

  cout << endl
       << " Bankir 1.0 - Telkom University. "
       << "Type \"help\" for more information." << endl << endl;

  string input, command;
  vector <string> arguments;

  cout << "[main]>> ";
  while (getline(cin, input) && input != "exit")
  {
    parse(input, command, arguments);

    if      (command == "help")   showHelp();
    else if (command == "info")   showInfo(L);
    else if (command == "insert") doInsert(arguments, LC, LA, L);
    else if (command == "delete") doDelete();
    else if (command == "update") doUpdate();
    else if (command == "show")   doShow();
    else if (command == "link")   doLinkList(arguments, LA, L);
    else if (command == "unlink") doUnlinkList(arguments, LA, L);
    else if (command != "")
      returnMsg(" Can't recognize \"" + command + "\" command!");
    
    cout << "[main]>> ";
  }
  return 0;
}
