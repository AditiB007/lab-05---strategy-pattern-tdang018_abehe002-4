#ifndef __SELECT_OR_TEST_H__
#define __SELECT_OR_TEST_H__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"

TEST(OrTest, TrueTest) {
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

  Select_Or test = new Select_Or(new Select_Contains(sheet, "Last", "Summers"),
                                 new Select_Contains(sheet, "Last", "Genius"));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 8));
}

TEST(OrTest, FalseTest) {
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

  Select_Or test = new Select_Or(new Select_Contains(sheet, "First", "Aditi"),
                                 new Select_Contains(sheet, "Last", "Behera"));
  sheet.set_selection(test);
  EXPECT_FALSE(test->select(sheet, 0));
}

TEST(OrTest, HalfHalfTest) {
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

  Select_Or test = new Select_Or(new Select_Contains(sheet, "First", "Aditi"),
                                 new Select_Contains(sheet, "Last", "Andrews"));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 0));

}

TEST(OrTest, EmptyTest) {
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

  Select_Or test = new Select_Or(new Select_Contains(sheet, "First", ""),
                                 new Select_Contains(sheet, "Last", ""));
  sheet.set_selection(test);
  EXPECT_FALSE(test->select(sheet, 1));
}

TEST(OrTest, AndTest) {
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

  Select_Or test = new Select_Or(new Select_And(new Select_Contains(sheet, "First", "Amanda"),
                                                new Select_Contains(sheet, "Last", "Andrews")),
                                 new Select_Contains(sheet, "First", "Aditi"));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 0));
}

TEST(OrTest, NotTest) {
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

  Select_Or test = new Select_Or(new Select_Not(new Select_Contains(sheet, "First", "Aditi")),
                                 new Select_Not(new Select_Contains(sheet, "Last", "Behera")));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 2));
}

#endif //__SELECT_OR_TEST_H__
