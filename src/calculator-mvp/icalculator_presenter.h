/**
 * File:   icalculator_presenter.h
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

#ifndef TK_ICALCULATOR_PRESENTER_H
#define TK_ICALCULATOR_PRESENTER_H

#include "awtk.h"
#include "types_def.h"
#include "ipresenter.h"
#include "calculator.h"

BEGIN_C_DECLS

struct _icalculator_presenter_t;
typedef struct _icalculator_presenter_t icalculator_presenter_t;

typedef ret_t (*icalculator_presenter_add_char_t)(icalculator_presenter_t* p, char c);
typedef ret_t (*icalculator_presenter_remove_char_t)(icalculator_presenter_t* p);
typedef ret_t (*icalculator_presenter_eval_t)(icalculator_presenter_t* p);

/**
 * @class icalculator_presenter_t
 * @parent ipresenter_t
 * 计算器呈现器接口。
 *
 */
struct _icalculator_presenter_t {
  ipresenter_t ipresenter;
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
  icalculator_view_t* view;

  /*private*/
  icalculator_presenter_eval_t eval;
  icalculator_presenter_add_char_t add_char;
  icalculator_presenter_remove_char_t remove_char;
};

/**
 * @method icalculator_presenter_add_char
 * 追加一个字符。
 * @param {icalculator_presenter_t*} presenter icalculator_presenter对象。
 * @param {char} c 要追加的字符。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t icalculator_presenter_add_char(icalculator_presenter_t* presenter, char c);

/**
 * @method icalculator_presenter_remove_char
 * 删除一个字符。
 * @param {icalculator_presenter_t*} presenter icalculator_presenter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t icalculator_presenter_remove_char(icalculator_presenter_t* presenter);

/**
 * @method icalculator_presenter_eval
 * 计算表达式。
 * @param {icalculator_presenter_t*} presenter icalculator_presenter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t icalculator_presenter_eval(icalculator_presenter_t* presenter);

END_C_DECLS

#endif /*TK_ICALCULATOR_PRESENTER_H*/
