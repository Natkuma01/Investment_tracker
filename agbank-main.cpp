/*
* Name: Shimin Chan
* Project Two - AireGead Banking
* Purpose of the program is to allow users to see how their investment will grow over time
*/

#include <iostream>
#include <vector>
#include <string>
#include "agbanking.h"

// encapsulate the steps for account setup which include prompt user fiancial data, display data and reports
void runAccountSetUp(Banking& myAccount) {
    myAccount.promptUserData();     // prompt user financial data
    std::cout << "\n";      
    myAccount.displayUserData();        // display user's entered data
    myAccount.showReport();             // show report without additional deposit
    std::cout << "\n";   
    myAccount.showReportWithDeposit();      // show report with deposit
}

int main() {
    int choice = 0;     // set vatiable to store the user's menu choice

    std::cout << greeting() << std::endl;       // display a greeting message based on the current time of day
    std::cout << "Let’s create a powerful investment plan that sets you on the path to achieving your financial dreams!  \n" << std::endl;

    
    Banking myAccount;         // create a Banking object for the user account
    runAccountSetUp(myAccount);     // run the initial account setup

    // loop to display menu options and allow the user to choose an action
    do {
    std::cout << "More Options: " << std::endl;
    std::cout << "[1] Make another financial plan" << std::endl;
    std::cout << "[2] Print report" << std::endl;
    std::cout << "[3] Exit the program" << std::endl;
    
    std::cin >> choice;    

    // check if the input is non-numeric or out of valid range and prompt the user to try again
    if (std::cin.fail() || choice >3 || choice <=0) {
        std::cin.clear();       // clear input error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // ignore the remaining
        std::cout << "Please enter invalid number." << std::endl;
        continue;   // skip the rest of the loop and prompt the user again
    }

    // if user chooses option 2, export the financial report (with deposit table) to a file
    if (choice == 2) {   
        std::vector<std::string> outputLines = myAccount.showReportWithDeposit();   // get report lines with deposits
        printReport("Report.txt", outputLines);     // print the report to a file
    }

    // if user chooses option 1, make another financial plan, return to account setup
    if (choice ==1) {
        runAccountSetUp(myAccount);     // return account setup process
    }
    }
    while (choice != 3);        // continur looping until the user selects option 3 to exist


return 0;
}