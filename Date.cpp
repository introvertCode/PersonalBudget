#include "Date.h"

bool Date::isDateCorrect(string strDate)
{
    todaysDate();

    if(isDateWellFormatted(strDate) != true)
    {
        return false;
    }
    extractDateFromString(strDate);

    if(isProperDay() && isProperMonth() && isProperYear())
    {
        return true;
    }
    return false;
}

void Date::extractDateFromString(string strDate)
{
    year = stoi(strDate.substr(0,4));
    month = stoi(strDate.substr(5,2));
    day = stoi(strDate.substr(8,2));

    return;
}

bool Date::isDateWellFormatted(string date)
{
    if (date.length() != 10)
    {
        return false;
    }

    for (int i = 0; i < date.length(); i++)
    {
        if(i == 4 || i == 7)
        {
            if (date[i] != '-') return false;
        }
        else if (date[i] > '9' || date[i] < '0')
        {
            cout << "There is a letter" << endl;
            return false;
        }
    }
    return true;
}

bool Date::isLeapYear()
{
    if((year%400==0) || (year%4==0 && year%100!=0))
    {
        return true;
    }
    return false;
}

bool Date::isProperDay()
{
    int maxDays = getMaxDayOfMonth();
    if (day >= 1 && day <= maxDays)
    {
        return true;
    }
    else return false;
}

bool Date::isProperMonth()
{
    if(month >= 1 && month <= 12) return true;
    else return false;
}

bool Date::isProperYear()
{
    if(year < 2000 && year > currentYear) return false;
    return true;
}

int Date::convertStringDateToInt(string strDate)
{
    extractDateFromString(strDate);
    int date = year*10000 + month*100 + day;
    return date;
}

void Date::todaysDate()
{
    time_t ttime = time(0);

    tm *local_time = localtime(&ttime);
    currentYear = 1900 + local_time->tm_year;
    currentMonth = 1 + local_time->tm_mon;
    currentDay = local_time->tm_mday;

    return;
}

void Date::setTodaysDateAsOperationDate()
{
    todaysDate();
    year = currentYear;
    month = currentMonth;
    day = currentDay;

    return;
}

string Date::intDateToStringWithDashes()
{
    stringstream ssDate;
    string stringDate;
    char dash = '-';

    ssDate << year << dash;

    if(month < 10)
    {
        ssDate << "0" << month << dash;
    }
    else ssDate << month << dash;

    if(day < 10)
    {
        ssDate << "0" << day;
    }
    else ssDate << day;

    ssDate >> stringDate;
 return stringDate;
}

string Date::getTodaysDateAsString()
{
    string date = "";
    setTodaysDateAsOperationDate();
    date = intDateToStringWithDashes();
    return date;
}

string Date::getDateFormattedAsString(int intDate)
{
    year = intDate/10000;
    intDate -= year*10000;

    month = intDate/100;
    intDate -= month*100;

    day = intDate;

    return intDateToStringWithDashes();
}

int Date::getTodaysDateAsOneInt()
{
    todaysDate();
    int date = currentYear*10000 + currentMonth*100 + currentDay;
    return date;
}

int Date::getFirstDayOfCurrentMonth()
{
    todaysDate();
    int date = currentYear*10000 + currentMonth*100 + currentDay;
    int firstDayOfMonth = date - (currentDay - 1);
    return firstDayOfMonth;
}

int Date::getMaxDayOfMonth()
{
    int maxDays = 0;

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        maxDays = 31;
    }
    else if (month == 2)
    {
        if(isLeapYear() == true)
        {
            maxDays = 29;
        }
        else maxDays = 28;
    }
    else maxDays = 30;

    return maxDays;
}

int Date::getLastDayOfLastMonth()
{
    int date = 0;
    todaysDate();
    setTodaysDateAsOperationDate();

    if (month == 12)
    {
        year -= 1;
        month = 1;
    }
    else month -= 1;

    int maxDay = getMaxDayOfMonth();

    date = year*10000 + month*100 + maxDay;

    return date;
}

int Date::getFirstDayOfLastMonth()
{
    todaysDate();
    setTodaysDateAsOperationDate();
    if (month == 12)
    {
        year -= 1;
        month = 1;
    }
    else month -= 1;

    day = 1;

    int date = year*10000 + month*100 + day;

    return date;
}

int Date::addDate()
{
    bool isCorrect = false;
    int incomeDate = 0;

    do
    {
        string dateFromUserToCheck = "";

        cout <<"Write date in YYYY-MM-DD format: ";
        cin >> dateFromUserToCheck;
        isCorrect = isDateCorrect(dateFromUserToCheck);
        if (isCorrect)
        {
            incomeDate = convertStringDateToInt(dateFromUserToCheck);
            return incomeDate;
        }
        else
        {
            cout <<"Wrong date or format!";
        }
    }
    while(!isCorrect);
}
