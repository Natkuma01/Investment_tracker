#pragma once
#ifndef banking_h
#define banking_h

using std::string;

// class that handles banking -related oeprations for the investment plan
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

      // setters to assign values to the private member variablees
      void setInitialInvestment(double);
      void setMonthlyDeposit(double);
      void setAnnualInterest(double);
      void setNumYears(int);

      // getters ti retrieve values of the private member variables
      double getInitialInvestment() const;
      double getMonthlyDeposit() const;
      double getAnnualInterest() const;
      int getNumYears() const;
 
      void promptUserData();        // function to prompt user financial data
      void displayUserData();       // function to display the entered data 
      void showReport();        // function to generate and display the report without monthly depsoit
      std::vector<std::string> showReportWithDeposit();     // function to generate and return the report with monthly deposits
};

// template function to validate the input data is positive number
template <typename RawData>
RawData validateInput(const std::string& questionToUser);

// function to print the financial report to a file
void printReport(const std::string& filename, const std::vector<std::string>& lines);

// function to generate a greeting based on the current time of the user
std::string greeting();

#endif