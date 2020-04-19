#include "Global.h"

BOOL CALLBACK DlgAddNeuron(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
	case WM_INITDIALOG:
		{
            return TRUE;
		}
		break;
	case WM_COMMAND:
		{
			switch(wparam)
			{
			case IDOK:
				{
                    EndDialog(hDlg, 1);
                    return TRUE;
				}
				break;
			case IDCANCEL:
				{
                    EndDialog(hDlg, 0);
                    return TRUE;
				}
				break;
			default: return FALSE;
			}
		}
		break;
	default: return FALSE;
	}
	return FALSE;
}
				
BOOL CALLBACK NewDlgFunction(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND wnd = NULL;
	switch(message)
	{
	case WM_INITDIALOG:
		wnd = GetDlgItem(hDlg, IDC_ED_LAUER);
		SendDlgItemMessage(hDlg, IDC_SP_LAUER, UDM_SETBUDDY,(WPARAM) (HWND) wnd, 0);
		SendDlgItemMessage(hDlg, IDC_SP_LAUER, UDM_SETRANGE, 0, 150);
		SendDlgItemMessage(hDlg, IDC_SP_LAUER, UDM_SETPOS, 0, 0);
		SendDlgItemMessage(hDlg, IDC_RA_MLP, BM_SETCHECK, BST_CHECKED, 0);
		wnd = GetDlgItem(hDlg, IDC_ED_WIDTCH);
		SendDlgItemMessage(hDlg, IDC_SP_WIDTCH, UDM_SETBUDDY,(WPARAM) (HWND) wnd, 0);
		SendDlgItemMessage(hDlg, IDC_SP_WIDTCH, UDM_SETRANGE, 10, 250);
		SendDlgItemMessage(hDlg, IDC_SP_WIDTCH, UDM_SETPOS, 0, 10);
		wnd = GetDlgItem(hDlg, IDC_ED_HEIGHT);
		//SendDlgItemMessage(hDlg, IDC_SP_HEIGHT, UDM_SET, 0, 0);
		SendDlgItemMessage(hDlg, IDC_SP_HEIGHT, UDM_SETBUDDY,(WPARAM) (HWND) wnd, 0);
		SendDlgItemMessage(hDlg, IDC_SP_HEIGHT, UDM_SETRANGE, 10, 250);
		SendDlgItemMessage(hDlg, IDC_SP_HEIGHT, UDM_SETPOS, 0, 10);
		return TRUE;
	case WM_COMMAND:
		{
			switch(wParam)
			{
			case IDC_CHECK_EMPTU:
				if(BST_CHECKED == IsDlgButtonChecked(hDlg, IDC_CHECK_EMPTU))
				{
					wnd = GetDlgItem(hDlg, IDC_RA_MLP);
					EnableWindow(wnd, FALSE);
					wnd = GetDlgItem(hDlg, IDC_ST_TYPE);
					EnableWindow(wnd, FALSE);
					wnd = GetDlgItem(hDlg, IDC_ST_PARAM);
					EnableWindow(wnd, FALSE);
				}
				else
				{
					wnd = GetDlgItem(hDlg, IDC_RA_MLP);
					EnableWindow(wnd, TRUE);
					wnd = GetDlgItem(hDlg, IDC_ST_TYPE);
					EnableWindow(wnd, TRUE);
					wnd = GetDlgItem(hDlg, IDC_ST_PARAM);
					EnableWindow(wnd, TRUE);
				}
				return FALSE;
			case IDOK:
				UINT mx, my;
				my =(UINT)LOWORD(SendDlgItemMessage(hDlg, IDC_SP_HEIGHT, UDM_GETPOS, 0, 0));
				mx =(UINT)LOWORD(SendDlgItemMessage(hDlg, IDC_SP_WIDTCH, UDM_GETPOS, 0, 0));
				g_MapHeight = (my * MAP_STEP) + 20;
				g_MapWidtch = (mx * MAP_STEP) + 20;
				PrepContext();
				EndDialog(hDlg, 1);
				return TRUE;
			case IDCANCEL:
				EndDialog(hDlg, 0);
				return TRUE;
			default: return FALSE;
			}
		}
		break;
	default: return FALSE;
	}
	return FALSE;
}

BOOL CALLBACK DlgAddSynapse(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
	case WM_INITDIALOG:
		{
			return TRUE;
		}
		break;
	case WM_COMMAND:
		{
			switch(wparam)
			{
			case IDOK:
				{
					EndDialog(hDlg, 1);
					return TRUE;
				}
				break;
			case IDCANCEL:
				{
					EndDialog(hDlg, 0);
					return TRUE;
				}
				break;
			default: return FALSE;
			}
		}
		break;
	default: return FALSE;
	}
	return FALSE;
}

BOOL CALLBACK DlgInfo(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
	case WM_INITDIALOG:
		{
			HWND wnd;
			UINT cou = 0;
			char tst[32];
			cou = (UINT)NeuView.size();
			wnd = GetDlgItem(hDlg, IDC_ST_NEURONCOUNT);
			g_Str = "Количество нейронов: ";
			g_Str += itoa(cou, tst, 32);
			SetWindowText(wnd, g_Str.c_str());
			
            return TRUE;
		}
		break;
	case WM_COMMAND:
		switch(wparam)
		{
		case IDOK:
			{
				EndDialog(hDlg, 1);
				return FALSE;
			}
			break;
		case IDCANCEL:
			{
				EndDialog(hDlg, 0);
				return FALSE;
			}
			break;
		default: return FALSE;
			break;
		}
	default: return FALSE;
		break;
	}
	return FALSE;
}