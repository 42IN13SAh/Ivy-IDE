QT += widgets

HEADERS     = mainwindow.h \
              codeeditor.h \
              syntaxhighlighter.h

SOURCES     = mainwindow.cpp \
              main.cpp \
              codeeditor.cpp \
              syntaxhighlighter.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/richtext/syntaxhighlighter
INSTALLS += target
