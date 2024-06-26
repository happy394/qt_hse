#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "listmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      // list(new QStringListModel),
      // filmList(new Netflix),
      tableModel(new tablemodel) // dynamic memory
{
    ui->setupUi(this);

    // list->setStringList(filmList->stringList);
    // ui->listView->setModel(list);
    ui->tableView->setModel(tableModel);

    for (const QString &i: tableModel->getGenres())
        ui->comboBox->addItem(i);
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete list;
    // delete filmList;
    delete tableModel;
}

void MainWindow::on_pushButton_clicked()
{
    ui->searchLineEdit->setText("Pushed");
}


// void MainWindow::on_listView_clicked(const QModelIndex &index)
// {
//     QList <QString> row = filmList->list[index.row()];
//     ui->countryLineEdit->setText(row[2]);
//     ui->countryLineEdit->setEnabled(false);
//     ui->dateLineEdit->setText(row[4]);
//     ui->dateLineEdit->setEnabled(false);
//     ui->ratingLineEdit->setText(row[5]);
//     ui->ratingLineEdit->setEnabled(false);
// }

