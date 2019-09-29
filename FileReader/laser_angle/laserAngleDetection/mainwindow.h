#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <utility>
#include <QButtonGroup>

using namespace std;
typedef pair<int,int> pii;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void angleVal(QFile&);
    double calcAng(QVector<pii>&);
    void openFile(QString);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup fileButtonGrp;

};

#endif // MAINWINDOW_H
