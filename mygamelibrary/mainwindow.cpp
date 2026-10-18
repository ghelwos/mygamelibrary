#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("My Game Library");
    this->setWindowIcon(QIcon(":/icon.png"));

    int columns = 3;
    int dimensions = 64;

    int i = 0;
    for (const game &gameData : games) {
        auto* cell = new QFrame;
        cell->setObjectName("gameCell");

        QVBoxLayout* content = new QVBoxLayout(cell);

        QLabel* image = new QLabel;
        image->setObjectName("gameIcon");
        image->setPixmap(gameData.icon.pixmap(dimensions, dimensions));

        QLabel* name = new QLabel(gameData.name);
        name->setObjectName("gameTitle");

        content->addWidget(image);
        content->addWidget(name);

        ui->gamesGrid->addWidget(cell, i / columns, i % columns);
        ++i;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (aj.exec() == QDialog::Accepted) {
        std::vector<QVariant> new_game_data = aj.return_game_values();
        game new_game;
        new_game.name = new_game_data[0].toString();
        new_game.path = new_game_data[1].toString();
        new_game.icon = QIcon(new_game_data[2].toString());
        games.push_back(new_game);
    }
}
