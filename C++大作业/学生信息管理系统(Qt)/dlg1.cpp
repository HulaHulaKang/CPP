#include "dlg1.h"
#include "ui_dlg1.h"
#include "dlg_btn_write.h"
#include "dlg_btn_show.h"
#include "dlg_btn_add.h"
#include "dlg_btn_find.h"
#include "dlg_btn_read.h"

Dlg1::Dlg1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg1)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());//固定窗口大小
}

Dlg1::~Dlg1()
{
    delete ui;
}



void Dlg1::on_Btn_write_clicked()
{
    static Dlg_Btn_write* dbw=new Dlg_Btn_write;
    dbw->show();
}


void Dlg1::on_Btn_show_clicked()
{
    static Dlg_Btn_show* dbs;
    if(dbs!=NULL)delete dbs;
    dbs=new Dlg_Btn_show();
    dbs->show();
}


void Dlg1::on_Btn_add_clicked()
{
    static Dlg_Btn_add dba;
    dba.show();
}


void Dlg1::on_Btn_find_clicked()
{
    static Dlg_Btn_find dbd;
    dbd.show();
}


void Dlg1::on_Btn_read_clicked()
{
    static Dlg_Btn_read dbr;
    dbr.show();
}



