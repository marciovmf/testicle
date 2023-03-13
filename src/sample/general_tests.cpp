#include <smol_test.h>
#include <string>

SMOL_TEST(force_success)
{
  SMOL_TEST_SUCCESS;
}

SMOL_TEST(inequality_macro)
{
  SMOL_TEST_EXPECT_NEQ(55, 99);
}

SMOL_TEST(greater_than_macro)
{
  SMOL_TEST_EXPECT_GT(42, 1);
}

SMOL_TEST(less_than_macro)
{
  SMOL_TEST_EXPECT_LT(100, 200);
}

SMOL_TEST(expect_true_macro)
{
  std::string greeting = "Hello Sailor!";
  SMOL_TEST_EXPECT_TRUE(greeting.substr(6) == "Sailor!");
}

SMOL_TEST(expect_false_macro)
{
  SMOL_TEST_EXPECT_FALSE(false);
}

SMOL_TEST(explicit_macros)
{
  int a = 0;
  int b = 0;
  if (&b > &a)
  {
    SMOL_TEST_SUCCESS;
  }
  else
  {
    SMOL_TEST_FAIL;
  }
}
