#include "dlg_btn_write.h"
#include "ui_dlg_btn_write.h"
#include "dlg1.h"
#include <QMessageBox>
#include <fstream>
#include "dlg_fail.h"
#include "dlg_success.h"
#include<classes/DataBase.h>

int write(QString);
extern DataBase mydata;

Dlg_Btn_write::Dlg_Btn_write(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Btn_write)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());//固定窗口大小
}

Dlg_Btn_write::~Dlg_Btn_write()
{
    delete ui;
}

void Dlg_Btn_write::on_radio_default_clicked()
{
    ui->lineEdit_Path->setEnabled(false);
}


void Dlg_Btn_write::on_radio_personal_clicked()
{
    ui->lineEdit_Path->setEnabled(true);
}


void Dlg_Btn_write::on_Btn_cancel_clicked()
{
    this->close();
}



void Dlg_Btn_write::on_Btn_write_clicked()
{
    int result=QMessageBox::warning(this,"警告","如果同名文件存在，*点击“写入”会导致原来的文件内容被覆盖，请确认",QMessageBox::Ok|QMessageBox::Cancel);
     switch(result)
     {
         case QMessageBox::Ok:
                break;
         case QMessageBox::Cancel:
                return;
     }

      using namespace std;

    int flag;//flag用于标识写入结果
    QString qs;

    if(ui->radio_default->isChecked())  qs=ui->lineEdit_default->text();
    else                                qs=ui->lineEdit_Path->text();

    flag=write(qs);

    if(flag==-1)
    {
        static Dlg_Fail dfail;
        dfail.show();
    }

    else if(flag==0)
    {
        static Dlg_Success dsucc;
        dsucc.show();
        this->close();
    }

}


int write(QString qs)
{
    using namespace std;

    string path=qs.toStdString();
    ofstream fout(path);
    if(!fout.is_open())
    {
        return -1;
    }


    int n=mydata.gettotal();
    for(int i=0;i<n;++i)
    {
        fout<<mydata[i].getname().toStdString()
           <<"\t"
           <<mydata[i].getID().toStdString()
           <<"\t"
           <<mydata[i].getrank()
           <<"\t"
           <<mydata[i].getgender().toStdString()
           <<"\t"
           <<mydata[i].getEduBkg().toStdString()
           <<"\n";
    }
    return 0;
}
