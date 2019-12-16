QT += widgets

SOURCES += \
    code/custommerinfocontainer.cpp \
    code/mainwindow.cpp \
    code/passwordchecker.cpp \
    code/screenblocker.cpp \
    code/settingwindow.cpp \
    code/timerecever.cpp \
    code/timewindows.cpp \
    import/pricedurationcalc_v.cpp \
    main.cpp

HEADERS += \
    code/custommerinfocontainer.h \
    code/mainwindow.h \
    code/passwordchecker.h \
    code/screenblocker.h \
    code/settingwindow.h \
    code/timerecever.h \
    code/timewindows.h \
    import/pricedurationcalc_v.h

RESOURCES += \
    data/appRes.qrc

RC_ICONS = data/myApp.ico

FORMS += \
    code/timewindows.ui
