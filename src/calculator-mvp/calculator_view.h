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
#include "calculator_view.h"
#include "calculator_presenter.h"

BEGIN_C_DECLS

struct _calculator_view_t;
typedef struct _calculator_view_t calculator_view_t;

/**
 * @class calculator_view_t
 * @parent icalculator_view_t
 *
 * 计算器视图。
 *
 */
struct _calculator_view_t {
  icalculator_view_t icalculator_view;

  widget_t* window;
};

/**
 * @method calculator_view_create
 * 创建视图对象。
 *
 * @param {calculator_view_t*} view calculator_view对象。
 * @param {widget_t*} window 窗口对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
icalculator_view_t* calculator_view_create(widget_t* window);

/**
 * @method calculator_view_set_presenter
 * 设置presenter对象。
 *
 * @param {icalculator_view_t*} view calculator_view对象。
 * @param {icalculator_presenter_t*} presenter 呈现器。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_view_set_presenter(icalculator_view_t* view, icalculator_presenter_t* presenter);

/**
 * @method calculator_view_destroy
 * 销毁视图对象。
 *
 * @param {icalculator_view_t*} view calculator_view对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_view_destroy(icalculator_view_t* view);

END_C_DECLS

#endif /*TK_CALCULATOR_VIEW_H*/
