/********************************************************************************
** Form generated from reading UI file 'geninfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENINFO_H
#define UI_GENINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_genInfoDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *fuzznum;
    QPushButton *statButton;
    QPushButton *plotButton;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QPushButton *crashButton;
    QListWidget *listView;
    QPushButton *checkCrashButton;
    QLabel *label;
    QPushButton *refreshButton;

    void setupUi(QDialog *genInfoDialog)
    {
        if (genInfoDialog->objectName().isEmpty())
            genInfoDialog->setObjectName(QString::fromUtf8("genInfoDialog"));
        genInfoDialog->resize(484, 414);
        tabWidget = new QTabWidget(genInfoDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 441, 361));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 11, 431, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        fuzznum = new QLineEdit(widget);
        fuzznum->setObjectName(QString::fromUtf8("fuzznum"));

        horizontalLayout->addWidget(fuzznum);

        statButton = new QPushButton(widget);
        statButton->setObjectName(QString::fromUtf8("statButton"));

        horizontalLayout->addWidget(statButton);

        plotButton = new QPushButton(widget);
        plotButton->setObjectName(QString::fromUtf8("plotButton"));

        horizontalLayout->addWidget(plotButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        crashButton = new QPushButton(tab_2);
        crashButton->setObjectName(QString::fromUtf8("crashButton"));
        crashButton->setGeometry(QRect(0, 0, 141, 25));
        listView = new QListWidget(tab_2);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(0, 30, 431, 291));
        checkCrashButton = new QPushButton(tab_2);
        checkCrashButton->setObjectName(QString::fromUtf8("checkCrashButton"));
        checkCrashButton->setGeometry(QRect(290, 0, 141, 25));
        tabWidget->addTab(tab_2, QString());
        label = new QLabel(genInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 111, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        refreshButton = new QPushButton(genInfoDialog);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(370, 20, 89, 25));

        retranslateUi(genInfoDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(genInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *genInfoDialog)
    {
        genInfoDialog->setWindowTitle(QApplication::translate("genInfoDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("genInfoDialog", "goto Fuzzer No.", nullptr));
        statButton->setText(QApplication::translate("genInfoDialog", "Stats", nullptr));
        plotButton->setText(QApplication::translate("genInfoDialog", "Plot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("genInfoDialog", "Runtime_Stats", nullptr));
        crashButton->setText(QApplication::translate("genInfoDialog", "get crash list", nullptr));
        checkCrashButton->setText(QApplication::translate("genInfoDialog", "check crash", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("genInfoDialog", "Crash_Stats", nullptr));
        label->setText(QApplication::translate("genInfoDialog", "Fuzzer Stats", nullptr));
        refreshButton->setText(QApplication::translate("genInfoDialog", "refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class genInfoDialog: public Ui_genInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENINFO_H
