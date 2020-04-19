#pragma once

#ifndef DIALOGFUNC_H
#define DIALOGFUNC_H

BOOL CALLBACK DlgInfo(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK DlgAddSynapse(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK NewDlgFunction(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgAddNeuron(HWND hDlg, UINT message, WPARAM wparam, LPARAM lparam);
#endif