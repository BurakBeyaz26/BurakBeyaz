#ifndef _DLL_IMPORT_H_
#define _DLL_IMPORT_H_
#include <windows.h>
#include "_RC_SDK.h"
#include "sysError.h"
#include <QDateTime>
#include <QtWidgets/QColormap>

typedef unsigned long  DWORD;

// LEVEL 0 : GLOBAL FUNCTIONS
extern "C" __declspec(dllimport) int       __stdcall __Get_SDK_Version          (void);
extern "C" __declspec(dllimport) void      __stdcall __Get_Error_Message        (int result, char *message);
extern "C" __declspec(dllimport) void      __stdcall __Show_Error_Message       (int result);
extern "C" __declspec(dllimport) void      __stdcall __Show_Error_Message_Msec  (int duration, int result);
extern "C" __declspec(dllimport) void      __stdcall __Show_Message_Msec        (int duration, char *message);
extern "C" __declspec(dllimport) int       __stdcall __Set_Advanced_Mode        (void);
extern "C" __declspec(dllimport) void      __stdcall __Ping                     (char *ipString);







// LEVEL 1 : STAND ALONE FUNCTIONS
//   LEVEL 1-A Basic device functions
extern "C" __declspec(dllimport) void     *__stdcall __Start_Relax_Mode         (DWORD deviceSerialNo, int *errorStatus, void **encoderDevice, int localIP, bool connectionRequired, int *relaxCardCode, DWORD timeOut);
extern "C" __declspec(dllexport) bool      __stdcall __Pause_Relax_Mode         (void *relaxHandle);
extern "C" __declspec(dllexport) void      __stdcall __Resume_Relax_Mode        (void *relaxHandle);
extern "C" __declspec(dllimport) void      __stdcall __Exit_Relax_Mode          (void *relaxHandle);
extern "C" __declspec(dllimport) void      __stdcall __Set_Relax_Wmode          (void *relaxHandle, int val);
extern "C" __declspec(dllimport) int       __stdcall __Device_Properties        (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port);
extern "C" __declspec(dllimport) int       __stdcall __Get_Status               (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, bool task, void *status);
extern "C" __declspec(dllimport) int       __stdcall __Get_Config               (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, WORD start, WORD len, BYTE *data);
extern "C" __declspec(dllimport) int       __stdcall __Get_Record_Count         (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD *count);
extern "C" __declspec(dllimport) int       __stdcall __Get_Records              (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD *count, void *dr);
extern "C" __declspec(dllimport) int       __stdcall __Clear_Memory             (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port);
extern "C" __declspec(dllimport) int       __stdcall __Set_Start_Mode           (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port);
extern "C" __declspec(dllimport) int       __stdcall __Set_Safe_Mode            (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, bool safeMode);
extern "C" __declspec(dllimport) int       __stdcall __Set_Time                 (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE *timeVal);
extern "C" __declspec(dllimport) int       __stdcall __Set_Relay                (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE relay, bool value, void *status);
extern "C" __declspec(dllimport) int       __stdcall __Set_Led_Color            (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE led, bool value, void *status);
extern "C" __declspec(dllimport) int       __stdcall __Set_Price                (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int accessID, int iPrice);
extern "C" __declspec(dllimport) int       __stdcall __Set_Relay_Program        (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int index, bool active, WORD relayHM, BYTE relayNo, BYTE duration, BYTE dayOfWeek);
extern "C" __declspec(dllimport) int       __stdcall __Set_Relay_Program_V2     (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int index, bool active, WORD relayHM1, WORD relayHM2, BYTE relayNo, BYTE duration, BYTE dayOfWeek);
extern "C" __declspec(dllimport) int       __stdcall __Show_Text_Message        (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE y, BYTE x, char *message, BYTE font);
extern "C" __declspec(dllimport) int       __stdcall __Show_Graphic_Message     (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE msgNo, BYTE duration);
extern "C" __declspec(dllimport) int       __stdcall __Beep                     (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE times, BYTE duration);
extern "C" __declspec(dllimport) int       __stdcall __Indicators               (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE times, BYTE duration, BYTE ledVal, BYTE relayNo, BYTE relayVal, BYTE relayTime, BYTE msgIndex, BYTE timeOut, BYTE yMsg);
extern "C" __declspec(dllimport) int       __stdcall __Get_Offline_Permission   (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD cardNo, bool *access);
extern "C" __declspec(dllimport) int       __stdcall __Set_Offline_Permission   (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD cardNo, bool  access);
extern "C" __declspec(dllimport) int       __stdcall __Set_Device_IP_Port       (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD deviceIP, WORD devicePort);
extern "C" __declspec(dllimport) int       __stdcall __Set_Server_IP_Port       (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD serverIP, WORD serverPort);
extern "C" __declspec(dllimport) int       __stdcall __Set_Ext_Device_IP_Port   (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD extIP, WORD extPort);
extern "C" __declspec(dllimport) int       __stdcall __Set_Setting_From_BDS_File(DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, char *fileName);

//   LEVEL 1-B Card functions
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_Inf             (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, WORD *atqa, BYTE *sak, BYTE *uidSize, BYTE *cardUID);
extern "C" __declspec(dllimport) int       __stdcall __Format_Card_Basic        (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, char *cardName, DWORD cardNo, WORD cardPassword, BYTE cardGroup);
extern "C" __declspec(dllimport) int       __stdcall __Read_And_Get_Card_Data   (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *cardData);
extern "C" __declspec(dllimport) int       __stdcall __Write_Card_Data_MS       (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *cardData, BYTE *sectorPassword);
extern "C" __declspec(dllimport) int       __stdcall __Read_Card_Block_Random   (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE *bPassword, BYTE blockNo, BYTE *data, BYTE keyAB);
extern "C" __declspec(dllimport) int       __stdcall __Write_Card_Block_Random  (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, BYTE *bPassword, BYTE blockNo, BYTE *data, BYTE keyAB);
extern "C" __declspec(dllimport) int       __stdcall __Read_TC_NO               (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, char *tcNo);
extern "C" __declspec(dllimport) int       __stdcall __Write_TC_NO              (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, char *tcNo);
//extern "C" __declspec(dllimport) int       __stdcall __Read_Sector_EX           (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *cardData, char *cardUIDstr);
//extern "C" __declspec(dllimport) int       __stdcall __Write_Sector_EX          (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *cardData, char *cardUIDstr);
//extern "C" __declspec(dllimport) int       __stdcall __Delete_Sector_EX         (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port);
extern "C" __declspec(dllimport) int       __stdcall __Read_Ticket              (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int *ticketNo, QDateTime *entryTime, QDateTime *paymentTime, bool *paymentCompleted, bool *inside, BYTE *locationID, char *plate);
extern "C" __declspec(dllimport) int       __stdcall __Write_Ticket             (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int ticketNo, QDateTime entryTime, QDateTime paymentTime, bool paymentCompleted, bool inside, BYTE locationID, char *plate);
extern "C" __declspec(dllimport) int       __stdcall __Format_Ticket            (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, int ticketNo);


//   LEVEL 1-C Online control functions
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_UID_Readed      (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, DWORD *cardUID);
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_Data_Readed     (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *cardData);
extern "C" __declspec(dllimport) int       __stdcall __Set_Online_Permission    (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, bool permission);
extern "C" __declspec(dllimport) int       __stdcall __Device_Resume            (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port);
extern "C" __declspec(dllimport) int       __stdcall __Device_Finish            (DWORD deviceSerialNo, DWORD password, DWORD ip, WORD port, void *status);

//   LEVEL 1-D Utility functions
extern "C" __declspec(dllimport) QDateTime __stdcall __Get_Record_Time          (void *deviceRecord);
extern "C" __declspec(dllimport) double    __stdcall __Get_Record_Credit        (void *deviceRecord);
extern "C" __declspec(dllimport) void      __stdcall __Get_Device_Time          (void *status, char *text);
extern "C" __declspec(dllimport) void      __stdcall __Get_Indicators           (void *status, char *text);
extern "C" __declspec(dllimport) void      __stdcall __Get_Error_Inf_Text       (void *status, char *text);
extern "C" __declspec(dllimport) void      __stdcall __Get_Power_Desc           (void *status, char *text);
extern "C" __declspec(dllimport) QColor    __stdcall __Get_Led_Color            (void *status);







// LEVEL 2 : RC DATABASE FUNCTIONS
//   LEVEL 2-A functions ( Without login )
extern "C" __declspec(dllimport) int       __stdcall __Get_Server_Name          (char *serverName);
extern "C" __declspec(dllimport) int       __stdcall __Help                     (char *helpFile, int language, int id);
extern "C" __declspec(dllimport) int       __stdcall __Get_Time_Interval        (void *timeInterval);
extern "C" __declspec(dllimport) int       __stdcall __Get_Time_Day             (void *timeDay);
extern "C" __declspec(dllimport) int       __stdcall __Edit_SQL_Fields          (void *cSql);
extern "C" __declspec(dllimport) int       __stdcall __Ticket_Decode            (char *ticket, QDateTime *time, WORD *counter, BYTE *otoparkID, BYTE *locationID);
extern "C" __declspec(dllimport) int       __stdcall __Create_Report_File       (int userID, int *pCur, int *pMax, int *pCancel);
extern "C" __declspec(dllimport) int       __stdcall __Connect_Server           (void *sqlCFG);
extern "C" __declspec(dllimport) int       __stdcall __Set_Target_DB            (char *serverName, int authenticationType, char *username, char *password, char *databaseName, char *targetFile);
extern "C" __declspec(dllimport) int       __stdcall __Set_Target_DB_Dialog     (void);
extern "C" __declspec(dllimport) int       __stdcall __Login_RC                 (char *userName, char *password);
extern "C" __declspec(dllimport) int       __stdcall __Login_Dialog_RC          (void *sqlCFG, bool srvSettingsEnable);
extern "C" __declspec(dllimport) int       __stdcall __Print                    (void *printINF, bool autoPrint, int targetPrinter);


//   LEVEL 2-B functions ( Required login )
//     LEVEL 2-B.1 Unvisible functions
extern "C" __declspec(dllimport) int       __stdcall __Add_Person               (int loginID, int departmentID, char *name, char *surName, char *tcNo, char *sicilNo, char *eMail, int *personID);
extern "C" __declspec(dllimport) int       __stdcall __Get_Person_From_TC       (int loginID, char *tcNo, int *personID, int *departmentID, char *name, char *surName, char *sicilNo, char *eMail);
extern "C" __declspec(dllimport) int       __stdcall __Add_Card                 (int loginID, int personID, int cardTemplateID, int *rcCardCode, char *cardUIDstr, int cardStatus);
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_List            (int loginID, int personID, int *count, int *cardArray, int cardStatus, int cardTemplate);
extern "C" __declspec(dllimport) int       __stdcall __Add_Picture              (int loginID, int personID, BYTE *pictureBuffer, int bufferSize, char *fileExt);
extern "C" __declspec(dllimport) int       __stdcall __Add_Department           (int loginID, char *departmentName);
extern "C" __declspec(dllimport) int       __stdcall __Add_Data                 (int loginID, void *data);
extern "C" __declspec(dllimport) int       __stdcall __Define_Lost_Card         (int loginID, int oldRCcardCode, int *newRCcardCode, bool cardUIDconflict);
extern "C" __declspec(dllimport) int       __stdcall __Add_Credit_Record        (int loginID, int rcCardCode, int quantity, int accessID, int iPrice, int *personID, int appID);
extern "C" __declspec(dllimport) int       __stdcall __Add_Credit_Task          (int loginID, int rcCardCode, int appID, int credit, bool creditCard, QDateTime taskTime);
extern "C" __declspec(dllimport) int       __stdcall __Format_Card_Directly     (int loginID, int rcCardCode, int *personID, bool getFromSerial, bool emulationControl, bool cardUIDconflict, void *sectorInfo);
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_Detail          (int loginID, int *personID, int *rcCardCode, int *credit, char *ownerName);
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_Detail_App      (int loginID, int *personID, int *rcCardCode, int *credit, char *ownerName, QDateTime *lastTime, QDateTime *expireTime, WORD *wStart, WORD *wEnd, BYTE *dayCount, BYTE *dayLimit, bool *inside, int appID);
extern "C" __declspec(dllimport) int       __stdcall __Print_Card               (int loginID, int rcCardCode, bool preview, int designID, int cardSide);
extern "C" __declspec(dllimport) int       __stdcall __Add_Credit_To_Card       (int loginID, int credit, int appID, bool creditCard, int *personID, int *rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Use_Credit_From_Card     (int loginID, int quantity, int accessID, int iPrice, bool discount, int appID, int *personID, int *rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Set_Expire_Date          (int loginID, int rcCardCode, int appID, QDateTime expireDate);
extern "C" __declspec(dllimport) int       __stdcall __Set_Use_Limit            (int loginID, int rcCardCode, int appID, BYTE useLimit);
extern "C" __declspec(dllimport) int       __stdcall __Set_Working_Hours        (int loginID, int rcCardCode, int appID, WORD start, WORD end);
extern "C" __declspec(dllimport) int       __stdcall __Set_Card_Status          (int loginID, int rcCardCode, int tagStatus, bool cardUIDconflict);
extern "C" __declspec(dllimport) int       __stdcall __Set_Department           (int loginID, int personID, int departmanID);
extern "C" __declspec(dllimport) int       __stdcall __Create_Card_Status_Task  (int loginID, int rcCardCode, int tagStatus, QDateTime taskTime);
extern "C" __declspec(dllimport) int       __stdcall __Set_Card_Group           (int loginID, int rcCardCode, BYTE cardGroup);
extern "C" __declspec(dllimport) int       __stdcall __Set_Person_Item          (int loginID, int personID, int itemIndex, char *itemData);
extern "C" __declspec(dllimport) int       __stdcall __Add_Subscriber_To_Card   (int loginID, int subscriberID, bool creditCard, int *personID, int *rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Bank_Get_Inf_For_Payment (int loginID, char *tcNo, char *ownerName, char *ownerSurname, int *personID, int *rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Bank_Add_Payment         (int loginID, QDateTime paymentTime, int personID, int rcCardCode, int credit, char *receipt, char *transactionID);
extern "C" __declspec(dllimport) int       __stdcall __Bank_Get_Payment_Total   (int loginID, QDateTime time1, QDateTime time2, int *count);
extern "C" __declspec(dllimport) int       __stdcall __Bank_Query_Transaction   (int loginID, char *transactionID);
extern "C" __declspec(dllimport) int       __stdcall __Bank_Query_Receipt       (int loginID, char *receipt);



//     LEVEL 2-B.2 Visible functions
extern "C" __declspec(dllimport) int       __stdcall __Admin_Operations         (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Web_Settings             (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Change_User_Password     (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __User_Options             (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Departments              (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Applications             (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Operations               (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Locations                (int loginID, int *locationID);
extern "C" __declspec(dllimport) int       __stdcall __Persons                  (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Card_Defines             (int loginID, int personID);
extern "C" __declspec(dllimport) int       __stdcall __Data_Records             (int loginID, char *fieldName, int fieldVal, char *queryString);
extern "C" __declspec(dllimport) int       __stdcall __Abone_Records            (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __System_Logs              (int loginID, int transID, int refID, int tableID);
extern "C" __declspec(dllimport) int       __stdcall __Local_Computer           (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Computer_Settings        (int loginID, int hdSerial);
extern "C" __declspec(dllimport) int       __stdcall __System_Licance           (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Department_Filter        (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __System_Items_Filter      (int loginID, int mask);
extern "C" __declspec(dllimport) int       __stdcall __Person_Properties        (int loginID, char *caption, int personID, void *person, bool stayOnTop);
extern "C" __declspec(dllimport) int       __stdcall __Card_Properties          (int loginID, int personID, BYTE cardType, bool serverBase, char *captionText, void *cardData);
extern "C" __declspec(dllimport) int       __stdcall __Card_Active_Subscriptions(int loginID, int rcTagCode);
extern "C" __declspec(dllimport) int       __stdcall __Reports                  (int loginID, bool showAllSettings, bool showReport);
extern "C" __declspec(dllimport) int       __stdcall __System_Tasks             (int loginID, int personID, int rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Card_Tasks               (int loginID, int rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Mail_Tasks               (int loginID, int personID);
extern "C" __declspec(dllimport) int       __stdcall __Stocks                   (int loginID);
extern "C" __declspec(dllimport) void     *__stdcall __Manuel_Entry             (int loginID, int *formActive);
extern "C" __declspec(dllimport) void     *__stdcall __Watch_Online             (int loginID, int *formActive);
extern "C" __declspec(dllimport) int       __stdcall __Improper_Card_Use        (int loginID, int warnType);
extern "C" __declspec(dllimport) int       __stdcall __Z_Report                 (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Format_Card              (int loginID, int rcCardCode, int cardType);
extern "C" __declspec(dllimport) int       __stdcall __Update_Card              (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Update_Subscriber        (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Fast_Sale                (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Keyb_Simulation_From_Card(int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Report_Viewer_From_Card  (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Apply_Credit_Task        (int loginID, int autoExit);
extern "C" __declspec(dllimport) int       __stdcall __Print_Parameters         (int loginID, int printIndex, int computerID);
extern "C" __declspec(dllimport) int       __stdcall __Fast_Sale_Settings       (int loginID, int hdSerial);
extern "C" __declspec(dllimport) int       __stdcall __Device_Access_Permissions(int loginID, int refID);
extern "C" __declspec(dllimport) int       __stdcall __Update_Status_Of_Devices (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Select_Devices           (int loginID, int maxDevice, int *deviceSN);
extern "C" __declspec(dllimport) int       __stdcall __All_Person_Operations    (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __All_Card_Operations      (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Get_Person               (int loginID, int *personID, char *queryStr);
extern "C" __declspec(dllimport) int       __stdcall __Get_Person_And_Card      (int loginID, int *personID, int *rcCardCode);
extern "C" __declspec(dllimport) int       __stdcall __Get_Card_Template        (int loginID, int *cardTemplateID, int visitorCard);
extern "C" __declspec(dllimport) int       __stdcall __Subscriber_Packets       (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Subscriber_Services      (int loginID);
extern "C" __declspec(dllimport) int       __stdcall __Get_Subscriber_Totals    (int loginID, void *subscriberPacket, void *hSubscriberTarget, SHORT *subscriberCredit, int *subscriberPrice);
extern "C" __declspec(dllimport) int       __stdcall __Add_Card_Task_For_Spacket(int loginID, int personID, int appID, int date1, int date2, char *selection, bool creditCard, char *targetfile, int subscriberPacketID);
extern "C" __declspec(dllimport) int       __stdcall __Send_Mail                (int loginID, void *dyn_Personel);
extern "C" __declspec(dllimport) int       __stdcall __Person_IO_Status         (int loginID, int personID);

#endif


