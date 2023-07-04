#include "mainwindow.h"
#include "ui_mainwindow.h"

double calVal= 0.0;
bool divTrig= false;
bool mulTrig= false;
bool addTrig= false;
bool subTrig= false;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");

    ui->Display->setText(QString::number(calVal));
    QPushButton *numButtons[10];

    for(int i=0; i<10;++i){

        QString butName= "btn"+QString::number(i);
        numButtons[i]= MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this,
                SLOT(NumPressed()));

    }
    connect(ui->btnAdd, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->btnSub, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->btnDiv, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->btnMul, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->btnEq, SIGNAL(released()),this,
            SLOT(EqualButtonPressed()));
    connect(ui->btnClr, SIGNAL(released()),this,
            SLOT(ClearButtonPressed()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NumPressed(){

    QPushButton *button=(QPushButton *)sender();
    QString butval = button->text();
    QString displayVal= ui->Display->text();

    if(displayVal.toDouble()==0 || displayVal.toDouble() == 0.0){
        ui->Display->setText(butval);
    }
    else{
        QString newVal=displayVal+butval;
        double dbNewVal=newVal.toDouble();
        ui->Display->setText(QString::number(dbNewVal,'g',16));
    }


}

void MainWindow::MathButtonPressed(){

   divTrig= false;
   mulTrig= false;
   addTrig= false;
   subTrig= false;
   QString displayVal= ui->Display->text();
   calVal= displayVal.toDouble();
   QPushButton *button= (QPushButton *)sender();
   QString butval=button->text();

   if(QString::compare(butval,"/",Qt::CaseInsensitive)==0){
        divTrig=true;

   } else if(QString::compare(butval,"*",Qt::CaseInsensitive)==0){
            mulTrig=true;

        }else if(QString::compare(butval,"+",Qt::CaseInsensitive)==0){
            addTrig=true;

            } else{
            subTrig=true;

        }
            ui->Display->setText("");
}


void MainWindow::EqualButtonPressed(){

            double solution=0.0;

            QString displayVal= ui->Display->text();
            double dbDisplayVal=displayVal.toDouble();

            if(addTrig || subTrig||divTrig||mulTrig){
            if(addTrig){
                solution=calVal+dbDisplayVal;
            }
            else if(addTrig){
            solution=calVal+dbDisplayVal;
            }else if(subTrig){
            solution=calVal-dbDisplayVal;
            }else if(divTrig){
            solution=calVal/dbDisplayVal;
            }else{
            solution=calVal*dbDisplayVal;
            }
           }
           ui->Display->setText(QString::number(solution));
}


void MainWindow::ClearButtonPressed(){

           calVal=0.0;
           ui->Display->setText(QString::number(calVal));

}





