/**
 * File:   ipresenter.c
 * Author: AWTK Develop Team
 * Brief:  presenter interface
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

#include "ipresenter.h"

ret_t ipresenter_on_model_changed(ipresenter_t* presenter) {
  return_value_if_fail(presenter != NULL && presenter->on_model_changed != NULL, RET_BAD_PARAMS);

  presenter->on_model_changed(presenter);

  return RET_OK;
}
