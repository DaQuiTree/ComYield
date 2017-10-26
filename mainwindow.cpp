#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yielddata.h"

static uchar DataXor(uchar *ptr,ushort len)
{
  ushort i;
  uchar xorV;

  xorV=0;
  for(i=0;i<len;i++)
  {
      xorV ^= ptr[i];
  }
  return(xorV);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSerialPort = new QSerialPort;

    //PushButoon Slot
    QObject::connect(ui->pButton_Start, SIGNAL(clicked(bool)), this, SLOT(StartSlot()));
    QObject::connect(ui->pButton_Reset, SIGNAL(clicked(bool)), this, SLOT(ResetSlot()));
    QObject::connect(this->mSerialPort, SIGNAL(readyRead()), this, SLOT(HandlingReadDataSlot()));

    qsrand(10);//产生随机数
    GenericPanel();//产生随机数

    //Init UI
    InitUI();
}

MainWindow::~MainWindow()
{
    delete mSerialPort;
    delete ui;
}

void MainWindow::StartSlot()
{
    QSerialPort::BaudRate mBaudRate;
    QSerialPort::Parity mParity;
    static bool portStatus = 0;

    if(!portStatus)
    {
        mSerialPort->setPortName(ui->comboBox_port->currentText());//port

        switch(ui->comboBox_baudrate->currentIndex())//baudRate
        {
            case 0: mBaudRate = QSerialPort::Baud115200; break;
            case 1: mBaudRate = QSerialPort::Baud57600; break;
            case 2: mBaudRate = QSerialPort::Baud38400; break;
            case 3: mBaudRate = QSerialPort::Baud19200; break;
            case 4: mBaudRate = QSerialPort::Baud9600; break;
            default: mBaudRate = QSerialPort::Baud57600; break;
        }
        mSerialPort->setBaudRate(mBaudRate);

        switch(ui->comboBox_Parity->currentIndex())//baudRate
        {
            case 0: mParity = QSerialPort::NoParity; break;
            case 1: mParity = QSerialPort::EvenParity; break;
            case 2: mParity = QSerialPort::OddParity; break;
            default: mParity = QSerialPort::NoParity; break;
        }
        mSerialPort->setParity(mParity);

        mSerialPort->setDataBits(QSerialPort::Data8); //other
        mSerialPort->setStopBits(QSerialPort::OneStop);
        mSerialPort->setFlowControl(QSerialPort::NoFlowControl);

        portStatus = mSerialPort->open(QIODevice::ReadWrite);
        if(portStatus){
            ui->label_PortStatus->setText("串口已开启");
            ui->pButton_Start->setText("close");
        }else{
            ui->label_PortStatus->setText("打开失败");
        }
    }else{
        mSerialPort->close();
        portStatus = 0;
        ui->label_PortStatus->setText("串口已关闭");
        ui->pButton_Start->setText("start");
    }
}

void MainWindow::ResetSlot()
{
    GenericPanel();
    FillTable();
}

void MainWindow::InitUI()
{
    //Init combobox baudrate & parity
    ui->comboBox_baudrate->setCurrentText("38400");//38400
    ui->comboBox_Parity->setCurrentText("Even");//parityEven

    //Init Serial Port
    QList<QSerialPortInfo> portList;
    QSerialPortInfo *mSerialPortInfo = new QSerialPortInfo;

    portList = mSerialPortInfo->availablePorts();
    for(int i=0; i < portList.count(); i++)
    {
        ui->comboBox_port->addItem(portList.at(i).portName());
    }
    delete mSerialPortInfo;
    FillTable();
}

void MainWindow::HandlingReadDataSlot()
{
    QByteArray buffer;
    QByteArray cmdRead,cmdClear;
    ushort mv,cv;
    bool bc;

    if(mSerialPort->bytesAvailable() >= 5){
        buffer = mSerialPort->readAll();
        if(DataXor((uchar*)buffer.data(), 4) == buffer[4]) //校验通过...
        {
            switch(buffer[3])
            {
                case 0x74://获取数据
                    yd[buffer[0]-1].GetData(mv,cv,bc);
                    cmdRead = QByteArray::fromHex("100107740120700093025D00FB000004");
                    cmdRead[1] = (uchar)buffer[0];
                    cmdRead[9] = (uchar)(mv>>8);
                    cmdRead[8] = (uchar)mv;
                    cmdRead[7] = (uchar)cv;
                    cmdRead[15] = DataXor((uchar*)cmdRead.data(),15);
                    mSerialPort->write(cmdRead);
                    break;
                case 0x7A:
                    cmdClear = QByteArray::fromHex("0501077A79");
                    cmdClear[1] = (uchar)buffer[0];
                    cmdClear[0] = (uchar)buffer[1];
                    cmdClear[4] = DataXor((uchar*)cmdClear.data(),4);
                    ChangeClearSta(buffer[0]);
                    mSerialPort->write(cmdClear);
                    break;
                default: break;
            }
        }
    }
}

void MainWindow::GenericPanel()
{
    for(int i = 0; i < 32; i++)
    {
        yd[i].GenericData();
    }
}

void MainWindow::FillTable()
{
    QTableWidgetItem *item;
    QByteArray array[2];
    ushort mv, cv;
    QString str1,str2;
    bool bc;

    for(int i = 0; i < 32; i++)
    {
        yd[i].GetData(mv,cv,bc);

        str1 = array[0].setNum(mv,16);
        str2 = array[1].setNum((uchar)cv,16);

        item = new QTableWidgetItem();
        int len = str1.length();
        for(int j = 0; j < 4-len; j++){
            str1.insert(0,"0");
        }
        item->setText(str1.toUpper());
        ui->panelTable->setItem(i,0,item);

        item = new QTableWidgetItem();
        if(str2.length() == 1)str2.insert(0,"0");
        item->setText(str2.toUpper());
        ui->panelTable->setItem(i,1,item);

        item = new QTableWidgetItem();
        if(bc){
            item->setText("Y");
        }else{
            item->setText("N");
        }
        ui->panelTable->setItem(i,2,item);
    }
}

void MainWindow::ChangeClearSta(int pos)
{
    QTableWidgetItem* item = new QTableWidgetItem();
    QColor cl(0,255,0);

    item->setText("Y");
    item->setBackgroundColor(cl);
    ui->panelTable->setItem(pos-1, 2, item);
}
