#include "ajout.h"
#include "ui_ajout.h"

ajout::ajout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ajout)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle("Adding a game");
}

ajout::~ajout()
{
    delete ui;
}
