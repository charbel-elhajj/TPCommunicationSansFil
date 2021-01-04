#include "mafenetre.h"
#include "ui_mafenetre.h"
#include "ODALID.h"
#include <QtGui>
MaFenetre::MaFenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MaFenetre)
{
    ui->setupUi(this);
    ui->Image->setPixmap(QPixmap("C:/Users/ce135968/Desktop/Application/MonAppliQt/iimage.png")); // ce lien doit etre adapté en foncction de l'emplacement de l'image
    this->isConnectionClosed=true;
    updateUI();
}

MaFenetre::~MaFenetre()
{
    delete ui;
}

#define secteur_identification      2  //le numéro du secteur correspondant à l'identification
#define secteur_compteur            3  //le numéro du secteur correspondant au compteur
#define index_key_identification    2  //index de l’EEPROM (de 0 à 15 suivant le bloc)
#define index_key_compteur          3  //index de l’EEPROM (de 0 à 15 suivant le bloc)

uint8_t key1[6] = {0xA0,0xA1,0xA2,0xA3,0xA4,0xA5};  //Clé A utilisé pour l'identification
uint8_t key2[6] = {0xB0,0xB1,0xB2,0xB3,0xB4,0xB5};  //Clé B utilisé pour l'identification
uint8_t key3[6] = {0xC0,0xC1,0xC2,0xC3,0xC4,0xC5};  //Clé A utilisé pour le compteur
uint8_t key4[6] = {0xD0,0xD1,0xD2,0xD3,0xD4,0xD5};  //Clé B utilisé pour le compteur
uint8_t atq[2]; // réponse à la requette
uint8_t sak[1]; // la réponse (acknowledgement) de la carte sélectionnée
uint8_t uid[12]; // identifiant unique de la carte 
uint16_t uid_len = 12; // taille de l'identifiat de la carte
ReaderName MonLecteur; // Le lecteur
char pszHost[] = "192.168.1.4"; // ip en cas de communiaction TCP/IP (qui n'est pas notre cas)

void MaFenetre::on_Update_clicked()
{
    //Variables
    uint8_t data[16];
    int16_t status = 0;
    QString firstName, lastName;

    //Nom et prénom saisis par l'utilisateur sur l'interface graphique
    lastName = ui->LastName->text();
    firstName = ui->FirstName->text();

    //Ecrire nom, block 10, secteur 2
    strncpy ((char*)data, lastName.toLatin1().constData(),16);
    qDebug() << "Data " << (char*)data;
    status = Mf_Classic_Write_Block(&MonLecteur, TRUE, (secteur_identification*4)+2, data, Auth_KeyB, 2);
    qDebug() << "Mf_Classic_Write_Block_10" << status;

//    if(status == 0)
//        LEDBuzzer(&MonLecteur, BUZZER_ON);
//    LEDBuzzer(&MonLecteur, BUZZER_OFF);

    //Ecrire prénom, block 9, secteur 2
    strncpy ((char*)data, firstName.toLatin1().constData(),16);
    qDebug() << "Data " << (char*)data;
    status = Mf_Classic_Write_Block(&MonLecteur, TRUE, (secteur_identification*4)+1, data, Auth_KeyB, 2);
    qDebug() << "Mf_Classic_Write_Block_9" << status;

//    if(status == 0)
//        LEDBuzzer(&MonLecteur, BUZZER_ON);
//    LEDBuzzer(&MonLecteur, BUZZER_OFF);
}


void MaFenetre::on_Connect_clicked()
{
    char version[30];
    uint8_t serial[4];
    char stackReader[20];

    uint16_t status = 0;
    //MonLecteur.Type = ReaderTCP;
    //strcpy(MonLecteur.IPReader, pszHost);
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = OpenCOM(&MonLecteur);
    qDebug() << "OpenCOM" << status;
    if(status == 0)
    {
        this->isConnectionClosed = false;
        updateUI();
        //Activer champ RF du lecteur
        RF_Power_Control(&MonLecteur, TRUE, 0);

        //Chargement des clés dans la mémoire du lecteur
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key1, index_key_identification);
        qDebug() << "Mf_Classic_LoadKey A" << status;
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key2, index_key_identification);
        qDebug() << "Mf_Classic_LoadKey B" << status;
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyA, key3, index_key_compteur);
        qDebug() << "Mf_Classic_LoadKey A" << status;
        status = Mf_Classic_LoadKey(&MonLecteur, Auth_KeyB, key4, index_key_compteur);
        qDebug() << "Mf_Classic_LoadKey B" << status;
		// prise en contact avec la carte 
        status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);

        //Affichage version
        status = Version(&MonLecteur, version, serial, stackReader);
        ui->Version->setText(version);
        ui->Version->update();

//        status = LEDBuzzer(&MonLecteur, LED_GREEN_ON);

//        status = LEDBuzzer(&MonLecteur, BUZZER_ON);
        readName();
        readCredit();
    }

}


void MaFenetre::on_Disconnect_clicked()
{
    int16_t status = 0;
	// Eteindre champs magnétique du lecteur  
    RF_Power_Control(&MonLecteur, FALSE, 0);
//    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    qDebug() << "CloseCOM"<<status;
    if(status == 0)
    {
        this->isConnectionClosed = true;
        updateUI();
    }
}

void MaFenetre::on_Exit_clicked()
{
    int16_t status = 0;
	// Eteindre champs magnétique du lecteur  
    RF_Power_Control(&MonLecteur, FALSE, 0);
//    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    qDebug() << "CloseCOM"<<status;
    qApp->quit();
}

void MaFenetre::on_Withdraw_clicked()
{
    uint32_t value;
    int16_t status = 0;
    int amount = ui->NbDecrement->value();
    ui->NbDecrement->setValue(0);

	//Décrémenter la valeur de credit dans le Backup Compteur (bloc 13) de 1
	status = Mf_Classic_Decrement_Value(&MonLecteur, TRUE, (secteur_compteur*4)+2, amount, (secteur_compteur*4)+1, Auth_KeyA, index_key_compteur);
	qDebug() << "Mf_Classic_Decrement" << status;
	//Copier la valeur du Backup Compteur (bloc 13) dans le Compteur (bloc 14)
	status = Mf_Classic_Restore_Value(&MonLecteur, TRUE, (secteur_compteur*4)+1, (secteur_compteur*4)+2, Auth_KeyB, index_key_compteur);
	qDebug() << "Mf_Classic_Restore" << status;




    readCredit();

}

void MaFenetre::on_Deposit_clicked()
{
    uint32_t value;
    int16_t status = 0;
    int amount = ui->NbIncrement->value();
    ui->NbIncrement->setValue(0);

	//Décrémenter la valeur de credit dans le Backup Compteur (bloc 13) de 1
	status = Mf_Classic_Increment_Value(&MonLecteur, TRUE, (secteur_compteur*4)+2, amount, (secteur_compteur*4)+1, Auth_KeyB, index_key_compteur);
	qDebug() << "Mf_Classic_Decrement" << status;
	//Copier la valeur du Backup Compteur (bloc 13) dans le Compteur (bloc 14)
	status = Mf_Classic_Restore_Value(&MonLecteur, TRUE, (secteur_compteur*4)+1, (secteur_compteur*4)+2, Auth_KeyB, index_key_compteur);
	qDebug() << "Mf_Classic_Restore" << status;




    readCredit();
}


void MaFenetre::readName()
{
    uint8_t data[16];
    int16_t status = 0;
    QString firstName;
    QString lastName;
    //Lire le nom du bloc 10, secteur 2
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, (secteur_identification*4)+2, data, Auth_KeyA, index_key_identification);
    qDebug() << "Mf_Classic_Read_Block_10" << status;

    if(status == 0){
        
//        LEDBuzzer(&MonLecteur, BUZZER_ON);
        lastName = (char*)data;
        ui->LastName->setText(lastName);
        ui->LastName->update();
    }
//    LEDBuzzer(&MonLecteur, BUZZER_OFF);

    //Lire le prénom du bloc 9, secteur 2
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, (secteur_identification*4)+1, data, Auth_KeyA, index_key_identification);
    qDebug() << "Mf_Classic_Read_Block_9" << status;
    if(status == 0){
        //Biip
//        LEDBuzzer(&MonLecteur, BUZZER_ON);
        firstName = (char*)data;
        ui->FirstName->setText(firstName);
        ui->FirstName->update();
    }
//    LEDBuzzer(&MonLecteur, BUZZER_OFF);

    qDebug() << "Nom et Prenom: " << lastName <<" "<<firstName;
}

void MaFenetre::updateUI()
{
    if(this->isConnectionClosed)
    {
        ui->FirstName->setEnabled(false);
        ui->LastName->setEnabled(false);
        ui->NbDecrement->setEnabled(false);
        ui->NbIncrement->setEnabled(false);
        ui->Disconnect->setEnabled(false);
        ui->Update->setEnabled(false);
        ui->Withdraw->setEnabled(false);
        ui->Deposit->setEnabled(false);
    }
    else
    {
        ui->FirstName->setEnabled(true);
        ui->LastName->setEnabled(true);
        ui->NbDecrement->setEnabled(true);
        ui->NbIncrement->setEnabled(true);
        ui->Disconnect->setEnabled(true);
        ui->Update->setEnabled(true);
        ui->Withdraw->setEnabled(true);
        ui->Deposit->setEnabled(true);
    }
}

void MaFenetre::readCredit()
{
    uint32_t *value;
    int16_t status = 0;
    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, (secteur_compteur*4)+2, value, Auth_KeyA, index_key_compteur);
    ui->NbDecrement->setMaximum(*value);
    qDebug() << "Mf_Classic_Read_Value_14" << status;
    ui->NbUnit->setText(QString::number(*value));
    ui->NbUnit->update();
}

