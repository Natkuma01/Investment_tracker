#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "agbanking.h"

// return a time-based greeting message based on the current hour
std::string greeting() {
    int currHour;       // declare variable to store user current time 

    // get the current time as a time_t object
    std::time_t now = std::time(0);     
    // convert the time_t value to local time and return a pointer to a tm structure wuth hr,min,day
    std::tm localTime;
    
    localtime_r(&now, &localTime);      

    currHour = localTime.tm_hour;      // extract current hour in 24 hour format

    // define greeting statment based on current hour
    if (currHour >=3 && currHour <=11) {
        return "Good Morning! \nWelcome to AireGead Banking.";
    }
    else if (currHour >=12 && currHour <16) {
        return "Good Afternoon! \nWelcome to AireGead Banking";
    }
    else {
    return "Good Evening! \nWelcome to AireGead Banking";
  
    }
}

// write the investment report data into a text file
// the function takes a vector of strings as input, where each string represents a report line
void printReport(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outFile;
    outFile.open("Report.txt");     // open and create the file

    // check if file opened sucessfully
    if(!outFile.is_open()) {
        std::cerr << "Unable to print out the report at this moment." << std::endl;
        return;
    }

    // hardcode these lines into the Report.txt file
    outFile << "    Balance and Interest With Additional Monthly Deposits" << std::endl;
    outFile << "=================================================================" << std::endl;
    outFile << "     Year            Year End Balance         Year End Earned Interest" << std::endl;
    outFile << "------------------------------------------------------------------------" << std::endl;

    // iterate through each line in the vector<string> and write it to the Report.txt file
    // use 'auto' to automatically deduce the type of 'line' to simplify code and avoid type mismatches
    // requires C++11 or later. If using an older standard, 
    // this code will cause a compiler error unless the '-std=c++11' (or later) flag is specified.
    for (const auto& line : lines) {
        outFile << line << std::endl;
    }

    // close the file after writing is completed
    outFile.close();

    std::cout << "Your report is successfully export as a text file." << std::endl;

}