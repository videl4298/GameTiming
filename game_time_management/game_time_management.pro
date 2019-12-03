QT += widgets

SOURCES += \
    code/mainwindow.cpp \
    code/passwordchecker.cpp \
    code/screenblocker.cpp \
    code/settingwindow.cpp \
    code/timerecever.cpp \
    code/timewindows.cpp \
    main.cpp

HEADERS += \
    code/mainwindow.h \
    code/passwordchecker.h \
    code/screenblocker.h \
    code/settingwindow.h \
    code/timerecever.h \
    code/timewindows.h

RESOURCES += \
    data/appRes.qrc

RC_ICONS = data/myApp.ico

FORMS += \
    code/timewindows.ui
