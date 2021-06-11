
bool fd=0;
char *sda  [] = { "9","42","23","46","5","6","7","8","9","10"};
char *sda1  [] = { "9","42","23","46","5","6","7","8","9","10"};
int moved=0;
int bufxmoved=0;
int bufymoved=0;
int offsetx=0;
int offsety=0;
int ss=1;
void _stdcall SZOHack(LPDIRECT3DDEVICE9 pDevice)
{
		//Меню
	MenuX			=NameX+2;
	MenuY			=NameY+15;

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


	POINT mpos; 
	GetCursorPos(&mpos); 
	ScreenToClient(GetForegroundWindow(),&mpos);

	

	for(int i=0;Lubech[i].Name!=NULL;i++)
		LBMaxItem=i+1;
	for(int i=0;Noob_City[i].Name!=NULL;i++)
		NCMaxItem=i+1;
	for(int i=0;Caravan[i].Name!=NULL;i++)
		CrvMaxItem=i+1;
	for(int i=0;Tunguska[i].Name!=NULL;i++)
		TungMaxItem=i+1;
	for(int i=0;Vesuvius[i].Name!=NULL;i++)
		VesMaxItem=i+1;
	for(int i=0;NewEarth[i].Name!=NULL;i++)
		NEMaxItem=i+1;
	for(int i=0;SnowMen[i].Name!=NULL;i++)
		SnowMenMaxItem=i+1;
	for(int i=0;OtherTP[i].Name!=NULL;i++)
		OTPMaxItem=i+1;
	for(int i=0;Bighunt[i].Name!=NULL;i++)
		BHMaxItem=i+1;

	sprintf(PlayerX,"PosX %f",Player.X);
	sprintf(PlayerY,"PosY %f",Player.Y);
	sprintf(PlayerZ,"PosZ %f",Player.Z);
	sprintf(DistObj,"%f",DistanceObject);
	sprintf(dbg1,"Coord X=%d",bufxmoved);
	sprintf(dbg2,"Coord Y=%d",bufymoved);
	
	sprintf(x1,"Coord X=%f",RadarX[1]);
	sprintf(x2,"Coord X=%f",RadarX[5]);
	sprintf(x3,"Coord X=%f",RadarY[1]);
	sprintf(x4,"Coord X=%f",RadarZ[1]);
	
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

		if(scr!=1)//если НЕ выполняется скриншот
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

			//SString(infx,infy+90,WHITE,DT_LEFT| DT_NOCLIP,x1);
			//SString(infx,infy+100,WHITE,DT_LEFT| DT_NOCLIP,x2);
			//SString(infx,infy+110,WHITE,DT_LEFT| DT_NOCLIP,x3);
			//SString(infx,infy+120,WHITE,DT_LEFT| DT_NOCLIP,x4);

			cVisual->Button(228,21,"Show",Show,pDevice);

			if(Fun.FreezeHeigth==1){color=RED;}
			else{color=GREEN;}

			Circle(234,12,5,10,color);
			Circle(234,12,4,10,color);
			Circle(234,12,3,10,color);
			Circle(234,12,2,10,color);
			Circle(234,12,1,10,color);
			if(DistanceObject!=(-1)||(0))
			{
			SString(SCX+5,SCY+5,WHITE,DT_LEFT| DT_NOCLIP,DistObj);
			}
		}

	if (Show==true&&scr!=1)
	{
	if((IsInBox(NameX,NameY,NameWidth-45,NameLength))||moved==1)
	{
		if(flm)
		{
			moved=1;
		//
			if(ss==1)
			{
			for(int i=0;i<2;i++)
			{
				bufxmoved=mpos.x;
				bufymoved=mpos.y;
				ss=0;
			}
			}
			offsetx=mpos.x-bufxmoved;
			offsety=mpos.y-bufymoved;
			NameX+=offsetx;
			NameY+=offsety;
			bufxmoved+=offsetx;
			bufymoved+=offsety;
		}
		else
		{
		moved=0;
		ss=1;
		}
	}
		infx=MenuX+MenuWidth+10;
		infy=MenuY;

		cVisual->DrawMenu(pDevice);
		cVisual->ButtonMenu(MenuX,MenuY+2,"Visual",Fun.Visual,pDevice);
		cVisual->ButtonMenu(MenuX+187,MenuY+2,"Other",Fun.Other,pDevice);
		cVisual->Options(NameX+NameWidth-13,NameY+2,"R","Сбросить настройки",Fun.Reset,pDevice);
		cVisual->Options(NameX+NameWidth-29,NameY+2,"S","Сохранить настройки",Fun.Save,pDevice);
		cVisual->Options(NameX+NameWidth-45,NameY+2,"L","Загрузить настройки",Fun.Load,pDevice);

		//cVisual->Button(9,58+44,"Aim-Bot",Fun.Test3,pDevice);
		//cVisual->Button(9,58+66,"ESP",Fun.Test4,pDevice);
		//cVisual->Button(9,58+88,"Settings",Fun.Test5,pDevice);
	
		if (Fun.Visual == 1)
		{
			cVisual->DoubleCheck(MenuX+10,MenuY+30,"Люди",Fun.pvp,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+50,"Мобы",Fun.Mob,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+70,"Артефакты",Fun.Art,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+90,"Дроп",Fun.Drop,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+110,"Нычки",Fun.Cache,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+130,"Грибы",Fun.Grib,pDevice);//Ширина 15

			cVisual->DoubleCheck(MenuX+188,MenuY+30,"Листва",Fun.Listva,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+188,MenuY+50,"Осветление",Fun.Svet,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+188,MenuY+70,"Crosshair",Fun.Crosshair,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+188,MenuY+90,"WireFrame",Fun.WireFrame,pDevice);//Ширина 15
		}

		if (Fun.Other == 1)
		{
			cVisual->DoubleCheck(MenuX+10,MenuY+30,"NoAnim",Fun.NoAnimMob,pDevice);//Ширина 15
				cVisual->DoubleCheck(MenuX+188,MenuY+30,"Телепорт",Fun.Teleport,pDevice);//Ширина 15
				cVisual->DoubleCheck(MenuX+188,MenuY+50,"Zoom",Fun.ZOOM,pDevice);//Ширина 15
				cVisual->DoubleCheck(MenuX+188,MenuY+70,"Ghost",Fun.Ghost,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+50,"Заморозить высоту",Fun.FreezeHeigth,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+70,"TUSA",Fun.Tusa,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+90,"Точность",Fun.Accuracy,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+10,MenuY+110,"Ограничитель обзора",Fun.Camera,pDevice);//Ширина 15
			cVisual->Scroll(MenuX+388,MenuY+150,"Множитель телепорта",NULL,100,1,Fun.MoveX,true,pDevice);
			cVisual->Scroll(MenuX+10,MenuY+150,"Прыжок (PageUp)",NULL,150,1,Fun.Jump,false,pDevice);
			cVisual->Scroll(MenuX+188,MenuY+150,"Падение(PageDown)",NULL,150,1,Fun.Fall,false,pDevice);
			cVisual->DoubleCheck(MenuX+10,MenuY+170,"Прыжок",Fun.jump,pDevice);//Ширина 15
			cVisual->DoubleCheck(MenuX+188,MenuY+170,"Падение",Fun.fall,pDevice);//Ширина 15
		}

		if(Fun.Teleport == 1)
		{
			cVisual->DopMenu(MenuX,MenuY+MenuLength+10,MenuWidth,500,pDevice);
			cVisual->TeleportMenu(MenuX,MenuY+MenuLength+10,"Квесты",Fun.QuestTab,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*1),MenuY+MenuLength+10,"Город",Fun.Noob_City,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*2),MenuY+MenuLength+10,"Лес",Fun.Lubech,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*3),MenuY+MenuLength+10,"Караван",Fun.Caravan,pDevice);

			//cVisual->TeleportMenu(MenuX,MenuY+MenuLength+32,"Вулкан",Fun.Vulkano,pDevice);
			cVisual->TeleportMenu(MenuX,MenuY+MenuLength+32,"Везувий",Fun.Vesuvius,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*1),MenuY+MenuLength+32,"Новая земля",Fun.Novaya,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*2),MenuY+MenuLength+32,"Тунгуска",Fun.Tunguska,pDevice);
			cVisual->TeleportMenu(MenuX+((MenuWidth/4)*3),MenuY+MenuLength+32,"Другое...",Fun.OtherTP,pDevice);
			cVisual->Teleport(MenuX+289,MenuY+MenuLength+495,"Lastest coord",lastestCoord,pDevice);
			cVisual->Teleport(MenuX+5,MenuY+MenuLength+495,"Отлёжка",Death,pDevice);

			if(Fun.Lubech==1)
			{
					for(int i=i2=0;i<LBMaxItem;i++)
					{
						if(Lubech[i].isQuest==true)
						{
						cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*i2),Lubech[i].Name,Lubech[i].value,pDevice);
						i2++;
						}
						else
						cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*(i-i2)),Lubech[i].Name,Lubech[i].value,pDevice);
					}
				if(i2!=0)
				cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,10+i2*15,"Квесты",pDevice);
			}
			if(Fun.Noob_City==1)
			{
					for(int i=i1=0;i<NCMaxItem;i++)
					{
						if(Noob_City[i].isQuest==true)
						{
						cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*i1),Noob_City[i].Name,Noob_City[i].value,pDevice);
						i1++;
						}
						else
						cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*(i-i1)),Noob_City[i].Name,Noob_City[i].value,pDevice);
					}
				if(i1!=0)
				cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,10+i1*15,"Квесты",pDevice);
			}
			if(Fun.Caravan==1)
			{
				for(int i=0;i<CrvMaxItem;i++)
					cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*i),Caravan[i].Name,Caravan[i].value,pDevice);
			}
			if(Fun.QuestTab==1)
			{
				cVisual->QuestMenu(MenuX+5,MenuY+MenuLength+47+15,"Потеряные вещи",Fun.LostItem,pDevice);
				cVisual->QuestMenu(MenuX+5,MenuY+MenuLength+47+45,"Большая охота",Fun.BigHunt,pDevice);
				cVisual->QuestMenu(MenuX+5,MenuY+MenuLength+47+75,"Снеговик",Fun.SnowMen,pDevice);
				if(Fun.SnowMen==1)
					for(int i=0;i<SnowMenMaxItem;i++)
						cVisual->Teleport(MenuX+130,MenuY+MenuLength+55+(15*i),SnowMen[i].Name,SnowMen[i].value,pDevice);
				if(Fun.BigHunt==1)
					for(int i=0;i<BHMaxItem;i++)
						cVisual->Teleport(MenuX+130,MenuY+MenuLength+55+(15*i),Bighunt[i].Name,Bighunt[i].value,pDevice);
			}
			if(Fun.Tunguska==1)
			{
				for(int i=0;i<TungMaxItem;i++)
				{
					cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*i),Tunguska[i].Name,Tunguska[i].value,pDevice);
				}
			}
			if(Fun.Vesuvius==1)
			{
					for(int i=i3=0;i<VesMaxItem;i++)
					{
						if(Vesuvius[i].isQuest==true)
						{
						cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*i3),Vesuvius[i].Name,Vesuvius[i].value,pDevice);
						i3++;
						}
						else
						cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*(i-i3)),Vesuvius[i].Name,Vesuvius[i].value,pDevice);
					}
				if(i3!=0)
				cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,10+i3*15,"Квесты",pDevice);
			}
			if(Fun.Novaya==1)
			{
					for(int i=i4=0;i<NEMaxItem;i++)
					{
						if(NewEarth[i].isQuest==true)
						{
						cVisual->Teleport(MenuX+187,MenuY+MenuLength+67+(15*i4),NewEarth[i].Name,NewEarth[i].value,pDevice);
						i4++;
						}
						else
						cVisual->Teleport(MenuX+5,MenuY+MenuLength+67+(15*(i-i4)),NewEarth[i].Name,NewEarth[i].value,pDevice);
					}
				if(i4!=0)
				cVisual->Group_Box(MenuX+182,MenuY+MenuLength+60,178,10+i4*15,"Квесты",pDevice);
			}
			if(Fun.OtherTP==1)
			{
				
				for(int i=countBV=0;i<OTPMaxItem;i++)
				{
					cVisual->Teleport(MenuX+10,MenuY+MenuLength+67+(15*i),OtherTP[i].Name,OtherTP[i].value,pDevice);
					countBV++;
				}
				if(countBV!=0)
				cVisual->Group_Box(MenuX+5,MenuY+MenuLength+60,178,10+countBV*15,"Болото Василиска",pDevice);
			}
//===========================================//
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
		SString(150, 10, 0xFF80ff00,DT_LEFT| DT_NOCLIP, "Автор: Крайслер", 0);
        SString(10, 10, 0xFFFFFFFF,DT_LEFT| DT_NOCLIP, "Установить шаг: %i", incrementBy);

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

        if(GetAsyncKeyState(VK_DELETE)&1)model[menuIndex].isLogging = !model[menuIndex].isLogging;//Активыция функции

        if(GetAsyncKeyState(VK_INSERT)&1)model[menuIndex].value = 0;//Сброс
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




