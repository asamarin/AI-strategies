/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 5. Nov 11:45:34 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_tablero;
    QAction *actionGuardar_tablero;
    QAction *actionSalir;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QRadioButton *radioButton_random;
    QRadioButton *radioButton_manual;
    QSpinBox *spinBox_rows;
    QSpinBox *spinBox_cols;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_generate;
    QSlider *slider_densidad;
    QLabel *label_densidad;
    QFrame *frame_2;
    QRadioButton *radioButton_ciegaAnchura;
    QRadioButton *radioButton_heuristica;
    QPushButton *pushButton_calcular;
    QRadioButton *radioButton_ciegaProfundidad;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *radioButton_heuristica_2;
    QRadioButton *radioButton_heuristica_3;
    QPushButton *pushButton_acercaDe;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(857, 658);
        actionAbrir_tablero = new QAction(MainWindow);
        actionAbrir_tablero->setObjectName(QString::fromUtf8("actionAbrir_tablero"));
        actionGuardar_tablero = new QAction(MainWindow);
        actionGuardar_tablero->setObjectName(QString::fromUtf8("actionGuardar_tablero"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 591, 591));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(620, 10, 221, 291));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        radioButton_random = new QRadioButton(frame);
        radioButton_random->setObjectName(QString::fromUtf8("radioButton_random"));
        radioButton_random->setGeometry(QRect(20, 100, 102, 21));
        radioButton_random->setChecked(true);
        radioButton_manual = new QRadioButton(frame);
        radioButton_manual->setObjectName(QString::fromUtf8("radioButton_manual"));
        radioButton_manual->setGeometry(QRect(20, 180, 102, 21));
        spinBox_rows = new QSpinBox(frame);
        spinBox_rows->setObjectName(QString::fromUtf8("spinBox_rows"));
        spinBox_rows->setGeometry(QRect(20, 60, 58, 25));
        spinBox_rows->setValue(10);
        spinBox_cols = new QSpinBox(frame);
        spinBox_cols->setObjectName(QString::fromUtf8("spinBox_cols"));
        spinBox_cols->setGeometry(QRect(130, 60, 58, 25));
        spinBox_cols->setValue(10);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(24, 30, 50, 15));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 30, 61, 16));
        pushButton_generate = new QPushButton(frame);
        pushButton_generate->setObjectName(QString::fromUtf8("pushButton_generate"));
        pushButton_generate->setGeometry(QRect(60, 250, 111, 24));
        slider_densidad = new QSlider(frame);
        slider_densidad->setObjectName(QString::fromUtf8("slider_densidad"));
        slider_densidad->setGeometry(QRect(21, 133, 151, 33));
        slider_densidad->setMinimum(5);
        slider_densidad->setMaximum(85);
        slider_densidad->setValue(15);
        slider_densidad->setOrientation(Qt::Horizontal);
        slider_densidad->setTickPosition(QSlider::TicksBothSides);
        label_densidad = new QLabel(frame);
        label_densidad->setObjectName(QString::fromUtf8("label_densidad"));
        label_densidad->setGeometry(QRect(180, 140, 16, 16));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(620, 310, 221, 201));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        radioButton_ciegaAnchura = new QRadioButton(frame_2);
        radioButton_ciegaAnchura->setObjectName(QString::fromUtf8("radioButton_ciegaAnchura"));
        radioButton_ciegaAnchura->setEnabled(true);
        radioButton_ciegaAnchura->setGeometry(QRect(20, 30, 171, 21));
        radioButton_ciegaAnchura->setChecked(true);
        radioButton_heuristica = new QRadioButton(frame_2);
        radioButton_heuristica->setObjectName(QString::fromUtf8("radioButton_heuristica"));
        radioButton_heuristica->setGeometry(QRect(20, 100, 171, 21));
        radioButton_heuristica->setChecked(false);
        pushButton_calcular = new QPushButton(frame_2);
        pushButton_calcular->setObjectName(QString::fromUtf8("pushButton_calcular"));
        pushButton_calcular->setGeometry(QRect(50, 170, 121, 24));
        radioButton_ciegaProfundidad = new QRadioButton(frame_2);
        radioButton_ciegaProfundidad->setObjectName(QString::fromUtf8("radioButton_ciegaProfundidad"));
        radioButton_ciegaProfundidad->setEnabled(true);
        radioButton_ciegaProfundidad->setGeometry(QRect(20, 50, 191, 21));
        radioButton_ciegaProfundidad->setChecked(false);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 121, 16));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 161, 16));
        label_4->setFont(font);
        radioButton_heuristica_2 = new QRadioButton(frame_2);
        radioButton_heuristica_2->setObjectName(QString::fromUtf8("radioButton_heuristica_2"));
        radioButton_heuristica_2->setGeometry(QRect(20, 120, 181, 21));
        radioButton_heuristica_3 = new QRadioButton(frame_2);
        radioButton_heuristica_3->setObjectName(QString::fromUtf8("radioButton_heuristica_3"));
        radioButton_heuristica_3->setGeometry(QRect(20, 140, 161, 21));
        pushButton_acercaDe = new QPushButton(centralWidget);
        pushButton_acercaDe->setObjectName(QString::fromUtf8("pushButton_acercaDe"));
        pushButton_acercaDe->setGeometry(QRect(670, 540, 121, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 857, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir_tablero);
        menuArchivo->addAction(actionGuardar_tablero);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "*** IA - 2011/2012 - Estrategias de b\303\272squedas ***", 0, QApplication::UnicodeUTF8));
        actionAbrir_tablero->setText(QApplication::translate("MainWindow", "Abrir tablero...", 0, QApplication::UnicodeUTF8));
        actionGuardar_tablero->setText(QApplication::translate("MainWindow", "Guardar tablero...", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        radioButton_random->setText(QApplication::translate("MainWindow", "Aleatorio", 0, QApplication::UnicodeUTF8));
        radioButton_manual->setText(QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Filas", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Columnas", 0, QApplication::UnicodeUTF8));
        pushButton_generate->setText(QApplication::translate("MainWindow", "Generar", 0, QApplication::UnicodeUTF8));
        label_densidad->setText(QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8));
        radioButton_ciegaAnchura->setText(QApplication::translate("MainWindow", "B\303\272squeda en anchura", 0, QApplication::UnicodeUTF8));
        radioButton_heuristica->setText(QApplication::translate("MainWindow", "Dist. eucl\303\255dea", 0, QApplication::UnicodeUTF8));
        pushButton_calcular->setText(QApplication::translate("MainWindow", "Calcular", 0, QApplication::UnicodeUTF8));
        radioButton_ciegaProfundidad->setText(QApplication::translate("MainWindow", "B\303\272squeda en profundidad", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "B\303\272squeda ciega", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "B\303\272squeda heur\303\255stica A*", 0, QApplication::UnicodeUTF8));
        radioButton_heuristica_2->setText(QApplication::translate("MainWindow", "Dist. Manhattan", 0, QApplication::UnicodeUTF8));
        radioButton_heuristica_3->setText(QApplication::translate("MainWindow", "Dist. Mahalanobis", 0, QApplication::UnicodeUTF8));
        pushButton_acercaDe->setText(QApplication::translate("MainWindow", "Acerca de ...", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
