#include "Includes.h"
#include "Color.h"
#include "Tools.h"
#include "Variables.h"
#include "Draw.h"
#include "Components.h"
#include "Menu.h"
#include "Textures.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "memhack.h"
#include <vector>
#include "asm_Fun.h"

int boxi;// функция с меню
cFun Fun;
bool asd20=false;
bool asd30=false;
D3DVIEWPORT9 viewport;
IDirect3DPixelShader9* psTemp_30;
IDirect3DPixelShader9* psTemp_20;

unsigned int m_Stride;
char *GetDirFile(char *filename);
int s,l;
#define g_uiStride m_Stride
//#define MinIndex MinVertexIndex 
//#define StartIndex startIndex
//#define Stride m_Stride
//#define PrimitiveCount primCount


    float SHNull[4]={1.0f,1.0f,1.0f,0.15f};     // clNull       :  0
    float SHWhite[4]={1.0f,1.0f,1.0f,1.0f };     // clWhite      :  1
    float SHSvYellow[4]={1.0f,1.0f,0.5f,1.0f };     // clSvYellow   :  2
    float SHYellow[4]={1.0f,1.0f,0.0f,1.0f };     // clYellow     :  3
    float SHOrange[4]={1.0f,0.5f,0.0f,1.0f };     // clOrange     :  4
    float SHSvGreen[4]={0.5f,1.0f,0.5f,1.0f };     // clSvGreen    :  5
    float SHGreen[4]={0.0f,1.0f,0.0f,1.0f };     // clGreen      :  6
    float SHSalat[4]={0.5f,1.0f,0.0f,1.0f };     // clSalat      :  7
    float SHSvBlue[4]={0.0f,0.5f,1.0f,1.0f };     // clSvBlue     :  8
    float SHBlue[4]={0.0f,0.0f,1.0f,1.0f };     // clBlue       :  9
    float SHSvRed[4]={1.0f,0.0f,0.5f,1.0f };     // clSvRed      : 10
    float SHRed[4]={1.0f,0.0f,0.0f,1.0f };     // clRed        : 11
    float SHSvRose[4]={1.0f,0.5f,1.0f,1.0f };     // clSvRose     : 12
    float SHRose[4]={1.0f,0.0f,1.0f,1.0f };     // clRose       : 13
    float SHSvAqua[4]={0.5f,1.0f,1.0f,1.0f };     // clSvAqua     : 14
    float SHAqua[4]={0.0f,1.0f,1.0f,1.0f };     // clAqua       : 15
    float SHSer[4]={0.8f,0.8f,0.8f,1.0f };      // clSer        : 16

char STRASM [256];

void initp_30( LPDIRECT3DDEVICE9 pDevice )
{
	D3DCAPS9 caps;
	pDevice->GetDeviceCaps(&caps);

	sprintf( STRASM, "ps_%d_%d\nmov oC0,c0\n",D3DSHADER_VERSION_MAJOR(caps.PixelShaderVersion),D3DSHADER_VERSION_MINOR(caps.PixelShaderVersion));
	//sprintf( STRASM, "ps_3_0\nmov oC0,c0\n");
	//LPD3DXBUFFER psbTemp=NULL;
	ID3DXBuffer *psbTemp=NULL;

    if (D3DXAssembleShader(STRASM,sizeof(STRASM),NULL,NULL,0,&psbTemp,NULL)==D3D_OK)
	{
    pDevice->CreatePixelShader((DWORD*)psbTemp->GetBufferPointer(),&psTemp_30);
	asd30=true;
	}
}
void initp_20( LPDIRECT3DDEVICE9 pDevice )
{
	D3DCAPS9 caps;
	pDevice->GetDeviceCaps(&caps);

	//sprintf( STRASM, "ps_%d_%d\nmov oC0,c0\n",D3DSHADER_VERSION_MAJOR(caps.PixelShaderVersion),D3DSHADER_VERSION_MINOR(caps.PixelShaderVersion));
	sprintf( STRASM, "ps_2_0\nmov oC0,c0\n");
	LPD3DXBUFFER psbTemp=NULL;
	//ID3DXBuffer *psbTemp=NULL;

    if (D3DXAssembleShader(STRASM,sizeof(STRASM),NULL,NULL,0,&psbTemp,NULL)==D3D_OK)
	{
    pDevice->CreatePixelShader((DWORD*)psbTemp->GetBufferPointer(),&psTemp_20);
	asd20=true;
	}
}

HRESULT WINAPI myReset (LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if(pFont)pFont->OnLostDevice();
	if(pLine)pLine->OnLostDevice();
	HRESULT hRet = pReset( pDevice, pPresentationParameters );
	if(SUCCEEDED(hRet))
	{
		if(pFont)pFont->OnResetDevice();
		if(pLine)pLine->OnResetDevice();
	}
	return hRet;
}

HRESULT APIENTRY myQuery(LPDIRECT3DDEVICE9 pDevice,D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) 
{
    if( Type == D3DQUERYTYPE_OCCLUSION )
    {
        Type = D3DQUERYTYPE_EVENT;
    }
	return pQuery(pDevice,Type,ppQuery);
}

HRESULT APIENTRY myEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if(Fun.Crosshair==1)
	{
		Xhair(WHITE,pDevice);
	}

		if (!asd20)
	{
		initp_20(pDevice);
	}
		if (!asd30)
	{
		initp_30(pDevice);
	}
			if( !Create )
	{
		D3DXCreateLine(pDevice,&pLine);
		Font("Tahoma",14,FW_BOLD,pDevice);
		//Font("Fixedsys",14,FW_REGULAR,pDevice);
	    //Font("Arial",14,FW_NORMAL,pDevice);//Паблик
		Create = true;
	}	
	if( pFont == NULL )pFont->OnLostDevice();
	else
	{
	   SZOHack(pDevice);
	   //memhack();
	}
	if(Fun.Save==true){Save();}
	if(Fun.Load==true){Load();}
	if(Fun.Reset==true){Fun.Grib=Fun.Travi=Fun.Cache=Fun.Drop=Fun.Art=Fun.Mob=Fun.pvp=Fun.Svet=Fun.Listva=Fun.Crosshair=Fun.WireFrame=Fun.Accuracy=Fun.Camera=Fun.Fall=Fun.fall=Fun.FreezeHeigth=Fun.Jump=Fun.jump=Fun.NoAnimMob=Fun.Teleport=Fun.Tusa=Fun.Reset=0;}
	return pEndScene(pDevice);
}

HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
    if(FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
        return E_FAIL;
    
    WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
	            	|(WORD)(((colour32>>20)&0xF)<<8)
	             	|(WORD)(((colour32>>12)&0xF)<<4)
                 	|(WORD)(((colour32>>4)&0xF)<<0);

    D3DLOCKED_RECT d3dlr;    
    (*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
    WORD *pDst16 = (WORD*)d3dlr.pBits;

    for(int xy=0; xy < 8*8; xy++)
        *pDst16++ = colour16;

    (*ppD3Dtex)->UnlockRect(0);

    return S_OK;
}
HRESULT WINAPI myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	if(Color)
{
GenerateTexture(pDevice, &White,  WHITE);
GenerateTexture(pDevice, &Red,    RED);
GenerateTexture(pDevice, &Green,  GREEN);
GenerateTexture(pDevice, &Blue,   BLUE);
GenerateTexture(pDevice, &Black,  BLACK);
GenerateTexture(pDevice, &Purple, PURPLE);
GenerateTexture(pDevice, &Grey,   GREY);
GenerateTexture(pDevice, &Yellow, YELLOW);
GenerateTexture(pDevice, &Orange, ORANGE);
Color = false;
}
	if(GetAsyncKeyState(VK_F3)&1)
	{
		scr=1;

	}


if (Fun.Listva==1&&scr!=1)
{
	if (ListvaT))
	{
		return S_OK;
	}
}

if (Fun.Svet==1&&scr!=1)
{
	if((NumVertices == 12601) && (primCount == 20800))
	{
		pDevice->SetRenderState(D3DRS_ZENABLE,0);
		pDevice->SetPixelShader(NULL);
		pDevice->SetPixelShader(psTemp_20);
		pDevice->SetPixelShaderConstantF(0,SHNull,1);
       pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
       pDevice->SetRenderState(D3DRS_ZENABLE,1);
	   pDevice->SetPixelShader(NULL);
		pDevice->SetPixelShader(psTemp_20);
		pDevice->SetPixelShaderConstantF(0,SHNull,1);
	}
}

if(Fun.pvp==1&&scr!=1) // PvP
{
	if (People)
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
pDevice->SetPixelShaderConstantF(0,SHOrange,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
pDevice->SetPixelShaderConstantF(0,SHYellow,1);
	}
}

if(Fun.Mob==1&&scr!=1) // PvE
{
	if (MobT)||MobNew)
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Mob==1)pDevice->SetPixelShaderConstantF(0,SHRed,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Mob==1)pDevice->SetPixelShaderConstantF(0,SHRose,1);
	}
}

if(Fun.Art==1&&scr!=1) //арты
{
	if (ArtsT)))
{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Art==1)pDevice->SetPixelShaderConstantF(0,SHBlue,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Art==1)pDevice->SetPixelShaderConstantF(0,SHAqua,1);
	}
}

if (Fun.Drop==1&&scr!=1) // Дроп
{
	if (DropT)))
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Drop==1)pDevice->SetPixelShaderConstantF(0,SHGreen,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Drop==1)pDevice->SetPixelShaderConstantF(0,SHGreen,1);
	}
}

if (Fun.Cache==1&&scr!=1) // Нычки
{
	if (BoxT)
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_20);
if (Fun.Cache==1)pDevice->SetPixelShaderConstantF(0,SHWhite,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_20);
if (Fun.Cache==1)pDevice->SetPixelShaderConstantF(0,SHWhite,1);
	}
}
if (Fun.Travi==1&&scr!=1) // Травы
{
	if (travi)
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
if(Fun.Travi==1)pDevice->SetTexture(0,Purple);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE, 1);
if(Fun.Travi==1)pDevice->SetTexture(0,Purple);
	}
}
if (Fun.Grib==1&&scr!=1) // грибы
{
	if (грибыТ)
	{
pDevice->SetRenderState(D3DRS_ZENABLE,0);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Grib==1)pDevice->SetPixelShaderConstantF(0,SHRed,1);
pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
pDevice->SetRenderState(D3DRS_ZENABLE,1);
pDevice->SetPixelShader(NULL);
pDevice->SetPixelShader(psTemp_30);
if (Fun.Grib==1)pDevice->SetPixelShaderConstantF(0,SHRose,1);
	}
}

if (((Fun.WireFrame)||(GetAsyncKeyState(VK_CAPITAL)))&&scr!=1) // WireFrame
{

		{
			pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		}
			}
			else
			{
		{
			pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		}
}

	return pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT WINAPI mySetStreamSource(void* self, DWORD StreamNumber, IDirect3DVertexBuffer9* pStreamData, DWORD OffsetInBytes, DWORD Stride)
{
	// Установка m_Stride для визуал хаков
	if(StreamNumber == 0) m_Stride = Stride; 

 return pSetStreamSource(self, StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT APIENTRY Start_key(LPDIRECT3DDEVICE9 pDevice)
{
while(1)
{

if(GetAsyncKeyState(VK_F12)){ExitProcess(0);}
if (GetAsyncKeyState(VK_HOME) & 1)Show = (!Show);
Sleep(1);
}
}
int HookpDevice(void)
{
	DWORD*vtbl=0;
	DWORD hD3D9=(DWORD)LoadLibraryA("d3d9.dll");
	DWORD table=FindPattern(hD3D9,0x128000,(PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86","xx????xx????xx");
	memcpy(&vtbl,(void*)(table+2),4);
	pEndScene=(oEndScene)DetourCreate((PBYTE)vtbl[42],(PBYTE)myEndScene,7);
	add_log("EndScene --> Hooked");
	pDrawIndexedPrimitive=(oDrawIndexedPrimitive)DetourCreate((PBYTE)vtbl[82],(PBYTE)myDrawIndexedPrimitive,5);
	add_log("DrawIndexPrimitive --> Hooked");	
	pSetStreamSource=(oSetStreamSource)DetourCreate((PBYTE)vtbl[100],(PBYTE)mySetStreamSource,7);
	add_log("SetStreamSource --> Hooked");
	pReset=(oReset)DetourCreate((PBYTE)vtbl[16],(PBYTE)myReset,12);
	add_log("Reset --> Hooked");
	pQuery=(oQuery)DetourCreate((PBYTE)vtbl[118],(PBYTE)myQuery,12);
	add_log("Query --> Hooked");
	return 0;
}

void MainProc()
{
CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)HookpDevice,NULL,NULL,NULL);  
CreateThread(0,0,(LPTHREAD_START_ROUTINE)Start_key,0,0,0);
ExitThread(hExitThread);
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{

	DisableThreadLibraryCalls(hDll);
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		char *dat = Date();
		GetModuleFileName(hDll, dlldir, 512);
		for(int i = strlen(dlldir); i > 0; i--) { if(dlldir[i] == '\\') { dlldir[i+1] = 0; break; } }
		//ofile.open(GetDirFile("ttnlog.txt"), ios::app);

		add_log("\n---------------------\nSZOhack Started...\n%s\n---------------------",dat);

		StartLogModule(hDll);
		add_log("logmodule started");
		//StartRoutine(HookpDevice);
		DisableThreadLibraryCalls(hDll);
		add_log("disabled calls");
		//привязка();
		EraseHeaders(hDll);
		add_log("headers erased");
		HideModule(hDll);
		add_log("module hided");

		CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)MainProc,NULL,NULL,NULL);
		add_log("thread created");
		Fun.Color1 = 1;
	}
	//if (dwReason == DLL_PROCESS_DETACH);
	//{
	//	add_log("---------------------\nSZOhack Exiting...\n---------------------\n");
	//	if(ofile) { ofile.close(); }
	//}
	return TRUE;
}

void Save()
{
	WritePPI(VisualMenu,"PVP",Fun.pvp,GetDirFile(filename));
	WritePPI(VisualMenu,"Mob",Fun.Mob,GetDirFile(filename));
	WritePPI(VisualMenu,"Art",Fun.Art,GetDirFile(filename));
	WritePPI(VisualMenu,"Drop",Fun.Drop,GetDirFile(filename));
	WritePPI(VisualMenu,"Cache",Fun.Cache,GetDirFile(filename));
	WritePPI(VisualMenu,"Mushroom",Fun.Grib,GetDirFile(filename));
	WritePPI(VisualMenu,"Leaves",Fun.Listva,GetDirFile(filename));
	WritePPI(VisualMenu,"Ligth",Fun.Svet,GetDirFile(filename));
	WritePPI(VisualMenu,"Crosshair",Fun.Crosshair,GetDirFile(filename));

	//WritePPI(OtherMenu,"FreezeHeight",Fun.FreezeHeigth,GetDirFile(filename));
	WritePPI(OtherMenu,"Jump_Voll",Fun.Jump,GetDirFile(filename));
	WritePPI(OtherMenu,"Fall_Voll",Fun.Fall,GetDirFile(filename));
	WritePPI(OtherMenu,"jump",Fun.jump,GetDirFile(filename));
	WritePPI(OtherMenu,"fall",Fun.fall,GetDirFile(filename));
	WritePPI(OtherMenu,"Camera",Fun.Camera,GetDirFile(filename));

	WritePPI(Settings,"NameX",NameX,GetDirFile(filename));
	WritePPI(Settings,"NameY",NameY,GetDirFile(filename));
	Fun.Save=false;
}

void Load()
{
	Fun.pvp=GPPI(VisualMenu,"PVP",Fun.pvp,GetDirFile(filename));
	Fun.Mob=GPPI(VisualMenu,"Mob",Fun.Mob,GetDirFile(filename));
	Fun.Art=GPPI(VisualMenu,"Art",Fun.Art,GetDirFile(filename));
	Fun.Drop=GPPI(VisualMenu,"Drop",Fun.Drop,GetDirFile(filename));
	Fun.Cache=GPPI(VisualMenu,"Cache",Fun.Cache,GetDirFile(filename));
	Fun.Grib=GPPI(VisualMenu,"Mushroom",Fun.Grib,GetDirFile(filename));
	Fun.Listva=GPPI(VisualMenu,"Leaves",Fun.Listva,GetDirFile(filename));
	Fun.Svet=GPPI(VisualMenu,"Ligth",Fun.Svet,GetDirFile(filename));
	Fun.Crosshair=GPPI(VisualMenu,"Crosshair",Fun.Crosshair,GetDirFile(filename));

	//Fun.FreezeHeigth=GPPI(OtherMenu,"FreezeHeight",Fun.FreezeHeigth,GetDirFile(filename));
	Fun.Jump=GPPI(OtherMenu,"Jump_Voll",Fun.Jump,GetDirFile(filename));
	Fun.Fall=GPPI(OtherMenu,"Fall_Voll",Fun.Fall,GetDirFile(filename));
	Fun.jump=GPPI(OtherMenu,"jump",Fun.jump,GetDirFile(filename));
	Fun.fall=GPPI(OtherMenu,"fall",Fun.fall,GetDirFile(filename));
	Fun.Camera=GPPI(OtherMenu,"Camera",Fun.Camera,GetDirFile(filename));

	NameX=GPPI(Settings,"NameX",NameX,GetDirFile(filename));
	NameY=GPPI(Settings,"NameY",NameY,GetDirFile(filename));
	Fun.Load=false;
}
