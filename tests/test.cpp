#include "testcommand.h"

#include "gtest/gtest.h"

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

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
