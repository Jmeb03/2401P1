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
    void load_from_file(std::istream &ins);
    void remove(int num);
    void number_sort();
    void date_sort();
    void payto_sort();
    double average();
    void show(std::string target);
    double get_balance()const {return balance;}
    void show_all(std::ostream &outs)const;
    void deposit(double amt){balance += amt;}
    void write_check(std::istream &ins);
    void save(std::ostream &outs);
    private:
    Check book [200];
    double balance;
    int checknum;
    int howfull;
};

#endif