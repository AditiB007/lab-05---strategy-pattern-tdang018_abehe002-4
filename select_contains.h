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
      std::string data = sheet->cell_data(row, column);      
      for(int i=0; i<data.size(); ++i) {
        for(int j=0; j<substring.size(); ++j) {
           //std::cout << substring.at(j);
           if(i+j > data.size()-1) { return false; }
           if(data.at(i+j) != substring.at(j)) { continue; }
           //std::cout << substring.at(j);
        } // able to loop through both strings without the substring having any mismatches
      }
      std::cout << "true" << std::endl;
      return true;
    }
};

#endif // __SELECT_CONTAINS__
