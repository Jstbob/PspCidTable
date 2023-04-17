#pragma once

#include<wdm.h>

VOID DriverUnload(PDRIVER_OBJECT driverObject);

HANDLE g_obHandle;
const char* desProcessName = "QQSG.exe";
const char* ceName = "nb.exe";


NTSTATUS protectAndPromoteProcess(PDRIVER_OBJECT driverObject);

BOOLEAN isProtectProcess(PEPROCESS pEProcess);
NTKERNELAPI PUCHAR PsGetProcessImageFileName(PEPROCESS pEProcess);	//引用未导出api
OB_PREOP_CALLBACK_STATUS addHanleAccess(PVOID registrationContext, POB_PRE_OPERATION_INFORMATION pObPreOperationInfo);
NTSTATUS obAddProcessAccess(PDRIVER_OBJECT driverObject);
void obUnRegister();
NTSTATUS protectProcess();
NTSTATUS PsLookupProcessByProcessName(OUT PEPROCESS* outPEprocess);
__int64 __fastcall ExpLookupHandleTableEntry(unsigned int* a1, __int64 a2);
NTKERNELAPI HANDLE PsGetProcessId(IN PEPROCESS Process);