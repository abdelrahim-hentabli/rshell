#include "testcommand.h"
#include "testconnector.h"
#include "testparse.h"
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

TEST(TEST_VALID_TEST_E_COMMAND, SRC){
  EXPECT_EQ(0, test_valid_test_e_command());
}

TEST(TEST_INVALID_TEST_E_COMMAND, S){
  EXPECT_EQ(2, test_invalid_test_e_command());
}

TEST(TEST_VALID_TEST_D_COMMAND, SRC){
  EXPECT_EQ(0, test_valid_test_d_command());
}

TEST(TEST_INVALID_TEST_D_COMMAND, TEST){
  EXPECT_EQ(2, test_invalid_test_d_command());
}

TEST(TEST_VALID_TEST_F_COMMAND, TEST){
  EXPECT_EQ(0, test_valid_test_f_command());
}

TEST(TEST_INVALID_TEST_F_COMMAND, SRC){
  EXPECT_EQ(2, test_invalid_test_f_command());
}

TEST(TEST_VALID_ONE_ARGUMENT_TEST_COMMAND, SRC){
  EXPECT_EQ(0, test_valid_one_argument_test_command());
}

TEST(TEST_INVALID_ONE_ARGUMENT_TEST_COMMAND, S){
  EXPECT_EQ(2, test_invalid_one_argument_test_command());
}

TEST(TEST_ZERO_ARGUMENT_TEST_COMMAND, EMPTY){
  EXPECT_EQ(2, test_zero_argument_test_command());
}

TEST(TEST_THREE_ARGUMENT_TEST_COMMAND, SRC_FAIL){
  EXPECT_EQ(2, test_three_argument_test_command());
}

/*Connector Tests*/

//Or Test
TEST(OR, LS_OR_EXIT){
  EXPECT_EQ(0, test_ls_or_exit());
}

TEST(OR, QS_OR_EXIT){
  EXPECT_EQ(3, test_qs_or_exit());
}

TEST(OR, EXIT_OR_LS){
  EXPECT_EQ(3, test_exit_or_ls());
}

TEST(OR, EQIT_OR_LS){
  EXPECT_EQ(0, test_eqit_or_ls());
}

TEST(OR, EQIT_OR_QS){
  EXPECT_EQ(2, test_eqit_or_qs());
}

/*Parse Tests*/
TEST(TEST_VALID_PARSE, ls){
  EXPECT_EQ(0, test_valid_parse());
}

TEST(TEST_INVALID_PARSE, qs){
  EXPECT_EQ(2, test_invalid_parse());
}

TEST(TEST_EXIT_PARSE, EXIT){
  EXPECT_EQ(3, test_exit_parse());
}

TEST(TEST_VALID_PARSE_WITH_ARGUMENT, LS_A){
  EXPECT_EQ(0, test_valid_parse_with_arg());
}

TEST(TEST_VALID_PARSE_WITH_EMPTY_ARGUMENT, LS_){
  EXPECT_EQ(0, test_valid_parse_with_empty_arg());
}

TEST(TEST_INVALID_PARSE_WITH_ARGUMENT, QS_A){
  EXPECT_EQ(2, test_invalid_parse_with_arg());
}


//And Test
TEST(AND, LS_AND_EXIT){
  EXPECT_EQ(3, test_ls_and_exit());
}

TEST(AND, QS_AND_EXIT){
  EXPECT_EQ(2, test_qs_and_exit());
}

TEST(AND, EXIT_AND_LS){
  EXPECT_EQ(3, test_exit_and_ls());
}

TEST(AND, EQIT_AND_LS){
  EXPECT_EQ(2, test_eqit_and_ls());
}

TEST(AND, EQIT_AND_QS){
  EXPECT_EQ(2, test_eqit_and_qs());
}

//And Test
TEST(SEPARATOR, LS_SEP_EXIT){
  EXPECT_EQ(3, test_ls_sep_exit());
}

TEST(SEPARATOR, QS_SEP_EXIT){
  EXPECT_EQ(3, test_qs_sep_exit());
}

TEST(SEPARATOR, EXIT_SEP_LS){
  EXPECT_EQ(3, test_exit_sep_ls());
}

TEST(SEPARATOR, EQIT_SEP_LS){
  EXPECT_EQ(0, test_eqit_sep_ls());
}

TEST(SEPARATOR, EQIT_SEP_QS){
  EXPECT_EQ(2, test_eqit_sep_qs());
}

//Comment Test
TEST(COMMENT, EXIT_COMMENT){
  EXPECT_EQ(3, test_exit_comment());
}

TEST(COMMENT, LS_COMMENT){
  EXPECT_EQ(0, test_ls_comment());
}

TEST(COMMENT, QS_COMMENT){
  EXPECT_EQ(2, test_qs_comment());
}

//Bracket Test
TEST(BRACKET, E_TEST){
  EXPECT_EQ(0, test_valid_bracket());
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
