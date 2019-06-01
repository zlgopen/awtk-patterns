/**
 * File:   calculator.c
 * Author: AWTK Develop Team
 * Brief:  calculator model
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-06-01 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "tkc/expr_eval.h"
#include "calculator.h"

calculator_t* calculator_create(void) {
  calculator_t* calculator = TKMEM_ZALLOC(calculator_t);
  return_value_if_fail(calculator != NULL, NULL);

  str_init(&(calculator->expr), 10);

  return calculator;
}

ret_t calculator_destroy(calculator_t* calculator) {
  return_value_if_fail(calculator != NULL, RET_BAD_PARAMS);

  str_reset(&(calculator->expr));

  TKMEM_FREE(calculator);

  return RET_OK;
}

ret_t calculator_add_char(calculator_t* calculator, char c) {
  str_append_char(&(calculator->expr), c);
  iview_update(calculator->view);

  return RET_OK;
}

ret_t calculator_remove_char(calculator_t* calculator) {
  str_pop(&(calculator->expr));
  iview_update(calculator->view);

  return RET_OK;
}

ret_t calculator_eval(calculator_t* calculator) {
  str_from_float(&(calculator->expr), tk_expr_eval(calculator->expr.str));
  iview_update(calculator->view);

  return RET_OK;
}

ret_t calculator_set_view(calculator_t* calculator, iview_t* view) {
  return_value_if_fail(calculator != NULL && view != NULL, RET_BAD_PARAMS);

  calculator->view = view;

  return RET_OK;
}
