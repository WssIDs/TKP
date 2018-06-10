// PolyProp.cpp : Implementation of CPolyProp

#include "stdafx.h"
#include "PolyProp.h"


// CPolyProp


LRESULT CPolyProp::OnEnChangeSides(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the __super::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	SetDirty(TRUE);

	return 0;
}
