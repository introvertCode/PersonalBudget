#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include "XmlFile.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
public:
    FileWithExpenses(string filePath = "expenses.xml", string element = "Expense") : XmlFile(filePath, element)
    {
    }
};



#endif
