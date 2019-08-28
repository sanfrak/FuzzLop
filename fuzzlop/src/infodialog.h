#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QFileDialog>
#include <QDialog>
#include <QVector>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    int getEngine() const;

    QVector<QString> getPosition() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_prjButton_clicked();

private:
    QVector<QString> position;
    int Engine;
    QString prjDIR;

    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
