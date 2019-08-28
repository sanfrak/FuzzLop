#include "widget.h"
#include "ui_widget.h"
#include "geninfo.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideInfoButton_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);

    //Show the dialog non model
    connect(dialog,&InfoDialog::accepted,[=](){

        config = dialog->getPosition();
        engine = dialog->getEngine();
        QString engstr;
        if(engine == 1)
            engstr = "AFL";
        else if(engine == 2)
            engstr = "AFL-Fast";
        else if(engine == 3)
            engstr = "AFL+LibFuzzer";
        else if(engine == 4)
            engstr = "AFL+AFL-Fast";

        qDebug() << "Configuration accepted.\nProject Dir: " << config[0] <<
                    "\nInput Dir: " << config[1] <<"\nOutput Dir: " << config[2] << "\nExecutable: " << config[3] <<
                    "\nnumFuzzer: " << config[4] << "\nFuzzer Engine Type: " << engstr;
        ui->infoLabel->setText("Configuration accepted.\nProject Dir: " + config[0] +
                               "\nInput Dir: " +config[1] + "\nOutput Dir: " +config[2] +
                               "\nExecutable: " +config[3] + "\nnumFuzzer: " +config[4] +
                               "\nFuzzer Engine Type: " + engstr);

    });

    connect(dialog,&InfoDialog::rejected,[=](){
        qDebug() << "Dialog rejected";
        ui->infoLabel->setText("Your Config is invalid!");
        this->repaint();

    });


    //Show the dialog
    dialog->show();
    dialog->raise();
    dialog->activateWindow();

}

void Widget::on_runButton_clicked()
{

    // get the current executable directory
    QString curdir = qApp->applicationDirPath();
    curdir += "/scripts/";

    // Parse the Engine Configs
    QString pwdDir = curdir + "pwd.txt";
    QFile pwdFile(pwdDir);
    //qDebug() << "current DIR:"<< pwdDir;

    pwdFile.remove();
    if( !pwdFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        qDebug() << "error opening the file!";
        return;
    }

    // write the configs to pwd.txt
    QTextStream fout(&pwdFile);

    for(int i=0; i<5; i++)
        fout << config[i]<< "\n";

    pwdFile.close();


    QProcess runscript;
    // run EngineMode1: AFL
    if(engine == 1){
        QString mod1Dir = curdir + "mod1.sh";
        qDebug() << "current mod1Dir: "<< mod1Dir;
        if(runscript.execute(QString("/bin/bash ") + mod1Dir) < 0)
            qDebug() << "fail to run mod1";

    }
    // run EngineMode1: AFL-Fast
    else if(engine == 2){
        QString mod2Dir = curdir + "mod2.sh";
        qDebug() << "current mod1Dir: "<< mod2Dir;
        if(runscript.execute(QString("/bin/bash ") + mod2Dir) < 0)
            qDebug() << "fail to run mod2";

    }
    // run EngineMode1: AFL + LibFuzzer
    else if(engine == 3){
        QString mod3Dir = curdir + "mod3.sh";
        qDebug() << "current mod1Dir: "<< mod3Dir;
        if(runscript.execute(QString("/bin/bash ") + mod3Dir) < 0)
            qDebug() << "fail to run mod3";

    }
    // run EngineMode1: AFL-Fast + LibFuzzer
    else if(engine == 4){
        QString mod4Dir = curdir + "mod4.sh";
        qDebug() << "current mod1Dir: "<< mod4Dir;
        if(runscript.execute(QString("/bin/bash ") + mod4Dir) < 0)
            qDebug() << "fail to run mod4";

    }
}

void Widget::on_StopButton_clicked()
{
    // get the current executable directory
    QString curdir = qApp->applicationDirPath();
    curdir += "/scripts/";

    // run stop.sh to terminate execution
    QProcess runscript;
    QString stopDir = curdir + "stop.sh";
    qDebug() << "stopDir: "<< stopDir;
    if(runscript.execute(QString("/bin/bash ") + stopDir) < 0)
        qDebug() << "fail to run stop.sh";
}

void Widget::on_genButton_clicked()
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





    genInfoDialog * genDialog = new genInfoDialog(this);
    genDialog->getdirs(config);
    //Show the dialog non model
    connect(genDialog,&genInfoDialog::accepted,[=](){

    });

    connect(genDialog,&genInfoDialog::rejected,[=](){
        qDebug() << "genDialog rejected";
        this->repaint();

    });


    //Show the genDialog
    genDialog->show();
    genDialog->raise();
    genDialog->activateWindow();



}
