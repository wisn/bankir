#ifndef BANKIR_FUNCTIONALLITY_INCLUDED
#define BANKIR_FUNCTIONALLITY_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void parse(string input, string &command, vector <string> &arguments)
{
  if (input.length() > 0)
  {
    vector <string> tokens, tail;
    istringstream iss(input);
    copy(istream_iterator <string> (iss),
        istream_iterator <string> (),
        back_inserter(tokens));
    
    command   = tokens.front();

    if (tokens.size() < 2) tail = vector <string> ();
    else tail = vector <string> (tokens.begin() + 1, tokens.end());

    arguments = tail;
  }
  else command   = "";
}

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

void showInfo()
{
  cout << "Displaying info..." << endl;
}

void doInsert()
{
  cout << "Do insert here..." << endl;
}

void doDelete()
{
  cout << "Do delete here..." << endl;
}

void doUpdate()
{
  cout << "Do update here..." << endl;
}

void doShow()
{
  cout << "Do show here..." << endl;
}

#endif
