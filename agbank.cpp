#include <iostream>
#include <iomanip>
#include <sstream>  //for ostringstream
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include "agbanking.h"


Banking::Banking() {        //constructor
    NumYears = 0;
    InitialInvestment = 0.0;
    MonthlyDeposit = 0.0;
    AnnualInterest = 0.0;
    BeginBalance = 0.0;
    Interest = 0.0;
    CloseBalance = 0.0;
}

// setters
void Banking::setInitialInvestment(double initialInvestment) {
    InitialInvestment = initialInvestment;
}
void Banking::setMonthlyDeposit(double monthlyDeposit) {
    MonthlyDeposit = monthlyDeposit;
}
void Banking::setAnnualInterest(double annualInterest) {
    AnnualInterest = annualInterest;
}
void Banking::setNumYears(int numYears) {
    NumYears = numYears;
}

// getters
double Banking::getInitialInvestment() const {
    return InitialInvestment;
}

double Banking::getMonthlyDeposit() const {
    return MonthlyDeposit;
}

double Banking::getAnnualInterest() const {
    return AnnualInterest;
}

int Banking::getNumYears() const {
    return NumYears;
}

// prompt the user for investment data and store it using setter methods 
void Banking::promptUserData() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    initialInvestment = validateInput<double>("Initial Investment Amout: ");    //prompt and validate initial investment input
    setInitialInvestment(initialInvestment);        //store validated input

    monthlyDeposit = validateInput<double>("Monthly Deposit: ");        //prompt and validate monthly deposit input
    setMonthlyDeposit(monthlyDeposit);

    annualInterest = validateInput<double>("Annual Interest (in %): ");     //prompt and validate annual interest input
    setAnnualInterest(annualInterest);

    numYears = validateInput<int>("Number of Years: ");         //prompt and validate number of years input
    setNumYears(numYears);

    std:: cout << "\n";
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();         //wait for user to press Enter 

}

// display the stored investment data to the user
void Banking::displayUserData() {
    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    // format all decimal value to 2 digits
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Inital Investment Amount: $" << getInitialInvestment() << std::endl;
    std::cout << "Monthly Deposit: $" << getMonthlyDeposit() << std::endl;

    // display annual interest as a whole number
    std::cout << "Annual Interest: " << std::fixed << std::setprecision(0) << getAnnualInterest() << "%" << std::endl;      
    std::cout << "Number of years: " << getNumYears() << std::endl;

    std:: cout << "\n";
    std::cout << "Press Enter to see the analysis" << std::endl;
    std::cin.get();     //wait for user to press Enter before proceeding
}


// validate the user input to ensure it is a positive number
template <typename RawData>         // use template function to work for any data type
RawData validateInput(const std::string& questionToUser) {
    RawData input;          // declare variable named input to store the value entered by the user
    bool isPositive = false;

    do {
        std::cout << questionToUser;
        std::cin >> input;

        // ensure the input is not non-numeric or negative
        if(std::cin.fail() || input < 0) {
           std::cin.clear();        // clear error state
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore remaining input

           std::cout << "Invalid input. Please enter a positive number" << std::endl;
        }
        else {
            isPositive = true;      // confirm it is valid input
            break;
        }
    } while (!isPositive);      // continue the loop if the input is not positive or numeric

    return input;    // return the input after validation, ready to store the value
}

// generate and display an annual investment report without additional monthly deposits
void Banking::showReport() {
    double CloseBalance = 0.0;      // set closing balance back to 0
    double interest = 0.0;          // interest earned in a year
    AnnualInterest = AnnualInterest/100;        // convert interest rate to decimal
    BeginBalance = InitialInvestment;       // set the beginning balance for calculation

    std::cout << std::fixed << std::setprecision(2);    // format output to 2 decimal

    std::cout << "    Balance and Interest Without Additional Monthly Deposits" << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "     Year            Year End Balance         Year End Earned Interest" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;

    // calculate and display the ending balance and interest earned for each year
    for(int year = 1; year <= NumYears; year++) {
        CloseBalance = InitialInvestment * pow((1+AnnualInterest), year);   // compound interest formula without monthly deposits
        interest = CloseBalance - BeginBalance;     // calculate yearly interest earned
        BeginBalance = CloseBalance;        // update beginning balance for next year's calculation

        // display the result for current year
        std::cout << std::setw(8) << year << std::setw(20) << "$" << CloseBalance << std::setw(20) << "$" << interest << std::endl;
    }
}


// generate and displays an annual investment report with additional monthly deposits
// returns output as a vector of formatted strings
// which prepare for saving to a file or print out feature
std::vector<std::string> Banking::showReportWithDeposit() {
    std::vector<std::string> outputLines;       // declare variable as a vector with string type for store each line
    double total = 0.0;         // hold balance before interest for the month
    double monthlyInterestRate = AnnualInterest/12;         // convert annual interest to monthly
    BeginBalance = InitialInvestment;       // start balance for the first month
    
    std::cout << "    Balance and Interest With Additional Monthly Deposits" << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "     Year            Year End Balance         Year End Earned Interest" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;

    // outer loop: iterate through each year
    // inner loop: simulate each month's deposit and interest
    for(int year = 1; year <= NumYears; year++) {
        for (int month = 1; month <= 12; month++) {
            total = BeginBalance + MonthlyDeposit;          // add monthly deposit to balance
            CloseBalance = total * (1 + monthlyInterestRate);       // apply monthly interest
            BeginBalance = CloseBalance;        // update balance for next month
            Interest += CloseBalance - total;       // accumulate interest earned this year
        }

        // format balance and interest for align all output
        std::ostringstream balanceStream, interestStream;
        balanceStream << "$" << std::fixed << std::setprecision(2) << BeginBalance;
        interestStream << "$" << std::fixed << std::setprecision(2) << Interest;

        // purpose of format is to prepare to add in the vector<string> outputLines
        std::ostringstream lineStream;
        lineStream << std::setw(8) << year
                  << std::setw(26) << balanceStream.str()
                  << std::setw(28) << interestStream.str()
                  << std::endl;
        
        // save line to vector
        outputLines.push_back(lineStream.str()); 
        std::cout << lineStream.str() << std::endl;     // display it to console

        Interest = 0.0;     // reset yearly interest for next year's calculation
    }
    
    return outputLines;     // return all formatted lines as vector<string>
    
}
