#ifndef __SELECT_CONTAINS_TEST_H__
#define __SELECT_CONTAINS_TEST_H__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"

#include "select_contains.h"
#include "Select_And.h"
#include "Select_Or.h"
#include "Select_Not.h"

TEST(ContainsTest, TrueTest) {
  Spreadsheet sheet;
  sheet.set_column_names({"First","Last","Age","Major"});
  sheet.add_row({"Amanda","Andrews","22","business"});
  sheet.add_row({"Brian","Becker","21","computer science"});
  sheet.add_row({"Carol","Conners","21","computer science"});
  sheet.add_row({"Joe","Jackson","21","mathematics"});
  sheet.add_row({"Sarah","Summers","21","computer science"});
  sheet.add_row({"Diane","Dole","20","computer engineering"});
  sheet.add_row({"David","Dole","22","electrical engineering"});
  sheet.add_row({"Dominick","Dole","22","communications"});
  sheet.add_row({"George","Genius","9","astrophysics"});

  
Select_Contains* test = new Select_Contains(&sheet, "First", "George");
 sheet.set_selection(test);
 EXPECT_TRUE(test->select(&sheet, 8));
}

TEST(ContainsTest, FalseTest) {
  Spreadsheet sheet;
  sheet.set_column_names({"First","Last","Age","Major"});
  sheet.add_row({"Amanda","Andrews","22","business"});
  sheet.add_row({"Brian","Becker","21","computer science"});
  sheet.add_row({"Carol","Conners","21","computer science"});
  sheet.add_row({"Joe","Jackson","21","mathematics"});
  sheet.add_row({"Sarah","Summers","21","computer science"});
  sheet.add_row({"Diane","Dole","20","computer engineering"});
  sheet.add_row({"David","Dole","22","electrical engineering"});
  sheet.add_row({"Dominick","Dole","22","communications"});
  sheet.add_row({"George","Genius","9","astrophysics"});

  Select_Contains* test = new Select_Contains(&sheet, "First", "Aditi");
  sheet.set_selection(test);
  EXPECT_FALSE(test->select(&sheet, 0));
}

TEST(ContainsTest, EmptyTest) {
  Spreadsheet sheet;
  sheet.set_column_names({"First","Last","Age","Major"});
  sheet.add_row({"Amanda","Andrews","22","business"});
  sheet.add_row({"Brian","Becker","21","computer science"});
  sheet.add_row({"Carol","Conners","21","computer science"});
  sheet.add_row({"Joe","Jackson","21","mathematics"});
  sheet.add_row({"Sarah","Summers","21","computer science"});
  sheet.add_row({"Diane","Dole","20","computer engineering"});
  sheet.add_row({"David","Dole","22","electrical engineering"});
  sheet.add_row({"Dominick","Dole","22","communications"});
  sheet.add_row({"George","Genius","9","astrophysics"});

  Select_Contains* test = new Select_Contains(&sheet, "First", " ");
  sheet.set_selection(test);
  EXPECT_FALSE(test->select(&sheet, 1));
}

#endif //__SELECT_CONTAINS_TEST_H__
