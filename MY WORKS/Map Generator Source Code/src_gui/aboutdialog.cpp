#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QFile>
#include <QDir>
#include <QDesktopServices>
#include <QColorDialog>

AboutDialog::AboutDialog(QWidget *parent, MainWindow *mainwindow) :
    QDialog(parent),
    mainwindow(mainwindow),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_sourcecode, SIGNAL(clicked()), this, SLOT(openSourcecodeLink()));
    connect(ui->pushButton_latestVersion, SIGNAL(clicked()), this, SLOT(openLatestVersionLink()));

    connect(ui->radioButton_useCustomColors, SIGNAL(toggled(bool)), mainwindow, SLOT(setUseCustomUiColors(bool)));
    connect(ui->pushButton_mainColor, SIGNAL(clicked()), this, SLOT(showMainColorDialog()));
    connect(ui->pushButton_textColor, SIGNAL(clicked()), this, SLOT(showTextColorDialog()));
    connect(ui->pushButton_graphicsViewColor, SIGNAL(clicked()), this, SLOT(showGraphicsViewColorDialog()));
    connect(ui->pushButton_resetColorsToDefault, SIGNAL(clicked()), mainwindow, SLOT(resetUiColors()));

    ui->radioButton_useCustomColors->setChecked(mainwindow->getUseCustomUiColors());
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::openSourcecodeLink() {
    QDesktopServices::openUrl(QUrl(""));
}

void AboutDialog::openLatestVersionLink() {
    QDesktopServices::openUrl(QUrl(""));
}

void AboutDialog::showMainColorDialog() {
    QColorDialog *colorDialog = new QColorDialog(mainwindow->getUiColorMain(), this);
    connect(colorDialog, SIGNAL(currentColorChanged(QColor)), mainwindow, SLOT(setUiColorMain(QColor)));
    colorDialog->show();
}

void AboutDialog::showTextColorDialog() {
    QColorDialog *colorDialog = new QColorDialog(mainwindow->getUiColorText(), this);
    connect(colorDialog, SIGNAL(currentColorChanged(QColor)), mainwindow, SLOT(setUiColorText(QColor)));
    colorDialog->show();
}

void AboutDialog::showGraphicsViewColorDialog() {
    QColorDialog *colorDialog = new QColorDialog(mainwindow->getUiColorGraphicsView(), this);
    connect(colorDialog, SIGNAL(currentColorChanged(QColor)), mainwindow, SLOT(setUiColorGraphicsView(QColor)));
    colorDialog->show();
}
