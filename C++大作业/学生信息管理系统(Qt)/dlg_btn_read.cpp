#include "dlg_btn_read.h"
#include "ui_dlg_btn_read.h"

#include <string>
#include <fstream>
#include <sstream>
#include "classes/DataBase.h"
#include "dlg_fail.h"
#include "dlg_success.h"

extern DataBase mydata;

Dlg_Btn_read::Dlg_Btn_read(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Btn_read)
{
    ui->setupUi(this);
}

Dlg_Btn_read::~Dlg_Btn_read()
{
    delete ui;
}

void Dlg_Btn_read::on_Btn_read_clicked()
{
    using namespace std;
    string path=ui->lineEdit->text().toStdString();
    ifstream fin(path);

    if(!fin.is_open())
    {
        static Dlg_Fail dfail;
        dfail.show();
        return;
    }

    string oneline;
    while(!fin.eof())
    {
        getline(fin,oneline);
        if(oneline=="")continue;
        stringstream ssm;
        ssm<<oneline;
        string _name,_ID,_gender,_edu;
        int __rank;
        ssm>>_name>>_ID>>__rank>>_gender>>_edu;

        QString __name=QString::fromStdString(_name);
        QString __ID=QString::fromStdString(_ID);
        QString __gender=QString::fromStdString(_gender);
        QString __edu=QString::fromStdString(_edu);

        CS_Student stu1(__rank,__ID,__name,__gender,__edu);
        mydata.insert(stu1);

    }

    static Dlg_Success dsucc;
    dsucc.show();
    ui->lineEdit->setText("");
    this->close();
}

