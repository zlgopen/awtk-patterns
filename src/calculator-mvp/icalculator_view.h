/**
 * File:   icalculator_view.h
 * Author: AWTK Develop Team
 * Brief:  calculator view interface
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

#ifndef TK_ICALCULATOR_VIEW_H
#define TK_ICALCULATOR_VIEW_H

#include "awtk.h"
#include "types_def.h"
#include "icalculator_presenter.h"

BEGIN_C_DECLS

typedef ret_t (*icalculator_view_set_expr_t)(icalculator_view_t* p, const char* expr);
typedef ret_t (*icalculator_view_get_expr_t)(icalculator_view_t* p, str_t* str);

/**
 * @class icalculator_view_t
 *
 * 计算器呈现器接口。
 *
 */
struct _icalculator_view_t {
  /**
   * @property {icalculator_presenter_t*} presenter
   * @annotation ["private"]
   * presenter对象。
   */
  icalculator_presenter_t* presenter;

  icalculator_view_set_expr_t set_expr;
  icalculator_view_get_expr_t get_expr;
};

/**
 * @method icalculator_view_set_expr
 * 设置表达式到视图。
 * @param {icalculator_view_t*} view icalculator_view对象。
 * @param {const char*} expr 表达式。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t icalculator_view_set_expr(icalculator_view_t* view, const char* expr);

/**
 * @method icalculator_view_get_expr
 * 从视图获取表达式。
 * @param {icalculator_view_t*} view icalculator_view对象。
 * @param {str_t*} expr 用于返回表达式。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t icalculator_view_get_expr(icalculator_view_t* view, str_t* expr);

END_C_DECLS

#endif /*TK_ICALCULATOR_VIEW_H*/
