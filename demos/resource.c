/**
 * File:   resource.c
 * Author: Li XianJing <xianjimli@hotmail.com>
 * Brief:  resource init
 *
 * Copyright (c) 2018 - 2018  Li XianJing <xianjimli@hotmail.com>
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
 * 2018-02-03 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "res/fonts/font20.data"
#include "res/images/checked.data"
#include "res/images/earth.data"
#include "res/images/info.data"
#include "res/images/radio_checked.data"
#include "res/images/radio_unchecked.data"
#include "res/images/unchecked.data"
#include "res/theme/theme.data"
#include "res/ui/window1.data"
#include "res/ui/dialog1.data"
#include "res/ui/dialog2.data"

#include "base/theme.h"
#include "font/font_bitmap.h"
#include "base/font_manager.h"
#include "base/image_manager.h"
#include "base/resource_manager.h"
#include "image_loader/image_loader_bitmap.h"

ret_t resource_init() {
  theme_init(theme_data);
  resource_manager_init(10);
  image_loader_t* bitmap_loader = image_loader_bitmap_create(10);
  font_manager_add(default_fm(), font_bitmap_create(font_font20));

  resource_manager_add((const resource_info_t*)ui_dialog1);
  resource_manager_add((const resource_info_t*)ui_dialog2);
  resource_manager_add((const resource_info_t*)ui_window1);
  image_loader_bitmap_add(bitmap_loader, earth);
  image_loader_bitmap_add(bitmap_loader, info);
  image_loader_bitmap_add(bitmap_loader, checked);
  image_loader_bitmap_add(bitmap_loader, unchecked);
  image_loader_bitmap_add(bitmap_loader, radio_checked);
  image_loader_bitmap_add(bitmap_loader, radio_unchecked);

  image_manager_add_loader(default_im(), bitmap_loader);

  return RET_OK;
}
