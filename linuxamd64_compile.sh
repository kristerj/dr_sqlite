#!/bin/sh

OSTYPE=`uname -s`
if [ "x$OSTYPE" = "xDarwin" ]; then
  PLATFORM=macos
  DLLEXT=dylib
else
  PLATFORM=linux-amd64
  DLLEXT=so
fi

DRB_ROOT=../
mkdir -p native/$PLATFORM


#$DRB_ROOT/dragonruby-bind -ffi-module=LIBSQLITE3 --output=native/libsqlite3-bindings.c app/lib/sqlite3.h
clang \
  -isystem $DRB_ROOT/include -isystem $DRB_ROOT -I. \
   -shared -fPIC app/lib/sqlite3.c native/libsqlite3-bindings.c -o native/$PLATFORM/ext_libsqlite3.$DLLEXT 

#old stuff
#${DRB_ROOT}dragonruby-bind --output=native/sqlite3-bindings_l64.c --ffi-module=LIBSQLITE3  app/lib/sqlite3.h
#clang -v -shared native/sqlite3-bindings_l64.c app/lib/sqlite3.so -isystem ${DRB_ROOT}include -I. -o native/linux-amd64/ext_libsqlite.so
