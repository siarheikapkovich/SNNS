#pragma once

#ifndef STRICT
#define STRICT
#endif
// Отключаем всякую муйню
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

// Шаг карты
const UINT MAP_STEP = 40;
// Для прокрутки
extern INT HDefence, VDefence, HPosition, VPosition;
// Контекст
extern HDC g_hDC, g_hCDC;
// Хендлы битовых образов
extern HBITMAP g_hComBitmap, g_hOldBitmap;
// Глобальные переменные, определяющие ширину и высоту поля (Grid)
extern UINT g_MapWidtch, g_MapHeight;
// Можно использовать где необходимо
extern RECT g_Rect;
// Переменные Windows
extern HINSTANCE g_hInst;
// Глобальный хендл окна
extern HWND g_hWnd;
// Количество входов, нейронов, выходов соответственно
extern UINT g_ICount, g_NCount, g_OCount;
// Перечисление типов объектов
enum OBJ_TYPE
{
	INPUT,
	NEURON,
	OUTPUT
};
// Структура представления нейрона
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