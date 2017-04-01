#ifndef BANKIR_FUNCTIONALLITY_INCLUDED
#define BANKIR_FUNCTIONALLITY_INCLUDED

/*! Functionallity
*   --------------
*   @author         Wisnu Adi Nurcahyo
*   @contact        <wisnu@nurcahyo.me>
*   @license        MIT License
*/

#include <iostream>
#include <vector>
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
void parse(string input, string &command, vector <string> &arguments);

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
bool isNumeric(string input);

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
void checkNumThenAssign(string input, auto &val);

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
bool isWords(string input);

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
void checkWordsThenAssign(string input, string &val);

/*  returnValue
    -----------
    @input          input        Auto
    @return                      Void
===================================================================*/
void returnValue(auto input);

/*  returnString
    ------------
    @input          input        String
    @return                      Void
===================================================================*/
void returnString(string input);

/*  returnMsg
    ---------
    @input          input        String
    @return                      Void
===================================================================*/
void returnMsg(string input);

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
string joinString(vector <string> input);

/*  showHelp
    --------
    @return                      Void
===================================================================*/
void showHelp();

void showInfo(List L);

/*  doInsertCustomer
    ----------------
    @input/output   LC           customerList
                    L            List
    @return                      Void
===================================================================*/
void doInsertCustomer(customerList &LC, List &L);

/*  doInsertAccount
    ---------------
    @input/output   LA           accountList
    @return                      Void
===================================================================*/
void doInsertAccount(accountList &LA);

/*  doInsert
    --------
    @input          args        <String>
    @input/output   LC           customerList
                    LA           accountList
                    L            List
    @return                      Void
===================================================================*/
void doInsert(vector <string> args, customerList &LC, accountList &LA, List &L);

/*  doLinkList
    ----------
    @input          args        <String>
    @input/output   LA           accountList
                    L            List
    @return                      Void
===================================================================*/
void doLinkList(vector <string> args, accountList &LA, List &L);

void doDelete();

void doUpdate();

void doShow();

#endif
