// StopWait.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Global.h"
#include "RdtSender.h"
#include "RdtReceiver.h"
#include "StopWaitRdtSender.h"
#include "StopWaitRdtReceiver.h"
#include "GBNRdtReceiver.h"
#include "GBNRdtSender.h"
#include "SRRdtReceiver.h"
#include "SRRdtSender.h"
#include "TCPRdtSender.h"


int main(int argc, char* argv[])
{
    RdtSender* ps;
    RdtReceiver* pr;
    int choice = 0;
    switch (choice) {
    case 0:
        ps = new StopWaitRdtSender();
        pr = new StopWaitRdtReceiver();
        break;
    case 1:
        ps = new GBNRdtSender();
        pr = new GBNRdtReceiver();
        break;
    case 2:
        ps = new SRRdtSender();
        pr = new SRRdtReceiver();
        break;
    case 3:
        ps = new TCPRdtSender();
        pr = new GBNRdtReceiver();
        break;
    default:
        ps = new StopWaitRdtSender();
        pr = new StopWaitRdtReceiver();
        break;

    }
//	pns->setRunMode(0);  //VERBOSģʽ
	pns->setRunMode(1);  //����ģʽ
	pns->init();
	pns->setRtdSender(ps);
	pns->setRtdReceiver(pr);
	pns->setInputFile("C:\\Users\\admin\\Desktop\\code\\network2-rdt\\Windows VS2017\\input.txt");
	pns->setOutputFile("C:\\Users\\admin\\Desktop\\code\\network2-rdt\\Windows VS2017\\output.txt");

	pns->start();

	delete ps;
	delete pr;
	delete pUtils;									//ָ��Ψһ�Ĺ�����ʵ����ֻ��main��������ǰdelete
	delete pns;										//ָ��Ψһ��ģ�����绷����ʵ����ֻ��main��������ǰdelete
	
	return 0;
}

