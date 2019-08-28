/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *infoLabel;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *runButton;
    QPushButton *StopButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *provideInfoButton;
    QPushButton *genButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(322, 371);
        infoLabel = new QLabel(Widget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(9, 162, 291, 151));
        infoLabel->setWordWrap(true);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 80, 205, 22));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 320, 301, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(widget);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        horizontalLayout->addWidget(runButton);

        StopButton = new QPushButton(widget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));

        horizontalLayout->addWidget(StopButton);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(9, 129, 301, 27));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        provideInfoButton = new QPushButton(widget1);
        provideInfoButton->setObjectName(QString::fromUtf8("provideInfoButton"));

        horizontalLayout_2->addWidget(provideInfoButton);

        genButton = new QPushButton(widget1);
        genButton->setObjectName(QString::fromUtf8("genButton"));

        horizontalLayout_2->addWidget(genButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        infoLabel->setText(QApplication::translate("Widget", "Configure: \n"
" Click \"Set Configuration\" to set.", nullptr));
        label->setText(QApplication::translate("Widget", "FuzzLop Hybrid Fuzzer", nullptr));
        runButton->setText(QApplication::translate("Widget", "Run", nullptr));
        StopButton->setText(QApplication::translate("Widget", "Stop", nullptr));
        provideInfoButton->setText(QApplication::translate("Widget", "Set Configuration", nullptr));
        genButton->setText(QApplication::translate("Widget", "Check Stats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
