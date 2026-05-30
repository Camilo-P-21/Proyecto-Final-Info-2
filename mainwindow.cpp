#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "juegogui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    JuegoGUI *miJuego = new JuegoGUI();
    setCentralWidget(miJuego);
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}