/***************************************************************
 *Copyright(c) 2014-2015 Company By LH Unigress
 *All rights reserved.
 *�ļ����ƣ���¼��־�ļ�
 *��Ҫ�����������¼ʱ��״̬��Ϣ
 *
 *��ǰ�汾��V2.0
 *���ߣ�Kelvin Li
 *�������ڣ�2014/10
 *˵����
*****************************************************************/

#include <QSettings>
#include "myapp.h"

QString Myapp::AppPath = "";

//�洢��ǰ��¼�û���Ϣ,�����û������޸ĺ��û��˳�����
QString Myapp::CurrentUserName = "";
QString Myapp::CurrentUserPwd = "";
QString Myapp::CurrentUserType = "";
QString Myapp::CurrentUserId ="";

QString Myapp::LastLoginter = "";

QString Myapp::AppTitle = "���ڳ�������";
QString Myapp::CompanyName = "̫ԭ�����Ƽ����޹�˾";
QString Myapp::Contacts = "����ʦ";
QString Myapp::Address = "ɽ��ʡ̫ԭ����һ·��ͷ��ʡ���ϴ���1218";
QString Myapp::PhoneNumber = "18734153953";


Myapp::Myapp()
{
}

/*
 *�������ܣ���ȡ�����ļ�����
 *�����������
 *�����������
 *����ֵ:  ��
*/
void Myapp::ReadConfig()
{
    QString fileName = Myapp::AppPath+"config.txt";
    //��������ļ�������,���Գ�ʼֵ��������
    //û������жϵĻ�,���ø�ֵ��Ϊ��
    if(!myHelper::FileIsExist(fileName))
    {
        Myapp::CurrentUserType = Myapp::CurrentUserType.toLatin1();
        Myapp::CurrentUserName = Myapp::CurrentUserName.toLatin1();
        Myapp::AppTitle = Myapp::AppTitle.toLatin1();
        Myapp::CompanyName = Myapp::CompanyName.toLatin1();
        Myapp::Address = Myapp::Address.toLatin1();
        return;
    }

    QSettings *set = new QSettings(fileName,QSettings::IniFormat);
    set->beginGroup("AppConfig");

    Myapp::AppTitle = set->value("AppTitle").toString();
    Myapp::CompanyName = set->value("CompanyName").toString();
    Myapp::Contacts = set->value("Contacts").toString();
    Myapp::PhoneNumber = set->value("PhoneNumber").toString();
    Myapp::Address = set->value("Address").toString();

    set->endGroup();

}

void Myapp::WriteConfig()
{
    QString fileName = Myapp::AppPath+"config.txt";
    QSettings *set = new QSettings(fileName,QSettings::IniFormat);

    set->beginGroup("AppConfig");

    set->setValue("LastLoginer",Myapp::LastLoginter);
    set->setValue("CurrentUserPwd",Myapp::CurrentUserPwd);
    set->setValue("CurrentUserType",Myapp::CurrentUserType);
    set->value("urrentUserId",Myapp::CurrentUserId);

    set->value("AppTitle",Myapp::AppTitle);
    set->value("CompanyName",Myapp::CompanyName);
    set->value("Contacts",Myapp::Contacts);
    set->value("PhoneNumber",Myapp::PhoneNumber);
    set->value("Address",Myapp::Address);

    set->endGroup();
}
