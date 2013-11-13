#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(ui->slider_densidad, SIGNAL(valueChanged(int)), ui->label_densidad, SLOT(setNum(int)));
    createActions();
    generateMap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// fromUI = false significa que el tablero se cargara a traves de un fichero
void MainWindow::generateMap(const bool fromUI) {
    int rows = ui->spinBox_rows->value();
    int cols = ui->spinBox_cols->value();
    /*qDebug() << "rows= " << ui->spinBox_rows->value();
    qDebug() << "cols= " << ui->spinBox_cols->value();*/
    qreal diameter = (ui->graphicsView->width() * FACTOR_CORRECCION) / ((rows > cols) ? rows : cols);

    scene->clear();
    tab = new Tablero(cols, rows, diameter, scene);
    if (fromUI) {
        if (ui->radioButton_random->isChecked())
            tab->randomize(ui->slider_densidad->value() / 100.0);
        else if(ui->radioButton_manual->isChecked())
            tab->ramdomizeRobot();
    }
    tab->draw();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::createActions()
{
    connect(ui->actionAbrir_tablero, SIGNAL(triggered()), this, SLOT(on_menuButton_abrirTablero_clicked()));
    connect(ui->actionGuardar_tablero, SIGNAL(triggered()), this, SLOT(on_menuButton_guardarTablero_clicked()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(on_menuButton_salir_clicked()));
}

void MainWindow::on_pushButton_generate_clicked()
{
    generateMap(true);
}

void MainWindow::on_pushButton_acercaDe_clicked()
{
    QMessageBox acercaDe(this);
    acercaDe.setWindowTitle("Acerca de");
    acercaDe.setInformativeText("ETSII - Universidad de La Laguna \n"
                     "Asignatura: Inteligencia Artificial\n"
                     "Practica: Estrategias de busqueda\n\n"
                     "                Autor:\n"
                     "Alejandro Samarin Perez - alu3862\n"
    acercaDe.exec();
}

void MainWindow::on_pushButton_calcular_clicked()
{
    if (ui->radioButton_ciegaAnchura->isChecked()) {
        BusquedaEnAnchura *bAnch = new BusquedaEnAnchura();
        QColor rojo(Qt::red);
        tab->redraw();
        Camino a = bAnch->buscar(tab);
        a.drawPath(scene, rojo);
        if (a.ultimoNodo()->getCoords() == tab->getInicio()->getCoords())
            QMessageBox::warning(this, tr("Sin solucion"),
                                 tr("No hay solucion para estas condiciones"));
    }
    else if(ui->radioButton_ciegaProfundidad->isChecked()) {
        BusquedaEnProfundidad *bProf = new BusquedaEnProfundidad();
        QColor azul(Qt::blue);
        tab->redraw();
        Camino a = bProf->buscar(tab);
        a.drawPath(scene, azul);
        if (a.ultimoNodo()->getCoords() == tab->getInicio()->getCoords())
            QMessageBox::warning(this, tr("Sin solucion"),
                                 tr("No hay solucion para estas condiciones"));
    }
    else if(ui->radioButton_heuristica->isChecked()) {
        BusquedaEuclidea *bEucl = new BusquedaEuclidea();
        QColor negro(Qt::black);
        tab->redraw();
        Camino a = bEucl->search(tab);
        a.drawPath(scene, negro);
        if (a.ultimoNodo()->getCoords() == tab->getInicio()->getCoords())
            QMessageBox::warning(this, tr("Sin solucion"),
                                 tr("No hay solucion para estas condiciones"));
    }
    else if(ui->radioButton_heuristica_2->isChecked()) {
        BusquedaManhattan *bManh = new BusquedaManhattan();
        QColor negro(Qt::black);
        tab->redraw();
        Camino a = bManh->search(tab);
        a.drawPath(scene, negro);
        if (a.ultimoNodo()->getCoords() == tab->getInicio()->getCoords())
            QMessageBox::warning(this, tr("Sin solucion"),
                                 tr("No hay solucion para estas condiciones"));
    } else if(ui->radioButton_heuristica_3->isChecked()) {
        BusquedaMahalanobis *bMaha = new BusquedaMahalanobis();
        QColor negro(Qt::black);
        tab->redraw();
        Camino a = bMaha->search(tab);
        a.drawPath(scene, negro);
        if (a.ultimoNodo()->getCoords() == tab->getInicio()->getCoords())
            QMessageBox::warning(this, tr("Sin solucion"),
                                 tr("No hay solucion para estas condiciones"));
    }
}

void MainWindow::on_menuButton_abrirTablero_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir tablero"),
                                                    QDir::currentPath(),
                                                    tr("Ficheros XML (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Abrir tablero"),
                             tr("No se puede abrir para lectura %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    this->xmlreader = new QXmlStreamReader(&file);

    while(!xmlreader->atEnd()) {
        xmlreader->readNextStartElement();
        //qDebug() << xmlreader->name();
        if (xmlreader->name() == "xml");
        else if (xmlreader->name() == "size") {
            ui->spinBox_rows->setValue(xmlreader->attributes().value("rows").toString().toInt());
            ui->spinBox_cols->setValue(xmlreader->attributes().value("cols").toString().toInt());
            generateMap(false);
        } else if (xmlreader->name() == "robot") {
            int robotXPos = xmlreader->attributes().value("xpos").toString().toInt();
            int robotYPos = xmlreader->attributes().value("ypos").toString().toInt();
            tab->setCell(robotXPos, robotYPos, robot);
        } else if (xmlreader->name() == "target") {
            int targetXPos = xmlreader->attributes().value("xpos").toString().toInt();
            int targetYPos = xmlreader->attributes().value("ypos").toString().toInt();
            tab->setCell(targetXPos, targetYPos, objetivo);
        } else if (xmlreader->name() == "obstacle") {
            int obstacleXPos = xmlreader->attributes().value("xpos").toString().toInt();
            int obstacleYPos = xmlreader->attributes().value("ypos").toString().toInt();
            tab->setCell(obstacleXPos, obstacleYPos, obstaculo);
        } else {
            xmlreader->skipCurrentElement();
        }
        /*qDebug() <<*/ xmlreader->readNext();
    }
    tab->redraw();
    /*} else
        QMessageBox::warning(this, tr("Abrir tablero"),
                             tr("Error al parsear el fichero %1:\n%2")
                             .arg(fileName)
                             .arg(xmlreader->errorString()));*/
}

void MainWindow::on_menuButton_guardarTablero_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar tablero"),
                                                    QDir::currentPath(),
                                                    tr("Ficheros XML (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Fichero de especificacion de tablero"),
                             tr("No se puede abrir para escritura %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    this->xmlwriter = new QXmlStreamWriter(&file);
    xmlwriter->setAutoFormatting(true);
    xmlwriter->writeStartDocument();
    xmlwriter->writeStartElement("xml");

    xmlwriter->writeStartElement("size");
    xmlwriter->writeAttribute("rows", QString::number(tab->getHeight()));
    xmlwriter->writeAttribute("cols", QString::number(tab->getWidth()));
    xmlwriter->writeEndElement();

    xmlwriter->writeStartElement("robot");
    xmlwriter->writeAttribute("xpos", QString::number(tab->getInicio()->getCoords().x()));
    xmlwriter->writeAttribute("ypos", QString::number(tab->getInicio()->getCoords().y()));
    xmlwriter->writeEndElement();

    xmlwriter->writeStartElement("target");
    xmlwriter->writeAttribute("xpos", QString::number(tab->getMeta()->getCoords().x()));
    xmlwriter->writeAttribute("ypos", QString::number(tab->getMeta()->getCoords().y()));
    xmlwriter->writeEndElement();

    //xmlwriter->writeComment("Definicion de obstaculos");
    for (int i = 0; i < tab->getWidth(); ++i) {
        for (int j = 0; j < tab->getHeight(); ++j) {
            if (tab->getCell(i, j)->getType() == obstaculo) {
                xmlwriter->writeStartElement("obstacle");
                xmlwriter->writeAttribute("xpos", QString::number(i));
                xmlwriter->writeAttribute("ypos", QString::number(j));
                xmlwriter->writeEndElement();
            }
        }
    }
    xmlwriter->writeEndElement();
    xmlwriter->writeEndDocument();
}

void MainWindow::on_menuButton_salir_clicked()
{
    this->close();
}
