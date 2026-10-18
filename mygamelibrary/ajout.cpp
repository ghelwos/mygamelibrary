#include "ajout.h"
#include "ui_ajout.h"

ajout::ajout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ajout)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle("Adding a game");
    this->setWindowIcon(QIcon(":/add.png"));
}

ajout::~ajout()
{
    delete ui;
}

void ajout::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        tr("Choose a file"),
        QDir::homePath(),
        tr("Executable files (*.exe);;All file (*.*)")
        );

    if (!file.isEmpty())
        ui->lineEdit->setText(file);
}

void ajout::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        tr("Choose a file"),
        QDir::homePath(),
        tr("Image (*.png);;All file (*.*)")
        );

    if (!file.isEmpty())
        ui->lineEdit_2->setText(file);
}

std::vector<QVariant> ajout::return_game_values() {
    std::vector<QVariant> res;
    res.push_back(ui->lineEdit_3->text());
    res.push_back(ui->lineEdit->text());
    res.push_back(ui->lineEdit_2->text());
    return res;
}