#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
#include "assets/default/inc/strings/en_US.data"
#include "assets/default/inc/strings/zh_CN.data"
#include "assets/default/inc/styles/default.data"
#include "assets/default/inc/ui/calculator.data"
#ifdef WITH_STB_IMAGE
#include "assets/default/inc/images/arrow_down_n.res"
#include "assets/default/inc/images/arrow_down_o.res"
#include "assets/default/inc/images/arrow_down_p.res"
#include "assets/default/inc/images/arrow_left_n.res"
#include "assets/default/inc/images/arrow_left_o.res"
#include "assets/default/inc/images/arrow_left_p.res"
#include "assets/default/inc/images/arrow_right_n.res"
#include "assets/default/inc/images/arrow_right_o.res"
#include "assets/default/inc/images/arrow_right_p.res"
#include "assets/default/inc/images/arrow_up_n.res"
#include "assets/default/inc/images/arrow_up_o.res"
#include "assets/default/inc/images/arrow_up_p.res"
#include "assets/default/inc/images/check.res"
#include "assets/default/inc/images/checked.res"
#include "assets/default/inc/images/earth.res"
#include "assets/default/inc/images/edit_clear_n.res"
#include "assets/default/inc/images/edit_clear_o.res"
#include "assets/default/inc/images/edit_clear_p.res"
#include "assets/default/inc/images/empty.res"
#include "assets/default/inc/images/radio_checked.res"
#include "assets/default/inc/images/radio_unchecked.res"
#include "assets/default/inc/images/unchecked.res"
#else
#include "assets/default/inc/images/arrow_down_n.data"
#include "assets/default/inc/images/arrow_down_o.data"
#include "assets/default/inc/images/arrow_down_p.data"
#include "assets/default/inc/images/arrow_left_n.data"
#include "assets/default/inc/images/arrow_left_o.data"
#include "assets/default/inc/images/arrow_left_p.data"
#include "assets/default/inc/images/arrow_right_n.data"
#include "assets/default/inc/images/arrow_right_o.data"
#include "assets/default/inc/images/arrow_right_p.data"
#include "assets/default/inc/images/arrow_up_n.data"
#include "assets/default/inc/images/arrow_up_o.data"
#include "assets/default/inc/images/arrow_up_p.data"
#include "assets/default/inc/images/check.data"
#include "assets/default/inc/images/checked.data"
#include "assets/default/inc/images/earth.data"
#include "assets/default/inc/images/edit_clear_n.data"
#include "assets/default/inc/images/edit_clear_o.data"
#include "assets/default/inc/images/edit_clear_p.data"
#include "assets/default/inc/images/empty.data"
#include "assets/default/inc/images/radio_checked.data"
#include "assets/default/inc/images/radio_unchecked.data"
#include "assets/default/inc/images/unchecked.data"
#endif /*WITH_STB_IMAGE*/
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#if defined(WITH_STB_FONT) || defined(WITH_FT_FONT)
#include "assets/default/inc/fonts/ap.res"
#include "assets/default/inc/fonts/default.res"
#include "assets/default/inc/fonts/default_full.res"
#else/*WITH_STB_FONT or WITH_FT_FONT*/
#include "assets/default/inc/fonts/default_16.data"
#include "assets/default/inc/fonts/default_18.data"
#include "assets/default/inc/fonts/default_20.data"
#include "assets/default/inc/fonts/default_24.data"
#include "assets/default/inc/fonts/default_32.data"
#include "assets/default/inc/fonts/default_96.data"
#endif /*WITH_STB_FONT or WITH_FT_FONT*/
#endif /*WITH_FS_RES*/

ret_t assets_init_default(void) {
  assets_manager_t* am = assets_manager();

#ifdef WITH_FS_RES
  assets_manager_preload(am, ASSET_TYPE_FONT, "default");
  assets_manager_preload(am, ASSET_TYPE_STYLE, "default");
#else
  assets_manager_add(am, strings_en_US);
  assets_manager_add(am, strings_zh_CN);
  assets_manager_add(am, style_default);
  assets_manager_add(am, ui_calculator);
  assets_manager_add(am, image_arrow_down_n);
  assets_manager_add(am, image_arrow_down_o);
  assets_manager_add(am, image_arrow_down_p);
  assets_manager_add(am, image_arrow_left_n);
  assets_manager_add(am, image_arrow_left_o);
  assets_manager_add(am, image_arrow_left_p);
  assets_manager_add(am, image_arrow_right_n);
  assets_manager_add(am, image_arrow_right_o);
  assets_manager_add(am, image_arrow_right_p);
  assets_manager_add(am, image_arrow_up_n);
  assets_manager_add(am, image_arrow_up_o);
  assets_manager_add(am, image_arrow_up_p);
  assets_manager_add(am, image_check);
  assets_manager_add(am, image_checked);
  assets_manager_add(am, image_earth);
  assets_manager_add(am, image_edit_clear_n);
  assets_manager_add(am, image_edit_clear_o);
  assets_manager_add(am, image_edit_clear_p);
  assets_manager_add(am, image_empty);
  assets_manager_add(am, image_radio_checked);
  assets_manager_add(am, image_radio_unchecked);
  assets_manager_add(am, image_unchecked);
#if defined(WITH_STB_FONT) || defined(WITH_FT_FONT)
  assets_manager_add(am, font_ap);
  assets_manager_add(am, font_default);
  assets_manager_add(am, font_default_full);
#else /*WITH_STB_FONT or WITH_FT_FONT*/
  assets_manager_add(am, font_default_16);
  assets_manager_add(am, font_default_18);
  assets_manager_add(am, font_default_20);
  assets_manager_add(am, font_default_24);
  assets_manager_add(am, font_default_32);
  assets_manager_add(am, font_default_96);
#endif /*WITH_STB_FONT or WITH_FT_FONT*/
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#endif

  tk_init_assets();
  return RET_OK;
}
