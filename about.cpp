#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->movie=new QMovie("333.gif");
    ui->movieLabel->setMovie(this->movie);
    this->movie->start();

    QObject::connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(stopMovieSlot()));
    QObject::connect(ui->beginButton,SIGNAL(clicked(bool)),this,SLOT(beginMovieSlot()));

}

about::~about()
{
    delete ui;
}

void about::stopMovieSlot()
{
    this->movie->stop();
}

void about::beginMovieSlot()
{
    this->movie->start();
}
