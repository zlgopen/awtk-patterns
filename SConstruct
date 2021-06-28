import os
import scripts.app_helper as app

DEPENDS_LIBS = [
  {
    "root" : '../awtk-mvvm',
    'shared_libs': ['mvvm'],
    'static_libs': []
  }
]

APP_SRC = os.path.normpath(os.path.join(os.getcwd(), 'src'))
APP_CPPPATH = [
  os.path.join(APP_SRC, 'common'),
  os.path.join(APP_SRC, 'view_models'),
]

helper = app.Helper(ARGUMENTS);
helper.set_deps(DEPENDS_LIBS).add_cpppath(APP_CPPPATH).call(DefaultEnvironment)

helper.SConscript(['src/SConscript', 'tests/SConscript'])
