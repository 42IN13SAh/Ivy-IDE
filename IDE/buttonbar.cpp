#include <QHBoxLayout>
#include <QPalette>
#include <QDebug>

#include "buttonbar.h"

ButtonBar::ButtonBar(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();

    runButton = new QPushButton();
    //runButton->setText("Run");
    runButton->setMaximumSize(50, 20);
    runButton->setMinimumSize(50, 20);
    QPixmap pix(":/Images/Images/RunButtonIcon.png");
    QIcon icon(pix);
    runButton->setIcon(icon);
    runButton->setIconSize(QSize(20, 20));

    buildButton = new QPushButton();
    buildButton->setText("Build");
    buildButton->setMaximumSize(50, 20);
    buildButton->setMinimumSize(50, 20);

    connect(runButton, SIGNAL(released()), this, SLOT(runButtonClicked()));
    connect(buildButton, SIGNAL(released()), this, SLOT(buildButtonClicked()));

    layout->addWidget(runButton);
    layout->addWidget(buildButton);
    layout->setContentsMargins(5, 5, 0, 5);
    layout->setAlignment(Qt::AlignLeft);
    setLayout(layout);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#323232");
    setAutoFillBackground(true);
    setPalette(Pal);
}

void ButtonBar::runButtonClicked()
{
}

void ButtonBar::buildButtonClicked()
{
}
