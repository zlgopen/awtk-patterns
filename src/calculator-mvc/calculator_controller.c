/**
 * File:   calculator_controller.c
 * Author: AWTK Develop Team
 * Brief:  calculator controller
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

#include "calculator_controller.h"

static ret_t calculator_controller_on_add_char(void* ctx, event_t* e) {
  widget_t* button = WIDGET(e->target);
  calculator_controller_t* controller = (calculator_controller_t*)ctx;
  return_value_if_fail(controller != NULL && e != NULL && button != NULL, RET_BAD_PARAMS);

  calculator_add_char(controller->model, (char)(button->text.str[0]));

  return RET_OK;
}

static ret_t calculator_controller_on_remove_char(void* ctx, event_t* e) {
  calculator_controller_t* controller = (calculator_controller_t*)ctx;
  return_value_if_fail(controller != NULL && e != NULL, RET_BAD_PARAMS);

  calculator_remove_char(controller->model);

  return RET_OK;
}

static ret_t calculator_controller_on_eval(void* ctx, event_t* e) {
  calculator_controller_t* controller = (calculator_controller_t*)ctx;
  return_value_if_fail(controller != NULL && e != NULL, RET_BAD_PARAMS);

  calculator_eval(controller->model);

  return RET_OK;
}

static ret_t calculator_controller_init(calculator_controller_t* controller) {
  widget_t* win = controller->view->window;

  widget_child_on(win, "0", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "1", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "2", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "3", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "4", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "5", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "6", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "7", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "8", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "9", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "+", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "-", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "*", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "/", EVT_CLICK, calculator_controller_on_add_char, controller);
  widget_child_on(win, "backspace", EVT_CLICK, calculator_controller_on_remove_char, controller);
  widget_child_on(win, "=", EVT_CLICK, calculator_controller_on_eval, controller);

  return RET_OK;
}

calculator_controller_t* calculator_controller_create(calculator_view_t* view,
                                                      calculator_t* model) {
  calculator_controller_t* controller = NULL;
  return_value_if_fail(view != NULL && view->window != NULL && model != NULL, NULL);

  controller = TKMEM_ZALLOC(calculator_controller_t);
  return_value_if_fail(controller != NULL, NULL);

  controller->view = view;
  controller->model = model;
  calculator_controller_init(controller);

  return controller;
}

ret_t calculator_controller_destroy(calculator_controller_t* controller) {
  return_value_if_fail(controller != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(controller);

  return RET_OK;
}
