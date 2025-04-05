/*
* Name: Shimin Chan
* Project Two - AireGead Banking
* Purpose of the program is to allow users to see hoe their investment will grow over time
*/

#include <iostream>
#include "agbanking.hpp"


using std::string;



int main() {
    Banking myAccount;
    myAccount.promptUserData();
    std::cout << "\n";
    myAccount.displayUserData();
    myAccount.showReport();
    std::cout << "\n";   
    myAccount.showReportWithDeposit();



return 0;
}