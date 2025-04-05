#pragma once
#ifndef banking_h
#define banking_h

using std::string;


class Banking {
    private:
        int NumYears;
        double InitialInvestment;
        double MonthlyDeposit;
        double AnnualInterest;
        double BeginBalance;
        double Interest;
        double CloseBalance;

    public:
      Banking();

      void setInitialInvestment(double);
      void setMonthlyDeposit(double);
      void setAnnualInterest(double);
      void setNumYears(int);

      double getInitialInvestment() const;
      double getMonthlyDeposit() const;
      double getAnnualInterest() const;
      int getNumYears() const;
 
      void promptUserData();
      void displayUserData();
      void showReport();
      void showReportWithDeposit();
      void printReport();
};

template <typename RawData>
RawData validateSobbleData(const std::string& questionToUser);

void clearScreen();

std::string greeting();

#endif