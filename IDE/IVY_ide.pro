QT += widgets

HEADERS     = View/mainwindow.h \
              View/codeeditor.h \
              View/syntaxhighlighter.h \
    Controller/keyinputcontroller.h

SOURCES     = View/mainwindow.cpp \
              main.cpp \
              View/codeeditor.cpp \
              View/syntaxhighlighter.cpp \
    Controller/keyinputcontroller.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/richtext/syntaxhighlighter
INSTALLS += target
