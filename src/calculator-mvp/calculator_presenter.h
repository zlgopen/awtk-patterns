/**
 * File:   calculator_presenter.h
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

#ifndef TK_CALCULATOR_PRESENTER_H
#define TK_CALCULATOR_PRESENTER_H

#include "calculator.h"
#include "icalculator_view.h"
#include "icalculator_presenter.h"

BEGIN_C_DECLS

struct _calculator_presenter_t;
typedef struct _calculator_presenter_t calculator_presenter_t;

/**
 * @class calculator_presenter_t
 * @parent icalculator_presenter_t
 * 计算器呈现器。
 *
 */
struct _calculator_presenter_t {
  icalculator_presenter_t icalculator_presenter;
};

/**
 * @method calculator_presenter_create
 * 创建呈现器对象。
 *
 * @param {icalculator_view_t*} view 视图对象。
 * @param {icalculator_t*} model 模型。
 *
 * @return {icalculator_presenter_t} 返回icalculator_presenter对象。
 */
icalculator_presenter_t* calculator_presenter_create(icalculator_view_t* view, calculator_t* model);

/**
 * @method calculator_presenter_destroy
 * 销毁呈现器对象。。
 * @param {calculator_presenter_t*} presenter calculator_presenter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_presenter_destroy(icalculator_presenter_t* presenter);

END_C_DECLS

#endif /*TK_CALCULATOR_PRESENTER_H*/
