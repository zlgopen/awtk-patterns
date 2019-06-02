#include "gtest/gtest.h"
#include "calculator-mvvm/calculator.h"

TEST(CalculatorMVVM, basic) {
  value_t expr;
  view_model_t* vm = calculator_view_model_create(NULL);
  object_t* obj = OBJECT(vm);

  ASSERT_EQ(view_model_exec(vm, "add_char", "1"), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_STREQ(value_str(&expr), "1");

  ASSERT_EQ(view_model_exec(vm, "add_char", "+"), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_STREQ(value_str(&expr), "1+");

  ASSERT_EQ(view_model_exec(vm, "add_char", "2"), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_STREQ(value_str(&expr), "1+2");

  ASSERT_EQ(view_model_exec(vm, "add_char", "="), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_STREQ(value_str(&expr), "1+2=");

  ASSERT_EQ(view_model_exec(vm, "remove_char", ""), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_STREQ(value_str(&expr), "1+2");

  ASSERT_EQ(view_model_exec(vm, "eval", ""), RET_OBJECT_CHANGED);
  ASSERT_EQ(view_model_get_prop(vm, "expr", &expr), RET_OK);
  ASSERT_EQ(value_int(&expr), 3);

  object_unref(obj);
}
