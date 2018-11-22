#include "commandtest.h"

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

TEST(TEST_VALID_COMMAND_WITH_ARGUMENT, LS-A){
  EXPECT_EQ(0, test_valid_command_with_argument);
}
