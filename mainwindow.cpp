#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QClipboard>

QString ConstructPrompt(Ui::MainWindow* QUI)
{
    QString Prompt;
    Prompt.append(QUI->permutationsEdit->text());
    Prompt.append(" ");
    Prompt.append(QUI->prefixEdit->text());
    Prompt.append(" ");
    Prompt.append(QUI->subjectEdit->text());
    Prompt.append(", ");
    Prompt.append(QUI->suffixEdit->text());
    return Prompt;
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->promptEdit->setPlainText(ConstructPrompt(ui));

};


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_subjectEdit_textChanged(const QString &arg1)
{
    ConstructPrompt(ui);
}


void MainWindow::on_permutationsEdit_textChanged(const QString &arg1)
{
    ConstructPrompt(ui);
}


void MainWindow::on_prefixEdit_textChanged(const QString &arg1)
{
    ConstructPrompt(ui);
}


void MainWindow::on_suffixEdit_textChanged(const QString &arg1)
{
    ConstructPrompt(ui);
}


void MainWindow::on_pushButton_clicked()
{
    // Access the clipboard
    QClipboard *clipboard = QApplication::clipboard();

    // Set text to the clipboard
    clipboard->setText(QString(ui->promptEdit->toPlainText()));

}

