#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>
#include <QVector>
#include <QDesktopServices>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_provideInfoButton_clicked();

    void on_runButton_clicked();

    void on_StopButton_clicked();

    void on_genButton_clicked();

private:
    Ui::Widget *ui;
    QVector<QString> config;
    int engine;
};

#endif // WIDGET_H
