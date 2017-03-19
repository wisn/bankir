#ifndef BANKIR_FUNCTIONALLITY_INCLUDED
#define BANKIR_FUNCTIONALLITY_INCLUDED

#include <iostream>
using namespace std;

void showHelp()
{
  cout << " Bankir is a system management for your customer." << endl
       << " Keywords: \"c\" stand for Customer, \"a\" stand for Account." << endl
       << endl
       << " Commands" << endl
       << "   help                     Display this message" << endl
       << "   info                     Display all customer and their account" << endl
       << "   insert [c|a]             Insert new data" << endl
       << "   delete [c|a] <id>        Delete data by their ID" << endl
       << "   update [c|a] <id>        Update data by their ID" << endl
       << "   show   [c|a] <id>        Show data by their ID" << endl
       << endl
       << " Examples" << endl
       << "   insert c" << endl
       << "   This will takes you to the Insert Customer sub-program." << endl
       << endl
       << "   delete a 2" << endl
       << "   This will remove Account with ID 2." << endl
       << endl;
}

#endif
