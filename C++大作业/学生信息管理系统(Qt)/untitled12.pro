QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_btn_add.cpp \
    dlg_btn_find.cpp \
    dlg_btn_read.cpp \
    dlg_btn_show.cpp \
    dlg_btn_write.cpp \
    dlg_fail.cpp \
    dlg_success.cpp \
    main.cpp \
    dlg1.cpp \
    classes/CS_Student.cpp \
    classes/DataBase.cpp \
    classes/People.cpp \
    classes/Student.cpp \

HEADERS += \
    classes/CS_Student.h \
    classes/DataBase.h \
    classes/People.h \
    classes/Student.h \
    dlg1.h \
    dlg_btn_add.h \
    dlg_btn_find.h \
    dlg_btn_read.h \
    dlg_btn_show.h \
    dlg_btn_write.h \
    dlg_fail.h \
    dlg_success.h


FORMS += \
    dlg1.ui \
    dlg_btn_add.ui \
    dlg_btn_find.ui \
    dlg_btn_read.ui \
    dlg_btn_show.ui \
    dlg_btn_write.ui \
    dlg_fail.ui \
    dlg_success.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
