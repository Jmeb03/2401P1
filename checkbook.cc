#include "CHECKBOOK.H"
using namespace std; 

Checkbook::Checkbook(){
    balance = 0;
    checknum = 1;
    howfull = 0;
}

void Checkbook::show_all(ostream &outs)const{
    for (int i = 0; i < howfull; i++)
    {
        if(book[i].get_num() > 0){  //checks if check is deleted
            outs << book[i];    //loops output of all non-deleted checks
        }
    }
}

void Checkbook::write_check(istream &ins){
    if(&ins == &cin){
        Check a;  //temporary check
        a.write_check(ins);
        a.set_check_num(checknum); //setting check number based on next available
        book[howfull] = a;  //loading temporary check into book
        howfull++; 
        checknum++;
    }else{
    Check a;
    a.write_check(ins);
    book[howfull] = a;
    howfull++;
    }
}

void Checkbook::remove(int num){
    for (int i = 0; i < howfull; i++)
    {
        if(num == book[i].get_num()){
            for (int j = i; j < howfull; j++)
            {
                book[j] = book[j + 1];
            }
        }
    }
    howfull--;
}

void Checkbook::load_from_file(istream &ins){
    ins >> balance;
    ins >> checknum;
    while(!ins.eof()){
        write_check(ins);
    }
}

void Checkbook::save(ostream &outs){
    outs << balance << endl;
    outs << checknum << endl;
    show_all(outs);
}

void Checkbook::show(string target){
    for (int i = 0; i < howfull; i++)
    {
        if(book[i].get_payto() == target){
            cout <<"Payto: "<< book[i].get_payto() << endl;
            cout << "Amount: " << book[i].get_amount() << endl;
        }
    }
    
}

void Checkbook::number_sort(){
    int upper_bound = howfull - 1;
    Check tmp;
    bool done = false;

    while(!done){
        done = true;

        for (int i = 0; i < upper_bound; i++)
        {
            if(book[i].get_num() > book[i + 1].get_num()){
                tmp = book[i];
                book[i] = book[i + 1];
                book[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

void Checkbook::payto_sort(){
    int upper_bound = howfull - 1;
    Check tmp;
    bool done = false;

    while(!done){
        done = true;

        for (int i = 0; i < upper_bound; i++)
        {
            if(book[i].get_payto() > book[i + 1].get_payto()){
                tmp = book[i];
                book[i] = book[i + 1];
                book[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

void Checkbook::date_sort(){
    int upper_bound = howfull - 1;
    Check tmp;
    bool done = false;

    while(!done){
        done = true;

        for (int i = 0; i < upper_bound; i++)
        {
            if(book[i].get_date() > book[i + 1].get_date()){
                tmp = book[i];
                book[i] = book[i + 1];
                book[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

double Checkbook::average(){
    int total = 0;
    int count = 0;
    for (int i = 0; i < howfull - 1; i++)
    {
        total += book[i].get_amount();
        count++;
    }
    return total/count;
}