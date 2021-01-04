#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MaFenetre; }
QT_END_NAMESPACE

class MaFenetre : public QMainWindow
{
    Q_OBJECT

public:
    MaFenetre(QWidget *parent = nullptr);
    ~MaFenetre();

private slots:
    void on_Connect_clicked();
    void on_Disconnect_clicked();
    void on_Exit_clicked();
    void on_Withdraw_clicked();
    void on_Deposit_clicked();
    void on_Update_clicked();

private:
    Ui::MaFenetre *ui;
    bool isConnectionClosed;
    void updateUI();
    void readName();
    void readCredit();
};
#endif // MAFENETRE_H
