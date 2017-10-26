/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_PortStatus;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_port;
    QSpacerItem *verticalSpacer_3;
    QComboBox *comboBox_baudrate;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox_Parity;
    QFormLayout *formLayout;
    QPushButton *pButton_Start;
    QPushButton *pButton_Reset;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QTableWidget *panelTable;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(476, 318);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_PortStatus = new QLabel(centralWidget);
        label_PortStatus->setObjectName(QStringLiteral("label_PortStatus"));
        label_PortStatus->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_PortStatus);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));

        verticalLayout->addWidget(comboBox_port);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        comboBox_baudrate = new QComboBox(centralWidget);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));

        verticalLayout->addWidget(comboBox_baudrate);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        comboBox_Parity = new QComboBox(centralWidget);
        comboBox_Parity->setObjectName(QStringLiteral("comboBox_Parity"));

        verticalLayout->addWidget(comboBox_Parity);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pButton_Start = new QPushButton(centralWidget);
        pButton_Start->setObjectName(QStringLiteral("pButton_Start"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pButton_Start);

        pButton_Reset = new QPushButton(centralWidget);
        pButton_Reset->setObjectName(QStringLiteral("pButton_Reset"));

        formLayout->setWidget(2, QFormLayout::LabelRole, pButton_Reset);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::SpanningRole, verticalSpacer_5);


        formLayout_2->setLayout(2, QFormLayout::LabelRole, formLayout);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::SpanningRole, verticalSpacer_4);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, formLayout_2);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, formLayout_3);

        panelTable = new QTableWidget(centralWidget);
        if (panelTable->columnCount() < 3)
            panelTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        panelTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        panelTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        panelTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (panelTable->rowCount() < 32)
            panelTable->setRowCount(32);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        panelTable->setItem(0, 0, __qtablewidgetitem3);
        panelTable->setObjectName(QStringLiteral("panelTable"));
        panelTable->setMinimumSize(QSize(351, 241));
        panelTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        panelTable->setTabKeyNavigation(true);
        panelTable->setAlternatingRowColors(false);
        panelTable->setRowCount(32);
        panelTable->setColumnCount(3);
        panelTable->horizontalHeader()->setVisible(true);
        panelTable->horizontalHeader()->setCascadingSectionResizes(false);
        panelTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        panelTable->verticalHeader()->setVisible(true);
        panelTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, panelTable);


        gridLayout->addLayout(formLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        panelTable->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\241\346\255\245\345\231\250\346\243\200\346\265\213\345\267\245\345\205\267", Q_NULLPTR));
        label_PortStatus->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\267\262\345\205\263\351\227\255", Q_NULLPTR));
        comboBox_baudrate->clear();
        comboBox_baudrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
        );
        comboBox_baudrate->setCurrentText(QApplication::translate("MainWindow", "115200", Q_NULLPTR));
        comboBox_Parity->clear();
        comboBox_Parity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Even", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Odd", Q_NULLPTR)
        );
        pButton_Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        pButton_Reset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = panelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\345\245\266\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = panelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\347\224\265\345\257\274\347\216\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = panelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));

        const bool __sortingEnabled = panelTable->isSortingEnabled();
        panelTable->setSortingEnabled(false);
        panelTable->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
