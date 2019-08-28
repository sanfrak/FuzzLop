#ifndef GENINFO_H
#define GENINFO_H

#include <QFile>
#include <QFileDialog>
#include <QDialog>
#include <QProcess>
#include <QDebug>
#include <QDesktopServices>
#include <QVector>
#include <QString>
#include <QDir>
#include <QDirIterator>

namespace Ui {
class genInfoDialog;
}

class genInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit genInfoDialog(QWidget *parent = nullptr);
    ~genInfoDialog();

    void getdirs(QVector<QString> dirvec);

private slots:

    void on_refreshButton_clicked();

    void on_plotButton_clicked();

    void on_statButton_clicked();

    void on_crashButton_clicked();

    void on_checkCrashButton_clicked();

private:

    Ui::genInfoDialog *ui;

    QString fuzznumStr;
    QVector<QString> dirs;
};

#endif // GENINFO_H
