#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f = new Field(0);
    connect(f, SIGNAL(nextStep()), this, SLOT(update()));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QImage im(FIELD_WIDTH, FIELD_HEIGHT, QImage::Format_RGB888);
    QPainter imagePainter(&im);
    if(run){
        for (int i = 0; i < FIELD_WIDTH ; ++i) {
            for (int j = 0; j < FIELD_HEIGHT; ++j) {
                if(f->getCell(Coords{i, j}).getWolfIndexes().size() &&
                        f->getCell(Coords{i, j}).getRabbitIndexes().size()){
                    imagePainter.setPen(Qt::yellow);
                    imagePainter.drawPoint(i, j);
                }else if(f->getCell(Coords{i, j}).getWolfIndexes().size()){
                    imagePainter.setPen(Qt::red);
                    imagePainter.drawPoint(i, j);
                }else if(f->getCell(Coords{i, j}).getRabbitIndexes().size()){
                    imagePainter.setPen(Qt::blue);
                    imagePainter.drawPoint(i, j);      
                }else if(f->wasWolfHere(Coords{i, j})){
                    unsigned red = std::min(255u, f->getCell({i, j}).getTotalSmell());
                    imagePainter.setPen(QColor::fromHsv(0, red / 20.0 * 255, 100 + 5 * red));
                    imagePainter.drawPoint(i, j);
                }else if(f->wasRabbitHere(Coords{i, j})){
                    unsigned blue = std::min(255u, f->getCell({i, j}).getTotalSmell());
                    imagePainter.setPen(QColor::fromHsv(240, blue / 20.0 * 255, 100 + 5 * blue));
                    imagePainter.drawPoint(i, j);
                }else if(f->getCell(Coords{i, j}).isThereGrass()){
                    imagePainter.setPen(QColor::fromHsv(120, 255, f->getCell(Coords{i, j}).grass / 150.0 * 255));
                    imagePainter.drawPoint(i, j);
                }else{
                    imagePainter.setPen(Qt::white);
                    imagePainter.drawPoint(i, j);
                }
            }
        }
        QPainter painter(this);
        QMatrix m;
        m.rotate(90);
        painter.drawImage(0,0, im.transformed(m).scaled(this->width(), this->height()));
    }
    e->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W){
        f->write();
    }
}

void MainWindow::on_actionRun_triggered()
{
    if(!run){
        run = true;
        QThreadPool::globalInstance()->start(f);    
    }
}
