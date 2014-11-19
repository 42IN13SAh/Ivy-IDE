#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "syntaxhighlighter.h"
#include "codeeditor.h"
#include "keyinputcontroller.h"
#include <QMainWindow>

class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void about();
    void newFile();
    void openFile(const QString &path = QString());
    void defaultKeyPressEvent(QKeyEvent* event);

private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    void setupControllers();

    CodeEditor *editor;
    Highlighter *highlighter;
    KeyInputController *keyInputController;

protected:
    void keyPressEvent(QKeyEvent* event);
};

#endif // MAINWINDOW_H
