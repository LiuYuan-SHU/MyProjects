QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_ICONS = ico.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	MD5/my_md5.cpp \
	SHA/SHA256.cpp \
	main.cpp \
	mainwindow.cpp

HEADERS += \
    DES/DES.h \
    MD5/MD5.h \
    SHA/SHA256.h \
    SHA/SHA_Tools.h \
    mainwindow.h

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: tatget.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

