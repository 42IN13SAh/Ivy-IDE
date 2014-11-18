#include "keyinputcontroller.h"

KeyInputController::KeyInputController(MainWindow *window)
{
    this->source = window;
}

void KeyInputController::handleKeyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F6){
        //F6 was pressed, start compiling

    }else{
        //No shortcut found; pass the event to the base class to continue default behaviour
        source->defaultKeyPressEvent(event);
    }
}
