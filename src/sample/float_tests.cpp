#include <smol_test.h>

SMOL_TEST(float_equality_macro)
{
  float a = 0.45f;
  float b = 0.4499999f;
  SMOL_TEST_EXPECT_FLOAT_EQ(a, b);
}

SMOL_TEST(float_inequality_macro)
{
  float a = 0.45f;
  float b = 0.41f;
  SMOL_TEST_EXPECT_FLOAT_NEQ(a, b);
}
