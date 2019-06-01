/**
 * File:   calculator_controller.h
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

#ifndef TK_CALCULATOR_CONTROLLER_H
#define TK_CALCULATOR_CONTROLLER_H

#include "awtk.h"
#include "calculator.h"
#include "calculator_view.h"

BEGIN_C_DECLS

/**
 * @class calculator_controller_t
 *
 * 计算器控制器。
 *
 */
typedef struct _calculator_controller_t {
  /**
   * @property {calculator_t*} model
   * @annotation ["private"]
   * 模型对象。
   */
  calculator_t* model;
  /**
   * @property {calculator_view_t*} view
   * @annotation ["private"]
   * 视图对象。
   */
  calculator_view_t* view;
} calculator_controller_t;

/**
 * @method calculator_controller_create
 * 创建calculator_controller对象。
 * @param {calculator_view_t*} view view对象。
 * @param {calculator_model_t*} model model对象。
 *
 * @return {calculator_controller_t*} 返回calculator_controller对象。
 */
calculator_controller_t* calculator_controller_create(calculator_view_t* view, calculator_t* model);

/**
 * @method calculator_controller_destroy
 * 销毁calculator_controller对象。
 * @param {calculator_t*} calculator_controller calculator_controller对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_controller_destroy(calculator_controller_t* controller);

END_C_DECLS

#endif /*TK_CALCULATOR_CONTROLLER_H*/
