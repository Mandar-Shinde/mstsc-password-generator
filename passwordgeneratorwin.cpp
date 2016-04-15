#include "passwordgeneratorwin.h"
#include "ui_passwordgeneratorwin.h"
#include <qmessagebox.h>

#pragma comment(lib, "crypt32.lib")
#include <windows.h>
#include <Wincrypt.h>
#include <tlhelp32.h>
#include <tchar.h>

char* encryptRDPPassword(QString testPassword )
{
    int count =0;
    char *encPass;
    DATA_BLOB DataIn,DataOut;
    mbstate_t state;
    memset(&state, 0, sizeof(state));
    DataIn.pbData = (BYTE *)testPassword.utf16();

    if (DataIn.pbData == NULL)
        return NULL;

    DataIn.cbData = (DWORD)(wcslen((LPWSTR)DataIn.pbData) * sizeof(WCHAR));
    if (CryptProtectData(&DataIn,(LPCWSTR)L"simple.wincrypt",NULL,NULL,NULL,CRYPTPROTECT_UI_FORBIDDEN,&DataOut))
    {
        encPass = (char*)calloc(DataOut.cbData*2 + 1,1);
        for (count=0; count < DataOut.cbData; count++ )
            sprintf(encPass, "%s%02X", encPass, DataOut.pbData[count]);
        LocalFree(DataOut.pbData);
        return encPass;
    }
    QMessageBox::information(0," Password Generation fail"," Password Generation fail");
    return NULL;
}

PasswordGeneratorWin::PasswordGeneratorWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PasswordGeneratorWin)
{
    ui->setupUi(this);
}

PasswordGeneratorWin::~PasswordGeneratorWin()
{
    delete ui;
}

void PasswordGeneratorWin::on_GeneratePassword_clicked()
{
    ui->leNewPassword->clear();
    QString password=encryptRDPPassword(ui->lePassword->text());
    ui->leNewPassword->appendPlainText(password);
    ui->leSize->setText(QString::number( password.length()));
    ui->leMstscOutput->appendPlainText("password 51:b:"+password);
}

