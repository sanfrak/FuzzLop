#include "geninfo.h"
#include "ui_geninfo.h"

genInfoDialog::genInfoDialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::genInfoDialog)
{
    ui->setupUi(this);
}

genInfoDialog::~genInfoDialog()
{
    delete ui;
}

void genInfoDialog::getdirs(QVector<QString> dirvec)
{
    dirs = dirvec;
    qDebug() << "dirs 0 is: "<<dirs[0];
}

void genInfoDialog::on_refreshButton_clicked()
{
    // get the current executable directory
    QString curdir = qApp->applicationDirPath();
    curdir += "/scripts/";

    // run stop.sh to terminate execution
    QProcess runscript;
    QString genDir = curdir + "gen.sh";
    qDebug() << "stopDir: "<< genDir;
    if(runscript.execute(QString("/bin/bash ") + genDir) < 0)
        qDebug() << "fail to run gen.sh";
}

void genInfoDialog::on_plotButton_clicked()
{
    fuzznumStr = ui->fuzznum->text();
    if(fuzznumStr.isEmpty()){
        qDebug() << "fuzzer number is empty!";
        return;
    }


    QString prjDir = dirs[0];
    QString outDir = dirs[2] + "/fuzzer" + fuzznumStr;
    QString link = prjDir + outDir + "/plot/index.html";
    qDebug() << "cur link" << link;
    QDesktopServices::openUrl(QUrl(link));
}

void genInfoDialog::on_statButton_clicked()
{
    fuzznumStr = ui->fuzznum->text();
    if(fuzznumStr.isEmpty()){
        qDebug() << "fuzzer number is empty!";
        return;
    }

    QString prjDir = dirs[0];
    QString outDir = dirs[2] + "/fuzzer" + fuzznumStr;
    QString filename = prjDir + outDir + "/fuzzer_stats";
    qDebug() << "cur filename" << filename;

    QString  fileContent;
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString error = "error loading fuzzer!";
        ui->textBrowser->setPlainText(error);
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        fileContent.append(line);
        fileContent.append("\n");
        line = in.readLine();
    }

    file.close();

    ui->textBrowser->clear();
    ui->textBrowser->setPlainText(fileContent);
}

void genInfoDialog::on_crashButton_clicked()
{
    QString prjDir = dirs[0];
    QString crashdir = prjDir + "crashes/";
    qDebug() << "crashes dir: " << crashdir;

    // display all crash files in listView
    ui->listView->clear();
    QDirIterator iterator(crashdir, QDirIterator::Subdirectories);
    while (iterator.hasNext()) {
        QFile file(iterator.next());
        if ( file.open( QIODevice::ReadOnly ) ){
            QFileInfo fileInfo(file.fileName());
            QString cfilename(fileInfo.fileName());
            ui->listView->addItem(cfilename);
            //qDebug() << "Opened:" << cfilename << endl;
        }
        else
            qDebug() << "Can't open " << file.fileName() << file.errorString() << endl;
    }

}

void genInfoDialog::on_checkCrashButton_clicked()
{
    QString prjDir = dirs[0];
    QString crashdir = prjDir + "crashes/";
    //qDebug() << "crashes dir: " << crashdir;

    QString curcrash = ui->listView->currentItem()->text();
    if(curcrash.isEmpty()){
        qDebug() << "no crash file is selected!";
        return;
    }

    QString curcrashfile = crashdir + curcrash;
    qDebug() << "current selected crash:" << curcrashfile << endl;
    QDesktopServices::openUrl(QUrl(curcrashfile));
}
