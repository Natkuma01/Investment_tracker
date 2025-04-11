#include <iostream>
#include <vector>
#include <string>
#include "agbanking.h"

// encapsulate the steps for account setup which include prompt user fiancial data, display data and reports
void runAccountSetUp(Banking& myAccount) {
    myAccount.promptUserData();     
    std::cout << "\n";      
    myAccount.displayUserData();       
    myAccount.showReport();             
    std::cout << "\n";   
    myAccount.showReportWithDeposit();     
}

int main() {
    int choice = 0;     

    std::cout << greeting() << std::endl;       
    std::cout << "Let’s create a powerful investment plan that sets you on the path to achieving your financial dreams!  \n" << std::endl;

    
    Banking myAccount;         // create a Banking object for the user account
    runAccountSetUp(myAccount);     // run the initial account setup

    
    do {
    std::cout << "More Options: " << std::endl;
    std::cout << "[1] Make another financial plan" << std::endl;
    std::cout << "[2] Print report" << std::endl;
    std::cout << "[3] Exit the program" << std::endl;
    
    std::cin >> choice;    

    
    if (std::cin.fail() || choice >3 || choice <=0) {
        std::cin.clear();       
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     
        std::cout << "Please enter invalid number." << std::endl;
        continue;   
    }

    
    if (choice == 2) {   
        std::vector<std::string> outputLines = myAccount.showReportWithDeposit();   
        printReport("Report.txt", outputLines);     
    }

    if (choice ==1) {
        runAccountSetUp(myAccount);     
    }
    }
    while (choice != 3);        


return 0;
}