/*************************************************************************
    This is the implementation file for the Check class. For more 
		information about the class see check.h.
    Students are expected to implement some of the functions shown below.

	John Dolan			Ohio University EECS	September 2019
	Patricia Lindner	Ohio University EECS	August 2022
*************************************************************************/
#include "check.h"
using namespace std;

Check::Check(Date d, string p, int num, double amt){
	date = d;
	payto = p;
	checknum = num;
	amount = amt;
}

// Input and output functions
void Check::write_check(std::istream& ins){
	if(&ins == &cin){ //check if input stream is cin
		cout << "Please enter the check's date in format DD/MM/YYYY: ";
		ins >> date;
		cout << "Please enter the payto: ";
		while(ins.peek() == '\n' || ins.peek() == '\r'){
			ins.ignore();
		}
		getline(ins, payto);
		cout << "Please enter the check amount: ";
		ins >> amount;
	}else{ //else it is a file
		ins >> checknum;
		ins >> date;
		while(ins.peek() == '\n' || ins.peek() == '\r'){ //check for and ignore all newlines not removed by >> operator
			ins.ignore();
		}
		getline(ins, payto);
		ins >> amount;
	}
}

void Check::output(std::ostream& outs)const{
	if(&outs == &cout){ //check if input stream is cin
		outs << " Check Number: " << checknum << endl << " Date: " << date << endl << " Payto: " << payto << endl << " Amount: " << amount << endl;
	}else{  //else it is a file
		outs << checknum << endl << date << endl << payto << endl << amount << endl;
	}
}

ostream& operator << (ostream& outs, const Check& c){
	c.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Check& c){
	c.write_check(ins);
	return ins;
}