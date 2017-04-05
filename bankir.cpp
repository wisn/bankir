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

  addrAccount  AA;
  addrCustomer AC;
  address      A;

  showHelp();

  string input, command;
  vector <string> arguments;

  cout << "[main]>> ";
  while (getline(cin, input) && input != "exit")
  {
    parse(input, command, arguments);

    if      (command == "help")   showHelp();
    else if (command == "info")   showInfo(L);
    else if (command == "insert") doInsert(arguments, LC, LA, L);
    else if (command == "delete") doDelete(arguments, LC, LA, L, AC, AA, A);
    else if (command == "update") doUpdate();
    else if (command == "show")   doShow(arguments, LC, LA, L);
    else if (command == "link")   doLinkList(arguments, LA, L);
    else if (command == "unlink") doUnlinkList(arguments, LA, L);
    else if (command == "all")    doAll(arguments, LC, LA);
    else if (command == "maxa")   doFindMaxBalance(LA, LC);
    else if (command == "twos")   doTwos(LA, LC);
    else if (command != "")
      returnMsg(" Can't recognize \"" + command + "\" command!");

    cout << "[main]>> ";
  }
  return 0;
}
