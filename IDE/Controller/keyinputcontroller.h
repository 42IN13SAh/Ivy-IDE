#ifndef KEYINPUTCONTROLLER_H
#define KEYINPUTCONTROLLER_H

//#include <QMainWindow>
//class MainWindow;
#include "View/mainwindow.h"

class KeyInputController
{
public:
    KeyInputController(MainWindow *window);

    void handleKeyPressEvent(QKeyEvent* event);

private:
    MainWindow *source; //TODO: find better name?
};

#endif // KEYINPUTCONTROLLER_H
