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
    // constructor to initialize the Banking object with default values
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
      std::vector<std::string> showReportWithDeposit();     
};

template <typename RawData>
RawData validateInput(const std::string& questionToUser);

void printReport(const std::string& filename, const std::vector<std::string>& lines);

std::string greeting();

#endif