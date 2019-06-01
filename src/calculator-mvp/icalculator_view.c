/**
 * File:   icalculator_view.c
 * Author: AWTK Develop Team
 * Brief:  calculator view interface
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

#include "icalculator_view.h"
#include "icalculator_presenter.h"

ret_t icalculator_view_set_expr(icalculator_view_t* view, const char* expr) {
  return_value_if_fail(view != NULL && view->set_expr != NULL && expr != NULL, RET_BAD_PARAMS);

  return view->set_expr(view, expr);
}

ret_t icalculator_view_get_expr(icalculator_view_t* view, str_t* expr) {
  return_value_if_fail(view != NULL && view->get_expr != NULL && expr != NULL, RET_BAD_PARAMS);

  return view->get_expr(view, expr);
}
