/**
 * File:   ipresenter.h
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

#ifndef TK_IPRESENTER_H
#define TK_IPRESENTER_H

#include "tkc/types_def.h"

BEGIN_C_DECLS

struct _ipresenter_t;
typedef struct _ipresenter_t ipresenter_t;

typedef ret_t (*ipresenter_on_model_changed_t)(ipresenter_t* presenter);

/**
 * @class ipresenter_t
 *
 * 呈现器的接口。
 *
 */
struct _ipresenter_t {
  ipresenter_on_model_changed_t on_model_changed;
};

/**
 * @method ipresenter_on_model_changed
 * 模型变化时，通知presenter更新视图。
 * @param {ipresenter_t*} presenter 视图对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t ipresenter_on_model_changed(ipresenter_t* presenter);

END_C_DECLS

#endif /*TK_IPRESENTER_H*/
