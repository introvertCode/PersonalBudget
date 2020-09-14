#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
public:
    FileWithIncomes(string filePath = "incomes.xml", string element = "Income") : XmlFile(filePath, element)
    {
    }
};



#endif
