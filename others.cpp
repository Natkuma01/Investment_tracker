#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "agbanking.h"

std::string greeting() {
    int currHour;

    std::time_t now = std::time(0);
    std::tm *localTime = std::localtime(&now);

    currHour = localTime->tm_hour;

    if (currHour >=3 && currHour <=11) {
        return "Good Morning! \n Welcome to AireGead Banking.";
    }
    else if (currHour >=12 && currHour <16) {
        return "Good Afternoon! Welcome to AireGead Banking";
    }
    else {
    return "Good Evening! Welcome to AireGead Banking";
  
    }
}

void printReport() {
    outFile.open("Report.txt");

    if(!outFile.is_open()) {
        std::cerr << "Unable to print out the report at this moment." << std::endl;
    }

    

    outFile.close();

    std::cout << "Your report is successfully export as a text file." << std::endl;

}