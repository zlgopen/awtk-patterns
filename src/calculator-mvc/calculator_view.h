/**
 * File:   calculator_view.h
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

#ifndef TK_CALCULATOR_VIEW_H
#define TK_CALCULATOR_VIEW_H

#include "awtk.h"
#include "iview.h"
#include "calculator.h"

BEGIN_C_DECLS

/**
 * @class calculator_view_t
 * @parent view
 * 计算器视图。
 *
 */
typedef struct _calculator_view_t {
  iview_t view;

  /**
   * @property {calculator_t*} model
   * @annotation ["private"]
   * 模型对象。
   */
  calculator_t* model;

  /**
   * @property {window_t*} window
   * @annotation ["readonly"]
   * 窗口对象。
   */
  widget_t* window;
} calculator_view_t;

/**
 * @method calculator_view_create
 * 创建calculator_view对象。
 * @param {calculator_view_t*} view view对象。
 * @param {calculator_model_t*} model model对象。
 *
 * @return {calculator_view_t*} 返回calculator_view对象。
 */
calculator_view_t* calculator_view_create(widget_t* window, calculator_t* model);

/**
 * @method calculator_view_destroy
 * 销毁calculator_view对象。
 * @param {calculator_t*} calculator_view calculator_view对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_view_destroy(calculator_view_t* view);

END_C_DECLS

#endif /*TK_CALCULATOR_VIEW_H*/
