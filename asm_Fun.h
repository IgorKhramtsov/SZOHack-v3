#ifndef asm_Fun_h
#define asm_Fun_h

//#include "memhack.h"
 DWORD AdressRadarRet=0x00531A08;
// DWORD Adress_Tusa_Mob_Ret=0x0046B67C;
 DWORD Adress_Tusa_Mob_Ret=Adress_Tusa_Mob+0x11;
 DWORD Collusion_Ret = 0x005E60FA;
 DWORD ZoomRet=0x007981B0;

__declspec(naked) void TUSA_MOB_on()
{
 __asm 
 {
mov				edi,[XMob]
mov				[eax+0x10],edi
mov				edi,[ZMob]
lea				ecx,[eax+0x10]
mov				[ecx+0x04],edi
mov				edx,[YMob]
jmp		[Adress_Tusa_Mob_Ret]
 }
}
__declspec(naked) void TUSA_MOB_off()
{
 __asm 
 {
mov				edi,[edx]
mov				[eax+0x10],edi
mov				edi,[edx+0x04]
lea				ecx,[eax+0x10]
mov				[ecx+0x04],edi
mov				edx,[edx+0x08]


jmp 	[Adress_Tusa_Mob_Ret]
 }
}
__declspec(naked) void ZoomOn()
{
 __asm 
 {
movss	[ZoomVoll],xmm0
jmp		[ZoomRet]
 }
}
__declspec(naked) void ZoomOff()
{
 __asm 
 {
movss	[esi+0x10],xmm0
jmp		[ZoomRet]
 }
}
__declspec(naked) void Radar()
{
 __asm 
 {
mov [ecx+edx*0x4],eax
mov [n],edx
inc [esi+0x10]
pop edi
pop esi
jmp		[AdressRadarRet]
 }
	for(DWORD c=0x0;offset[v]>c;v++)
	{
 offset[v]=n;
 c=offset[v];
	}
}
/*
DWORD WRNC;
const DWORD WRNC_Return1=0x4332A9;
const DWORD WRNC_Return2=0x433B66;
DWORD adrwrncs;
DWORD adrwrs;

__declspec(naked) void WRNC_on1()
{
adrwrncs=opt.memhack.adrWRNC;
adrwrs=opt.memhack.adrWR;
 __asm 
 {

cmp EAX,dword ptr [adrwrncs]
jne a
sub esp,0x08
fstp qword ptr [esp]
inc [WRNC]
cmp dword ptr [WRNC],0x00000001
jne b
push eax
mov eax, dword ptr [adrwrs]
mov [eax],0x74CCCCCC
pop eax
jmp        [WRNC_Return1]

b:
jmp        [WRNC_Return1]

a:
sub esp,0x08
fstp qword ptr [esp]
jmp        [WRNC_Return1]
 }
}

__declspec(naked) void WRNC_off1()
{
 __asm 
 {
sub esp,0x08
fstp qword ptr [esp]
jmp        [WRNC_Return1]
}
}

__declspec(naked) void WRNC_on2()
{
adrwrncs=opt.memhack.adrWRNC;
adrwrs=opt.memhack.adrWR;
 __asm 
 {


fldz
mov eax,[esp+0x04]
cmp EAX,dword ptr [adrwrncs]
jne c
push eax
mov eax, dword ptr [adrwrs]
mov [eax],0xF4CCCCCC
pop eax
mov [WRNC],0x0
jmp        [WRNC_Return2]

 c:
jmp        [WRNC_Return2]
 }
}

__declspec(naked) void WRNC_off2()
{
adrwrs=opt.memhack.adrWR;
 __asm 
 {
push eax
mov eax, dword ptr [adrwrs]
mov [eax],0xF4CCCCCC
pop eax
fldz
mov eax,[esp+0x04]
jmp        [WRNC_Return2]
 }
}
*/


#endif