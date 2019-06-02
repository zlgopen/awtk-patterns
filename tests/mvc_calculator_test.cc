#include "gtest/gtest.h"
#include "calculator-mvc/calculator.h"

TEST(CalculatorMVC, basic) {
  calculator_t* calculator = calculator_create();

  ASSERT_STREQ(calculator->expr.str, "");
  ASSERT_EQ(calculator_add_char(calculator, '1'), RET_OK);
  ASSERT_EQ(calculator_add_char(calculator, '+'), RET_OK);
  ASSERT_EQ(calculator_add_char(calculator, '1'), RET_OK);
  ASSERT_EQ(calculator_add_char(calculator, '2'), RET_OK);
  ASSERT_STREQ(calculator->expr.str, "1+1=");
  ASSERT_EQ(calculator_remove_char(calculator), RET_OK);
  ASSERT_STREQ(calculator->expr.str, "1+1");
  ASSERT_EQ(calculator_eval(calculator), RET_OK);
  ASSERT_STREQ(calculator->expr.str, "2.0000");

  calculator_destroy(calculator);
}
