#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupFileMenu();
    setupHelpMenu();
    setupEditor();

    setCentralWidget(editor);
    setWindowTitle(tr("Ivy IDE"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Ivy IDE"),
                tr("<p>This is the <b>Ivy IDE</b> created by Tim van de Burgt</p>"));
}

void MainWindow::newFile()
{
    editor->clear();
}

void MainWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "Ivy File (*.ivy)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(10);

    editor = new CodeEditor(this);
    editor->setFont(font);

    const int tabStop = 4;  // 4 characters

    QFontMetrics metrics(font);
    editor->setTabStopWidth(tabStop * metrics.width(' '));

    QPalette p = editor->palette();

    QColor q = QColor();
    q.setNamedColor("#212121");
    p.setColor(QPalette::Active, QPalette::Base, q);
    p.setColor(QPalette::Inactive, QPalette::Base, q);
    p.setColor(QPalette::Active, QPalette::Text, Qt::white);
    p.setColor(QPalette::Inactive, QPalette::Text, Qt::white);

    editor->setPalette(p);
    highlighter = new Highlighter(editor->document());

    //TODO testen of open file werkt.
    //QFile file("mainwindow.h");
    //if (file.open(QFile::ReadOnly | QFile::Text))
        //editor->setPlainText(file.readAll());
}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()), QKeySequence::Open);
    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()), QKeySequence::Quit);
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(tr("&About"), this, SLOT(about()));
}
