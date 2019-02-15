#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    LoadSettings(); // when the window is show up call LoadSettings function.

}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::SaveSettings()
{
    //Save
    QSettings setting("MyApp","mysetting");  //MyApp = name, mysetting = subname
    setting.beginGroup("MainWindow");
    setting.setValue("position",this->geometry());
    setting.endGroup();

    qDebug() << "Saved";

}

void Dialog::LoadSettings()
{
    //Load
    QSettings setting("MyApp","mysetting");  //MyApp = name, mysetting = subname
    setting.beginGroup("MainWindow");
    QRect myrect = setting.value("position").toRect();
    setGeometry(myrect);
    setting.endGroup();

    qDebug() << "Loaded";
    //!!!!

}


void Dialog::on_pushButton_clicked()
{
    //Save
    SaveSettings(); //reason to create savesettings seperately is called disagn. we can call savesettings from everything
    //but calling on_pushbutton_clicked is a bit weird and outdate.

}

void Dialog::on_pushButton_2_clicked()
{
    //Load
    LoadSettings();

}

