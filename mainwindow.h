#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QListView>

#include <QMainWindow>

#include "datamodel.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    QListView   *m_list;
    QLineEdit   *m_edit;
    QPushButton *m_btnAdd;
    QPushButton *m_btnDel;

    QCheckBox *m_chkbox_rts;
    QCheckBox *m_chkbox_dtr;


    DataModel   *m_model;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void insertValueFromLineEdit();

};
#endif // MAINWINDOW_H
