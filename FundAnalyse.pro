######################################################################
# Automatically generated by qmake (2.01a) ?? 3? 28 10:44:24 2015
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . src test
INCLUDEPATH += . src test

# Input
HEADERS += src/downloader.h src/global.h src/onedayprice.h test/testdownloader.h
SOURCES += src/downloader.cpp \
           src/global.cpp \
           src/onedayprice.cpp \
           test/testdownloader.cpp


# 添加Qt库：
QT += network

# 添加调试信息：
CONFIG += debug

# 使用c++11特性（shared_ptr等）：
QMAKE_CXXFLAGS += -std=gnu++11

# 支持guile：
QMAKE_CFLAGS +=   -pthread
QMAKE_CXXFLAGS +=   -pthread
LIBS +=  -pthread  -lguile -lltdl -lgmp -lcrypt -lm -lltdl
# 其中flags由guile-config compile命令得到，libs由guile-config link得到

# 指定生成的应用程序放置的目录
DESTDIR = compile

# 指定生成的应用程序名
TARGET =

# 指定uic命令将.ui文件转化成ui_*.h文件的存放的目录
UI_DIR = compile

# 指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
RCC_DIR = compile

# 指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
MOC_DIR = compile

# 指定目标文件(obj)的存放目录
OBJECTS_DIR = compile
