#include "mainwindow.h"
// создание всех визуальных элементов без конструктора
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_model = new DataModel(this);

    m_model->Open();

    m_list = new QListView(this);
    m_list->setModel(m_model);

    m_edit = new QLineEdit("текст ...........",this);
    m_btnAdd = new QPushButton("Отправить", this);
    m_btnDel = new QPushButton("Очистить буфер", this);
    m_chkbox_rts = new QCheckBox("RTS", this);
    m_chkbox_dtr = new QCheckBox("DTR", this);
    //m_serial_rts = new QLineEdit("RTS",this);
    //m_serial_dts = new QLineEdit("RTS",this);

    setLayout(new QVBoxLayout);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(m_edit);
    lay->addWidget(m_btnAdd);
    lay->addWidget(m_btnDel);
    lay->addWidget(m_chkbox_rts);
    lay->addWidget(m_chkbox_dtr);

    layout()->addWidget(m_list);
    layout()->addItem(lay);

    connect(m_btnAdd, SIGNAL(clicked(bool)),this,SLOT(insertValueFromLineEdit()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::insertValueFromLineEdit()
{        
        QByteArray ba = m_edit->text().toLocal8Bit();
        char *c_str2 = ba.data();

        if (m_model->com.Write(c_str2)) {
                    m_model->addValue(m_edit->text());
            }
            else {
                m_model->addValue("Write error.\n");
            }

        ceSerial::Delay(3000); // delay to wait for a character

}
