#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QLineEdit>
#include <vector>

namespace Ui {
class ajout;
}

class ajout : public QDialog
{
    Q_OBJECT

public:
    explicit ajout(QWidget *parent = nullptr);
    std::vector<QObject> return_game_values(); // Returns in this order : game name, game path & game icon path
    ~ajout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ajout_accepted();

private:
    Ui::ajout *ui;
};

#endif // AJOUT_H
