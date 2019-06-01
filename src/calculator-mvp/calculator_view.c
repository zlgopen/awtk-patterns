/**
 * File:   calculator_view.c
 * Author: AWTK Develop Team
 * Brief:  calculator view
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
#include "calculator_view.h"

static ret_t calculator_view_on_add_char(void* ctx, event_t* e) {
  widget_t* button = WIDGET(e->target);
  icalculator_view_t* view = (icalculator_view_t*)ctx;
  return_value_if_fail(view != NULL && e != NULL && button != NULL, RET_BAD_PARAMS);

  icalculator_presenter_add_char(view->presenter, (char)(button->text.str[0]));

  return RET_OK;
}

static ret_t calculator_view_on_remove_char(void* ctx, event_t* e) {
  icalculator_view_t* view = (icalculator_view_t*)ctx;
  return_value_if_fail(view != NULL && e != NULL, RET_BAD_PARAMS);

  icalculator_presenter_remove_char(view->presenter);

  return RET_OK;
}

static ret_t calculator_view_on_eval(void* ctx, event_t* e) {
  icalculator_view_t* view = (icalculator_view_t*)ctx;
  return_value_if_fail(view != NULL && e != NULL, RET_BAD_PARAMS);

  icalculator_presenter_eval(view->presenter);

  return RET_OK;
}

static ret_t calculator_view_set_expr(icalculator_view_t* view, const char* str) {
  widget_t* expr = NULL;
  calculator_view_t* calculator_view = (calculator_view_t*)(view);
  return_value_if_fail(calculator_view != NULL, RET_BAD_PARAMS);

  expr = widget_lookup(calculator_view->window, "expr", TRUE);
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  return widget_set_text_utf8(expr, str);
}

ret_t calculator_view_get_expr(icalculator_view_t* view, str_t* str) {
  widget_t* expr = NULL;
  calculator_view_t* calculator_view = (calculator_view_t*)(view);
  return_value_if_fail(calculator_view != NULL, RET_BAD_PARAMS);

  expr = widget_lookup(calculator_view->window, "expr", TRUE);
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  return str_from_wstr(str, expr->text.str);
}

static ret_t calculator_view_init(calculator_view_t* view) {
  widget_t* win = view->window;

  widget_child_on(win, "0", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "1", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "2", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "3", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "4", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "5", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "6", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "7", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "8", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "9", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "+", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "-", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "*", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "/", EVT_CLICK, calculator_view_on_add_char, view);
  widget_child_on(win, "backspace", EVT_CLICK, calculator_view_on_remove_char, view);
  widget_child_on(win, "=", EVT_CLICK, calculator_view_on_eval, view);

  return RET_OK;
}

icalculator_view_t* calculator_view_create(widget_t* window) {
  calculator_view_t* view = NULL;
  icalculator_view_t* iview = NULL;

  return_value_if_fail(window != NULL, NULL);
  view = TKMEM_ZALLOC(calculator_view_t);
  return_value_if_fail(view != NULL, NULL);

  view->window = window;
  calculator_view_init(view);

  iview = (icalculator_view_t*)view;
  iview->set_expr = calculator_view_set_expr;
  iview->get_expr = calculator_view_get_expr;

  return (icalculator_view_t*)view;
}

ret_t calculator_view_set_presenter(icalculator_view_t* view, icalculator_presenter_t* presenter) {
  return_value_if_fail(view != NULL && presenter != NULL, RET_BAD_PARAMS);

  view->presenter = presenter;

  return RET_OK;
}

ret_t calculator_view_destroy(icalculator_view_t* view) {
  return_value_if_fail(view != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(view);

  return RET_OK;
}
