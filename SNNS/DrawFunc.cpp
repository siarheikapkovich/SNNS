#include "Global.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция подготавливает контекст к рисованию.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrepContext()
{
	if(!g_hDC)
	{
		g_hDC = GetDC(g_hWnd);
	}
	if(!g_hCDC)
	{
		g_hCDC = CreateCompatibleDC(g_hDC);
	}
	if(g_hComBitmap)
	{
		SelectObject(g_hCDC, g_hComBitmap);
		DeleteObject(g_hComBitmap);
	}
	if(g_MapHeight != 0 && g_MapWidtch != 0)
	{
		g_hComBitmap = CreateCompatibleBitmap(g_hDC, g_MapWidtch, g_MapHeight);
		SelectObject(g_hCDC, g_hComBitmap);
		PatBlt(g_hCDC, 0, 0, g_MapWidtch, g_MapHeight, PATCOPY);
	}
	else
	{
		g_MapHeight = (10 * MAP_STEP) + 20;
		g_MapWidtch = (10 * MAP_STEP) + 20;
		PrepContext();
	}
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает разметочную сетку.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawBackGround()
{
	HPEN pen;
	POINT pt;
	// Сначала сетка
	pen = CreatePen(PS_SOLID, 0, RGB(220,220,220));
	SelectObject(g_hCDC, pen);
	// По вертикали
	for(UINT i = 50; i < g_MapWidtch - 10; i += MAP_STEP)
	{
		MoveToEx(g_hCDC, i, 10, &pt);
		LineTo(g_hCDC, i, g_MapHeight - 10);
	}
	// По горизонтали
	for(UINT i = 50; i < g_MapHeight - 10; i += MAP_STEP)
	{
		MoveToEx(g_hCDC, 10, i, &pt);
		LineTo(g_hCDC, g_MapWidtch - 10, i);
	}
	SelectObject(g_hCDC, pen);
	DeleteObject(pen);
	// Теперь Рамка
	pen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
	SelectObject(g_hCDC, pen);
	MoveToEx(g_hCDC, 10, 10, &pt);
	LineTo(g_hCDC, g_MapWidtch - 10, 10);
	LineTo(g_hCDC, g_MapWidtch - 10, g_MapHeight - 10);
	LineTo(g_hCDC, 10, g_MapHeight - 10);
	LineTo(g_hCDC, 10, 9);
	SelectObject(g_hCDC, pen);
	DeleteObject(pen);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает рамку выделения нейрона.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawSelNeuRect(POINT pt)
{
	MoveToEx(g_hCDC, pt.x - 12, pt.y - 12, NULL);
	LineTo(g_hCDC, pt.x - 4, pt.y - 12);
	MoveToEx(g_hCDC, pt.x + 4, pt.y - 12, NULL);
	LineTo(g_hCDC, pt.x + 12, pt.y - 12);
	LineTo(g_hCDC, pt.x + 12, pt.y - 4);
	MoveToEx(g_hCDC, pt.x + 12, pt.y + 4, NULL);
	LineTo(g_hCDC, pt.x + 12, pt.y + 11);
	LineTo(g_hCDC, pt.x + 4, pt.y + 11);
	MoveToEx(g_hCDC, pt.x - 4, pt.y + 11, NULL);
	LineTo(g_hCDC, pt.x - 12, pt.y + 11);
	LineTo(g_hCDC, pt.x - 12, pt.y + 4);
	MoveToEx(g_hCDC, pt.x - 12, pt.y - 4, NULL);
	LineTo(g_hCDC, pt.x - 12, pt.y - 12);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает рамку выделения входа или выхода.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawSelInORect(POINT pt)
{
	MoveToEx(g_hCDC, pt.x - 22, pt.y - 12, NULL);
	LineTo(g_hCDC, pt.x - 14, pt.y - 12);
	//MoveToEx(g_hCDC, pt.x - 4, pt.y - 12, NULL);
	//LineTo(g_hCDC, pt.x + 4, pt.y - 12);
	MoveToEx(g_hCDC, pt.x + 14, pt.y - 12, NULL);
	LineTo(g_hCDC, pt.x + 22, pt.y - 12);
	LineTo(g_hCDC, pt.x + 22, pt.y - 4);
	MoveToEx(g_hCDC, pt.x + 22, pt.y + 4, NULL);
	LineTo(g_hCDC, pt.x + 22, pt.y + 11);
	LineTo(g_hCDC, pt.x + 14, pt.y + 11);
	//MoveToEx(g_hCDC, pt.x + 4, pt.y + 11, NULL);
	//LineTo(g_hCDC, pt.x - 4, pt.y + 11);
	MoveToEx(g_hCDC, pt.x - 14, pt.y + 11, NULL);
	LineTo(g_hCDC, pt.x - 22, pt.y + 11);
	LineTo(g_hCDC, pt.x - 22, pt.y + 4);
	MoveToEx(g_hCDC, pt.x - 22, pt.y - 4, NULL);
	LineTo(g_hCDC, pt.x - 22, pt.y - 12);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает вход.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawInput(POINT pt, MyE_NState param)
{
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 0, RGB(0,0,0));
	switch(param)
	{
	case NS_NULL:
		{
			brush = CreateSolidBrush(RGB(150,255,150));
		}
		break;
	case NS_TORMO:
		{
			brush = CreateSolidBrush(RGB(110,0,230));
		}
		break;
	case NS_AKTIV:
		{
			brush = CreateSolidBrush(RGB(255,0,0));
		}
		break;
	default:
		{
			brush = CreateSolidBrush(RGB(150,255,150));
		}
		break;
	}
	SelectObject(g_hCDC, pen);
	SelectObject(g_hCDC, brush);
	RoundRect(g_hCDC, pt.x-20,pt.y-10,pt.x+20,pt.y+10, 20, 20);
	RECT rect;
	rect.left = pt.x-20;
	rect.top  = pt.y-10;
	rect.right = pt.x+20;
	rect.bottom = pt.y+10;
	int bkm = SetBkMode(g_hCDC, TRANSPARENT); 
	DrawText(g_hCDC, "In", -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	SetBkMode(g_hCDC, bkm);
	DeleteObject(pen);
	DeleteObject(brush);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает нейрон.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawNeuron(POINT pt, MyE_NState param)
{
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 0, RGB(0,0,0));
	switch(param)
	{
	case NS_NULL:
		{
			brush = CreateSolidBrush(RGB(110,200,0));
		}
		break;
	case NS_TORMO:
		{
			brush = CreateSolidBrush(RGB(110,0,230));
		}
		break;
	case NS_AKTIV:
		{
			brush = CreateSolidBrush(RGB(255,0,0));
		}
		break;
	default:
		{
			brush = CreateSolidBrush(RGB(110,200,0));
		}
		break;
	}
	SelectObject(g_hCDC, pen);
	SelectObject(g_hCDC, brush);
	Ellipse(g_hCDC, pt.x-10,pt.y-10,pt.x+10,pt.y+10);
	DeleteObject(pen);
	DeleteObject(brush);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает выход.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawOutput(POINT pt, MyE_NState param)
{
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 0, RGB(0,0,0));
	switch(param)
	{
	case NS_NULL:
		{
			brush = CreateSolidBrush(RGB(255,255,120));
		}
		break;
	case NS_TORMO:
		{
			brush = CreateSolidBrush(RGB(110,0,230));
		}
		break;
	case NS_AKTIV:
		{
			brush = CreateSolidBrush(RGB(255,0,0));
		}
		break;
	default:
		{
			brush = CreateSolidBrush(RGB(110,200,0));
		}
		break;
	}
	SelectObject(g_hCDC, pen);
	SelectObject(g_hCDC, brush);
	RoundRect(g_hCDC, pt.x-20,pt.y-10,pt.x+20,pt.y+10, 20, 20);
	RECT rect;
	rect.left = pt.x-20;
	rect.top  = pt.y-10;
	rect.right = pt.x+20;
	rect.bottom = pt.y+10;
	int bkm = SetBkMode(g_hCDC, TRANSPARENT); 
	DrawText(g_hCDC, "Out", -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	SetBkMode(g_hCDC, bkm);
	DeleteObject(pen);
	DeleteObject(brush);
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Функция прорисовывает связь.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
