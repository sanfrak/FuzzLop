/********************************************************************************
** Form generated from reading UI file 'infodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *AFLFButton;
    QRadioButton *AButton;
    QRadioButton *AnLButton;
    QRadioButton *AFnLButton;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QPushButton *prjButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *inputdir;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *outputdir;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *execdir;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *numfuzz;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName(QString::fromUtf8("InfoDialog"));
        InfoDialog->resize(415, 381);
        label = new QLabel(InfoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 10, 106, 18));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        groupBox = new QGroupBox(InfoDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 220, 318, 101));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AFLFButton = new QRadioButton(groupBox);
        AFLFButton->setObjectName(QString::fromUtf8("AFLFButton"));

        gridLayout->addWidget(AFLFButton, 0, 1, 1, 1);

        AButton = new QRadioButton(groupBox);
        AButton->setObjectName(QString::fromUtf8("AButton"));

        gridLayout->addWidget(AButton, 0, 0, 1, 1);

        AnLButton = new QRadioButton(groupBox);
        AnLButton->setObjectName(QString::fromUtf8("AnLButton"));

        gridLayout->addWidget(AnLButton, 1, 0, 1, 1);

        AFnLButton = new QRadioButton(groupBox);
        AFnLButton->setObjectName(QString::fromUtf8("AFnLButton"));

        gridLayout->addWidget(AFnLButton, 1, 1, 1, 1);

        label_5 = new QLabel(InfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 34, 85, 17));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        layoutWidget = new QWidget(InfoDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 205, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        prjButton = new QPushButton(layoutWidget);
        prjButton->setObjectName(QString::fromUtf8("prjButton"));

        horizontalLayout->addWidget(prjButton);

        layoutWidget1 = new QWidget(InfoDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 92, 225, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        inputdir = new QLineEdit(layoutWidget1);
        inputdir->setObjectName(QString::fromUtf8("inputdir"));

        horizontalLayout_2->addWidget(inputdir);

        layoutWidget2 = new QWidget(InfoDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 121, 225, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        outputdir = new QLineEdit(layoutWidget2);
        outputdir->setObjectName(QString::fromUtf8("outputdir"));

        horizontalLayout_3->addWidget(outputdir);

        layoutWidget3 = new QWidget(InfoDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(12, 150, 233, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        execdir = new QLineEdit(layoutWidget3);
        execdir->setObjectName(QString::fromUtf8("execdir"));

        horizontalLayout_4->addWidget(execdir);

        layoutWidget4 = new QWidget(InfoDialog);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(12, 182, 284, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        numfuzz = new QLineEdit(layoutWidget4);
        numfuzz->setObjectName(QString::fromUtf8("numfuzz"));

        horizontalLayout_5->addWidget(numfuzz);

        layoutWidget5 = new QWidget(InfoDialog);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(26, 320, 352, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget5);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_6->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget5);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_6->addWidget(okButton);


        retranslateUi(InfoDialog);

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QApplication::translate("InfoDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("InfoDialog", "Configuration", nullptr));
        groupBox->setTitle(QApplication::translate("InfoDialog", "Select Fuzzer Engine", nullptr));
        AFLFButton->setText(QApplication::translate("InfoDialog", "AFL-Fast", nullptr));
        AButton->setText(QApplication::translate("InfoDialog", "AFL", nullptr));
        AnLButton->setText(QApplication::translate("InfoDialog", "AFL + LibFuzzer", nullptr));
        AFnLButton->setText(QApplication::translate("InfoDialog", "AFL-Fast + LibFuzzer", nullptr));
        label_5->setText(QApplication::translate("InfoDialog", "Project Info", nullptr));
        label_6->setText(QApplication::translate("InfoDialog", "Project DIR:", nullptr));
        prjButton->setText(QApplication::translate("InfoDialog", "Choose Folder", nullptr));
        label_2->setText(QApplication::translate("InfoDialog", "seeds DIR:", nullptr));
        label_3->setText(QApplication::translate("InfoDialog", "result DIR:", nullptr));
        label_4->setText(QApplication::translate("InfoDialog", "exec Name:", nullptr));
        label_7->setText(QApplication::translate("InfoDialog", "number of Fuzzers:", nullptr));
        cancelButton->setText(QApplication::translate("InfoDialog", "Cancel", nullptr));
        okButton->setText(QApplication::translate("InfoDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
