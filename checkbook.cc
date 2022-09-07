#include "CHECKBOOK.H"
using namespace std; 

void Checkbook::show_all(ostream &outs)const{
    for (size_t i = 0; i < howfull - 1; i++)
    {
        outs << book[i];
    }
}

void Checkbook::write_check(istream &ins){
    Check a;
    a.write_check(ins);
    a = book[howfull + 1];
    howfull += 1;
}

