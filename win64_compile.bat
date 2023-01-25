@ECHO OFF

set DRB_ROOT=..\
md native
md native\windows-amd64

:prompt
SET /P _inputname= "Compile (1) w64_libplc (2) w64_libfile (3) w64_libsqlite3 (4) none "
IF %_inputname%==1 GOTO :w64_libplc
IF %_inputname%==2 GOTO :w64_libfile
IF %_inputname%==3 GOTO :w64_libsqlite3
IF %_inputname%==4 GOTO :end

:: WINDOWS STUFF

:w64_libsqlite3
%DRB_ROOT%dragonruby-bind.exe --output=native\sqlite3-bindings_w64.c  --compiler-flags=--sysroot=C:\msys64\mingw64\x86_64-w64-mingw32\ --ffi-module=LIBSQLITE3  app\lib\sqlite3.h
clang -shared .\native\sqlite3-bindings_w64.c .\app\lib\sqlite3.lib --sysroot="C:\msys64\mingw64" --target=x86_64-w64-mingw32 -fuse-ld=lld -isystem %DRB_ROOT%\include -I. -o native\windows-amd64\ext_libsqlite3.dll
::-Wl,"/DEF:app\lib\sqlite3.def"

:end
