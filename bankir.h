#ifndef BANKIR_HEADER_INCLUDED
#define BANKIR_HEADER_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

#define Nil        NULL
#define first(L)   L.first
#define last(L)    L.last
#define next(P)    P->next
#define prev(P)    P->prev
#define info(P)    P->info
#define found(P)   P != Nil
#define single(L)  not (found (next(first(L))))

/*! Customer */
  struct infoTypeCustomer {
    unsigned long int id;
    unsigned int age;
    string name;
  };

  typedef struct elmListCustomer *addrCustomer;

  struct elmListCustomer {
    infoTypeCustomer info;
    addrCustomer     next;
    addrCustomer     prev;
  };

  struct customerList {
    addrCustomer first;
    addrCustomer last;
  };

/*! Account */
  struct infoTypeAccount {
    unsigned long int id, balance;
    unsigned int pointed;
  };

  typedef struct elmListAccount *addrAccount;

  struct elmListAccount {
    infoTypeAccount info;
    addrAccount     next;
    addrAccount     prev;
  };

  struct accountList {
    addrAccount first;
    addrAccount last;
  };

/*! List */
  #define account(P)  info(P).account
  #define customer(P) info(P).customer

  struct infotype {
    unsigned long int id;
    addrCustomer customer;

    vector <addrAccount>  account;
  };

  typedef struct elmList *address;

  struct elmList {
    infotype     info;
    address      next;
    address      prev;
  };

  struct List {
    address first;
    address last;
  };

#endif
