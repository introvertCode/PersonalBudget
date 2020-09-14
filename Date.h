#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class Date
{
    int year;
    int month;
    int day;
    int currentYear;
    int currentMonth;
    int currentDay;

    bool isProperDay();
    bool isProperMonth();
    bool isProperYear();
    bool isLeapYear();
    bool isDateWellFormatted(string);
    void extractDateFromString(string);
    void todaysDate();
    string intDateToStringWithDashes();
    void setTodaysDateAsOperationDate();
    int getMaxDayOfMonth();

public:
    int addDate();
    bool isDateCorrect(string);
    int convertStringDateToInt(string);
    string getTodaysDateAsString();
    string getDateFormattedAsString(int);
    int getTodaysDateAsOneInt();
    int getFirstDayOfCurrentMonth();
    int getFirstDayOfLastMonth();
    int getLastDayOfLastMonth();

};


#endif
