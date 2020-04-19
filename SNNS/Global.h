#pragma once

#ifndef STRICT
#define STRICT
#endif
// ��������� ������ �����
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <mmsystem.h>
#include <vector>
#include <string>
using namespace std;
#include "resource.h"
//#include "SC_MLP.h"

enum MyE_NState
{
	NS_NULL,
	NS_AKTIV,
	NS_TORMO
};

#include "DialogFunc.h"
#include "DrawFunc.h"
#include "MLP.h"

// ��� �����
const UINT MAP_STEP = 40;
// ��� ���������
extern INT HDefence, VDefence, HPosition, VPosition;
// ��������
extern HDC g_hDC, g_hCDC;
// ������ ������� �������
extern HBITMAP g_hComBitmap, g_hOldBitmap;
// ���������� ����������, ������������ ������ � ������ ���� (Grid)
extern UINT g_MapWidtch, g_MapHeight;
// ����� ������������ ��� ����������
extern RECT g_Rect;
// ���������� Windows
extern HINSTANCE g_hInst;
// ���������� ����� ����
extern HWND g_hWnd;
// ���������� ������, ��������, ������� ��������������
extern UINT g_ICount, g_NCount, g_OCount;
// ������������ ����� ��������
enum OBJ_TYPE
{
	INPUT,
	NEURON,
	OUTPUT
};
// ��������� ������������� �������
struct NEURON_VIEW
{
	string m_Help;
	OBJ_TYPE m_Type;
	UINT  m_Number;
	POINT m_Pos;
};

//extern MyC_MLP_NeuroNet g_NeuroNet;
extern vector<NEURON_VIEW> NeuView;
extern string g_Str;