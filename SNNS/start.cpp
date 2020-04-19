#include "global.h"

LRESULT CALLBACK WndFunction(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	INT RetVal = 0;
	static INT DragNum = -1;
	static INT CyrObj  = -1;
	static INT DesObj = -1;
	POINT pt;
	NEURON_VIEW nv;

	switch(message)
	{
	case WM_COMMAND:
		switch(wParam)
		{
		case IDM_NEW:
			RetVal = (INT)DialogBox(g_hInst, MAKEINTRESOURCE(IDD_CREATE_NEW), g_hWnd, NewDlgFunction);
			if(RetVal)
			{
				PrepContext();
			}
			break;
		case IDM_EXIT:
			DestroyWindow(hwnd);
			break;
		case IDM_ADD_NEURON:
			RetVal = (INT)DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ADD_NEURON), g_hWnd, DlgAddNeuron);
			if(RetVal == 1)
			{
				g_NCount++;
				nv.m_Number = g_NCount;
				nv.m_Type = NEURON;
				nv.m_Pos.x = 10 + MAP_STEP;
				nv.m_Pos.y = 10 + MAP_STEP;
				if(NeuView.size() != 0)
				{
					vector<NEURON_VIEW>::iterator p = NeuView.begin();
					while(p->m_Type != NEURON && p->m_Number != g_NCount - 1)
					{
						if(p == NeuView.end())
							break;
						p++;
					}
					p++;
					if(p <= NeuView.end())
					{
						NeuView.insert(p, nv);
					}
					else
						NeuView.push_back(nv);
				}
				else
					NeuView.push_back(nv);
			}
			SendMessage(g_hWnd, WM_PAINT, 0, 0);
			break;
		case IDM_ADD_INPUT:
			g_ICount++;
			nv.m_Number = g_ICount;
			nv.m_Type = INPUT;
			nv.m_Pos.x = 10 + MAP_STEP;
			nv.m_Pos.y = 10 + MAP_STEP;
			if(NeuView.size() != 0)
			{
				vector<NEURON_VIEW>::iterator p = NeuView.begin();
				while(p->m_Type != INPUT && p->m_Number != g_ICount - 1)
				{
					if(p == NeuView.end())
						break;
					p++;
				}
				p++;
				if(p <= NeuView.end())
				{
					NeuView.insert(p, nv);
				}
				else
					NeuView.push_back(nv);
			}
			else
				NeuView.push_back(nv);
			SendMessage(g_hWnd, WM_PAINT, 0, 0);
			break;
		case IDM_ADD_OUTPUT:
			g_OCount++;
			nv.m_Number = g_OCount;
			nv.m_Type = OUTPUT;
			nv.m_Pos.x = 10 + MAP_STEP;
			nv.m_Pos.y = 10 + MAP_STEP;
			NeuView.push_back(nv);
			SendMessage(g_hWnd, WM_PAINT, 0, 0);
			break;
		case IDM_ADD_SYNAPS:
			RetVal = (INT)DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ADD_SYNAPSE), g_hWnd, DlgAddSynapse);
			if(RetVal == 1)
			{
				MessageBox(g_hWnd, "Ура!!!", "Дебил", MB_OK);
			}
			break;
		case IDM_ADD_COLS:
			g_MapWidtch += MAP_STEP;
			PrepContext();
			SendMessage(g_hWnd, WM_PAINT, 0, 0);
			break;
		case IDM_ADD_ROWS:
			g_MapHeight += MAP_STEP;
			PrepContext();
			SendMessage(g_hWnd, WM_PAINT, 0, 0);
			break;
		case P_ADD_NEURON:
			SendMessage(g_hWnd, WM_COMMAND, IDM_ADD_NEURON, 0);
			break;
		case P_ADD_IN:
			SendMessage(g_hWnd, WM_COMMAND, IDM_ADD_INPUT, 0);
			break;
		case P_ADD_OUT:
			SendMessage(g_hWnd, WM_COMMAND, IDM_ADD_OUTPUT, 0);
			break;
		case P_ADD_SYNAPSE:
			if(DesObj != -1)
			{
				//
				DesObj = -1;
			}
			break;
		case P_INFO:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_INFO), g_hWnd, DlgInfo);
			if(DesObj != -1)
			{
				DesObj = -1;
			}
			break;
		}
		break;
	case WM_PAINT:
		HDC hd;
		PAINTSTRUCT ps;
		RECT Rect;
		hd = BeginPaint(hwnd, &ps);
		GetClientRect(g_hWnd, &Rect);
		PatBlt(hd, 0, 0, Rect.right, Rect.bottom, WHITENESS);
		PatBlt(g_hCDC, 0, 0, g_MapWidtch, g_MapHeight, WHITENESS);
		DrawBackGround();
		if(NeuView.size() > 0)
		{
			for(UINT i = 0; i < NeuView.size(); i++)
			{
				switch(NeuView[i].m_Type)
				{
				case INPUT:
					{
						DrawInput(NeuView[i].m_Pos, NS_NULL);
						if(CyrObj == i)
							DrawSelInORect(NeuView[i].m_Pos);
					}
					break;
				case NEURON:
					{
						DrawNeuron(NeuView[i].m_Pos, NS_NULL);
						if(CyrObj == i)
							DrawSelNeuRect(NeuView[i].m_Pos);
					}
					break;
				case OUTPUT:
					{
						DrawOutput(NeuView[i].m_Pos, NS_NULL);
						if(CyrObj == i)
							DrawSelInORect(NeuView[i].m_Pos);
					}
					break;
				default: break;
				}
			}
		}
		BitBlt(g_hDC, 0, 0,g_MapWidtch,g_MapHeight,g_hCDC,g_Rect.left,g_Rect.top,SRCCOPY);
		EndPaint(hwnd, &ps);
		break;
	case WM_CREATE:
		
		break;
	case WM_RBUTTONUP:
		HMENU hmenu;            // menu template          
		HMENU hmenuTrackPopup;  // shortcut menu   
		pt.x = GET_X_LPARAM(lParam); 
        pt.y = GET_Y_LPARAM(lParam);
		DesObj = -1;
		// Загрузка меню
 		hmenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MENU1)); 
		hmenuTrackPopup = GetSubMenu(hmenu, 0);

		if(NeuView.size() != 0)
		{
			UINT d2 = 1000;
			INT step = -1;
			while(d2 > 100)
			{
				step++;
				d2 = (pt.x - NeuView[step].m_Pos.x)*(pt.x - NeuView[step].m_Pos.x) + (pt.y - NeuView[step].m_Pos.y)*(pt.y - NeuView[step].m_Pos.y);
				
				if(step >= (INT)NeuView.size())
				{
					step = -1;
					break;
				}
			}
			if(step != -1)
				DesObj = step;
			if(NeuView.size() < 2 || DesObj == -1  || CyrObj == -1)
				EnableMenuItem(hmenuTrackPopup, P_ADD_SYNAPSE, MF_GRAYED);
		}
		else
			EnableMenuItem(hmenuTrackPopup, P_ADD_SYNAPSE, MF_GRAYED);
		
		if(DesObj != -1)
		{
			// Запрещаем операции не выполняемые над объектами
			EnableMenuItem(hmenuTrackPopup, P_ADD_NEURON, MF_GRAYED);
			EnableMenuItem(hmenuTrackPopup, P_ADD_IN, MF_GRAYED);
			EnableMenuItem(hmenuTrackPopup, P_ADD_OUT, MF_GRAYED);
		}
		// Отображаем меню
        ClientToScreen(hwnd, (LPPOINT) &pt); 
	    TrackPopupMenu(hmenuTrackPopup, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.x, pt.y, 0, g_hWnd, NULL); 
 	    DestroyMenu(hmenu); 
		break;
	case WM_LBUTTONDOWN:
		pt.x = GET_X_LPARAM(lParam);
		pt.y = GET_Y_LPARAM(lParam);
		// Проверяем попадание в обьект
		if(NeuView.size() != 0)
		{
			UINT d2;
			for(UINT i = 0; i < NeuView.size(); i++)
			{
				d2 = (pt.x - NeuView[i].m_Pos.x)*(pt.x - NeuView[i].m_Pos.x) + (pt.y - NeuView[i].m_Pos.y)*(pt.y - NeuView[i].m_Pos.y);
				if(d2 < 100)
				{
					// Захват объекта для перетаскивания
					DragNum = i;
					// Выделение объекта как текущего
					CyrObj = i;
				}
			}
		}
		break;
	case WM_LBUTTONUP:
		DragNum = -1;
		DesObj = -1;
		SendMessage(g_hWnd, WM_PAINT, 0, 0);
		break;
	case WM_MOUSEMOVE:
		// Перетаскивание
		if(DragNum != -1)
		{
			UINT sx, sy;
			pt.x = GET_X_LPARAM(lParam);
			pt.y = GET_Y_LPARAM(lParam);
			
			sx = (pt.x - 10) % MAP_STEP;
			if(sx >= 20)
				pt.x += MAP_STEP - sx;
			else
                pt.x -= sx;
			sy = (pt.y - 10) % MAP_STEP;
			if(sy >= 20)
				pt.y += MAP_STEP - sy;
			else
                pt.y -= sy;
			// Контроль выхода за границы карты
			if((UINT)pt.x > g_MapWidtch - 30)
				pt.x = g_MapWidtch - 30;
			if(pt.x < 30)
				pt.x = 30;
			if((UINT)pt.y > g_MapHeight - 30)
				pt.y = g_MapHeight - 30;
			if(pt.y < 30)
				pt.y = 30;
			
			NeuView[DragNum].m_Pos.x = pt.x ;
			NeuView[DragNum].m_Pos.y = pt.y;
		}
		break;
	case WM_SIZE:
		PrepContext();
		break;
	case WM_DESTROY:
		SelectObject(g_hCDC, g_hComBitmap);
		DeleteObject(g_hComBitmap);
		ReleaseDC(hwnd, g_hCDC);
		ReleaseDC(hwnd, g_hDC);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//RECT Rect;
	WNDCLASS wClass;
	MSG msg;

	g_hInst = hInstance;
	wClass.style = CS_HREDRAW|CS_VREDRAW;
	wClass.cbClsExtra = NULL;
	wClass.cbWndExtra = NULL;
	wClass.hInstance = hInstance;
	wClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.lpszClassName = "WindowClass";
	wClass.lpszMenuName = MAKEINTRESOURCE(IDR_MAIN_MENU);
	wClass.lpfnWndProc = WndFunction;

	RegisterClass(&wClass);
	g_hWnd = CreateWindow("WindowClass", "Нейросимулятор", WS_OVERLAPPEDWINDOW, 0, 0, 200, 200, NULL, LoadMenu(hInstance,MAKEINTRESOURCE(IDR_MAIN_MENU)), hInstance, NULL);
	if(!g_hWnd) return 0;

		
	ShowWindow(g_hWnd, SW_MAXIMIZE);
	UpdateWindow(g_hWnd);
	InitCommonControls();

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	ReleaseDC(g_hWnd, g_hDC);
	return (int)msg.lParam;
}