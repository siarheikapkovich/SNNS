
#include "Global.h"

INT HDefence, VDefence, HPosition, VPosition;
HDC g_hDC = NULL, g_hCDC = NULL;
HBITMAP g_hComBitmap = NULL, g_hOldBitmap = NULL;
UINT g_MapWidtch = 0, g_MapHeight = 0;
RECT g_Rect;
HINSTANCE g_hInst = NULL;
HWND g_hWnd = NULL;
UINT g_ICount = 0, g_NCount = 0, g_OCount = 0;

//MyC_MLP_NeuroNet g_NeuroNet;
vector<NEURON_VIEW> NeuView;
string g_Str;
