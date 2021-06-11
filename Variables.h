typedef HRESULT(WINAPI* oDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
typedef HRESULT(WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
typedef HRESULT(WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
typedef HRESULT(WINAPI* oQuery)(LPDIRECT3DDEVICE9 pDevice, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);
typedef HRESULT(WINAPI* oEndScene)(LPDIRECT3DDEVICE9 pDevice);
//typedef HRESULT (WINAPI* oSetStreamSource)(LPDIRECT3DDEVICE9 pDevice,UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride);
typedef HRESULT(WINAPI* oSetStreamSource)(void* self, DWORD StreamNumber, IDirect3DVertexBuffer9* pStreamData, DWORD OffsetInBytes, DWORD Stride);
oSetStreamSource pSetStreamSource;
oQuery pQuery;
oReset pReset;
oPresent pPresent;
oDrawIndexedPrimitive pDrawIndexedPrimitive;
oEndScene pEndScene;
D3DCOLOR EColOn; //���� ���������  [���]
bool Color = true;
BOOL Create;      //������� ��� ����������
bool hExitThread; //��������� �����
bool Show = false;//����� ����
int x, y, w, h;      //���������� ��� ���������
int infx,infy;
int scr;
POINT  mofs;      //�����			
POINT  mpos;      //�����
int	lm /*����� ������ ���� �������*/  , rm/*������ ������ ���� �������*/	,
	flm/*����� ������ �����. �������*/, frm/*������ ������ �����. �������*/	,
	up								  ,	down								,
	lt								  ,	rt									,
	ctr								  ,	sht									;
LPDIRECT3DDEVICE9 pD3D9;    //D3D9 ������ pD3D9
IDirect3DDevice9* pDevice;  //D3D9 ������ pDevice
ID3DXFont*  pFont;          //D3D9 ������ pFont
ID3DXFont*  pFonts;          //D3D9 ������ pFont
LPD3DXLINE  pLine;          //D3D9 ������ pLine
D3DVIEWPORT9 viewP;         //D3D9 ������ viewP

int dsa=0;
int dsa1=0;

LPDIRECT3DTEXTURE9 White,Red,Green,Blue,Black,Purple,Grey,Yellow,Orange;
char FileName[1024];
char PlayerX[100];
char PlayerY[100];
char PlayerZ[100];
char DistObj[100];
char dbg1[100];
char dbg2[100];
LPDIRECT3DSURFACE9 surf;   //D3D9 ������ 
int I;
#define CText (DT_CENTER|DT_NOCLIP)//����� "�����"
#define LText (DT_LEFT|DT_NOCLIP) //����� "����"
#define RText (DT_RIGHT|DT_NOCLIP)//����� "�����"
const float PI=3.1415926535f;//����� ��
float A1, A2, A3, A4;   //��������
float Aero;          //������������
char VisualMenu[]="---Visual---";
char OtherMenu[]="---Other---";
char Settings[]="---Settings---";
void Save();
void Load();
void LOGER();
char *NameHack="Multihack for SZoneOnline";
#define GPPI GetPrivateProfileIntA
char *filename = "SZO.settings";
//========== ���������� ����� ==========//
char *volue [] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40","41","42","43","44","45","46","47","48","49","50","51" };
char *antime [] = { "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1" };
DWORD Adress_numVert;
HMODULE SO = GetModuleHandleA("SZoneOnline.exe");
float DistanceObject;
float X_=0,Y_=0,XMob,YMob,ZMob;
void TUSA_MOB_on(),TUSA_MOB_off()	,Collusion_off(),Collusion_on()		,ZoomOn(),ZoomOff()		,Radar();
DWORD AccuracyVoll,AccyracyAdr;
//float RadarX,RadarY,RadarZ;
float ZoomVoll=0.2866951525f;
//DWORD Collusion = 0x005E60F5;
//DWORD Collusion = 0x0046B698;
float X,X2,X3,X4;
int MenuX,MenuY;
int NameX			=10;
int NameY			=100;
int NameWidth		=380;
int NameLength		=15;
int MenuWidth		=375;
int MenuLength		=200;
char x1[100],x2[100],x3[100],x4[100];
//char InputBox_Coord();
bool ISQUEST;
char Name_Coord[50];
//============Radar============//
int v=0;
DWORD n;
DWORD offset[256];
float RadarX[256],RadarY[256],RadarZ[256];
//============Radar============//
//========== ���������� ������� ==========//
class cFun
{
public:
	bool Grib,Travi,Cache,Drop,Art,Mob,pvp,Svet,Listva,Crosshair,WireFrame;
	bool Save,Load,Reset;
	bool Visual, Other,Teleport;//������� ����
	bool QuestTab,Noob_City,Lubech,Vesuvius,Novaya,Tunguska,Caravan,OtherTP;
	bool SnowMen,BigHunt,LostItem;
	bool Tusa,FreezeHeigth,Camera,NoClip,fall,jump,NoAnimMob,Accuracy,ZOOM,Ghost;
	int Jump,Fall,MoveX;
	int Color1, Color2, Color3, Color4, Color5, Color6;
};
extern cFun Fun;

struct sloger
{
	bool menu;
	int BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount,m_Stride;
	int Step;
	int Simvolbvi,Simvolmvi,Simvolnv,Simvolsi,Simvolpc,Simvolstr;
	bool Markbvi,Markmvi,Marknv,Marksi,Markpc,Markstr;
}loger;

struct sPlayer
{
	float X,Y,Z,Asimut,Vertical;
}Player;
int LBMaxItem,NCMaxItem,CrvMaxItem,TungMaxItem,VesMaxItem,NEMaxItem,SnowMenMaxItem,OTPMaxItem,BHMaxItem;
int lastestCoord=0;
int Death=0;
int LBQuestItem=0,NCQuesItem=0;
int i1,i2,i3,i4;
int countBV;
struct Menu
{
        char* Name;
        int   value;
		bool  isQuest;
		float X;
		float Y;
		float Z;
};
Menu Lubech[] = {
			{"����� ����",					0,true,	240.945831f		,-327.436035f	,42.632244f	},
			{"����� ���������",				0,true,1487.958130f,-919.835449f,0.913602f	},
			{"�������� ����������",			0,true,	1167.85144f		,-1452.27954f	,-0.113f	},
			{"������ �13",					0,true,	758.941833f		,-1013.710815f	,42.718540f	},
			{"��������� �����",				0,true,	1334.417725f	,-542.353455f	,-9.530018f	},
			{"��������� �����",				0,true,	1107.936768f	,93.417343f		,12.184882f	},
			{"�������� �����",				0,true,	1103.434448f	,-244.655701f	,-9.279671f	},
			{"����� ������",				0,true,-602.581360f		,-907.815369f	,15.124965f	},
			{"������������ ���� �2",					0,true,1519.400757f,1734.100952f,25.123159f	},
			{"������������ ���� B2",					0,true,-1365.909790f,1615.090332f,-6.567777f},
			{"������������ ���� �10",					0,true,-1916.210205f,-310.580475f,0.000000f	},
			{"������ ����������",					0,true,1175.196777f,1370.151733f,-25.202930f	},
        {"������",							0,false,-328.107300f	,-231.790649f	,2.830493f	},
        {"�����������",						0,false,940.661804f,-742.883118f,48.300362f	},
		{"�����",							0,false,715.397644f		,-232.663727f	,8.260275f	},
        {"������",							0,false,1282.422119f	,-390.855096f	,0.1f		},
		{"������� �����",					0,false,1610.20556f		,131.24119f		,-6.7550001f},
        {"������ ��������",					0,false,1494.058228f,1205.790649f,-22.428207f	},
		{"������ �������� �6",				0,false,-966.286438f,740.058594f,1.981265f	},
		{"���",								0,false,-38.889599f		,-293.096710f	,0.199979f	},
        {"���������(���)",					0,false,709.018615f		,1732.1127f		,102.992759f},
		{"����� �4-2",						0,false,474.824432f,1163.123047f,-22.081625f	},
		{"������ �����",					0,false,921.2673339f	,1656.7979f		,0.4154708f	},
        {"������",							0,false,1211.28540f		,1684.96679f	,-8.7157344f},
		{"���.�������",						0,false,-1328.211182f,-178.410690f,29.907907f	},
		{"�����",							0,false,1127.93847f		,-1436.47399f	,0.36123235f},
        {"���������",						0,false,1644.9199f		,941.18945f		,34.4035224f},
		{"��������",						0,false,-631.4f			,539.5f			,31.6f		},
        {"������� �4",						0,false,1033.2f			,1054.2f		,47.95f		},
		{"������� �� ����",					0,false,1430.3463f		,-1618.5340f	,-208.5809278f},
		{"�������� �� �������",				0,false,-1661.0f		,1186.0f		,7.6f		},
		{"���� � �����",					0,false,-86.988518f		,-803.742432f	,0.003882f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu Noob_City[] = {
			{"�����",						0,true,	110.965263f	,-238.677658f	,0.890332f		},
			{"�����",						0,true,	122.346313f	,-183.302246f	,0.881278f		},
			{"�����-�����",					0,true,	28.597357f	,-80.065514f	,0.629013f		},
			{"���������",					0,true,	6.430655f	,-126.686089f	,1.666232f		},
			{"���������-1",					0,true,	126.105362f	,-255.886658f	,1.125630f		},
			{"���������-2",					0,true,	171.133286f	,-213.395859f	,1.100195f		},
			{"���������-3",					0,true,	153.600937f	,-187.020096f	,1.100179f		},
			{"���� ������",					0,false,-289.18551f	,-10.814009f	,-0.797000f		},
        {"������",							0,false,23.032204f	,-240.597382f	,1.727835f		},
        {"��������",						0,false,-119.984161f,30.614092f		,1.363112f		},
        {"��",								0,false,-103.717201f,204.194809f	,6.502807f		},
		{"������� ��-1",					0,false,-180.339188f,297.388977f,0.004244f	},
		{"������� ��-3",					0,false,-281.349823f,100.872620f,0.001533f	},
		{"����� ��-2",					0,false,-110.076508f,346.706360f,0.000000f	},
		{"������",							0,false,-44.901257f	,295.903198f	,0.030887f		},
		{"������� ���",						0,false,6.366082f	,18.377121f		,5.181893f		},
		{"��������",						0,false,99.057655f	,82.630676f		,5.615067f		},
		{"������� � ������",				0,false,-112.850433f,200.762161f	,-300.205763f	},
		{"(������)������� �� �����",		0,false,-120.633232f,168.103470f	,-211.519477f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu Caravan[] = {
        {"��������",						0,false,43.0f		,522.0f			,19.0f			},
        {"��������� B4",					0,false,-4442.74121f,84.215614f		,-9.8f			},
        {"��������� AM5",					0,false,4750.0f		,-59.0f			,37.94f			},
		{"��������� A�7",					0,false,4537.0f		,-708.0f		,-6.1f			},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu Tunguska[] = {
		{"������ �����",					0,false,-791.564453f,515.904602f,29.368820f	},
        {"����",							0,false,-420.949402f,581.866577f	,45.031651f		},
		{"A�� �5",							0,false,337.575317f	,-23.338287f	,21.340406f		},
        {"�����������",						0,false,477.266754f	,229.852768f	,23.615719f		},
        {"��������� �� �������",			0,false,-580.633545f,-467.512451f	,38.567085f		},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu SnowMen[] = {
		{"���->������ ",						0,false,-333.904938f,-254.073547f	,1.900265f		},
		{"���->������� ����������",			0,false,757.948425f	,1716.829956f	,101.512047f	},
		{"���->���������",					0,false,-267.061066f,-727.696960f	,0.658062f		},
		{"���->�������",						0,false,-316.694092f,-971.275146f	,-0.330202f		},
		{"���->������� ����",				0,false,-544.907959f,-776.558899f	,8.479974f		},
		{"���->�����������",					0,false,933.046448f	,-762.373840f	,48.385849f		},
		{"���->����� �������",				0,false,923.991638f	,1594.623047f	,6.490005f		},
		{"���->������� �����",				0,false,1631.307495f,131.211777f	,-6.743001f		},
		{"���->��� �� ������",				0,false,1282.422119f,-390.855103f	,-0.047803f		},
		{"���->����� �������� �����",		0,false,1334.417725f,-542.353455f	,-9.530018f		},
		{"���->������� ���",					0,false,1268.485474f,-1314.365479f	,-8.823000f		},
		{"���->����������� ����������",		0,false,1167.851440f,-1452.279541f	,-0.113000f		},
		{"�����->��������",					0,false,-26.276026f	,-174.123810f	,0.064104f		},
		{"�����->���� �������������",		0,false,-3.202615f	,-280.748810f	,0.885451f		},
		{"�����->����������",				0,false,156.495331f	,-146.254303f	,1.983185f		},
		{"�����->���� � �������",			0,false,-116.471275f,38.096802f		,1.314311f		},
		{"�����->�������� ������.",			0,false,-106.178787f,270.370789f	,0.257669f		},
		{"������->������ �������",			0,false,61.169907f	,36.910233f		,154.047897f	},
		{"������->�����",					0,false,212.547684f	,-109.527977f	,134.965149f	},
		{"�������->���������",				0,false,-1107.22448f,276.420441f	,4.895913f		},
		{"�������->����������",				0,false,46.810211f	,609.984863f	,15.398022f		},
		{"�������->��������",				0,false,455.233887f	,666.643311f	,2.447779f		},
		{"�������->������ � ������",			0,false,643.602356f	,-447.450684f	,13.730575f		},
		{"�������->������ ���������",		0,false,1232.093506f,-733.469971f	,9.459281f		},
		{"�������->���� � ������",			0,false,436.053711f	,-572.020996f	,20.139402f		},
		{"��������->����� �����. ",			0,false,-171.251007f,161.503616f	,23.141228f		},
		{"����� �����->�����������. ",		0,false,-110.455284f,-201.752808f	,40.000000f		},
		{"����� �����->����.",				0,false,328.854706f	,26.559856f		,50.929497f		},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu Bighunt[] = {
		{"�����->������ ������� �����",				0,false,-117.778870f,-118.957947f,2.738091f	},
		{"�����->������� ���",						0,false,11.140006f,19.036182f,4.515377f	},
		{"�����->��������� �����",					0,false,-43.482479f,274.249359f,0.000000f	},
		{"�����->����� �������",					0,false,-207.593582f,1.494623f,0.419871f	},
		{"�����->����� �������-2",					0,false,-160.973129f,148.768890f,0.000000f	},
		{"�����->����� �������",					0,false,-56.481750f,-43.683231f,0.000000f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu Vesuvius[] = {
			{"��.������� �������",			0,true,-1165.579102f,5.235295f,-228.282440f	},
			{"������ �5-4",					0,true,	789.66210f	,147.11956f		,1.67431f		},
			{"������ �2",					0,true,	-1007.29748f,852.030640f	,-2.125886f		},
			{"�.���������",					0,true,	-1107.22448f,276.420441f	,4.895913f		},
			{"������� ���������",			0,true,	1254.189697f,-743.804016f	,0.379962f		},
			{"2����� ����� ",				0,true,1616.304688f,235.408707f,-4.028260f	},
			{"���� ���-7 ��������",			0,true,-313.496704f,1070.041626f,2.289375f	},
			{"���� ���-7 ��������",			0,true,-311.234497f,1068.676636f,5.811085f	},
			{"���� ���-7 ��������",			0,true,-277.086578f,1062.522949f,2.287037f	},
			{"���� ���-7 ��������",			0,true,-263.124603f,1108.731323f,2.335121f	},
			{"�����",						0,true,467.587280f,882.694336f,-3.568228f	},
			{"������ �����",				0,true,496.081482f,1191.257446f,-15.889816f	},
			{"������ �� �����",				0,true,-120.434502f,976.915588f,-2.366732f	},
			{"�����",						0,true,1035.986084f,-487.404816f,26.668999f	},
			{"�������",					0,true,-202.068130f,1260.982544f,25.738623f	},
		{"������",							0,false,-905.823975f,849.877014f	,0.862940f		},
		{"���",								0,false,-1002.24987f,-80.530769f	,2.217510f		},
		{"������",					0,false,1009.289551f,-1137.116455f,15.778546f	},
		{"������ ���",					0,false,-567.957031f,-667.965027f,15.344736f	},
		{"�����",							0,false,32.728245f	,535.619446f	,23.007542f		},
        {"����������",						0,false,16.109749f	,610.819946f	,19.914621f		},
		{"������",							0,false,725.931030f	,-620.350830f	,9.570001f		},
		{"������",							0,false,956.665039f,662.966980f,6.850000f			},
		{"���",								0,false,-664.379517f,-941.710388f	,-14.159100f	},
		{"��������",						0,false,876.733398f	,-411.787933f	,10.137699f		},
		{"���� �5",							0,false,906.318970f,143.473999f,12.992309f	},
		{"������� �� �����",				0,false,-1174.17944f,873.213806f	,-302.07519f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu NewEarth[] = {
			{"�������� 1",					0,true,	-243.142731f,-211.639145f	,38.871719f		},
			{"�������� 2",					0,true,	-70.860909f	,185.671265f	,39.346466f		},
			{"�������� 3",					0,true,	256.680267f	,183.084122f	,40.438095f		},
		{"�����",							0,false,-400.002594f,75.841454f		,40.000000f		},
		{"����������",						0,false,-104.954590f,-199.340607f	,40.000000f		},
		{"�����",							0,false,350.425659f,31.949368f,31.491266f	},
		{"������",							0,false,-375.284729f,72.764084f		,31.044899f		},
		{"�������",							0,false,-186.251694f,-74.671204f	,63.136486f		},
		{"��������� �� ��������",			0,false,48.362320f	,157.740280f	,40.046196f		},
		{"��������� �� �������",			0,false,-398.064880f,16.958458f		,30.083393f		},
		{"��������� ����",					0,false,321.215515f,32.991432f,49.034058f	},
		{"����->���������1",					0,false,419.483521f,-614.671021f,38.963200f	},
		{"����->���",						0,false,408.714752f,-635.681335f,34.731441f	},
		{"����->���������2",					0,false,401.770081f,-634.062561f,34.831921f	},
		{"����->���� �����",					0,false,417.893707f,-625.946838f,34.731426f	},
		{"����->�����",						0,false,354.257202f,-626.177612f,46.731346f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
Menu OtherTP[] = {
		{"�������",					0,false,327.822510f,-286.474487f,13.393600f	},
		{"���������",				0,false,313.569092f,322.849426f,15.897435f	},
															{NULL,		0,false,0.0f,0.0f,0.0f}
};
void Log(char* fmt, ...);
