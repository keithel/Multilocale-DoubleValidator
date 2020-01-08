#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include "multivalidator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mDoubleValidator = new QDoubleValidator(this);
    ui->sysLocaleLineEdit->setValidator(mDoubleValidator);

    mCLocaleDoubleValidator = new QDoubleValidator(this);
    mCLocaleDoubleValidator->setLocale(QLocale::c());

    initMultiDoubleValidator();
    ui->sysCLocaleLineEdit->setValidator(mMultiDoubleValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMultiDoubleValidator()
{
    MultiValidator* multiValidator = new MultiValidator(this);
    multiValidator->addValidator(mDoubleValidator);
    multiValidator->addValidator(mCLocaleDoubleValidator);
    mMultiDoubleValidator = multiValidator;
}
