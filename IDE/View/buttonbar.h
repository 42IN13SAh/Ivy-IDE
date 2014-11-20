#ifndef BUTTONBAR_H
#define BUTTONBAR_H

#include <QWidget>
#include <QPushButton>

class ButtonBar : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonBar(QWidget *parent = 0);

signals:

private slots:
    void runButtonClicked();
    void buildButtonClicked();

private:
    QPushButton *runButton;
    QPushButton *buildButton;
};

#endif // BUTTONBAR_H
