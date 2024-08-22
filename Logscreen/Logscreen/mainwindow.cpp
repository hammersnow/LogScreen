#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QProcess"
#include "QTextBrowser"
#include "QStringList"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    QString eds = ui->eds->currentText();
    QString log = ui->log->currentText();

    //Machine Fault

    if (log == "Machine Fault") {
        //ed1

        if (eds == "ED01") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.37 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed2
        if (eds == "ED02") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.40 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed3

        if (eds == "ED03") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.35 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed4

        if (eds == "ED04") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.36 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }


        //ed5

        if (eds == "ED05") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.38 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed06

        if (eds == "ED06") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.39 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed09

        if (eds == "ED09") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.25 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed10
        if (eds == "ED10") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.17 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed11


        if (eds == "ED11") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.23 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed12

        if (eds == "ED12") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.22 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed13


        if (eds == "ED13") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.33 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed14



        if (eds == "ED14") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.32 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed15



        if (eds == "ED15") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.20 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }


        //ed16


        if (eds == "ED16") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.28 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }


        //ed17



        if (eds == "ED17") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.21 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }

        //ed18


        if (eds == "ED18") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.26 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed19


        if (eds == "ED19") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.27 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



        //ed20



        if (eds == "ED20") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.24 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }


        //ed23



        if (eds == "ED23") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.44 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }

        //ed24



        if (eds == "ED24") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.46 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }


        //ed25


        if (eds == "ED25") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.43 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed26


        if (eds == "ED26") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.45 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed27

        if (eds == "ED27") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.41 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }




        //ed28

        if (eds == "ED28") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.42 ssh scc grep 'scs_fault_cause : state: ' /opt/eds/log/scs.log.2 /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | awk '{print $11}'");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
            QStringList lines = last.split('\n');
        QStringList messages;
        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines.at(i).trimmed();
            if (line == "0") {
                messages.append("Fault= None");
        } else if ( line == "1") {
        messages.append("Fault= WaitingForDevices");
        } else if ( line == "2") {
        messages.append("Fault= DevicesUninitialized");
        } else if ( line == "3") {
        messages.append("Fault= KeyPowerOff");
        } else if ( line == "4") {
        messages.append("Fault= SDB2_Fault");
        } else if ( line == "5") {
        messages.append("Fault= BIT_Fault");
        } else if ( line == "6") {
        messages.append("Fault= DIAG_Fault");
        } else if ( line == "7") {
        messages.append("Fault= DIAG_POST_TIMEOUT");
        } else if ( line == "8") {
        messages.append("Fault= SRC_FAILED");
        } else if ( line == "9"){
        messages.append("Fault= ISHWFAULTCONDITION");
        } else if ( line == "10"){
        messages.append("Fault= UserRequested");
        } else if ( line == "11"){
        messages.append("Fault= SubSystemMissing");
        } else if ( line == "12"){
        messages.append("Fault= PASSTHROUGH");
        } else if ( line == "13") {
        messages.append("Fault= DCBOFFSET_FAILURE");
        } else if ( line == "14") {
        messages.append("Fault= DARKCAL_REQUESTED");
        } else if ( line == "15"){
        messages.append("Fault= ENCODERCNT_EXCEEDED");
        } else if ( line == "16"){
        messages.append("Fault= E-STOP");
        } else if ( line == "17") {
        messages.append("Fault= INTERLOCK");
        } else if ( line == "18") {
        messages.append("Fault= HVPS_RAMPUP");
        } else if ( line == "19") {
        messages.append("Fault= Standby");
        } else if ( line == "20") {
        messages.append("Fault= Reboot");
        } else if ( line == "21") {
        messages.append("Fault= WatchDog");
        } else if ( line == "22") {
        messages.append("Fault= SYSTIC_FAULT");
        } else if ( line == "23") {
        messages.append("Fault= ENCODER_FAULT");
        } else if ( line == "24") {
        messages.append("Fault= LIGHT_CURTAIN_FAULT");
        } else if ( line == "25"){
        messages.append("Fault= GALIL_FAULT");
        } else if ( line == "26") {
        messages.append("Fault= Acuvim_Fault");
        } else if ( line == "27") {
        messages.append("Fault= Yaskawa_Fault");
        } else if ( line == "28") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "29") {
        messages.append("Fault= MFORCE_Fault");
        } else if ( line == "30") {
        messages.append("Fault= HVPS_Fault");
        } else if ( line == "31"){
        messages.append("Fault= DCB_Fault");
        } else if ( line == "32") {
        messages.append("Fault= System_Verify_Fault");
        } else if ( line == "33") {
        messages.append("Fault= BMS_Entrance_Bag_Jam");
        } else if ( line == "34") {
        messages.append("Fault= BMS_BHS_FAULT");
        } else if ( line == "35"){
        messages.append("Fault= SYSTIC_TIMEOUT");
        } else if ( line == "36") {
        messages.append("Fault= SDB2_TIMEOUT");
        } else if ( line == "37" ){
        messages.append("Fault= DCB_TIMEOUT");
        } else if ( line == "38") {
        messages.append("Fault= DPP_RTR_DOWN");
        } else if ( line == "39") {
        messages.append("Fault= BMS_RTR_DOWN");
        } else if ( line == "40") {
        messages.append("Fault= IAC_RTR_DOWN");
        } else if ( line == "41") {
        messages.append("Fault= DPP_OPSTATE_FAULT");
        } else if ( line == "42") {
        messages.append("Fault= IAC_OPSTATE_FAULT");
        } else if ( line == "43") {
        messages.append("Fault= INIT_TIMEOUT_FAULT");
        } else if ( line == "44") {
        messages.append("Fault= SEASONING_FAILED");
        } else if ( line == "45") {
        messages.append("Fault= Transients_Failed");
        } else if ( line == "46") {
        messages.append("Fault= Array_Test_Failed");
        } else if ( line == "47") {
        messages.append("Fault= BMS_SUBSYS_MISSING");
        } else if ( line == "48") {
        messages.append("Fault= IAC_SUBSYS_MISSING");
        } else if ( line == "49") {
        messages.append("Fault= DPP_SUBSYS_MISSING");
        } else if ( line == "50") {
        messages.append("Fault= DIAGS_SUBSYS_MISSING");
        } else if ( line == "51") {
        messages.append("Fault= PLC_Connection_Loss");
        } else if ( line == "52") {
        messages.append("Fault= DPP_HIGH_WATERMARK");
        } else if ( line == "54") {
            messages.append("Fault= CHILLER_FAULT");}
    }
        QString result = messages.join("\n");
        ui->cikti->setText(result);
        ui->cikti->moveCursor(QTextCursor::End);
         }



    }




    //Otk

    if (log == "Otk") {
        //ed1
        if (eds == "ED01") {
        QString command1 =  "ssh 10.1.10.37 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
        QString command1 =  "ssh 10.1.10.40 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
        QString command1 =  "ssh 10.1.10.35 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
        QString command1 =  "ssh 10.1.10.36 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
        QString command1 =  "ssh 10.1.10.38 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
        QString command1 =  "ssh 10.1.10.39 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
        QString command1 =  "ssh 10.1.10.25 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
        QString command1 =  "ssh 10.1.10.17 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
        QString command1 =  "ssh 10.1.10.23 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
        QString command1 =  "ssh 10.1.10.22 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
        QString command1 =  "ssh 10.1.10.33 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
        QString command1 =  "ssh 10.1.10.32 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
        QString command1 =  "ssh 10.1.10.20 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
        QString command1 =  "ssh 10.1.10.28 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
        QString command1 =  "ssh 10.1.10.21 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
        QString command1 =  "ssh 10.1.10.26 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
        QString command1 =  "ssh 10.1.10.27 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
        QString command1 =  "ssh 10.1.10.24 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
        QString command1 =  "ssh 10.1.10.44 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
        QString command1 =  "ssh 10.1.10.46 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
        QString command1 =  "ssh 10.1.10.43 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
        QString command1 =  "ssh 10.1.10.45 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
        QString command1 =  "ssh 10.1.10.41 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
        QString command1 =  "ssh 10.1.10.42 less /opt/eds/log/iqtk.log | sed 's/Bag Serial Number/\\nBag Serial Number/g' | sed 's/Bag Time/\\nBag Time/g' | sed 's/Bag Angle/\\nBag Angle/g' | sed 's/Nylon Sphere/\\n \\nNylon Sphere/g' | sed 's/Aluminum Sphere:/\\n \\nAluminum Sphere:/g' | sed 's/FINAL RESULT/\\nFINAL RESULT/g' | sed 's/{com/\\n{com/g'| sed 's/{mass/\\n{mass/g' | sed 's/{density/\\n{density/g' | sed 's/{volume/\\n{volume/g' | sed 's/{eroded_mass/\\n{eroded_mass/g' | sed 's/{eroded_density/\\n{eroded_density/g' | sed 's/{eroded_volume/\\n{eroded_volume/g' | sed 's/ASTM/\\n \\nASTM/g' | sed 's/{max_frequency/\\n{max_frequency/g' | sed 's/{raw_max_frequency/\\n{raw_max_frequency/g' | sed 's/Belt Speed/\\n \\nBelt Speed/g' | sed 's/{belt_speed_factor/\\n{belt_speed_factor/g' |sed 's/FINAL/\\n \\nFINAL/g' | sed '/^[0-9]\\{14\\}:/i\\\\' | sed '/^[0-9]\\{14\\}:/i\\\\...---...---...---...---...---...---...---...---...---...---...' | sed '/^[0-9]\\{14\\}:/i\\\\'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
    }





    //Bad Detectors

    if (log == "Bad Detectors") {
        //ed1
        if (eds == "ED01") {
        QString command1 =  "ssh 10.1.10.37 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
        QString command1 =  "ssh 10.1.10.40 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
        QString command1 =  "ssh 10.1.10.35 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
        QString command1 =  "ssh 10.1.10.36 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
        QString command1 =  "ssh 10.1.10.38 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
        QString command1 =  "ssh 10.1.10.39 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
        QString command1 =  "ssh 10.1.10.25 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
        QString command1 =  "ssh 10.1.10.17 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
        QString command1 =  "ssh 10.1.10.23 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
        QString command1 =  "ssh 10.1.10.22 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
        QString command1 =  "ssh 10.1.10.33 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
        QString command1 =  "ssh 10.1.10.32 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
        QString command1 =  "ssh 10.1.10.20 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
        QString command1 =  "ssh 10.1.10.28 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
        QString command1 =  "ssh 10.1.10.21 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
        QString command1 =  "ssh 10.1.10.26 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
        QString command1 =  "ssh 10.1.10.27 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
        QString command1 =  "ssh 10.1.10.24 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
        QString command1 =  "ssh 10.1.10.44 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
        QString command1 =  "ssh 10.1.10.46 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
        QString command1 =  "ssh 10.1.10.43 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
        QString command1 =  "ssh 10.1.10.45 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
        QString command1 =  "ssh 10.1.10.41 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
        QString command1 =  "ssh 10.1.10.42 ssh dpp cat /opt/eds/etc/bad_detectors.dat";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
    }



    //Array

    if (log == "Array Test") {
        //ed1
        if (eds == "ED01") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.37 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.37 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.40 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.40 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.35 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.35 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.36 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.36 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.38 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.38 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.39 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.39 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.25 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.25 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.17 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.17 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.23 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.23 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.22 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.22 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.33 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.33 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.32 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.32 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.20 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.20 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.28 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.28 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.21 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.21 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.26 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.26 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.27 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.27 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.24 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.24 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.44 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.44 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.46 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.46 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.43 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.43 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.45 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.45 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.41 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.41 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.42 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.42 ssh scc sed -n '/Array tests mode = 1/,/ArrayTest PASSED/p' /opt/eds/log/diag/trace/%1").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

    }





    //ARC

    if (log == "Hvps Arc") {
        //ed1
        if (eds == "ED01") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.37 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.37 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.40 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.40 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.35 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.35 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.36 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.36 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.38 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.38 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.39 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.39 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.25 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.25 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.17 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.17 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.23 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.23 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.22 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.22 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.33 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.33 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.32 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.32 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.20 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.20 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.28 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.28 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.21 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.21 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.26 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.26 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.27 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.27 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.24 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.24 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.44 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.44 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.46 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.46 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.43 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.43 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.45 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.45 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.41 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.41 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.42 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.42 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Arc'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

    }






    //Flowswitch
    if (log == "Flow Switch") {
        //ed1
        if (eds == "ED01") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.37 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.37 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.40 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.40 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.35 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();

        QString command1 =  QString("ssh 10.1.10.35 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.36 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.36 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.38 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.38 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.39 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.39 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.25 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.25 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.17 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.17 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.23 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.23 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.22 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.22 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.33 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.33 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.32 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.32 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.20 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.20 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.28 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.28 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.21 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.21 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.26 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.26 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.27 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.27 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.24 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.24 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.44 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.44 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.46 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.46 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.43 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.43 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.45 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.45 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.41 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.41 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
            QProcess lastfile;
            lastfile.start("ssh 10.1.10.42 ssh scc ls -t /opt/eds/log/diag/trace/ | head -n 1");
            lastfile.waitForFinished(10000);
            QString last = lastfile.readAllStandardOutput().trimmed();
        QString command1 =  QString("ssh 10.1.10.42 ssh scc less /opt/eds/log/diag/trace/%1 | grep 'Flow'").arg(last);
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

    }




    //BHS
    if (log == "Bhs Log") {
        //ed1
        if (eds == "ED01") {
        QString command1 =  "ssh 10.1.10.37 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

     //ed2
        if (eds == "ED02") {
        QString command1 =  "ssh 10.1.10.40 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
     //ed3
        if (eds == "ED03") {
        QString command1 =  "ssh 10.1.10.35 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed4
        if (eds == "ED04") {
        QString command1 =  "ssh 10.1.10.36 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed5
        if (eds == "ED05") {
        QString command1 =  "ssh 10.1.10.38 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed6
        if (eds == "ED06") {
        QString command1 =  "ssh 10.1.10.39 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed9
        if (eds == "ED09") {
        QString command1 =  "ssh 10.1.10.25 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed10
        if (eds == "ED10") {
        QString command1 =  "ssh 10.1.10.17 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed11
        if (eds == "ED11") {
        QString command1 =  "ssh 10.1.10.23 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed12
        if (eds == "ED12") {
        QString command1 =  "ssh 10.1.10.22 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed13
        if (eds == "ED13") {
        QString command1 =  "ssh 10.1.10.33 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed14
        if (eds == "ED14") {
        QString command1 =  "ssh 10.1.10.32 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed15
        if (eds == "ED15") {
        QString command1 =  "ssh 10.1.10.20 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed16
        if (eds == "ED16") {
        QString command1 =  "ssh 10.1.10.28 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed17
        if (eds == "ED17") {
        QString command1 =  "ssh 10.1.10.21 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed18
        if (eds == "ED18") {
        QString command1 =  "ssh 10.1.10.26 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed19
        if (eds == "ED19") {
        QString command1 =  "ssh 10.1.10.27 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed20
        if (eds == "ED20") {
        QString command1 =  "ssh 10.1.10.24 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed23
        if (eds == "ED23") {
        QString command1 =  "ssh 10.1.10.44 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed24
        if (eds == "ED24") {
        QString command1 =  "ssh 10.1.10.46 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed25
        if (eds == "ED25") {
        QString command1 =  "ssh 10.1.10.43 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed26
        if (eds == "ED26") {
        QString command1 =  "ssh 10.1.10.45 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed27
        if (eds == "ED27") {
        QString command1 =  "ssh 10.1.10.41 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }
        //ed28
        if (eds == "ED28") {
        QString command1 =  "ssh 10.1.10.42 ssh scc less /opt/eds/log/bhs.log | grep 'bag disposition'";
        QProcess process1;
        process1.start(command1);
        process1.waitForFinished(10000);
        QString output = process1.readAllStandardOutput();
        ui->cikti->setText(output);
        ui->cikti->moveCursor(QTextCursor::End);
         }

    }
}
