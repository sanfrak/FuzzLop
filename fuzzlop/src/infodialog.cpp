#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okButton_clicked()
{

    //Collect information
    QString inputDIR = ui->inputdir->text();
    QString outputDIR = ui->outputdir->text();
    QString execDIR = ui->execdir->text();
    QString numfuzzstr = ui->numfuzz->text();
    //int numfuzz = numfuzzstr.toInt();

    if( !prjDIR.isEmpty() && !inputDIR.isEmpty() && !outputDIR.isEmpty() && !execDIR.isEmpty() && !numfuzzstr.isEmpty())
    {
        position.push_back(prjDIR);
        position.push_back(inputDIR);
        position.push_back(outputDIR);
        position.push_back(execDIR);
        position.push_back(numfuzzstr);

        if(ui->AButton->isChecked())
        {
            Engine = 1;
        }

        if(ui->AFLFButton->isChecked())
        {
            Engine = 2;
        }

        if(ui->AnLButton->isChecked())
        {
            Engine = 3;
        }
        if(ui->AFnLButton->isChecked())
        {
            Engine = 4;
        }
    }

    // Accept the dialog
    accept();

}

void InfoDialog::on_cancelButton_clicked()
{
    //
    reject();
}

QVector<QString> InfoDialog::getPosition() const
{
    return position;
}

int InfoDialog::getEngine() const
{
    return Engine;
}

void InfoDialog::on_prjButton_clicked()
{
    //getExistingDirectory
    prjDIR = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    prjDIR += "/";
}
