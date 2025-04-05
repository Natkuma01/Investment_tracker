/*
* Name: Shimin Chan
* Project Two - AireGead Banking
* Purpose of the program is to allow users to see how their investment will grow over time
*/

#include <iostream>
#include "agbanking.h"


using std::string;



int main() {
    int choice = 0;

    std::cout << greeting() << std::endl;
    std::cout << "Let's try to build your investment plan so you can be rich soon! \n" << std::endl;

    
    Banking myAccount;
    myAccount.promptUserData();
    std::cout << "\n";
    myAccount.displayUserData();
    myAccount.showReport();
    std::cout << "\n";   
    myAccount.showReportWithDeposit();

    do {
    std::cout << "more options: " << std::endl;
    std::cout << "[1] change my input" << std::endl;
    std::cout << "[2] print report" << std::endl;
    std::cout << "[3] exit the program" << std::endl;
    
    std::cin >> choice;
    if (std::cin.fail() || choice >3 || choice <=0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter invalid number.";
        continue;
    }
    if (choice == 2) {
        //myAccount.printReport();
    }
    if (choice ==1) {
        Banking myAccount;
        myAccount.promptUserData();
        std::cout << "\n";
        myAccount.displayUserData();
        myAccount.showReport();
        std::cout << "\n";   
        myAccount.showReportWithDeposit();
    }
    }
    while (choice != 3);


return 0;
}