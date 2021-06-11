
#include "Includes.h"
#include <Windows.h>
#include <DbgHelp.h>
#include <Mmsystem.h>
#include "Coord.h"
#pragma comment (lib, "Winmm.lib")



 DWORD BufPos;
 DWORD BufCamera;
 DWORD BufAccuracy;

 float playerXmob;
 float playerYmob;
 float Heigthmob;
 //int b;
 float a=0,b=0,c=0;
 float zero=0.0f;

 float persX;
 float persY;
 float persH;
 float persX_=0;
 float persY_=0;
 float persH_=0;

 DWORD AdressPosition;
 DWORD AdressCamera;
 DWORD AdressAccuracy;
 DWORD AdressDistanceObject=0x009C3728;
 DWORD AdressZoom=0x007981AB;
 DWORD AdressFHVisual=0x004376F2;
 DWORD AdressRadarAsm=0x004376EF;
 DWORD AdressRadar;
 DWORD AdressDistanceObjectSbros=0x0043F840;//		\xF3\x0F\x11\x46\x10\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x8C\x24\x00\x00\x00\x00\x64\x89\x0D\x00\x00\x00\x00
											//		xxxxxxxx????xxx????xxx????

 DWORD Adress_Tusa_Mob=0x0046B66B;//	\x8B\x3A\x89\x78\x10\x8B\x7A\x04\x8D\x48\x10\x89\x79\x04\x8B\x52\x08\x89\x51\x08\x8B\x54\x24\x20\x8B\x3A\x89\x78\x1C\x8B\x7A\x04\x89\x78\x20\x8B\x52\x08\x89\x50\x24\x8B\x54\x24\x24\x5F
								  //	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 DWORD Adress_NoAnimMob=0x0046B69B;//Adress_Tusa_Mob+30
 DWORD fix_Target=0x0043F688;//			\x74\x37\x8D\x44\x24\x20\x50\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xF8\x8D\x4C\x24\x18\x51
							 //			xxxxxxxx????xxx????xxxxxxx
 DWORD Camera_fix=0x00791F56;//			\xF3\x0F\x11\x46\x1C\xDD\x5E\x68\x88\x5E\x18\xD9\xEE\x5F\x88\x5E\x18\xDD\x5E\x68
							 //			xxxxxxxxxxxxxxxxxxxx
  DWORD AdressFreeze=0x46ED41;//		\x89\x51\x24\x8B\x40\x08\x89\x41\x28\x8B\x44\x24\x1C\x85\xC0
							  //		xxxxxxxxxxxxxxx

 DWORD Z_offset=0x24;
 DWORD X_offset=0x20;
 DWORD Y_offset=0x28;
 DWORD Z=0x4;
 DWORD Y=0x8;
 DWORD Asimut_offset=0x20;
 DWORD Vertical_offset=0x1c;

 DWORD numvert;

 void memhack()
{

	AdressPosition=(DWORD)SO+0x005C379C;
	AdressCamera=(DWORD)SO+0x00609CB0;
	AdressAccuracy=(DWORD)SO+0x005B318C;
	AdressRadar=0x0058F09C;

	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressPosition), &BufPos, sizeof(BufPos), NULL);//Базовый
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+0x8), &BufPos, sizeof(BufPos), NULL);//Базовый+1смещение
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+0x40), &BufPos, sizeof(BufPos), NULL);//второе смещение
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+X_offset), &Player.X, sizeof(Player.X), NULL);//координаты Х
    ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+Y_offset), &Player.Y, sizeof(Player.Y), NULL);//координаты Y
    ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z), NULL);//координаты Z

	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressCamera), &BufCamera, sizeof(BufCamera), NULL);//базовый адресс
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufCamera+Asimut_offset), &Player.Asimut, sizeof(Player.Asimut), NULL);//буфер базового+оффсет азимута
    ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufCamera+Vertical_offset), &Player.Vertical, sizeof(Player.Vertical), NULL);//буфер базового+оффсет вертикали 

	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressAccuracy), &BufAccuracy, sizeof(BufAccuracy), NULL);//Базовый+1смещение
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufAccuracy+0x254), &BufAccuracy, sizeof(BufAccuracy), NULL);//второе смещение
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufAccuracy+0x5BC), &BufAccuracy, sizeof(BufAccuracy), NULL);//AccuracyVol

		if(GetAsyncKeyState(VK_END)&1)
	{
		add_log("{%f},//Name\n""{%f},\n""{%f},",Player.X,Player.Y,Player.Z);
	}
		/*
	DetourCreate((PBYTE)AdressRadarAsm,(PBYTE)Radar,5);
		if(RadarX!=0&&RadarX!=a)
	{
		add_log("X:%f",RadarX);
		a=RadarX;
	}
	*/



	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressRadar+Y), &RadarY, sizeof(RadarY), NULL);//Y
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressRadar+Z), &RadarZ, sizeof(RadarZ), NULL);//Z
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressRadar), &RadarX, sizeof(RadarX), NULL);//X
	//add_log("X:%f",RadarX);

	
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufAccuracy+0x4e), &BufAccuracy, sizeof(BufAccuracy), NULL);//AccuracyVol
	//char Test[128];
	//sprintf(Test,"%d",AdressRadar);
	//MB(Test,"");
	/*
	if(RadarX!=0)
	{
		add_log("X:%f",RadarX);
		a=RadarX;
	}
	
	if(RadarY!=0)
	{
		add_log("Y:%f",RadarY);
		b=RadarY;
	}
	if(RadarZ!=0)
	{
		add_log("Z:%f",RadarZ);
		c=RadarZ;
	}
	*/
	if(Fun.Accuracy==1){MEMwrite((void *)(BufAccuracy+0x3e),(int*)(PBYTE)"\x74", 1);}
	else if(Fun.Accuracy==0){MEMwrite((void *)(BufAccuracy+0x3e),(int*)(PBYTE)"\xF4", 1);}
	if(Fun.Camera==1){MEMwrite((void *)(Camera_fix),(int*)(PBYTE)"\x90\x90\x90\x90\x90", 5);}
	if(Fun.Camera==0){MEMwrite((void *)(Camera_fix),(int*)(PBYTE)"\xF3\x0F\x11\x46\x1C", 5);}

	MEMwrite((void *)(AdressDistanceObjectSbros),(int*)(PBYTE)"\x90\x90\x90\x90\x90", 5);
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressDistanceObject), &DistanceObject, sizeof(DistanceObject), NULL);//DasitanceObject

	if(Fun.NoAnimMob==1){MEMwrite((void *)(Adress_NoAnimMob),(int*)(PBYTE)"\xEB\x0B", 2);}
	else{MEMwrite((void *)(Adress_NoAnimMob),(int*)(PBYTE)"\x74\x0B", 2);}
	if(Fun.Tusa==1)
	{
		if(b!=1)
		{
			XMob=Player.X;
			YMob=Player.Y;
			ZMob=Player.Z+6;
			b=1;
		}
		DetourCreate((PBYTE)Adress_Tusa_Mob,(PBYTE)TUSA_MOB_on,5);//Вкл
	}
	else
	{
		DetourCreate((PBYTE)Adress_Tusa_Mob,(PBYTE)TUSA_MOB_off,5);//Выкл
		b=0;
	}
		if(Fun.ZOOM==1)
	{
		DetourCreate((PBYTE)AdressZoom,(PBYTE)ZoomOn,5);//Вкл
	}
	else
	{
		DetourCreate((PBYTE)AdressZoom,(PBYTE)ZoomOff,5);//Выкл
	}

	if(GetAsyncKeyState(VK_DIVIDE)&1)Fun.FreezeHeigth=(!Fun.FreezeHeigth);
	if(Fun.FreezeHeigth==1)MEMwrite((void *)(AdressFreeze),(void *)"\x90\x90\x90",3);
	if(Fun.FreezeHeigth==0)MEMwrite((void *)(AdressFreeze),(void *)"\x89\x51\x24",3);


	  if (abs(Player.Asimut)<=(PI/2)) { X_=Player.Asimut;}
	  else if (Player.Asimut>=0) { X_=(PI/2)-(abs(Player.Asimut)-(PI/2));}
	  else  {X_=(-1*PI/2)+(abs(Player.Asimut)-(PI/2));}
      if (abs(Player.Asimut)<=(PI/2)) 
	  {
			  if (X_>0) 
			  {
				  Y_=(PI/2)-X_;
			  } 
			  else 
			  {
				  Y_=(PI/2)+X_;
			  }
	  } 
	  else if (X_>0) {Y_=X_-(PI/2);} 
	  else {Y_=-1*(X_+(PI/2));}

	  if(Fun.MoveX==0){Fun.MoveX=1;}
	  	  if(GetAsyncKeyState(VK_SUBTRACT)&1)
	  {
		  Player.Z=Player.Z+PI/18;
		  Player.X=Player.X+(X_/2)*(Fun.MoveX);
		  Player.Y=Player.Y+(Y_/2)*(Fun.MoveX);
		  Sleep (60);
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
      WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
	  }

	  	  if(GetAsyncKeyState(VK_ADD)&1)
	  {
		  Player.Z=Player.Z+PI/18;
		  Player.X=Player.X+(X_/2)*-1*(Fun.MoveX);
		  Player.Y=Player.Y+(Y_/2)*-1*(Fun.MoveX);
		  Sleep (60);
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
      WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
	  }
		
		  if((Fun.jump==1)&&(GetAsyncKeyState(VK_PRIOR)&1))
	  {
	  Player.Z=Player.Z+Fun.Jump;
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL);//Z
	  }

	  if((Fun.fall==1)&&(GetAsyncKeyState(VK_NEXT)&1))
	  {
	  Player.Z=Player.Z-Fun.Fall;
      WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL);//Z
	  }
		  ////////////////////////Lubech////////////////////////
		  if(gur!=0)
		  {
			  Player.X=Lubech[1];
			  Player.Y=Lubech[2];
			  if(gur==2){Player.Z=Lubech[3]-100;}
			  if(gur==1){Player.Z=Lubech[3];}
			  gur=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Since!=0)
		  {
			  Player.X=Lubech[7];
			  Player.Y=Lubech[8];
			  if(Since==1)Player.Z=Lubech[9];
			  if(Since==2)Player.Z=Lubech[9]-100;
			  Since=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(bolota!=0)
		  {
			  Player.X=Lubech[10];
			  Player.Y=Lubech[11];
			  if(bolota==1)Player.Z=Lubech[12];
			  else if(bolota==2)Player.Z=Lubech[12]-100;
			  bolota=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(InRyab!=0)
		  {
			  Player.X=Lubech[13];
			  Player.Y=Lubech[14];
			  if(InRyab==1)Player.Z=Lubech[15];
			  if(InRyab==2)Player.Z=Lubech[15]-100;
			  InRyab=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(himka!=0)
		  {
			  Player.X=Lubech[16];
			  Player.Y=Lubech[17];
			  if(himka==1)Player.Z=Lubech[18];
			  if(himka==2)Player.Z=Lubech[18]-100;
			  himka=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(DWhite!=0)
		  {
			  Player.X=Lubech[19];
			  Player.Y=Lubech[20];
			  if(DWhite==1)Player.Z=Lubech[21];
			  if(DWhite==2)Player.Z=Lubech[21]-100;
			  DWhite=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(PBandits!=0)
		  {
			  Player.X=Lubech[22];
			  Player.Y=Lubech[23];
			  if(PBandits==1)Player.Z=Lubech[24];
			  if(PBandits==2)Player.Z=Lubech[24]-100;
			  PBandits=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Provodnuk!=0)
		  {
			  Player.X=Lubech[25];
			  Player.Y=Lubech[26];
			  if(Provodnuk==1)Player.Z=Lubech[27];
			  if(Provodnuk==2)Player.Z=Lubech[27]-100;
			  Provodnuk=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(paukKost!=0)
		  {
			  Player.X=Lubech[28];
			  Player.Y=Lubech[29];
			  if(paukKost==1)Player.Z=Lubech[30];
			  if(paukKost==2)Player.Z=Lubech[30]-100;
			  paukKost=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(PaukResp!=0)
		  {
			  Player.X=Lubech[31];
			  Player.Y=Lubech[32];
			  if(PaukResp==1)Player.Z=Lubech[33];
			  if(PaukResp==2)Player.Z=Lubech[33]-100;
			  PaukResp=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Sanatorka!=0)
		  {
			  Player.X=Lubech[34];
			  Player.Y=Lubech[35];
			  if(Sanatorka==1)Player.Z=Lubech[36];
			  if(Sanatorka==2)Player.Z=Lubech[36]-100;
			  Sanatorka=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Psiha!=0)
		  {
			  Player.X=Lubech[37];
			  Player.Y=Lubech[38];
			  if(Psiha==1)Player.Z=Lubech[39];
			  if(Psiha==2)Player.Z=Lubech[39]-100;
			  Psiha=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Provodnik_CRV!=0)
		  {
			  Player.X=Lubech[40];
			  Player.Y=Lubech[41];
			  if(Provodnik_CRV==1)Player.Z=Lubech[42];
			  if(Provodnik_CRV==2)Player.Z=Lubech[42]-100;
			  Provodnik_CRV=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(UkrepH4!=0)
		  {
			  Player.X=Lubech[43];
			  Player.Y=Lubech[44];
			  if(UkrepH4==1)Player.Z=Lubech[45];
			  if(UkrepH4==2)Player.Z=Lubech[45]-100;
			  UkrepH4=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Imarek!=0)
		  {
			  Player.X=Lubech[46];
			  Player.Y=Lubech[47];
			  if(Imarek==1)Player.Z=Lubech[48];
			  if(Imarek==2)Player.Z=Lubech[48]-100;
			  Imarek=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  ////////////////////////Noob City////////////////////////
		  if(Vokzal!=0)
		  {
			  Player.X=noob_city[1];
			  Player.Y=noob_city[2];
			  if(Vokzal==2){Player.Z=noob_city[3]-100;}
			  if(Vokzal==1){Player.Z=noob_city[3];}
			  Vokzal=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Mentovka!=0)
		  {
			  Player.X=noob_city[4];
			  Player.Y=noob_city[5];
			  if(Mentovka==2){Player.Z=noob_city[6]-100;}
			  if(Mentovka==1){Player.Z=noob_city[6];}
			  Mentovka=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(DK!=0)
		  {
			  Player.X=noob_city[7];
			  Player.Y=noob_city[8];
			  if(DK==2){Player.Z=noob_city[9]-100;}
			  if(DK==1){Player.Z=noob_city[9];}
			  DK=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(KP1!=0)
		  {
			  Player.X=noob_city[10];
			  Player.Y=noob_city[11];
			  if(KP1==2){Player.Z=noob_city[12]-100;}
			  if(KP1==1){Player.Z=noob_city[12];}
			  KP1=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(KP2!=0)
		  {
			  Player.X=noob_city[13];
			  Player.Y=noob_city[14];
			  if(KP2==2){Player.Z=noob_city[15]-100;}
			  if(KP2==1){Player.Z=noob_city[15];}
			  KP2=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(KP3!=0)
		  {
			  Player.X=noob_city[16];
			  Player.Y=noob_city[17];
			  if(KP3==2){Player.Z=noob_city[18]-100;}
			  if(KP3==1){Player.Z=noob_city[18];}
			  KP3=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Basmach!=0)
		  {
			  Player.X=noob_city[19];
			  Player.Y=noob_city[20];
			  if(Basmach==2){Player.Z=noob_city[21]-100;}
			  if(Basmach==1){Player.Z=noob_city[21];}
			  Basmach=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Myachik!=0)
		  {
			  Player.X=noob_city[22];
			  Player.Y=noob_city[23];
			  if(Myachik==2){Player.Z=noob_city[24]-100;}
			  if(Myachik==1){Player.Z=noob_city[24];}
			  Myachik=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Mishka!=0)
		  {
			  Player.X=noob_city[25];
			  Player.Y=noob_city[26];
			  if(Mishka==2){Player.Z=noob_city[27]-100;}
			  if(Mishka==1){Player.Z=noob_city[27];}
			  Mishka=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Rubik!=0)
		  {
			  Player.X=noob_city[28];
			  Player.Y=noob_city[29];
			  if(Rubik==2){Player.Z=noob_city[30]-100;}
			  if(Rubik==1){Player.Z=noob_city[30];}
			  Rubik=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Nevalyashka!=0)
		  {
			  Player.X=noob_city[31];
			  Player.Y=noob_city[32];
			  if(Nevalyashka==2){Player.Z=noob_city[33]-100;}
			  if(Nevalyashka==1){Player.Z=noob_city[33];}
			  Nevalyashka=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Televizor1!=0)
		  {
			  Player.X=noob_city[34];
			  Player.Y=noob_city[35];
			  if(Televizor1==2){Player.Z=noob_city[36]-100;}
			  if(Televizor1==1){Player.Z=noob_city[36];}
			  Televizor1=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Televizor2!=0)
		  {
			  Player.X=noob_city[37];
			  Player.Y=noob_city[38];
			  if(Televizor2==2){Player.Z=noob_city[39]-100;}
			  if(Televizor2==1){Player.Z=noob_city[39];}
			  Televizor2=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Televizor3!=0)
		  {
			  Player.X=noob_city[40];
			  Player.Y=noob_city[41];
			  if(Televizor3==2){Player.Z=noob_city[42]-100;}
			  if(Televizor3==1){Player.Z=noob_city[42];}
			  Televizor3=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(DetskiySad!=0)
		  {
			  Player.X=noob_city[43];
			  Player.Y=noob_city[44];
			  if(DetskiySad==2){Player.Z=noob_city[45]-100;}
			  if(DetskiySad==1){Player.Z=noob_city[45];}
			  DetskiySad=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Skameiki!=0)
		  {
			  Player.X=noob_city[46];
			  Player.Y=noob_city[47];
			  if(Skameiki==2){Player.Z=noob_city[48]-100;}
			  if(Skameiki==1){Player.Z=noob_city[48];}
			  Skameiki=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  ////////////////////////Caravan////////////////////////
		  if(crvAnomaly!=0)
		  {
			  Player.X=Caravan[1];
			  Player.Y=Caravan[2];
			  if(crvAnomaly==2){Player.Z=Caravan[3]-100;}
			  if(crvAnomaly==1){Player.Z=Caravan[3];}
			  crvAnomaly=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(ProvodnikCrv1!=0)
		  {
			  Player.X=Caravan[4];
			  Player.Y=Caravan[5];
			  if(ProvodnikCrv1==2){Player.Z=Caravan[6]-100;}
			  if(ProvodnikCrv1==1){Player.Z=Caravan[6];}
			  ProvodnikCrv1=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(ProvodnikCrv2!=0)
		  {
			  Player.X=Caravan[7];
			  Player.Y=Caravan[8];
			  if(ProvodnikCrv2==2){Player.Z=Caravan[9]-100;}
			  if(ProvodnikCrv2==1){Player.Z=Caravan[9];}
			  ProvodnikCrv2=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(ProvodnikCrv3!=0)
		  {
			  Player.X=Caravan[10];
			  Player.Y=Caravan[11];
			  if(ProvodnikCrv3==2){Player.Z=Caravan[12]-100;}
			  if(ProvodnikCrv3==1){Player.Z=Caravan[12];}
			  ProvodnikCrv3=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  ////////////////////////Тунгуска////////////////////////
		  if(Tung_Resp!=0)
		  {
			  Player.X=Tunguska[1];
			  Player.Y=Tunguska[2];
			  if(Tung_Resp==2){Player.Z=Tunguska[3]-100;}
			  if(Tung_Resp==1){Player.Z=Tunguska[3];}
			  Tung_Resp=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Otverjeniy!=0)
		  {
			  Player.X=Tunguska[4];
			  Player.Y=Tunguska[5];
			  if(Otverjeniy==2){Player.Z=Tunguska[6]-100;}
			  if(Otverjeniy==1){Player.Z=Tunguska[6];}
			  Otverjeniy=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
		  if(Provodnikcrv!=0)
		  {
			  Player.X=Tunguska[7];
			  Player.Y=Tunguska[8];
			  if(Provodnikcrv==2){Player.Z=Tunguska[9]-100;}
			  if(Provodnikcrv==1){Player.Z=Tunguska[9];}
			  Provodnikcrv=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }

	  }
}
/*
		  if(name!=0)
		  {
			  Player.X=loc[i];
			  Player.Y=loc[i];
			  if(name==2){Player.Z=loc[i]-100;}
			  if(name==1){Player.Z=loc[i];}
			  name=0;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
		  }
*/