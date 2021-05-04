#ifndef __SELECT_AND_H__
#define __SELECT_AND_H__

#include "select.hpp"

using namespace std;

class Select_And: public Select {
  private:
    Select* select1;
    Select* select2;

  public:
    Select_And(Select* selectPar1, Select* selectPar2): select1(selectPar1), select2(selectPar2) {}

    bool select(const Spreadsheet* sheet, int row) const {
      bool store1 = select1->select(sheet, row);
      bool store2 = select2->select(sheet, row);

      if((store1 == true) && (store2 == true)) {
        return true;
      }
      else {
        return false;
      }
    }
};

#endif //__SELECT_AND_H__
