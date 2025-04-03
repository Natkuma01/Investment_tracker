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

      void Banking::setInitialInvestment(double);
      void Banking::setMonthlyDeposit(double);
      void Banking::setAnnualInterest(double);
      void Banking::setNumYears(int);

      double getInitialInvestment() const;
      double getMonthlyDeposit() const;
      double getAnnualInterest() const;
      int getNumYears() const;
        
};


#endif