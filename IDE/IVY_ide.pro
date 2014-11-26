QT += widgets

HEADERS     = mainwindow.h \
              codeeditor.h \
              syntaxhighlighter.h \
    buttonbar.h \
    bottombar.h \
    errorlistitem.h

SOURCES     = mainwindow.cpp \
              main.cpp \
              codeeditor.cpp \
              syntaxhighlighter.cpp \
    buttonbar.cpp \
    bottombar.cpp \
    errorlistitem.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/richtext/syntaxhighlighter
INSTALLS += target

RESOURCES += \
    Resources.qrc
