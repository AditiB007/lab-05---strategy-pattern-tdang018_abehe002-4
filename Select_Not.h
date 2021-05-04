#ifndef __SELECT_NOT_H__
#define __SELECT_NOT_H__

#include "select.hpp"

class Select_Not: public Select {
  private:
    Select* selection;

  public:
    Select_Not(Select* selectPar) {
      selection = selectPar;
    }

    bool select(const Spreadsheet* sheet, int row) const {
      return !(selection->select(sheet, row)); 
    }
};

#endif //__SELECT_NOT_H__
