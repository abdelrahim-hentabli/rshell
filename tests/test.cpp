#include "testcommand.h"
#include "testconnector.h"
#include "gtest/gtest.h"


/*Command Tests*/
TEST(TEST_VALID_COMMAND, ls){
  EXPECT_EQ(0, test_valid_command());
}

TEST(TEST_INVALID_COMMAND, qs){
  EXPECT_EQ(2, test_invalid_command());
}

TEST(TEST_EMPTY_COMMAND, EMPTY){
  EXPECT_EQ(2, test_empty_command());
}

TEST(TEST_EXIT_COMMAND, EXIT){
  EXPECT_EQ(3, test_exit_command());
}

TEST(TEST_VALID_COMMAND_WITH_ARGUMENT, LS_A){
  EXPECT_EQ(0, test_valid_command_with_argument());
}

TEST(TEST_VALID_COMMAND_WITH_EMPTY_ARGUMENT, LS_){
  EXPECT_EQ(2, test_valid_command_with_empty_argument());
}

TEST(TEST_INVALID_COMMAND_WITH_ARGUMENT, QS_A){
  EXPECT_EQ(2, test_invalid_command_with_argument());
}



/*Connector Tests*/

//Or Test
TEST(OR, LS_OR_EXIT){
  EXPECT_EQ(0, test_ls_or_exit());
}

TEST(OR, QS_OR_EXIT){
  EXPECT_EQ(3, test_qs_or_exit());
}

TEST(OR, EXIT_or_LS){
  EXPECT_EQ(3, test_exit_or_ls());
}

TEST(OR, EQIT_OR_LS){
  EXPECT_EQ(0, test_eqit_or_ls());
}

TEST(OR, EQIT_OR_QS){
  EXPECT_EQ(2, test_eqit_or_qs());
}



int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
