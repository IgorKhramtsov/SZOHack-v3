#include <windows.h>
#include <fstream>
using namespace std;

#define MB(text,head) MessageBox(NULL, text, head, MB_OK);
ofstream ofile;	
/*
char* FPS(void)
{
	static int FPScounter = 0;
	static float FPSfLastTickCount = 0.0f;
	static float FPSfCurrentTickCount;
	static char cfps[6] = "";

	FPSfCurrentTickCount = clock() * 0.001f;
	FPScounter++;
	if((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f)
	{
			FPSfLastTickCount = FPSfCurrentTickCount;
			sprintf(cfps," %d",FPScounter);
			FPScounter = 0;
			return cfps;
	}
}
*/
void Log(char* fmt, ...)
{
        char buf[1024] = {0};
        va_list va_alist;
        ofstream output;

        va_start(va_alist, fmt);
        vsnprintf(buf, sizeof(buf), fmt, va_alist);
        va_end(va_alist);

        output.open("Coord.txt", ios::app);//Имя фаила с логом текстур
        if(output.fail()) return;
        output << buf << endl;
        output.close();
}
char* FPS(void)
{

static int	 FPScounter = 0;
static float FPSfLastTickCount = 0.0f;
static float FPSfCurrentTickCount;
static char  cFPS[6] = "";

FPSfCurrentTickCount = clock() * 0.001f;
FPScounter++;
if((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f)
{
   FPSfLastTickCount = FPSfCurrentTickCount;
   sprintf(cFPS,"FPS  %d",FPScounter);
   FPScounter = 0;
}


return cFPS;
}

char* Time(void)
{
	static char ctime[20] = "" ;
	struct tm * current_tm;
	time_t current_time;
	time (&current_time);
	current_tm = localtime (&current_time);
	if(current_tm->tm_hour>12)
		sprintf( ctime, "%d:%02d:%02d PM", current_tm->tm_hour - 12, current_tm->tm_min, current_tm->tm_sec );
	else
		sprintf( ctime, "%d:%02d:%02d AM", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );
	return ctime;
}
char* Date(void)
{
	struct tm * current_tm;
	time_t current_time;time (&current_time);
	current_tm = localtime (&current_time);
	char *month []={"Январь.","Февраль.","Март.","Апрель.","Май","Июнь","Июль","Август.","Сентябрь.","Октябрь.","Ноябрь.","Декабрь."};
	char *logbuf = new char[ 256 ];

	sprintf( logbuf, "%02d.%s20%d",current_tm->tm_mday,month[current_tm->tm_mon],current_tm->tm_year-100);
	return logbuf;
}

BOOL WritePPI (LPCTSTR lpAppName,LPCTSTR lpKeyName,int nInteger,LPCTSTR lpFileName)
{
TCHAR lpString[1024];
wsprintf(lpString,"%d",nInteger);
return WritePrivateProfileString(lpAppName,lpKeyName,lpString,lpFileName);
}
char dlldir[MAX_PATH];
char *GetDirFile(char *filename)
{
	static char path[320];
	strcpy_s(path, dlldir);
	strcat_s(path, filename);
	return path;
}
void  OpenURL(LPCSTR URL)
{
	ShellExecute(NULL,"open",URL,NULL,NULL,SW_SHOWNORMAL);
	return;
}
void  TimeWaiting(int seconds)
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while((clock() < endwait)){	}
	return;
}
DWORD* Dev(DWORD Base,DWORD Len)
{
	unsigned long i = 0, n = 0;

	for( i = 0; i < Len; i++ )
	{
        if(*(BYTE *)(Base+i+0x00)==0xC7)n++;
	    if(*(BYTE *)(Base+i+0x01)==0x06)n++;
	    if(*(BYTE *)(Base+i+0x06)==0x89)n++;
	    if(*(BYTE *)(Base+i+0x07)==0x86)n++;	
        if(*(BYTE *)(Base+i+0x0C)==0x89)n++;
	    if(*(BYTE *)(Base+i+0x0D)==0x86)n++;

	    if(n == 6) return (DWORD_PTR *)
			(Base + i + 2);n = 0;
	}
	return(0);
}
void * DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp;
	DWORD dwback;
	DWORD jumpto, newjump;

	VirtualProtect(src,len,PAGE_READWRITE,&dwback);

	 if(src[0] == 0xE9)
	 {
		jmp = (BYTE*)malloc(10);
		jumpto = (*(DWORD*)(src+1))+((DWORD)src)+5;
		newjump = (jumpto-(DWORD)(jmp+5));
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = newjump;
		jmp += 5;
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = (DWORD)(src-jmp);
	 }
	 else
	 {
		jmp = (BYTE*)malloc(5+len);
		memcpy(jmp,src,len);
		jmp += len;
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = (DWORD)(src+len-jmp)-5;
	 }
	 src[0] = 0xE9;
	 *(DWORD*)(src+1) = (DWORD)(dst - src) - 5;

	 for(int i = 5; i < len; i++)
	  src[i] = 0x90;
	 VirtualProtect(src, len, dwback, &dwback);
	 return (jmp - len);
}
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);

char dlldir1[320];

void  StartLogModule(HMODULE hDll)
{
	DisableThreadLibraryCalls(hDll);
	GetModuleFileName(hDll, dlldir1, 512);
	for(int i = strlen(dlldir1); i > 0; i--)
	{
		if(dlldir1[i] == '\\')
		{
			dlldir1[i+1] = 0;
			break; 
		} 

	}
}

BOOL  bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for(;*szMask;++szMask,++pData,++bMask)
		if(*szMask=='x' && *pData!=*bMask) 
			return false;
	return (*szMask) == NULL;
}

DWORD  FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)
{
	for(DWORD i=0; i < dwLen; i++)
		if( bCompare((BYTE*)(dwAddress+i),bMask,szMask))
			return (DWORD)(dwAddress+i);

	return 0;
}

void MEMwrite(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}



void __cdecl add_log (const char *fmt, ...)
{
	ofile.open(GetDirFile("ttnlog.txt"), ios::app);
	//if(ofile != NULL)
	{
		if(!fmt) { return; }

		va_list va_alist;
		char logbuf[256] = {0};

		va_start (va_alist, fmt);
		vsnprintf_s(logbuf+lstrlenA(logbuf), sizeof(logbuf) - lstrlenA(logbuf), _TRUNCATE, fmt, va_alist);
		va_end (va_alist);

		ofile << logbuf << endl;
		ofile.close();
	}
}




//////////////////////////////////////////////////////////

void  EraseHeaders(HINSTANCE hModule1)
{
	
	PIMAGE_DOS_HEADER pDoH; 
	PIMAGE_NT_HEADERS pNtH;
	DWORD i, ersize, protect;

	if (!hModule1) return;

	pDoH = (PIMAGE_DOS_HEADER)(hModule1);

	pNtH = (PIMAGE_NT_HEADERS)((LONG)hModule1 + ((PIMAGE_DOS_HEADER)hModule1)->e_lfanew);

	ersize = sizeof(IMAGE_DOS_HEADER);
	if ( VirtualProtect(pDoH, ersize, PAGE_READWRITE, &protect) )
	{
		for ( i=0; i < ersize; i++ )
				*(BYTE*)((BYTE*)pDoH + i) = 0;
	}

	ersize = sizeof(IMAGE_NT_HEADERS);
	if ( pNtH && VirtualProtect(pNtH, ersize, PAGE_READWRITE, &protect) )
	{
		for ( i=0; i < ersize; i++ )
				*(BYTE*)((BYTE*)pNtH + i) = 0;
	}
	return;
}

typedef struct _UNICODE_STRING 
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _ModuleInfoNode
{
	LIST_ENTRY LoadOrder;
	LIST_ENTRY InitOrder;
	LIST_ENTRY MemoryOrder;
	HMODULE baseAddress;
	unsigned long entryPoint;
	unsigned int size;
	UNICODE_STRING fullPath;
	UNICODE_STRING name;
	unsigned long flags;
	unsigned short LoadCount;
	unsigned short TlsIndex;
	LIST_ENTRY HashTable;
	unsigned long timestamp;
} ModuleInfoNode, *pModuleInfoNode;

typedef struct _ProcessModuleInfo
{
	unsigned int size;
	unsigned int initialized;
	HANDLE SsHandle;
	LIST_ENTRY LoadOrder;
	LIST_ENTRY InitOrder;
	LIST_ENTRY MemoryOrder;
} ProcessModuleInfo, *pProcessModuleInfo;

#define UNLINK(x) (x).Blink->Flink = (x).Flink; \
	(x).Flink->Blink = (x).Blink;

int HideModule( HMODULE hMod )
{
	ProcessModuleInfo *pmInfo;
	ModuleInfoNode *module;

	_asm
	{
		mov eax, fs:[18h]
		mov eax, [eax + 30h]
		mov eax, [eax + 0Ch] 
		mov pmInfo, eax
	}

	module = (ModuleInfoNode *)(pmInfo->LoadOrder.Flink);

	while(module->baseAddress && module->baseAddress != hMod){
		module = (ModuleInfoNode *)(module->LoadOrder.Flink);}

	if(!module->baseAddress){
		return 0;}

	UNLINK(module->LoadOrder);
	UNLINK(module->InitOrder);
	UNLINK(module->MemoryOrder);
	UNLINK(module->HashTable);
	memset(module->fullPath.Buffer, 0, module->fullPath.Length);
	memset(module, 0, sizeof(ModuleInfoNode));
	return 1;
}