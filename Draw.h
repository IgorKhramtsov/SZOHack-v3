void Font(CHAR* FontName, int HFont, DWORD Stile, IDirect3DDevice9* pDevice)
{
	D3DXCreateFont(pDevice, HFont, 0, Stile, 1, 0, RUSSIAN_CHARSET, OUT_DEVICE_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, FontName, &pFont);
}
void DrawBox(FLOAT x, FLOAT y, FLOAT w, FLOAT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y - h, x + w, y };
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}

void DrawBorder(int x, int y, int w, int h, int o, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox(x, y, w, 2, color, pDevice);
	DrawBox(x - 1, y, 2, h, color, pDevice);
	DrawBox(x - 1, y - h, w + 2 + 1, 2, color, pDevice);
	DrawBox(x + w, y, 2, h, color, pDevice);
}

LPD3DXLINE S_Line;
void DrawLine(float StartX, float StartY, float EndX, float EndY, int Width, D3DCOLOR dColor)
{
	S_Line[0].SetWidth(Width);
	S_Line[0].SetGLLines(0);
	S_Line[0].SetAntialias(1);
	D3DXVECTOR2 v2Line[2];
	v2Line[0].x = StartX;
	v2Line[0].y = StartY;
	v2Line[1].x = EndX;
	v2Line[1].y = EndY;
	S_Line[0].Begin();
	S_Line[0].Draw(v2Line, 2, dColor);
	S_Line[0].End();
}
LPD3DXLINE              g_pLine = NULL;
void DrawRectangle(float x, float y, float w, int h)
{

        D3DXVECTOR2 vLine1[2];
        D3DXVECTOR2 vLine2[2];
        D3DXVECTOR2 vLine3[2];
        D3DXVECTOR2 vLine4[2];

        vLine1[0].x = x; 
        vLine1[0].y = y; 
        vLine1[1].x = x; 
        vLine1[1].y = y+h;

        vLine2[0].x = x+w; 
        vLine2[0].y = y; 
        vLine2[1].x = x+w; 
        vLine2[1].y = y+h;

        vLine3[0].x = x; 
        vLine3[0].y = y; 
        vLine3[1].x = x+w; 
        vLine3[1].y = y;

        vLine4[0].x = x; 
        vLine4[0].y = y+h; 
        vLine4[1].x = x+w; 
        vLine4[1].y = y+h;

        S_Line->SetWidth(2);
        S_Line->SetAntialias(false);
        S_Line->SetGLLines(false);
        S_Line->Begin();
        S_Line->Draw(vLine1, 2, 0xFF0000FF);
        S_Line->Draw(vLine2, 2, 0xFF0000FF);
        S_Line->Draw(vLine3, 2, 0xFF0000FF);
        S_Line->Draw(vLine4, 2, 0xFF0000FF);
        S_Line->End();

}

void  String(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
	{
		RECT rect;
		SetRect(&rect, x, y, x, y);
		char Buffer[1024] = { '\0' };
		va_list va_alist;
		va_start(va_alist, Format);
		vsprintf_s(Buffer, Format, va_alist);
		va_end(va_alist);
		pFont->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

		return;
	}

	void  SString(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
	{
		RECT rect;
		SetRect(&rect, x, y, x, y);
		char Buffer[1024] = { '\0' };
		va_list va_alist;
		va_start(va_alist, Format);
		vsprintf_s(Buffer, Format, va_alist);
		va_end(va_alist);
		pFont->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

		return;
	}

void  Box(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	}
	V[4] = { {x, y + h, 0.0f, 0.0f, Color}, { x, y, 0.0f, 0.0f, Color }, { x + w, y + h, 0.0f, 0.0f, Color }, { x + w, y, 0.0f, 0.0f, Color } };

	pD3D9->SetTexture(0, NULL);
	pD3D9->SetPixelShader(0);
	pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3D9->SetRenderState(D3DRS_ZENABLE, FALSE);
	pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
	return;
}

void Border(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	Box(x - s, y, s, h, Color, pD3D9);
	Box(x - s, y + h, w + s * 2, s, Color, pD3D9);
	Box(x - s, y - s, w + s * 2, s, Color, pD3D9);
	Box(x + w, y, s, h + s, Color, pD3D9);
}

//-----------------------------------------------------------------------------
// Exam: Xhair(Size,Width,Color,10,pDevice);
// Desc: Перехрестие в центре екрана (Прицел в шутерах , CrossHair)
// Сonc: Menu
//-----------------------------------------------------------------------------

VOID Xhair(D3DCOLOR Color, IDirect3DDevice9* pDevice)
{
D3DVIEWPORT9 viewP;
pDevice->GetViewport(&viewP);
DWORD ScreenCenterX = viewP.Width / 2;
DWORD ScreenCenterY = viewP.Height / 2;

D3DRECT rec16 = {ScreenCenterX-5, ScreenCenterY, ScreenCenterX+ 5, ScreenCenterY+1};
D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-5, ScreenCenterX+ 1,ScreenCenterY+5};
pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET, Color, 0,  0 );
pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET, Color, 0,  0 );  
}

//-----------------------------------------------------------------------------
// Exam: D3D9ScreenShot(pDevice);
// Desc: Скриншот
// Сonc: Menu
//-----------------------------------------------------------------------------
//int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19,i20,i21,i22,i23,i24,i25,i26,i27,i28,i29,i30,off,on,save;
void D3D9ScreenShot(IDirect3DDevice9* pDevice)
{
	/*
	i=Show;
	i1=Fun.Art;
	i2=Fun.Crosshair;
	i3=Fun.Drop;
	i4=Fun.Grib;
	i5=Fun.Listva;
	i6=Fun.Mob;
	i7=Fun.Nichki;
	i8=Fun.pvp;
	i9=Fun.Svet;
	i10=Fun.Travi;
	i11=Fun.WireFrame;

	Show=0;
	Fun.Art=0;
	Fun.Crosshair=0;
	Fun.Drop=0;
	Fun.Grib=0;
	Fun.Listva=0;
	Fun.Mob=0;
	Fun.Nichki=0;
	Fun.pvp=0;
	Fun.Svet=0;
	Fun.Travi=0;
	Fun.WireFrame=0;
	scr=1;
	if(	Show==0&&Fun.Art==0&&Fun.Crosshair==0&&Fun.Drop==0&&Fun.Grib==0&&Fun.Listva==0&&Fun.Mob==0&&Fun.Nichki==0&&Fun.pvp==0&&Fun.Svet==0&&Fun.Travi==0&&Fun.WireFrame==0&&scr==1)
	{
	sprintf(FileName, "SZOHack Screen %d.jpg", I);
	add_log("%d %d %d %d %d",Show,Fun.Art,Fun.Mob,Fun.pvp,scr);
	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &surf);
	D3DXSaveSurfaceToFile(FileName, D3DXIFF_JPG, surf, NULL, NULL);
	I++;
	Beep(1000, 100);
	//off=0;
	}
	Fun.Art=i1;
	Fun.Crosshair=i2;
	Fun.Drop=i3;
	Fun.Grib=i4;
	Fun.Listva=i5;
	Fun.Mob=i6;
	Fun.Nichki=i7;
	Fun.pvp=i8;
	Fun.Svet=i9;
	Fun.Travi=i10;
	Fun.WireFrame=i11;
	Show=i;
	scr=0;
	//on=0;
	*/
	scr=1;
	//for(int b;b<5;b++){nope=nope;}
	if(scr==1)
	{
	sprintf(FileName, "SZOHack Screen %d.jpg", I);
	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &surf);
	D3DXSaveSurfaceToFile(FileName, D3DXIFF_JPG, surf, NULL, NULL);
	I++;
	Beep(1000, 100);
	scr=0;
	}
}

//-----------------------------------------------------------------------------
// Exam: Circle(X,Y,10,10,Color);
// Desc: Круг
// Сonc: Menu
//-----------------------------------------------------------------------------

void Circle(int X, int Y, int radius, int numSides, DWORD Color)
{
	D3DXVECTOR2 Line[128];
	float Step = PI * 2.0 / numSides;
	int Count = 0;
	for (float a=0; a < PI*2.0; a += Step)
	{
		float X1 = radius * cos(a) + X;
		float Y1 = radius * sin(a) + Y;
		float X2 = radius * cos(a+Step) + X;
		float Y2 = radius * sin(a+Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count+1].x = X2;
		Line[Count+1].y = Y2;
		Count += 2;
	}
	pLine->Begin();
	pLine->Draw(Line,Count,Color);
	pLine->End();
}

//-----------------------------------------------------------------------------
// Компоненты ColorCircle
//-----------------------------------------------------------------------------

struct D3DTLVERTEX{float fX;float fY;float fZ;float fRHW;	D3DCOLOR Color;	float fU;	float fV;};
D3DTLVERTEX Vtex[400];
D3DTLVERTEX CreateD3DTLVERTEX (float X, float Y, float Z, float RHW, D3DCOLOR color, float U, float V)
{	
D3DTLVERTEX v;	
v.fX = X;v.fY = Y;v.fZ = Z;	
v.fRHW = RHW;v.Color = color;	
v.fU = U;v.fV = V;	
return v;
}

//-----------------------------------------------------------------------------
// Exam: ColorCircle(x,y,10,10,Colorit,pDevice);
// Desc: ЦветнойКруг
// Сonc: Menu
//-----------------------------------------------------------------------------

void ColorCircle(int x,int y,int radius,DWORD Colorit,IDirect3DDevice9* pDevice)
{
	float xPos = (float)x;
	float yPos = (float)y;
    //LPDIRECT3DTEXTURE9 Col_ = NULL;
	//GenerateTextureCircle(pDevice, &Col_,  Colorit);
    D3DCOLOR Color = D3DCOLOR_ARGB( 255, 255, 255, 255 ); 
	pDevice->SetTexture( 0, Green );	
		float x1 = xPos;
	    float y1 = yPos;
	for( int i=0;i<=363;i+=3 )
	{
		float angle = ( i / 57.3f );   
		float x2 = xPos + ( radius * sin( angle ) );
		float y2 = yPos + ( radius * cos( angle ) );             
		Vtex[i] =   CreateD3DTLVERTEX( xPos, yPos, 0, 1, Color, 0, 0 );	
		Vtex[i+1] = CreateD3DTLVERTEX( x1, y1, 0, 1,     Color, 0, 0 );	
		Vtex[i+2] = CreateD3DTLVERTEX( x2, y2, 0, 1,     Color, 0, 0 );	

		y1 = y2;
		x1 = x2;
	}
	pDevice->DrawPrimitiveUP( D3DPT_TRIANGLESTRIP, 363, Vtex, sizeof( D3DTLVERTEX ) );
}

//-----------------------------------------------------------------------------
// Exam: IsInBox(x,y,w,h);
// Desc: Наведение
// Сonc: Components
//-----------------------------------------------------------------------------

BOOL  IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}
/*
//Class создания шрифта
class cInstalling
{
public:

	void __fastcall InstallLine(LPDIRECT3DDEVICE9 pDevice)
	{
		D3DXCreateLine(pDevice, &pLine);
	}
	void __fastcall ResetLine()
	{
		pLine->OnLostDevice();
		pLine->OnResetDevice();
	}
	void __fastcall OnLostLine()
	{
		pLine->OnLostDevice();
	}
	void __fastcall InstallFont(LPDIRECT3DDEVICE9 pDevice)
	{
		D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "Tahoma", &pFont);
		D3DXCreateFontA(pDevice, 18, 0, FW_REGULAR, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "Fixedsys", &pFonts);
	}
	void __fastcall ResetFont()
	{
		pFont->OnLostDevice();
		pFont->OnResetDevice();
		pFonts->OnLostDevice();
		pFonts->OnResetDevice();
	}
	void __fastcall OnLostFont()
	{
		pFont->OnLostDevice();
		pFonts->OnLostDevice();
	}

	BOOL __fastcall CheckFont()
	{
		if (pFont && pFonts)
			return FALSE;
		else
			return TRUE;
	}
}*cInstall;
*/
