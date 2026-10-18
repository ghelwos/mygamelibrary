#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <vector>
#include "ajout.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    std::vector<game> games;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ajout aj;

};
#endif // MAINWINDOW_H
