#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutDialog(QWidget *parent = 0, MainWindow *mainwindow = 0);
    ~AboutDialog();
    
private:
    MainWindow *mainwindow;
    Ui::AboutDialog *ui;

private slots:
    void openSourcecodeLink();
    void openLatestVersionLink();
    void showMainColorDialog();
    void showTextColorDialog();
    void showGraphicsViewColorDialog();
};

#endif // ABOUTDIALOG_H
