#include <QDebug>
#include <QLibrary>

#include "keyinputcontroller.h"
#include "mainwindow.h"

KeyInputController::KeyInputController(MainWindow *window)
{
    this->source = window;

}

/**
 *  Supproted Keystrokes:
 *      - F6 - NOTHING
 *      -
 *
 *  @brief KeyInputController::handleKeyPressEvent Handles all key-presses that have non-default behaviour
 * @param event The caught key event
 */
void KeyInputController::handleKeyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F6){
        //F6 was pressed, start compiling
        QLibrary tokenizer("../IDE/Compiler.dll");
        tokenizer.load();
        if(tokenizer.isLoaded()){
            qDebug() << "Success! Compiler DLL library is now loaded!";

        }else{
            qDebug() << "Failed to load tokenizer.dll";
            qDebug() << tokenizer.errorString();
        }

        //TODO: call compile function bellow
        qDebug() << "F6 keyevent detected, calling compile function..";
    }else{
        //No shortcut(s) found; pass the event to the base class to continue default behaviour
        source->defaultKeyPressEvent(event);
    }
}
