#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "tablero.h"
#include "busquedaciega.h"
#include "busquedaheuristica.h"
#include "common.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void generateMap(const bool fromUI);

protected:
    void changeEvent(QEvent *e);
    void createActions();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    Tablero *tab;
    QXmlStreamWriter *xmlwriter;
    QXmlStreamReader *xmlreader;

private slots:
    void on_pushButton_acercaDe_clicked();
    void on_pushButton_generate_clicked();
    void on_pushButton_calcular_clicked();
    void on_menuButton_abrirTablero_clicked();
    void on_menuButton_guardarTablero_clicked();
    void on_menuButton_salir_clicked();
};

#endif // MAINWINDOW_H
