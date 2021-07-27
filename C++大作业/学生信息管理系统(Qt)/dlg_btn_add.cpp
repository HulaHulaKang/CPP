#include "dlg_btn_add.h"
#include "ui_dlg_btn_add.h"
#include "classes/DataBase.h"
#include "dlg_success.h"

extern DataBase mydata;

Dlg_Btn_add::Dlg_Btn_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Btn_add)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());//固定窗口大小
}

Dlg_Btn_add::~Dlg_Btn_add()
{
    delete ui;
}

void Dlg_Btn_add::on_Btn_submit_clicked()
{
    if(ui->lineEdit_name->text()==""){return;}
    if(ui->lineEdit_ID->text()==""){return;}
    if(ui->lineEdit_rank->text()==""){return;}
    if(ui->lineEdit_gender->text()==""){return;}
    if(ui->lineEdit_edu->text()==""){return;}

    QString _name=ui->lineEdit_name->text();
    QString _ID=ui->lineEdit_ID->text();
    int _rank=ui->lineEdit_rank->text().toInt();
    QString _gender=ui->lineEdit_gender->text();
    QString _edu=ui->lineEdit_edu->text();

    CS_Student s(_rank,_ID,_name,_gender,_edu);
    mydata.insert(s);


    ui->lineEdit_name->setText("");
    ui->lineEdit_ID->setText("");
    ui->lineEdit_rank->setText("");
    ui->lineEdit_gender->setText("");
    ui->lineEdit_edu->setText("");

    static Dlg_Success dsucc;
    dsucc.show();
    this->close();
}

