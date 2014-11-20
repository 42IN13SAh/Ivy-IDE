#include "console.h"

Console::Console(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();

    textArea = new QTextEdit();

    layout->addWidget(textArea);
    setLayout(layout);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#323232");
    setAutoFillBackground(true);
    setPalette(Pal);
}
