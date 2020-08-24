cmake_minimum_required (VERSION 3.0)

project (Simple-employ-Server)

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
#包含子目录
INCLUDE_DIRECTORIES(include)
#生成应用程序 main为名称 (在windows下会自动生成main.exe)
ADD_EXECUTABLE(employ ${DIR_SRCS}  )

