int dsa=0;
bool fd=0;
char *sda  [] = { "9","42","23","46","5","6","7","8","9","10"};
char *sda1  [] = { "9","42","23","46","5","6","7","8","9","10"};
int dsa1=0;

void _stdcall SZOHack(LPDIRECT3DDEVICE9 pDevice)
{
	//float wheel;
	//LOWORD(wheel);

	lm = GetAsyncKeyState(VK_LBUTTON)&1;
	rm = GetAsyncKeyState(VK_RBUTTON)&1;
	flm = GetAsyncKeyState(VK_LBUTTON);
	frm = GetAsyncKeyState(VK_RBUTTON);	
	up = GetAsyncKeyState(VK_UP)&1;
	down = GetAsyncKeyState(VK_DOWN)&1;
	rt = GetAsyncKeyState(VK_RIGHT)&1;
	lt = GetAsyncKeyState(VK_LEFT)&1;
	ctr = GetAsyncKeyState(VK_CONTROL)&1;
	sht = GetAsyncKeyState(VK_SHIFT)&1;
	sprintf(PlayerX,"PosX %f",Player.X);
	sprintf(PlayerY,"PosY %f",Player.Y);
	sprintf(PlayerZ,"PosZ %f",Player.Z);
	sprintf(DistObj,"%f",DistanceObject);
	sprintf(dbg1,"Coord X=%d",dsa);
	sprintf(dbg2,"Coord Y=%d",dsa1);

	DWORD color;
	
	if(rt){dsa++;}
	if(lt){dsa--;}
	if(up){dsa1++;}
	if(down){dsa1--;}

	if(scr==1)
	{
		I=GPPI(Settings,"I",I,GetDirFile(filename));
		Sleep(100);
		sprintf(FileName, "SZOHack Screen %d.jpg", I);
		pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &surf);
		D3DXSaveSurfaceToFile(FileName, D3DXIFF_JPG, surf, NULL, NULL);
		I++;
		Beep(1000, 100);
		WritePPI(Settings,"I",I,GetDirFile(filename));
		scr=0;
	}

		if(scr!=1)//���� �� ����������� ��������
		{

			D3DVIEWPORT9 viewP;
			pDevice->GetViewport(&viewP);
			DWORD SCX = viewP.Width / 2;
			DWORD SCY = viewP.Height / 2;

			SString(infx,infy+30,WHITE,DT_LEFT| DT_NOCLIP,FPS());
			SString(infx,infy+40,WHITE,DT_LEFT| DT_NOCLIP,PlayerX);
			SString(infx,infy+50,WHITE,DT_LEFT| DT_NOCLIP,PlayerY);
			SString(infx,infy+60,WHITE,DT_LEFT| DT_NOCLIP,PlayerZ);

			SString(infx,infy+70,WHITE,DT_LEFT| DT_NOCLIP,dbg1);
			SString(infx,infy+80,WHITE,DT_LEFT| DT_NOCLIP,dbg2);

			cVisual->Button(228,20,"Show",Show,pDevice);

			if(Fun.FreezeHeigth==1){color=GREEN;}
			else{color=RED;}

			Circle(234,12,5,10,color);
			Circle(234,12,4,10,color);
			Circle(234,12,3,10,color);
			Circle(234,12,2,10,color);
			Circle(234,12,1,10,color);
			if(DistanceObject!=(-1))
			{
			SString(SCX+5,SCY+5,WHITE,DT_LEFT| DT_NOCLIP,DistObj);
			}
		}

	if (Show==true&&scr!=1)
	{
		infx=MenuX+MenuWidth+10;
		infy=MenuY;

		cVisual->DrawMenu(pDevice);
		cVisual->ButtonMenu(MenuX,MenuY+2,"Visual",Fun.Visual,pDevice);
		cVisual->ButtonMenu(MenuX+187,MenuY+2,"Other",Fun.Other,pDevice);
		cVisual->Options(NameX+NameWidth-13,NameY+2,"R","�������� ���������",Fun.Reset,pDevice);
		cVisual->Options(NameX+NameWidth-29,NameY+2,"S","��������� ���������",Fun.Save,pDevice);
		cVisual->Options(NameX+NameWidth-45,NameY+2,"L","��������� ���������",Fun.Load,pDevice);

		//cVisual->Button(9,58+44,"Aim-Bot",Fun.Test3,pDevice);
		//cVisual->Button(9,58+66,"ESP",Fun.Test4,pDevice);
		//cVisual->Button(9,58+88,"Settings",Fun.Test5,pDevice);
	
		if (Fun.Visual == 1)
		{
			cVisual->DoubleCheck(MenuX+10,MenuY+30,"����",Fun.pvp,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+50,"����",Fun.Mob,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+70,"���������",Fun.Art,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+90,"����",Fun.Drop,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+110,"�����",Fun.Cache,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+130,"�����",Fun.Grib,pDevice);//������ 15

			cVisual->DoubleCheck(MenuX+188,MenuY+30,"������",Fun.Listva,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+50,"����������",Fun.Svet,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+70,"Crosshair",Fun.Crosshair,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+90,"WireFrame",Fun.WireFrame,pDevice);//������ 15
		}

		if (Fun.Other == 1)
		{
			cVisual->DoubleCheck(MenuX+10,MenuY+30,"NoAnim",Fun.NoAnimMob,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+30,"��������",Fun.Teleport,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+50,"Zoom",Fun.ZOOM,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+50,"���������� ������",Fun.FreezeHeigth,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+70,"TUSA",Fun.Tusa,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+90,"��������",Fun.Accuracy,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+10,MenuY+110,"������������ ������",Fun.Camera,pDevice);//������ 15
			cVisual->Scroll(MenuX+388,MenuY+150,"��������� ���������",NULL,100,1,Fun.MoveX,pDevice);
			cVisual->Scroll(MenuX+10,MenuY+150,"������ (PageUp)",NULL,150,1,Fun.Jump,pDevice);
			cVisual->Scroll(MenuX+188,MenuY+150,"�������(PageDown)",NULL,150,1,Fun.Fall,pDevice);
			cVisual->DoubleCheck(MenuX+10,MenuY+170,"������",Fun.jump,pDevice);//������ 15
			cVisual->DoubleCheck(MenuX+188,MenuY+170,"�������",Fun.fall,pDevice);//������ 15
		}

		if(Fun.Teleport == 1)
		{
			cVisual->DopMenu(MenuX,MenuY+MenuLength+10,MenuWidth,500,pDevice);
			cVisual->TeleportMenu(MenuX,MenuY+MenuLength+10,"�������",Fun.Stantion,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*1),MenuY+MenuLength+10,"�����",Fun.Noob_City,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*2),MenuY+MenuLength+10,"���",Fun.Lubech,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*3),MenuY+MenuLength+10,"�������",Fun.Caravan,pDevice);

			cVisual->TeleportMenu(MenuX,MenuY+MenuLength+32,"������",Fun.Vulkano,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*1),MenuY+MenuLength+32,"�������",Fun.Vesuvius,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*2),MenuY+MenuLength+32,"����� �����",Fun.Novaya,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*3),MenuY+MenuLength+32,"��������",Fun.Tunguska,pDevice);

			if(Fun.Lubech==1)
			{
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67, "������",gur,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*1), "�����������",Since,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*2), "������",bolota,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*3), "�����",Imarek,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*4),"������� �� ����",InRyab,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*5),"�����",himka,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*6),"������� �����",DWhite,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*7),"������ ��������",PBandits,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*8),"���������",Provodnuk,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*9),"������ �����",paukKost,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*10),"������",PaukResp,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*11),"���������",Sanatorka,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*12),"��������",Psiha,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*13),"�������� �� �������",Provodnik_CRV,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*14),"������� �4",UkrepH4,pDevice);
			}
			if(Fun.Noob_City==1)
			{
				cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,115,"������",pDevice);
				for(int i=0;i<7;i++)
				{
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*i),Noob_City[i].Name,Noob_City[i].value,pDevice);
				}
				for(int i=0;i<9;i++)
				{
					cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*i),Noob_City[i+7].Name,Noob_City[i+7].value,pDevice);
				}
				/*
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67, "������",Vokzal,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*1), "��������",Mentovka,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*2), "��",DK,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*3),"��-1",KP1,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*4),"��-2",KP2,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*5),"��-3",KP3,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*6),"������",Basmach,pDevice);
				   cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,115,"������",pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67,"�����",Myachik,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*1),"�����",Mishka,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*2),"�����-�����",Rubik,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*3),"���������",Nevalyashka,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*4),"���������-1",Televizor1,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*5),"���������-2",Televizor2,pDevice);
					cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*6),"���������-3",Televizor3,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*7),"������� ���",DetskiySad,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*8),"��������",Skameiki,pDevice);
				*/
			}
			if(Fun.Caravan==1)
			{
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67, "��������",crvAnomaly,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*1), "��������� B4",ProvodnikCrv1,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*2), "��������� AM5",ProvodnikCrv2,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*3),"��������� A�7",ProvodnikCrv3,pDevice);
			}
			if(Fun.Tunguska==1)
			{
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67,		 "����",Tung_Resp,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*1),"�����������",Otverjeniy,pDevice);
				cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*2),"��������� �� �������",Provodnikcrv,pDevice);
			}
			if(Fun.Vesuvius==1)
			{
				for(int i=0;i<3;i++)
				{
					cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*i),Vesuvius[i].Name,Vesuvius[i].value,pDevice);
				}
			}

		}
	}
	else
	{
		infx=10;
		infy=MenuY;
	}
}
/*
void LOGER()
	{
		SString(150, 10, 0xFF80ff00,DT_LEFT| DT_NOCLIP, "�����: ��������", 0);
        SString(10, 10, 0xFFFFFFFF,DT_LEFT| DT_NOCLIP, "���������� ���: %i", incrementBy);

        for(int i = 0; i < 5; i++)
		{
                if(i == menuIndex)
				{
                        DrawBorder(8, 23+(i*15), 140, 18,1,BLACK,pDevice);
                }
                SString(10, 25+(i*15), model[i].isLogging==true?0xFF00FF00:0xFFFF0000,DT_LEFT| DT_NOCLIP, "%s", model[i].type);
                if(i != LOGVALUES)
				{
                        SString(100, 25+(i*15), model[i].isLogging==true?0xFF00FF00:0xFFFF0000,DT_LEFT| DT_NOCLIP, "%i", model[i].value);
                }
        }

        if (up)    menuIndex--;
        if (down)  menuIndex++;
        if(lt)  model[menuIndex].value-=incrementBy;
        if(rt) model[menuIndex].value+=incrementBy;

        if(GetAsyncKeyState(VK_DELETE)&1)model[menuIndex].isLogging = !model[menuIndex].isLogging;//��������� �������

        if(GetAsyncKeyState(VK_INSERT)&1)model[menuIndex].value = 0;//�����
        if(GetAsyncKeyState(VK_NEXT)&1)
		{
                incrementBy *= 10;
                if(incrementBy > 1000)
				{
                        incrementBy = 1;
                }
        }
		
        if(GetAsyncKeyState(VK_END)&1)
		{
                for(int i = 0; i < 4; i++)
				{
                        model[i].isLogging = false;
                }
        }
		
        if(model[LOGVALUES].isLogging == true)
		{			
                model[LOGVALUES].isLogging = false;
                g_uiTimer = GetTickCount() + 2000;

                Log("Stride: %i | NumVerts: %i | PrimCount: %i | StartIndex: %i",
                        model[STRIDE].isLogging         == true ? model[STRIDE].value           : -1,
                        model[NUMVERTS].isLogging       == true ? model[NUMVERTS].value         : -1,
                        model[PRIMCOUNT].isLogging      == true ? model[PRIMCOUNT].value        : -1,
                        model[STARTINDEX].isLogging     == true ? model[STARTINDEX].value       : -1);
			
        }


        if(menuIndex > 4) menuIndex = 0;
        if(menuIndex < 0) menuIndex = 4;

        if(model[menuIndex].value < 0) model[menuIndex].value = 0;
	}
	*/


