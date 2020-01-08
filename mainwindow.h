#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QValidator;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initMultiDoubleValidator();
private:
    Ui::MainWindow *ui;
    QValidator* mDoubleValidator;
    QValidator* mCLocaleDoubleValidator;
    QValidator* mMultiDoubleValidator;
};
#endif // MAINWINDOW_H
