QT += widgets

HEADERS     = View/mainwindow.h \
              View/codeeditor.h \
              View/syntaxhighlighter.h \
    Controller/keyinputcontroller.h \
    View/buttonbar.h

SOURCES     = View/mainwindow.cpp \
              main.cpp \
              View/codeeditor.cpp \
              View/syntaxhighlighter.cpp \
    Controller/keyinputcontroller.cpp \
    View/buttonbar.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/richtext/syntaxhighlighter
INSTALLS += target

INCLUDEPATH += View/
INCLUDEPATH += Controller/

#================================!!!! IMPORTANT !!!!===========================================
#The code below is for referencing the diferent .lib files, that are of course the tokenizer,
#compiler and Virtual_machine. I (Sjors) have added these using the "add external library"
#wizzard within QT Creator. The paths appear to be relative, so make sure that the files are
#located at the correct location! My Ivy related folder structure:
#   - GitHub repository
#       - Ivy (i.e. back-end)
#           - Project_Ivy
#               - etc.
#       - Ivy-IDE
#           - IDE
#               - etc.
# As long as you have the same structure, I would assume this will work.
#==============================================================================================

INCLUDEPATH += "$$PWD/../../Ivy/Project Ivy/Debug"
DEPENDPATH += "$$PWD/../../Ivy/Project Ivy/Debug"

#====== Snippet for Tokenizer (added through add external library wizzard in QT Creator) ======
win32:CONFIG(release, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/release/ -lTokenizer"
else:win32:CONFIG(debug, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/debug/ -lTokenizer"
else:unix: LIBS += "-L$$PWD/../../Ivy/Project Ivy/ -lTokenizer"

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/libTokenizer.a"
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/libTokenizer.a"
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/Tokenizer.lib"
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/Tokenizer.lib"
else:unix: PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/libTokenizer.a"


#====== Snippet for Compiler (added through add external library wizzard in QT Creator) ======
win32:CONFIG(release, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/release/ -lCompiler"
else:win32:CONFIG(debug, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/debug/ -lCompiler"
else:unix: LIBS += "-L$$PWD/../../Ivy/Project Ivy/ -lCompiler"

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/libCompiler.a"
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/libCompiler.a"
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/Compiler.lib"
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/Compiler.lib"
else:unix: PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/libCompiler.a"


#====== Snippet for Virtual Machine (added through add external library wizzard in QT Creator) ======
win32:CONFIG(release, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/release/ -lVirtual Machine"
else:win32:CONFIG(debug, debug|release): LIBS += "-L$$PWD/../../Ivy/Project Ivy/debug/ -lVirtual Machine"
else:unix: LIBS += "-L$$PWD/../../Ivy/Project Ivy/ -lVirtual Machine"

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/libVirtual Machine.a"
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/libVirtual Machine.a"
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/release/Virtual Machine.lib"
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/debug/Virtual Machine.lib"
else:unix: PRE_TARGETDEPS += "$$PWD/../../Ivy/Project Ivy/libVirtual Machine.a"

RESOURCES += \
    Resources.qrc





