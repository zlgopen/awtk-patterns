/**
 * File:   iview.h
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

#ifndef TK_IVIEW_H
#define TK_IVIEW_H

#include "tkc/types_def.h"

BEGIN_C_DECLS

struct _iview_t;
typedef struct _iview_t iview_t;

typedef ret_t (*iview_update_t)(iview_t* view);

/**
 * @class iview_t
 *
 * 视图的接口。
 *
 */
struct _iview_t {
  iview_update_t update;
};

/**
 * @method iview_update
 * 模型变化时，通知视图更新。。
 * @param {iview_t*} view 视图对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t iview_update(iview_t* view);

END_C_DECLS

#endif /*TK_IVIEW_H*/
