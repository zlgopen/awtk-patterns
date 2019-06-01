/**
 * File:   calculator.h
 * Author: AWTK Develop Team
 * Brief:  calculator model
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

#ifndef TK_CALCULATOR_H
#define TK_CALCULATOR_H

#include "ipresenter.h"
#include "tkc/str.h"

BEGIN_C_DECLS

/**
 * @class calculator_t
 *
 * 计算器的模型。
 *
 */
typedef struct _calculator_t {
  /**
   * @property {str_t} expr
   * @annotation ["private"]
   * 表达式当前的值。
   */
  str_t expr;

  /**
   * @property {ipresenter_t*} presenter
   * @annotation ["private"]
   * 对视图对象的引用。
   */
  ipresenter_t* presenter;
} calculator_t;

/**
 * @method calculator_create
 * 创建calculator对象。
 *
 * @return {calculator_t*} 返回calculator对象。
 */
calculator_t* calculator_create(void);

/**
 * @method calculator_add_char
 * 追加一个字符。
 * @param {calculator_t*} calculator calculator对象。
 * @param {char} c 字符。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_add_char(calculator_t* calculator, char c);

/**
 * @method calculator_remove_char
 * 删除最后一个字符。
 * @param {calculator_t*} calculator calculator对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_remove_char(calculator_t* calculator);

/**
 * @method calculator_eval
 * 计算表达式。
 * @param {calculator_t*} calculator calculator对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_eval(calculator_t* calculator);

/**
 * @method calculator_set_presenter
 * 设置presenter对象。
 * @param {calculator_t*} calculator calculator对象。
 * @param {ipresenter_t*} presenter presenter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_set_presenter(calculator_t* calculator, ipresenter_t* presenter);

/**
 * @method calculator_destroy
 * 销毁calculator对象。
 * @param {calculator_t*} calculator calculator对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t calculator_destroy(calculator_t* calculator);

END_C_DECLS

#endif /*TK_CALCULATOR_H*/
