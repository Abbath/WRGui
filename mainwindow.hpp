#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <../WRTest/field.hpp>
#include <QtConcurrent/QtConcurrent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent* e);
    ~MainWindow();
    
private slots:
    void on_actionRun_triggered();
    
private:
    bool run = false;
    Field* f;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
