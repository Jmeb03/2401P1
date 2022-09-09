/*************************************************************************
    This is a header file for the checkbook class
    The checkbook class:
        *stores 200 checks
        *numbers checks
        *keeps a balance (checking account) 

  	Jake Bailey
*************************************************************************/

#ifndef CHECKBOOK_H
#define CHECKBOOK_H
#include "check.h"

class Checkbook{
    public:
    Checkbook();
    //getters & setters
    double get_balance()const {return balance;}
    void deposit(double amt){balance += amt;}
    //user data fcns
    void load_from_file(std::istream &ins);
    void save(std::ostream &outs);
    //checkbook manipulation fcns
    void write_check(std::istream &ins);
    void remove(int num);
    //display functions
    void show(std::string target);
    void show_all(std::ostream &outs)const;
    double average();
    //sort fcns
    void date_sort();
    void payto_sort();
    void number_sort();
    private:
    Check book [200]; //array to store checks
    double balance; //balance in account
    int checknum; //next available check number
    int howfull; //how many spaces in the array are occupied
};

#endif