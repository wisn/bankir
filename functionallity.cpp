/*! Functionallity
*   --------------
*   @author         Wisnu Adi Nurcahyo
*   @contact        <wisnu@nurcahyo.me>
*   @license        MIT License
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "functionallity.h"
using namespace std;

/*  Parse
    -----
    @input          input        String
    @input/output   command      String
                    arguments   <String>
    @return                      Void

    Example
    -------
    input = "delete c 2"
    parse(input, command, arguments)

    Return
    ------
      command   => "delete"
      arguments => <"c", "2">
===================================================================*/
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
  else command = "";
}

/*  isNumeric
    ---------
    @input          input        String
    @return                      Boolean

    Example
    -------
    bool test = isNumeric("123a")
         tset = isNumeric("1998")

    Return
    ------
      test => false
      tset => true
===================================================================*/
bool isNumeric(string input)
{
  unsigned long int i = 0, len = input.length();
  bool numeric = true;
  if (len > 0)
  {
    while (numeric && i < len)
    {
      if (not isdigit(input[i])) numeric = false;
      i++;
    }
  }
  return numeric;
}

/*  checkNumThenAssign
    ------------------
    @input          input        String
    @input/output   val          Int
    @return                      Void

    Example
    -------
    input = "1234"
    checkNumThenAssign(input, val)
    tupni = "321k"
    checkNumThenAssign(tupni, lav)

    Return
    ------
      val => 1234
      lav =>
===================================================================*/
void checkNumThenAssign(string input, auto &val)
{
  if (isNumeric(input)) val = stol(input);
  else cout << endl << " Please insert a positive number!" << endl << endl;
}

/*  isWords
    -------
    @input          input       String
    @return                     Boolean

    Example
    -------
    bool test = isWords("name")
         tset = isWords("al44")

    Return
    ------
      test => true
      tset => false
===================================================================*/
bool isWords(string input)
{
  unsigned long int i = 0, len = input.length();
  bool words = true;
  if (len > 0)
  {
    while (words && i < len)
    {
      if (isdigit(input[i])) words = false;
      i++;
    }
  }
  return words;
}

/*  checkWordsThenAssign
    --------------------
    @input          input        String
    @input/output   val          String
    @return                      Void

    Example
    -------
    input = "720p"
    checkWordsThenAssign(input, val)
    tupni = "love"
    checkWordsThenAssign(tupni, lav)

    Return
    ------
      val =>
      lav => "love"
===================================================================*/
void checkWordsThenAssign(string input, string &val)
{
  if (isWords(input)) val = input;
  else cout << endl << " Please insert a words!" << endl << endl;
}

/*  returnValue
    -----------
    @input          input        Auto
    @return                      Void
===================================================================*/
void returnValue(auto input)
{
  cout << endl << " => " << input << endl << endl;
}

/*  returnString
    ------------
    @input          input        String
    @return                      Void
===================================================================*/
void returnString(string input)
{
  cout << endl << " => \"" << input << "\"" << endl << endl;
}

/*  returnMsg
    ---------
    @input          input        String
    @return                      Void
===================================================================*/
void returnMsg(string input)
{
  cout << endl << input << endl << endl;
}

/*  joinString
    ----------
    @input          input      <String>
    @return                     String

    Example
    -------
    string join = joinString(<"one", "two">)

    Return
    ------
      join => "one two"
===================================================================*/
string joinString(vector <string> input)
{
  stringstream ss;
  for (size_t i = 0; i < input.size(); i++)
  {
    if (i > 0) ss << " ";
    ss << input.at(i);
  }

  return ss.str();
}

/*  showHelp
    --------
    @return                      Void
===================================================================*/
void showHelp()
{
  cout << " Bankir is a CLI based banking system management." << endl
       << " Keywords: \"c\" stand for Customer, \"a\" stand for Account." << endl
       << "           \"cid\" stand for Customer ID." << endl
       << "           \"aid\" stand for Account ID." << endl
       << endl
       << " Commands" << endl
       << "   help                     Display this message" << endl
       << "   info                     Display all customer and their account" << endl
       << "   insert [c|a]             Insert new data" << endl
       << "   delete [c|a] [cid|aid]   Delete data by their ID" << endl
       << "   update [c|a] [cid|aid]   Update data by their ID" << endl
       << "   show   [c|a] [cid|aid]   Show data by their ID" << endl
       << "   link   <aid> <cid>       Link Account to a Customer by ID" << endl
       << "   unlink <aid> <cid>       Unlink Account from a Customer by ID" << endl
       << "   exit                     Close this program" << endl
       << endl
       << " Examples" << endl
       << "   insert c" << endl
       << "   This will takes you to the Insert Customer sub-program." << endl
       << endl
       << "   delete a 2" << endl
       << "   This will remove Account with ID 2." << endl
       << endl;
}

void showInfo(List L)
{
  showAllList(L);
}

/*  doInsertCustomer
    ----------------
    @input/output   LC           customerList
                    L            List
    @return                      Void
===================================================================*/
void doInsertCustomer(customerList &LC, List &L)
{
  unsigned long int id;
  unsigned int age = 0;
  string name (""), input, attr, val;
  vector <string> args;
  addrCustomer P;
  infoTypeCustomer x;
  address Q;
  infotype y;

  cout << endl
       << " Attributes" << endl
       << " ----------" << endl
       << " id             Integer        Auto" << endl
       << " age            Integer        Required" << endl
       << " name           String         Required" << endl
       << endl
       << " Commands" << endl
       << " --------" << endl
       << " save           Save data" << endl
       << " back           Close this interface" << endl
       << endl;
  
  if (isEmpty(L)) id = 1;
  else id = info(last(L)).id + 1;

  cout << "[insert| c ]>> ";
  while (getline(cin, input) && input != "back")
  {
    parse(input, attr, args);

    if (attr != "" && attr != "save")
    {
      if (args.size() < 1)
      {
        if      (attr == "id")   returnValue(id);
        else if (attr == "age")  returnValue(age);
        else if (attr == "name") returnString(name);
        else returnMsg(" Attribute didn't exist!");
      }
      else
      {
        val = args.at(0);
        if      (attr == "id")   returnValue(id);
        else if (attr == "age")  checkNumThenAssign(val, age);
        else if (attr == "name")
        {
          val = joinString(args);
          checkWordsThenAssign(val, name);
        }
        else returnMsg(" Attribute didn't exist!");
      }
    }
    else if (attr == "save")
    {
      if (age < 1 || name == "")
        returnMsg(" Please fill out all required data!");
      else
      {
        x.id   = id;
        x.age  = age;
        x.name = name;
        P = allocateCustomer(x);
        insertLastCustomer(LC, P);

        y.id       = id;
        y.customer = P;
        Q = allocate(y);
        insertLast(L, Q);

        returnMsg(" Saved! Temporary data removed!");

        id   = info(last(L)).id + 1;
        age  = 0;
        name = "";
      }
    }

    cout << "[insert| c ]>> ";
  }
}

/*  doInsertAccount
    ---------------
    @input/output   LA           accountList
    @return                      Void
===================================================================*/
void doInsertAccount(accountList &LA)
{
  unsigned long int id;
  signed long int balance;
  string input, attr, val;
  vector <string> args;
  addrAccount P;
  infoTypeAccount x;

  cout << endl
       << " Attributes" << endl
       << " ----------" << endl
       << " id             Integer        Auto" << endl
       << " balance        Integer        Not Required" << endl
       << endl
       << " Commands" << endl
       << " --------" << endl
       << " save           Save data" << endl
       << " back           Close this interface" << endl
       << endl;
  
  if (isEmptyAccount(LA)) id = 1;
  else id = info(last(LA)).id + 1;

  cout << "[insert| a ]>> ";
  while (getline(cin, input) && input != "back")
  {
    parse(input, attr, args);

    if (attr != "" && attr != "save")
    {
      if (args.size() < 1)
      {
        if      (attr == "id")      returnValue(id);
        else if (attr == "balance") returnValue(balance);
        else returnMsg(" Attribute didn't exist!");
      }
      else
      {
        val = args.at(0);
        if      (attr == "id")      returnValue(id);
        else if (attr == "balance") checkNumThenAssign(val, balance);
        else returnMsg(" Attribute didn't exist!");
      }
    }
    else if (attr == "save")
    {
      x.id      = id;
      x.balance = balance;
      P = allocateAccount(x);
      insertLastAccount(LA, P);

      returnMsg(" Saved! Temporary data removed!");

      id      = info(last(LA)).id + 1;
      balance = 0;
    }

    cout << "[insert| a ]>> ";
  }
}

/*  doInsert
    --------
    @input          args        <String>
    @input/output   LC           customerList
                    LA           accountList
                    L            List
    @return                      Void
===================================================================*/
void doInsert(vector <string> args, customerList &LC, accountList &LA, List &L)
{
  if (args.size() < 1) cout << endl << " Arguments needed!" << endl << endl;
  else
  {
    string opt = args.at(0);
    if      (opt == "c") doInsertCustomer(LC, L);
    else if (opt == "a") doInsertAccount(LA);
    else cout << endl << " Please provides \"c\" or \"a\"!" << endl << endl;
  }
}

/*  doLinkList
    ----------
    @input          args        <String>
    @input/output   LA           accountList
                    L            List
    @return                      Void
===================================================================*/
void doLinkList(vector <string> args, accountList &LA, List &L)
{
  if (args.size() < 2) returnMsg(" Need two arguments!");
  else
  {
    if (isNumeric(args.at(0)) && isNumeric(args.at(1)))
    {
      unsigned long int aid = stol(args.at(0)),
                        cid = stol(args.at(1));

      addrAccount A = findAccountByID(LA, aid);
      if (found (A))
      {
        int linked = info(A).cid.size();
        if (linked < 2)
        {
          address R = findListByID(L, cid);
          if (found (R))
          {
            info(A).cid.insert(info(A).cid.end(), cid);
            info(R).account.insert(info(R).account.end(), A);
            returnMsg(" Linked successfuly!");
          }
          else returnMsg(" Customer not found!");
        }
        else returnMsg(" Maximum Account link reached! Max: 2.");
      }
      else returnMsg(" Account not found!");
    }
    else returnMsg(" Arguments must be an ID!");
  }
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