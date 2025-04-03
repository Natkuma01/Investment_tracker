#include <iostream>
#include <iomanip>
#include "agbanking.h"

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


void Banking::promptUserData(Banking& banking) {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    std::cout << "Initial Investment Amount: " << std::endl;
    std:cin >> initialInvestment;
    banking.setInitialInvestment(initialInvestment);

    std::cout << "Monthly Deposit: " << std::endl;
    std: cin >> monthlyDeposit;
    banking.setMonthlyDeposit(monthlyDeposit);

    std::cout << "Annual Interest: " << std::endl;
    std: cin >> annualInterest;
    banking.setAnnualInterest(annualInterest);

    std::cout << "Number of years: " << std::endl;
    std: cin >> numYears;
    banking.setNumYears(numYears);

    std::cout << "Press Enter to continue..." << std::endl;
    std:: cin.get();

}

void Banking::displayUserData(Banking& banking) {
    std::cout << "******************************" << std::endl;
    std::cout << "********* Data Input *********" << std::endl;

    std::cout << "Inital Investment Amount: " << banking.getInitialInvestment() << std::endl;

}