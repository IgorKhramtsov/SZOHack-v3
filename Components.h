	int ff2=15;
	//loger
	int mPos			=0;
	const int mPosMax	=6;
	char *Simvol [4]={"==",">=","<=","!="};

	bool test=false;
class Visual
{
public:

  inline void __fastcall  ButtonMenu( int x, int y,char *text, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
		
	DWORD color = BackGround,colors =BackGround, Text =Texts;

	if (IsInBox(x, y, 188, 20))
	{
	color = BackIsIn,colors = BackIsIn;
		if (lm)
		{
		if(Var == 1 && Var !=0)
           Var = 0;else if(Var == 0)
			{
				Fun.Visual = Fun.Other = 0; 
				 Var = 1;
			}
		}
	}
		  if (Var == 1)
	{
			colors=BackGroundOn2,color = BackGroundOn2,Text=BLACK;
	}
	Box(x,y,188,20,color,pDevice);
	Border(x,y,188,20,2,BLACK,pDevice);
		if (Var == 1)
	{
		Box(x,y+2, 188,20, BackGroundOn2, pDevice);
		DopButton(pDevice);
	}
	SString(x+70 , y + 5, Text, DT_LEFT| DT_NOCLIP, text);
}

  inline void __fastcall  Button( int x, int y,char *text, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
		
	DWORD color = BackGround,colors =BackGround, Text =Texts;
	int txlen = GetTextLen(text);

	if (IsInBox(x, y, txlen+10, 20))
	{
	color = BackIsIn,colors = BackIsIn;
		if (lm)
		{
				 Var = (!Var);
		}
	}
	 if (Var == 1)
	{
			colors=BackGroundOn2,color = BackGroundOn2,Text=BLACK;
	}
	Box(x,y,txlen+10,20,color,pDevice);
	Border(x,y,txlen+10,20,2,BLACK,pDevice);
		if (Var == 1)
	{
		Box(x,y, txlen+10,20, BackGroundOn2, pDevice);
	}
	SString(x+5 , y+2, Text, DT_LEFT| DT_NOCLIP, text);
}

  inline void __fastcall  TeleportMenu( int x, int y,char *text, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
		
	DWORD color = BackGround,colors =BackGround, Text =Texts;

	int txlen = GetTextLen(text);

	if (IsInBox(x, y, 96, 20))
	{
	color = BackIsIn,colors = BackIsIn;
		if (lm)
		{
		if(Var == 1 && Var !=0)
           Var = 0;else if(Var == 0)
			{
				Fun.QuestTab = Fun.Noob_City = Fun.Lubech = Fun.Vesuvius = Fun.OtherTP = Fun.Novaya = Fun.Tunguska = Fun.Caravan = 0; 
				 Var = 1;
			}
		}
	}
		  if (Var == 1)
	{
			colors=BackGroundOn2,color = BackGroundOn2,Text=BLACK;
	}
	Box(x,y,96,20,color,pDevice);
	Border(x,y,96,20,2,BLACK,pDevice);
	SString(x+5 , y+5, Text, DT_LEFT| DT_NOCLIP, text);
}
  inline void __fastcall  QuestMenu( int x, int y,char *text, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
		
	DWORD color = BackGround,colors =BackGround, Text =Texts;

	int txlen = GetTextLen(text);
	int weight=120;
	if (IsInBox(x, y, 96, 20))
	{
	color = BackIsIn,colors = BackIsIn;
		if (lm)
		{
		if(Var == 1 && Var !=0)
           Var = 0;
			else if(Var == 0)
			{
				Fun.SnowMen=Fun.BigHunt=Fun.LostItem=0;
				 Var = 1;
			}
		}
	}
		  if (Var == 1)
	{
			colors=BackGroundOn2,color = BackGroundOn2,Text=BLACK;
			weight=123;
			cVisual->DopButton2(x+weight,MenuY+MenuLength+54,x,y,color,pDevice);
	}
	Border(x,y,120,20,2,BLACK,pDevice);
	Box(x,y,weight,20,color,pDevice);
	SString(x+5 , y+5, Text, DT_LEFT| DT_NOCLIP, text);
}
  inline void __fastcall  Teleport( int x, int y,char *text, int &Var, LPDIRECT3DDEVICE9 pDevice)
{
	int txlen = GetTextLen(text);
	DWORD Text =Texts;

	if (IsInBox(x, y, txlen+2, 15))
	{
		Text=Texts_;
		if (lm)
		{
			Var=1;
		}
		else if(rm)
		{
			Var=2;
		}
	}
	SString(x,y,Text, DT_LEFT| DT_NOCLIP,text);
}
  inline void __fastcall  Options( int x, int y,char *BText,char *Info, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
	POINT mpos; 
	GetCursorPos(&mpos); 
	ScreenToClient(GetForegroundWindow(),&mpos);
	int textlen =	GetTextLen(Info);
	if (Var==0)
	{
	Border(x, y, 11, 11, 2, DARK16, pDevice);
	}
	if (Var == 1)
	{
	Border(x, y, 11, 11, 2, DARK18, pDevice);
	}
	if (IsInBox(x, y, 11, 11))
	{
	Box(mpos.x+5,mpos.y+17,textlen+10,15,DARK13,pDevice);
	Border(mpos.x+5,mpos.y+17,textlen+10,15,1,DARK8,pDevice);
	String(mpos.x+9,mpos.y+17,WHITE,DT_LEFT | DT_NOCLIP,Info);
		if (lm)
		{
			Var=(!Var);
		}
	}
	String(x+1,y-2,DARK20, DT_LEFT | DT_NOCLIP,BText);
}

  inline void __fastcall  DoubleCheck( int x, int y,char *BText, bool &Var, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD Col1;
	Border(x, y, 40, 15, 2, DARK12, pDevice);
		if (Var == 1)
	{
		Box(x+20, y +1, 18, 13, DARK8, pDevice);
		Col1=WHITE;
	}
	else if(Var==0)
	{
		Box(x+2, y +1, 18, 13, DARK8, pDevice);
		Col1=DARK20;
	}

	if (IsInBox(x, y, 150, 12))
	{
		if (lm)
		{
			Var = !Var;
		}
	}
	//Box(x + 1, y + 1, 38, 13, DARK5, pDevice);
	String( x + 50, y + 1, Col1, DT_LEFT | DT_NOCLIP,BText);
}
int GetTextLen(LPCTSTR szString)
{
    RECT rect = {0,0,0,0};
    pFont->DrawText(NULL, szString, -1, &rect, DT_CALCRECT, 0);
    return rect.right;
} 
  inline void __fastcall  Group_Box(int x,int y,int w,int h,LPCTSTR szString,IDirect3DDevice9* pDevice )
{
	int wht = 1;
	int Tmp_ = GetTextLen(szString);
	if(w>(Tmp_+2))
	{
	 DrawBox(x, y,4,wht,WHITE,  pDevice);//Верх до текста
	 DrawBox(x+7+Tmp_, y,w-6-Tmp_,wht,WHITE,  pDevice);//Верх после текста
     DrawBox(x, y+h,w,wht,WHITE,  pDevice);//низ
	 DrawBox(x, y+h,wht,h,WHITE,  pDevice);//Слева
	 DrawBox(x+w, y+h,wht,h,WHITE,  pDevice);//Справа
	 String( x+6,y-7, Light, DT_LEFT | DT_NOCLIP,(LPSTR)szString);
	}
}
  inline void __fastcall  Scroll(int x, int y,char *BText, char **typ,float w, int Num, int &GetCurrent,bool isfloat, LPDIRECT3DDEVICE9 pDevice)
{
	float GetCurrentf = (float)GetCurrent/10;
	POINT mpos;
	GetCursorPos(&mpos);
	ScreenToClient(GetForegroundWindow(), &mpos);
	if (IsInBox(x, y-2.5, w, ff2))
	{
			if (flm)
			{
				GetCurrent = mpos.x - (x);
				ff2=1000;
			}
			else
			{
				ff2=15;
			}
	}
	Box(x, y, w + 10, 10, DARK5, pDevice);
	Border(x , y, w+10, 10, 1, BLACK, pDevice);
	Box(x + GetCurrent, y,h-GetCurrent, 10, EColOn, pDevice);
	Box(x + GetCurrent, y-2.5, 10, 15, EColOn, pDevice);
	Border(x+ GetCurrent, y-2.5, 10, 15, 1, BLACK, pDevice);
 static char test[MAX_PATH];
 if(isfloat==true)
 sprintf(test, "  [%f] %s", GetCurrentf / Num,BText);
 else
 sprintf(test, "  [%d] %s", GetCurrent / Num,BText);
 String(x, y - 20, WHITE, DT_LEFT | DT_NOCLIP, test);
}
  inline	void __fastcall DopButton(LPDIRECT3DDEVICE9 pDevice)
{	
		//Box(x+154, 60, 390-144, 108, BackGroundOn, pDevice);
	    //Box(x+156, 62, 390-149, 103, BackGroundOn2 ,pDevice);
		Box(MenuX,MenuY+24,MenuWidth,MenuLength-24, BackGroundOn2, pDevice);
}
  inline	void __fastcall DopButton2(int x,int y,int xbutt,int ybutt,D3DCOLOR color,LPDIRECT3DDEVICE9 pDevice)
{	
		int a=ybutt-y;
		//Box(x+154, 60, 390-144, 108, BackGroundOn, pDevice);
	    //Box(x+156, 62, 390-149, 103, BackGroundOn2 ,pDevice);
		Box(x,y,247,456, color, pDevice);
		Box(x-2,y,2,ybutt-y,BLACK,pDevice);
		Box(x-2,y+a+20,2,456-a,BLACK,pDevice);
		//Box(x,y+20,2,456-20,BLACK,pDevice);
		//Box(x,y-20,2,456+20,BLACK,pDevice);
}
  inline	void __fastcall DopMenu(int x,int y, int w,int h,LPDIRECT3DDEVICE9 pDevice)
{	
		Box(x,y,w,h,BackGround,pDevice);
		Border(x,y,w,h,2,BLACK,pDevice);
}
  inline void __fastcall DrawMenu(LPDIRECT3DDEVICE9 pDevice)
{
	//NameHack="Multihack for SZoneOnline";
	Border(MenuX,MenuY,MenuWidth,MenuLength,2,BLACK,pDevice);//Menu
    Box(MenuX,MenuY,MenuWidth,MenuLength,BackGround,pDevice);//Menu

	Border(NameX,NameY,NameWidth,NameLength,2,BLACK,pDevice);//Title
	Box(NameX,NameY,NameWidth,NameLength,UpColor,pDevice);//Title
	String(NameX+4,NameY+2,WHITE,DT_LEFT | DT_NOCLIP, NameHack);
}

}*cVisual;