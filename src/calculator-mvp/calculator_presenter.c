/**
 * File:   calculator_presenter.c
 * Author: AWTK Develop Team
 * Brief:  calculator presenter
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

#include "calculator.h"
#include "icalculator_view.h"
#include "calculator_presenter.h"
#include "icalculator_presenter.h"

static ret_t presenter_on_model_changed(ipresenter_t* presenter) {
  icalculator_presenter_t* p = (icalculator_presenter_t*)presenter;

  icalculator_view_set_expr(p->view, p->model->expr.str);

  return RET_OK;
}

static ret_t calculator_presenter_add_char(icalculator_presenter_t* presenter, char c) {
  return calculator_add_char(presenter->model, c);
}

static ret_t calculator_presenter_remove_char(icalculator_presenter_t* presenter) {
  return calculator_remove_char(presenter->model);
}

static ret_t calculator_presenter_eval(icalculator_presenter_t* presenter) {
  return calculator_eval(presenter->model);
}

icalculator_presenter_t* calculator_presenter_create(icalculator_view_t* view,
                                                     calculator_t* model) {
  ipresenter_t* ipresenter = NULL;
  calculator_presenter_t* calculator_presenter = NULL;
  icalculator_presenter_t* icalculator_presenter = NULL;
  return_value_if_fail(view != NULL && model != NULL, NULL);

  calculator_presenter = TKMEM_ZALLOC(calculator_presenter_t);
  return_value_if_fail(calculator_presenter != NULL, NULL);

  icalculator_presenter = (icalculator_presenter_t*)calculator_presenter;

  icalculator_presenter->view = view;
  icalculator_presenter->model = model;
  icalculator_presenter->eval = calculator_presenter_eval;
  icalculator_presenter->add_char = calculator_presenter_add_char;
  icalculator_presenter->remove_char = calculator_presenter_remove_char;

  ipresenter = (ipresenter_t*)calculator_presenter;
  ipresenter->on_model_changed = presenter_on_model_changed;

  return icalculator_presenter;
}

ret_t calculator_presenter_destroy(icalculator_presenter_t* presenter) {
  return_value_if_fail(presenter != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(presenter);

  return RET_OK;
}
