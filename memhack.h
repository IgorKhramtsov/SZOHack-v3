
#include "Includes.h"
#include <Windows.h>
#include <DbgHelp.h>
#include <Mmsystem.h>
#pragma comment (lib, "Winmm.lib")


 DWORD buf;
 DWORD BufPos;
 DWORD BufCamera;
 DWORD BufAccuracy;
 DWORD BufRadar;
 DWORD BufRadar2;

 //delete
 DWORD buf1,buf2,buf3,buf4;
 //delete

 	int b=1;
	DWORD a=0;
	DWORD buff[64];

 byte radar;

 float bufx,bufy,bufz;

 float playerXmob;
 float playerYmob;
 float Heigthmob;
 //int b;
 //float a=0,b=0,c=0;
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
 DWORD AdressDistanceObject=0x009BF9C8;
 DWORD AdressZoom=0x007981AB;
 DWORD AdressFHVisual=0x004376F2;
 DWORD AdressRadarAsm=0x00531A00;
 DWORD AdressGhostHack=0x0046E3C3;//	\x8B\x46\x70\x83\xC6\x58\x8B\xF8\x23\xFA\x3B\xF8
									//	xxxxxxxxxxxx
 DWORD AdressRadar;
 DWORD AdressDistanceObjectSbros=0x43f190;//		\xF3\x0F\x11\x46\x10\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x8C\x24\x00\x00\x00\x00\x64\x89\x0D\x00\x00\x00\x00
											//		xxxxxxxx????xxx????xxx????
 /*
 DWORD Adress_Tusa_Mob=0x0046B66B;//	\x8B\x3A\x89\x78\x10\x8B\x7A\x04\x8D\x48\x10\x89\x79\x04\x8B\x52\x08\x89\x51\x08\x8B\x54\x24\x20\x8B\x3A\x89\x78\x1C\x8B\x7A\x04\x89\x78\x20\x8B\x52\x08\x89\x50\x24\x8B\x54\x24\x24\x5F
								  //	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 DWORD Adress_NoAnimMob=0x0046B69B;//Adress_Tusa_Mob+30
 DWORD fix_Target=0x0043F688;//			\x74\x37\x8D\x44\x24\x20\x50\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xF8\x8D\x4C\x24\x18\x51
							 //			xxxxxxxx????xxx????xxxxxxx
 DWORD Camera_fix=0x00791F56;//			\xF3\x0F\x11\x46\x1C\xDD\x5E\x68\x88\x5E\x18\xD9\xEE\x5F\x88\x5E\x18\xDD\x5E\x68
							 //			xxxxxxxxxxxxxxxxxxxx
  DWORD AdressFreeze=0x46ED41;//		\x89\x51\x24\x8B\x40\x08\x89\x41\x28\x8B\x44\x24\x1C\x85\xC0
							  //		xxxxxxxxxxxxxxx
*///Старое
DWORD Adress_Tusa_Mob=0x46acfb;//	\x8B\x3A\x89\x78\x10\x8B\x7A\x04\x8D\x48\x10\x89\x79\x04\x8B\x52\x08\x89\x51\x08\x8B\x54\x24\x20\x8B\x3A\x89\x78\x1C\x8B\x7A\x04\x89\x78\x20\x8B\x52\x08\x89\x50\x24\x8B\x54\x24\x24\x5F
								//	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
DWORD Adress_NoAnimMob=Adress_Tusa_Mob+0x30;//Adress_Tusa_Mob+30
DWORD fix_Target=0x43efd8;//			\x74\x37\x8D\x44\x24\x20\x50\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xF8\x8D\x4C\x24\x18\x51
							 //			xxxxxxxx????xxx????xxxxxxx
DWORD Camera_fix=0x0078E6F6;//			\xF3\x0F\x11\x46\x1C\xDD\x5E\x68\x88\x5E\x18\xD9\xEE\x5F\x88\x5E\x18\xDD\x5E\x68
							 //			xxxxxxxxxxxxxxxxxxxx
DWORD AdressFreeze=0x46E371;//		\x89\x51\x24\x8B\x40\x08\x89\x41\x28\x8B\x44\x24\x1C\x85\xC0
							  //		xxxxxxxxxxxxxxx

 DWORD Z_offset=0x24;
 DWORD X_offset=0x20;
 DWORD Y_offset=0x28;
 DWORD Z=0x4;
 DWORD Y=0x8;
 DWORD Asimut_offset=0x2C;
 DWORD Vertical_offset=0x30;

 DWORD numvert;

 void memhack()
{
	AdressPosition=(DWORD)SO+0x005BF02C;
	AdressCamera=(DWORD)SO+0x00609CB0;
	AdressAccuracy=(DWORD)SO+0x005B318C;
	AdressRadar=0x009C33F8;
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressPosition), &BufPos, sizeof(BufPos), NULL);//Базовый
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufPos+0x14), &BufPos, sizeof(BufPos), NULL);//Базовый+1смещение
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
	
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressDistanceObject), &DistanceObject, sizeof(DistanceObject), NULL);//DasitanceObject
	/*
	DetourCreate((PBYTE)AdressRadarAsm,(PBYTE)Radar,5);

	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (AdressRadar), &BufRadar, sizeof(BufRadar), NULL);
	/*
	for(int i;i<2;i++)
	{
	if(buff[b]=0x000000){ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+a), &buff[b], sizeof(buff[b]), NULL);}
	}
	*/
	/*
	DWORD c=0x0;
	for(;offset[b]>c;b++)
	{
		//a=b*4;
		//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+a), &i, sizeof(i), NULL);
		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+offset[b]*4), &buff[b], sizeof(buff[b]), NULL);

		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buff[b]+10), &RadarX[b], sizeof(RadarX[b]), NULL);
		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buff[b]+14), &RadarZ[b], sizeof(RadarZ[b]), NULL);
		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buff[b]+18), &RadarY[b], sizeof(RadarY[b]), NULL);
		c=offset[b];
	}

	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar), &buf1, sizeof(buf1), NULL);
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+0x4), &buf2, sizeof(buf2), NULL);
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+0x8), &buf3, sizeof(buf3), NULL);
	//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+0xC), &buf4, sizeof(buf4), NULL);

	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buf1+0x10), &X, sizeof(X), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buf2+0x10), &X2, sizeof(X2), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buf3+0x10), &X3, sizeof(X3), NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (buf4+0x10), &X4, sizeof(X4), NULL);
	*/
	//char tst[100];
	//sprintf(tst,"%d",radar);
	/*
	for(int i=0;i<15;i++)
	{
		buf=i*4;
		//ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+buf), &BufRadar2, sizeof(BufRadar2), NULL);
		ReadProcessMemory(GetCurrentProcess(), (LPVOID*)(DWORD) (BufRadar+0x4), &radar, sizeof(radar), NULL);
		MB(tst,"")
	}
	*/

	//DetourCreate((PBYTE)AdressRadarAsm,(PBYTE)Radar,5);
	//if(RadarX!=0&&RadarX!=a)
	//{
		//add_log("X:%f",RadarX);
		//a=RadarX;
	//}

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
		if(GetAsyncKeyState(VK_END)&1)
		Log("{\"NAME\",					0,false,%ff,%ff,%ff	},",Player.X,Player.Y,Player.Z);
	//if		(Fun.Accuracy==1){MEMwrite((void *)(BufAccuracy+0x3e),(int*)(PBYTE)"\x74", 1);add_log("Accuracy=1");}
	//else if	(Fun.Accuracy==0){MEMwrite((void *)(BufAccuracy+0x3e),(int*)(PBYTE)"\xF4", 1);add_log("Accuracy=0");}
	if		(Fun.Camera==1){MEMwrite((void *)(Camera_fix),(int*)(PBYTE)"\x90\x90\x90\x90\x90", 5);}
	else if	(Fun.Camera==0){MEMwrite((void *)(Camera_fix),(int*)(PBYTE)"\xF3\x0F\x11\x46\x1C", 5);}
	if		(Fun.Ghost==1){MEMwrite((void *)(AdressGhostHack),(int*)(PBYTE)"\x90\x90", 2);}
	else if	(Fun.Ghost==0){MEMwrite((void *)(AdressGhostHack),(int*)(PBYTE)"\x89\x10", 2);}
	//MEMwrite((void *)(AdressDistanceObjectSbros),(int*)(PBYTE)"\x90\x90\x90\x90\x90", 5);

	//if(Fun.NoAnimMob==1){MEMwrite((void *)(Adress_NoAnimMob),(int*)(PBYTE)"\xEB\x0B", 2);}
	//else{MEMwrite((void *)(Adress_NoAnimMob),(int*)(PBYTE)"\x74\x0B", 2);}
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
	//	if(Fun.ZOOM==1)
	//{
	//	DetourCreate((PBYTE)AdressZoom,(PBYTE)ZoomOn,5);//Вкл
	//}
	//else
	//{
	//	DetourCreate((PBYTE)AdressZoom,(PBYTE)ZoomOff,5);//Выкл
	//}

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
	  	  if(GetAsyncKeyState(VK_SUBTRACT))
	  {
		  Player.Z+=0.05f;
		  Player.X=Player.X+(X_/12)*((float)Fun.MoveX/10);
		  Player.Y=Player.Y+(Y_/12)*((float)Fun.MoveX/10);
		  //Sleep (60);
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
      WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
	  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
	  }

	  	  if(GetAsyncKeyState(VK_ADD))
	  {
		  Player.Z+=0.05f;
		  Player.X=Player.X+(X_/12)*-1*((float)Fun.MoveX/10);
		  Player.Y=Player.Y+(Y_/12)*-1*((float)Fun.MoveX/10);
		  //Sleep (60);
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
	  if(Fun.Teleport==1)
	  {
		  for(int i=0;i<NCMaxItem;i++)
		  {
			  if(Noob_City[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Noob_City[i].X;
				  Player.Y=Noob_City[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Noob_City[i].Z-100;}
				  Player.Z=Noob_City[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Noob_City[i].value=0;
			  }
		  }
		  for(int i=0;i<LBMaxItem;i++)
		  {
			  if(Lubech[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Lubech[i].X;
				  Player.Y=Lubech[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Lubech[i].Z-100;}
				  Player.Z=Lubech[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Lubech[i].value=0;
			  }
		  }
		  for(int i=0;i<SnowMenMaxItem;i++)
		  {
			  if(SnowMen[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=SnowMen[i].X;
				  Player.Y=SnowMen[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Lubech[i].Z-100;}
				  Player.Z=SnowMen[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  SnowMen[i].value=0;
			  }
		  }
		  for(int i=0;i<NEMaxItem;i++)
		  {
			  if(NewEarth[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=NewEarth[i].X;
				  Player.Y=NewEarth[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Lubech[i].Z-100;}
				  Player.Z=NewEarth[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  NewEarth[i].value=0;
			  }
		  }
		  for(int i=0;i<CrvMaxItem;i++)
		  {
			  if(Caravan[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Caravan[i].X;
				  Player.Y=Caravan[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Caravan[i].Z-100;}
				  Player.Z=Caravan[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Caravan[i].value=0;
			  }
		  }
		  for(int i=0;i<VesMaxItem;i++)
		  {
			  if(Vesuvius[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Vesuvius[i].X;
				  Player.Y=Vesuvius[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Vesuvius[i].Z-100;}
				  Player.Z=Vesuvius[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Vesuvius[i].value=0;
			  }
		  }
		  for(int i=0;i<TungMaxItem;i++)
		  {
			  if(Tunguska[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Tunguska[i].X;
				  Player.Y=Tunguska[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Tunguska[i].Z-100;}
				  Player.Z=Tunguska[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Tunguska[i].value=0;
			  }
		  }
		  for(int i=0;i<OTPMaxItem;i++)
		  {
			  if(OtherTP[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=OtherTP[i].X;
				  Player.Y=OtherTP[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Tunguska[i].Z-100;}
				  Player.Z=OtherTP[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  OtherTP[i].value=0;
			  }
		  }
		  for(int i=0;i<BHMaxItem;i++)
		  {
			  if(OtherTP[i].value==1)
			  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=Bighunt[i].X;
				  Player.Y=Bighunt[i].Y;
				  //if(Noob_City[i].value==2){Player.Z=Tunguska[i].Z-100;}
				  Player.Z=Bighunt[i].Z;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Bighunt[i].value=0;
			  }
		  }
		  if(lastestCoord==1)
		  {
				  Player.X=bufx;
				  Player.Y=bufy;
				  Player.Z=bufz;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  lastestCoord=0;
		  }
		  if(Death==1)
		  {
				  bufx=Player.X;
				  bufy=Player.Y;
				  bufz=Player.Z;
				  Player.X=zero;
				  Player.Y=zero;
				  Player.Z=-500;
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Asimut_offset),&zero, sizeof(zero),NULL); //Asimut
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufCamera+Vertical_offset),&zero, sizeof(zero),NULL); //Vertical

	  		  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+X_offset),&Player.X, sizeof(Player.X),NULL); //X
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Y_offset),&Player.Y, sizeof(Player.Y),NULL); //Y
			  WriteProcessMemory(GetCurrentProcess(),(LPVOID*)(DWORD) (BufPos+Z_offset), &Player.Z, sizeof(Player.Z),NULL); //Z
			  Death=0;
		  }
	  }
}