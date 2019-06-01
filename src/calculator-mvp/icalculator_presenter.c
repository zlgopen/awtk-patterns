/**
 * File:   icalculator_presenter.c
 * Author: AWTK Develop Team
 * Brief:  calculator presenter interface
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

ret_t icalculator_presenter_add_char(icalculator_presenter_t* presenter, char c) {
  return_value_if_fail(presenter != NULL && presenter->add_char != NULL, RET_BAD_PARAMS);

  return presenter->add_char(presenter, c);
}

ret_t icalculator_presenter_remove_char(icalculator_presenter_t* presenter) {
  return_value_if_fail(presenter != NULL && presenter->remove_char != NULL, RET_BAD_PARAMS);

  return presenter->remove_char(presenter);
}

ret_t icalculator_presenter_eval(icalculator_presenter_t* presenter) {
  return_value_if_fail(presenter != NULL && presenter->eval != NULL, RET_BAD_PARAMS);

  return presenter->eval(presenter);
}
