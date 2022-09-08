#include "CHECKBOOK.H"
using namespace std; 

Checkbook::Checkbook(){
    balance = 0;
    checknum = 1;
    howfull = 0;
}

void Checkbook::show_all(ostream &outs)const{
    for (size_t i = 0; i < howfull; i++)
    {
        outs << book[i];
    }
}

void Checkbook::write_check(istream &ins){
    Check a;
    a.write_check(ins);
    a.set_check_num(checknum);
    cout << a;
    book[howfull] = a;
    howfull += 1;
    checknum += 1;
}

void Checkbook::remove(int num){
    for (size_t i = 0; i < howfull; i++)
    {
        if(num == book[i].get_num()){
            for (size_t j = i; j < howfull; j++)
            {
                book[j] = book[j + 1];
            }
        }else{
            cout << "Check number not found, please try again" << endl;
        }
    }
}