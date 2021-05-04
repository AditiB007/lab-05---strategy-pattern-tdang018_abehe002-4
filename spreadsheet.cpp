#include "spreadsheet.hpp"
#include "select.hpp"

#include <algorithm>
#include <iostream>

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}

// Implement print_selection
void Spreadsheet::print_selection(std::ostream& out) const {
    if(!select) {
      for(int i=0; i<data.size(); ++i) {
        for(int j=0; j<data.at(i).size(); ++j) {
          out << cell_data(i, j) << " "; // separate row element outputs with space
        }
        out << std::endl; // separate row outputs with new line
      }
    }
    else { // select is not null, search for all matching strings and output them
      //std::cout << "select exists!" << std::endl;
      for(int i=0; i<data.size(); ++i) { // loop through rows
        //std::cout << "i: " + std::to_string(i)  << std::endl;
        if(this->select->select(this, i)) { 
          //std::cout << "match found!" << std::endl;
          for(int j=0; j<data.at(i).size(); ++j) { // loop through row's strings
            out << cell_data(i, j) << " "; // separate row element outputs with space
          }
          out << std::endl; // separate row outputs with new line
        }
      }
    }
}

void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}
