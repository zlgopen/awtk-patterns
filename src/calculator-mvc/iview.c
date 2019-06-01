/**
 * File:   iview.c
 * Author: AWTK Develop Team
 * Brief:  view interface
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

#include "iview.h"

ret_t iview_update(iview_t* view) {
  return_value_if_fail(view != NULL && view->update != NULL, RET_BAD_PARAMS);

  view->update(view);

  return RET_OK;
}
