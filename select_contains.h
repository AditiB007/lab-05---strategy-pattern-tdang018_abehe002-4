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
     
      if(substring.size() > entry.size()) { return false; }
      
      std::string entry_substr = "";
      for(int i=0; i<entry.size(); ++i) {
        if(i+substring.size() > entry.size()) { return false; }
        entry_substr = entry.substr(i, i+substring.size());
        if(entry_substr == substring) { return true; }
      }
      return false;
      
      /*
      for(int i=0; i<entry.size(); ++i) { // entry, loop through it
        //std::cout << "i: " << std::to_string(i) << " " << entry.at(i) << std::endl;
        int count = 0;
        for(int j=0; j<substring.size(); ++j) { // substring, loop through it
           //std::cout << "j: " << std::to_string(j)  << " " << substring.at(j) << " " << std::endl;
           if(i+j > entry.size()) { return false; }
           if(entry.at(i+j) == substring.at(j)) { ++count; }
           std::cout << "entry.at(i+j): " << entry.at(i+j) << " substring.at(j): " << substring.at(j) << std::endl;
           if(count == substring.size()) { return true; }
           //if(i+j+1 > entry.size()) {return false; }
        }
        //if(count == substring.size()) { return true; }
        // able to loop through both strings without the substring having any mismatches
        //else { return false; }
      }
      return false;
      */
    }
};

#endif // __SELECT_CONTAINS__
