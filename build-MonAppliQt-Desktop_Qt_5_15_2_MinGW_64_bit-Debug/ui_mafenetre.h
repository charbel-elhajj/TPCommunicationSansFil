/********************************************************************************
** Form generated from reading UI file 'mafenetre.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAFENETRE_H
#define UI_MAFENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaFenetre
{
public:
    QWidget *centralwidget;
    QPushButton *Connect;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *Disconnect;
    QPushButton *Exit;
    QLineEdit *LastName;
    QLineEdit *FirstName;
    QLineEdit *NbUnit;
    QSpinBox *NbDecrement;
    QSpinBox *NbIncrement;
    QPushButton *Deposit;
    QPushButton *Withdraw;
    QPushButton *Update;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label_5;
    QLineEdit *Version;
    QLabel *Image;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MaFenetre)
    {
        if (MaFenetre->objectName().isEmpty())
            MaFenetre->setObjectName(QString::fromUtf8("MaFenetre"));
        MaFenetre->resize(800, 600);
        centralwidget = new QWidget(MaFenetre);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(30, 460, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 101, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 80, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 110, 51, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 140, 47, 13));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 210, 151, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 240, 91, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 270, 161, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(350, 330, 161, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(350, 360, 161, 16));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(140, 460, 75, 23));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(630, 460, 81, 23));
        LastName = new QLineEdit(centralwidget);
        LastName->setObjectName(QString::fromUtf8("LastName"));
        LastName->setGeometry(QRect(500, 110, 113, 20));
        FirstName = new QLineEdit(centralwidget);
        FirstName->setObjectName(QString::fromUtf8("FirstName"));
        FirstName->setGeometry(QRect(500, 140, 113, 20));
        NbUnit = new QLineEdit(centralwidget);
        NbUnit->setObjectName(QString::fromUtf8("NbUnit"));
        NbUnit->setGeometry(QRect(560, 240, 51, 20));
        NbUnit->setReadOnly(true);
        NbDecrement = new QSpinBox(centralwidget);
        NbDecrement->setObjectName(QString::fromUtf8("NbDecrement"));
        NbDecrement->setGeometry(QRect(560, 270, 51, 22));
        NbIncrement = new QSpinBox(centralwidget);
        NbIncrement->setObjectName(QString::fromUtf8("NbIncrement"));
        NbIncrement->setGeometry(QRect(560, 360, 51, 22));
        Deposit = new QPushButton(centralwidget);
        Deposit->setObjectName(QString::fromUtf8("Deposit"));
        Deposit->setGeometry(QRect(634, 360, 81, 23));
        Withdraw = new QPushButton(centralwidget);
        Withdraw->setObjectName(QString::fromUtf8("Withdraw"));
        Withdraw->setGeometry(QRect(634, 270, 81, 23));
        Update = new QPushButton(centralwidget);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(634, 140, 81, 23));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(329, 89, 411, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(330, 220, 411, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(330, 339, 411, 71));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 430, 41, 16));
        Version = new QLineEdit(centralwidget);
        Version->setObjectName(QString::fromUtf8("Version"));
        Version->setGeometry(QRect(70, 430, 113, 20));
        Version->setReadOnly(true);
        Image = new QLabel(centralwidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(40, 110, 251, 261));
        Image->setPixmap(QPixmap(QString::fromUtf8("iimage.png")));
        MaFenetre->setCentralWidget(centralwidget);
        frame_3->raise();
        frame->raise();
        frame_2->raise();
        Connect->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        Disconnect->raise();
        Exit->raise();
        LastName->raise();
        FirstName->raise();
        NbUnit->raise();
        NbDecrement->raise();
        NbIncrement->raise();
        Deposit->raise();
        Withdraw->raise();
        Update->raise();
        label_5->raise();
        Version->raise();
        Image->raise();
        menubar = new QMenuBar(MaFenetre);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MaFenetre->setMenuBar(menubar);
        statusbar = new QStatusBar(MaFenetre);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MaFenetre->setStatusBar(statusbar);

        retranslateUi(MaFenetre);

        QMetaObject::connectSlotsByName(MaFenetre);
    } // setupUi

    void retranslateUi(QMainWindow *MaFenetre)
    {
        MaFenetre->setWindowTitle(QCoreApplication::translate("MaFenetre", "MaFenetre", nullptr));
        Connect->setText(QCoreApplication::translate("MaFenetre", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MaFenetre", "Porte Monnaie", nullptr));
        label_2->setText(QCoreApplication::translate("MaFenetre", "Identite:", nullptr));
        label_3->setText(QCoreApplication::translate("MaFenetre", "Nom:", nullptr));
        label_4->setText(QCoreApplication::translate("MaFenetre", "Prenom:", nullptr));
        label_6->setText(QCoreApplication::translate("MaFenetre", "Decrementer le porte monnaie", nullptr));
        label_7->setText(QCoreApplication::translate("MaFenetre", "Nombre d'unite:", nullptr));
        label_8->setText(QCoreApplication::translate("MaFenetre", "Nombre d'unite a decrementer:", nullptr));
        label_9->setText(QCoreApplication::translate("MaFenetre", "Incrementer le porte monnaie", nullptr));
        label_10->setText(QCoreApplication::translate("MaFenetre", "Nombre a incrementer:", nullptr));
        Disconnect->setText(QCoreApplication::translate("MaFenetre", "Disconnect", nullptr));
        Exit->setText(QCoreApplication::translate("MaFenetre", "Quitter", nullptr));
        Deposit->setText(QCoreApplication::translate("MaFenetre", "Charger", nullptr));
        Withdraw->setText(QCoreApplication::translate("MaFenetre", "Payer", nullptr));
        Update->setText(QCoreApplication::translate("MaFenetre", "Mise a jour", nullptr));
        label_5->setText(QCoreApplication::translate("MaFenetre", "Version:", nullptr));
        Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaFenetre: public Ui_MaFenetre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAFENETRE_H
