#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "agbanking.hpp"

using std::string;

Banking::Banking() {
    NumYears = 0;
    InitialInvestment = 0.0;
    MonthlyDeposit = 0.0;
    AnnualInterest = 0.0;
    BeginBalance = 0.0;
    Interest = 0.0;
    CloseBalance = 0.0;
}

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


void Banking::promptUserData() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    initialInvestment = validateSobbleData<double>("Initial Investment Amout: ");
    setInitialInvestment(initialInvestment);

    monthlyDeposit = validateSobbleData<double>("Monthly Deposit: ");
    setMonthlyDeposit(monthlyDeposit);

    annualInterest = validateSobbleData<double>("Annual Interest (in %): ");
    setAnnualInterest(annualInterest);

    numYears = validateSobbleData<int>("Number of Years: ");
    setNumYears(numYears);

    std:: cout << "\n";
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();

}

void Banking::displayUserData() {
    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    std::cout << "Inital Investment Amount: $" << getInitialInvestment() << std::endl;
    std::cout << "Monthly Deposit: $" << getMonthlyDeposit() << std::endl;
    std::cout << "Annual Interest: " << getAnnualInterest() << "%" << std::endl;      
    std::cout << "Number of years: $" << getNumYears() << std::endl;

    std:: cout << "\n";
    std::cout << "Press any key to continue...." << std::endl;
    std::cin.get();
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H" << std::flush;
}

// validate the user input are positive integer
template <typename RawData>
RawData validateSobbleData(const std::string& questionToUser) {
    RawData input;
    bool isPositive = false;

    do {
        std::cout << questionToUser;
        std::cin >> input;

        if(std::cin.fail() || input < 0) {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

           std::cout << "Invalid input. Please enter a positive number" << std::endl;
        }
        else {
            isPositive = true;
            break;
        }
    } while (!isPositive);

    return input;
}

void Banking::showReport() {
    double closingBal = 0.0;
    double interest = 0.0;
    AnnualInterest = AnnualInterest/100;
    BeginBalance = InitialInvestment;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "    Balance and Interest Without Additional Monthly Deposits" << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "     Year            Year End Balance         Year End Earned Interest" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;

    for(int i = 1; i <= NumYears; i++) {
        closingBal = InitialInvestment * pow((1+AnnualInterest), i);
        interest = closingBal - BeginBalance;
        BeginBalance = closingBal;
        std::cout << "       " << i << "                   " << closingBal << "                          " << interest << std::endl;
    }
}



void Banking::showReportWithDeposit() {
    double closingBal = 0.0;
    double interest = 0.0;
    double monthlyRate = AnnualInterest/12;
    AnnualInterest = AnnualInterest/100;

    std::cout << "    Balance and Interest Without Additional Monthly Deposits" << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "     Year            Year End Balance         Year End Earned Interest" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;

    for(int i = 1; i <= NumYears; i++) {
        
        interest = InitialInvestment*AnnualInterest;
        std::cout << "       " << i << "                   " << closingBal << "                          " << interest << std::endl;
    }
}
