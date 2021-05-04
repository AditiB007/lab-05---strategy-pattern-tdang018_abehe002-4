#ifndef __SELECT_NOT_TEST_H__
#define __SELECT_NOT_TEST_H__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include "Select_Not.h"
#include "select_contains.h"
#include "Select_And.h"
#include "Select_Or.h"

#include <vector>

TEST(NotTest, TrueTest) {
  Spreadsheet sheet;
  //const std::vector<std::string> names = {"First","Last","Age","Major"};
  sheet.set_column_names({"First","Last","Age","Major"});
  //sheet.add_row({"Amanda","Andrews","22","business"});
  //sheet.add_row({"Brian","Becker","21","computer science"});
  //sheet.add_row({"Carol","Conners","21","computer science"});
  //sheet.add_row({"Joe","Jackson","21","mathematics"});
  //sheet.add_row({"Sarah","Summers","21","computer science"});
  //sheet.add_row({"Diane","Dole","20","computer engineering"});
  //sheet.add_row({"David","Dole","22","electrical engineering"});
  //sheet.add_row({"Dominick","Dole","22","communications"});
  //sheet.add_row({"George","Genius","9","astrophysics"});

  //Select_Not* test = new Select_Not(new Select_Contains(&sheet, "First", "George"));
  //sheet.set_selection(test);
  //EXPECT_TRUE(test->select(&sheet, 7));
}
/*
TEST(NotTest, FalseTest) {
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

  Select_Not test = new Select_Not(new Select_Contains(sheet, "First", "Amanda"));
  sheet.set_selection(test);
  EXPECT_FALSE(test->select(sheet, 0));
}

TEST(NotTest, EmptyTest) {
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

  Select_Not test = new Select_Not(new Select_Contains(sheet, "First", ""));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 1));
}

TEST(NotTest, OrTest) {
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

  Select_Not test = new Select_Not(new Select_Or(new Select_Contains(sheet, "First", "Aditi"),
                                                 new Select_Contains(sheet, "First", "Amanda")));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 1));
}

TEST(NotTest, AndTest) {
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

  Select_Not test = new Select_Not(new Select_And(new Select_Contains(sheet, "First", "Aditi"),
                                                  new Select_Contains(sheet, "Last", "Behera"));
  sheet.set_selection(test);
  EXPECT_TRUE(test->select(sheet, 2));
}
*/
#endif //__SELECT_NOT_TEST_H__
