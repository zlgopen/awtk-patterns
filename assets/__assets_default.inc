#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
#include "default/inc/strings/zh_CN.data"
#include "default/inc/strings/en_US.data"
#include "default/inc/styles/default.data"
#include "default/inc/ui/calculator.data"
#ifdef WITH_STB_IMAGE
#include "default/inc/images/checked.res"
#include "default/inc/images/earth.res"
#include "default/inc/images/arrow_up_n.res"
#include "default/inc/images/arrow_right_p.res"
#include "default/inc/images/empty.res"
#include "default/inc/images/edit_clear_p.res"
#include "default/inc/images/arrow_up_o.res"
#include "default/inc/images/arrow_left_o.res"
#include "default/inc/images/arrow_left_n.res"
#include "default/inc/images/radio_checked.res"
#include "default/inc/images/check.res"
#include "default/inc/images/arrow_down_n.res"
#include "default/inc/images/arrow_down_o.res"
#include "default/inc/images/unchecked.res"
#include "default/inc/images/arrow_down_p.res"
#include "default/inc/images/radio_unchecked.res"
#include "default/inc/images/arrow_up_p.res"
#include "default/inc/images/edit_clear_o.res"
#include "default/inc/images/arrow_right_n.res"
#include "default/inc/images/arrow_right_o.res"
#include "default/inc/images/edit_clear_n.res"
#include "default/inc/images/arrow_left_p.res"
#else
#include "default/inc/images/arrow_right_o.data"
#include "default/inc/images/earth.data"
#include "default/inc/images/arrow_up_p.data"
#include "default/inc/images/arrow_right_n.data"
#include "default/inc/images/checked.data"
#include "default/inc/images/arrow_right_p.data"
#include "default/inc/images/arrow_up_o.data"
#include "default/inc/images/empty.data"
#include "default/inc/images/radio_unchecked.data"
#include "default/inc/images/arrow_up_n.data"
#include "default/inc/images/arrow_left_p.data"
#include "default/inc/images/edit_clear_n.data"
#include "default/inc/images/arrow_down_p.data"
#include "default/inc/images/edit_clear_o.data"
#include "default/inc/images/arrow_left_o.data"
#include "default/inc/images/check.data"
#include "default/inc/images/arrow_down_o.data"
#include "default/inc/images/radio_checked.data"
#include "default/inc/images/unchecked.data"
#include "default/inc/images/arrow_down_n.data"
#include "default/inc/images/arrow_left_n.data"
#include "default/inc/images/edit_clear_p.data"
#endif /*WITH_STB_IMAGE*/
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#ifdef WITH_TRUETYPE_FONT
#include "default/inc/fonts/ap.res"
#include "default/inc/fonts/default_full.res"
#include "default/inc/fonts/default.res"
#else /*WITH_TRUETYPE_FONT*/
#endif /*WITH_TRUETYPE_FONT*/
#endif /*WITH_FS_RES*/

ret_t assets_init_default(void) {
  assets_manager_t* am = assets_manager();

#ifdef WITH_FS_RES
  assets_manager_preload(am, ASSET_TYPE_FONT, "default");
  assets_manager_preload(am, ASSET_TYPE_STYLE, "default");
#else
  assets_manager_add(am, strings_zh_CN);
  assets_manager_add(am, strings_en_US);
  assets_manager_add(am, style_default);
  assets_manager_add(am, ui_calculator);
  assets_manager_add(am, image_checked);
  assets_manager_add(am, image_earth);
  assets_manager_add(am, image_arrow_up_n);
  assets_manager_add(am, image_arrow_right_p);
  assets_manager_add(am, image_empty);
  assets_manager_add(am, image_edit_clear_p);
  assets_manager_add(am, image_arrow_up_o);
  assets_manager_add(am, image_arrow_left_o);
  assets_manager_add(am, image_arrow_left_n);
  assets_manager_add(am, image_radio_checked);
  assets_manager_add(am, image_check);
  assets_manager_add(am, image_arrow_down_n);
  assets_manager_add(am, image_arrow_down_o);
  assets_manager_add(am, image_unchecked);
  assets_manager_add(am, image_arrow_down_p);
  assets_manager_add(am, image_radio_unchecked);
  assets_manager_add(am, image_arrow_up_p);
  assets_manager_add(am, image_edit_clear_o);
  assets_manager_add(am, image_arrow_right_n);
  assets_manager_add(am, image_arrow_right_o);
  assets_manager_add(am, image_edit_clear_n);
  assets_manager_add(am, image_arrow_left_p);
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#ifdef WITH_TRUETYPE_FONT
  assets_manager_add(am, font_ap);
  assets_manager_add(am, font_default_full);
  assets_manager_add(am, font_default);
#else /*WITH_TRUETYPE_FONT*/
#endif /*WITH_TRUETYPE_FONT*/
#endif

  tk_init_assets();
  return RET_OK;
}
