TEMPLATE = app

QT += qml quick widgets quickcontrols2 network
CONFIG += c++14

SOURCES += \
    main.cpp \
    Signal.cpp \
    extract.cpp \
    ClientConnection.cpp


RESOURCES += qml.qrc
QMAKE_CXXFLAGS += -Wno-unused-parameter
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -lGL

DISTFILES += \
    ../interactions.json


HEADERS += \
    Signal.hpp \
    extract.hpp \
    ../../boost_1_63_0/boost/optional.hpp \
    ClientConnection.hpp

unix:!macx: LIBS += -L$$PWD/../build/api-inst/lib/ -lossia

INCLUDEPATH += $$PWD/../build/api-inst/include
INCLUDEPATH += /home/kmercier/boost_1_63_0

DEPENDPATH += $$PWD/../build/api-inst/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../lib/build-ossia/api-inst/lib/release/ -lossia
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../lib/build-ossia/api-inst/lib/debug/ -lossia
else:unix: LIBS += -L$$PWD/../../../../../lib/build-ossia/api-inst/lib/ -lossia

INCLUDEPATH += $$PWD/../../../../../lib/build-ossia/api-inst/include
DEPENDPATH += $$PWD/../../../../../lib/build-ossia/api-inst/include
