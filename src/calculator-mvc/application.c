/**
 * File:   application.c
 * Author: AWTK Develop Team
 * Brief:  application entry
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

#include "calculator.h"
#include "calculator_view.h"
#include "calculator_controller.h"

typedef struct _application_t {
  calculator_t* model;
  calculator_view_t* view;
  calculator_controller_t* controller;
} application_t;

static application_t s_app;

static ret_t application_quit(void* ctx, event_t* e) {
  application_t* app = (application_t*)ctx;

  calculator_destroy(app->model);
  calculator_view_destroy(app->view);
  calculator_controller_destroy(app->controller);

  return RET_REMOVE;
}

ret_t application_init() {
  application_t* app = &s_app;
  widget_t* win = window_open("calculator");

  app->model = calculator_create();
  app->view = calculator_view_create(win, app->model);
  app->controller = calculator_controller_create(app->view, app->model);

  calculator_set_view(app->model, (iview_t*)(app->view));

  widget_on(win, EVT_DESTROY, application_quit, app);

  return RET_OK;
}
