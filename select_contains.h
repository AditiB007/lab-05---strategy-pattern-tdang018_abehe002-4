#ifndef __SELECT_CONTAINS__
#define __SELECT_CONTAINS__

#include "select.hpp"
#include <iostream>

class Select_Contains: public Select {
private: 
    Spreadsheet* sheet;
    std::string columnName;
    std::string substring;

public:
    Select_Contains(Spreadsheet* sheet, std::string columnName, std::string substring) {
      this->sheet = sheet;
      this->columnName = columnName;
      this->substring = substring;
    }

    bool select(const Spreadsheet* sheet, int row) const {
      int column = sheet->get_column_by_name(columnName);
      std::string entry = sheet->cell_data(row, column);      
      //std::cout << "data at cell(row, column): " + data << std::endl;
      //std::cout << "row: " + std::to_string(row) << std::endl;
      //std::cout << "column: " + std::to_string(column) << std::endl;
      for(int i=0; i<entry.size(); ++i) { // assume entry is longer than substring, loop through it
        //std::cout << "i: " << std::to_string(i) << " " << entry.at(i) << std::endl;
        int count = 0;
        for(int j=0; j<substring.size(); ++j) { // assume substring is shorter, loop through it
           //std::cout << "j: " << std::to_string(j)  << " " << substring.at(j) << " " << std::endl;
           if(i+j > entry.size()) { return false; }
           if(entry.at(i+j) == substring.at(j)) { ++count; }
        }
        if(count == substring.size()) { return true; }
        // able to loop through both strings without the substring having any mismatches
        else { return false; }
      }
    }
};

#endif // __SELECT_CONTAINS__
