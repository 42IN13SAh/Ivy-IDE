#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "syntaxhighlighter.h"
#include "codeeditor.h"

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

private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();

    CodeEditor *editor;
    Highlighter *highlighter;
};

#endif // MAINWINDOW_H
