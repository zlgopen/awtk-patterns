/**
 * File:   calculator
 * Author: AWTK Develop Team
 * Brief:  main window sources
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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

#include "awtk.h"

static ret_t calculator_on_add_char(void* ctx, event_t* e) {
  wstr_t str;
  widget_t* win = WIDGET(ctx);
  widget_t* button = WIDGET(e->target);
  widget_t* expr = widget_lookup(win, "expr", TRUE); 
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  wstr_init(&str, 0);
  wstr_set(&str, expr->text.str);
  wstr_append(&str, button->text.str);
  widget_set_text(expr, str.str);
  wstr_reset(&str);

  return RET_OK;
}

static ret_t calculator_on_remove_char(void* ctx, event_t* e) {
  wstr_t str;
  widget_t* win = WIDGET(ctx);
  widget_t* expr = widget_lookup(win, "expr", TRUE); 
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  wstr_init(&str, 0);
  wstr_set(&str, expr->text.str);
  wstr_pop(&str);
  widget_set_text(expr, str.str);
  wstr_reset(&str);

  return RET_OK;
}

static ret_t calculator_on_eval(void* ctx, event_t* e) {
  str_t str;
  double result = 0;
  widget_t* win = WIDGET(ctx);
  widget_t* expr = widget_lookup(win, "expr", TRUE); 
  return_value_if_fail(expr != NULL, RET_BAD_PARAMS);

  str_init(&str, 0);
  str_from_wstr(&str, expr->text.str);
  result = tk_expr_eval(str.str);
  str_from_float(&str, result);
  widget_set_text_utf8(expr, str.str);

  str_reset(&str);

  return RET_OK;
}

ret_t application_init() {
  widget_t* win = window_open("calculator");

  widget_child_on(win, "0", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "1", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "2", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "3", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "4", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "5", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "6", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "7", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "8", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "9", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "+", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "-", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "*", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "/", EVT_CLICK, calculator_on_add_char, win);
  widget_child_on(win, "backspace", EVT_CLICK, calculator_on_remove_char, win);
  widget_child_on(win, "=", EVT_CLICK, calculator_on_eval, win);

  return RET_OK;
}


