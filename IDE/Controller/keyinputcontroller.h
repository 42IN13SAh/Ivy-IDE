#ifndef KEYINPUTCONTROLLER_H
#define KEYINPUTCONTROLLER_H
#include <QKeyEvent>
class MainWindow;


class KeyInputController
{
public:
    KeyInputController(MainWindow *window);

    void handleKeyPressEvent(QKeyEvent* event);

private:
    MainWindow *source; //TODO: find better name?
};

#endif // KEYINPUTCONTROLLER_H
