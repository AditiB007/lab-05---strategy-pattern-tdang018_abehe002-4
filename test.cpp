#include "spreadsheet.hpp"
#include "Select_Not_Test.h"
#include "Select_And_Test.h"
//#include "Select_Or_Test.h"

#include "gtest/gtest.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
