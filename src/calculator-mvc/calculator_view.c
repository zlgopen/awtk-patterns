/**
 * File:   calculator_view.c
 * Author: AWTK Develop Team
 * Brief:  calculator_view
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

#include "calculator_view.h"

static ret_t calculator_view_update(iview_t* view) {
  widget_t* expr = NULL;
  calculator_view_t* calculator_view = (calculator_view_t*)(view);
  return_value_if_fail(calculator_view != NULL, RET_BAD_PARAMS);

  expr = widget_lookup(calculator_view->window, "expr", TRUE);
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  widget_set_text_utf8(expr, calculator_view->model->expr.str);

  return RET_OK;
}

ret_t calculator_view_destroy(calculator_view_t* view) {
  return_value_if_fail(view != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(view);

  return RET_OK;
}

calculator_view_t* calculator_view_create(widget_t* window, calculator_t* model) {
  calculator_view_t* view = NULL;
  return_value_if_fail(window != NULL && model != NULL, NULL);

  view = TKMEM_ZALLOC(calculator_view_t);
  return_value_if_fail(view != NULL, NULL);

  view->model = model;
  view->window = window;
  view->view.update = calculator_view_update;

  return view;
}
