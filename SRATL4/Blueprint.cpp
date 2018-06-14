// Blueprint.cpp : Implementation of CBlueprint
#include "stdafx.h"
#include "Blueprint.h"


// CBlueprint
STDMETHODIMP CBlueprint::get_Min(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Min;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_Min(SHORT newVal)
{
	// TODO: Add your implementation code here
	m_Min = newVal;
	m_Scale = abs(m_Min) + abs(m_Max);
	FireViewChange();
	return S_OK;
}

STDMETHODIMP CBlueprint::get_Max(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Max;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_Max(SHORT newVal)
{
	// TODO: Add your implementation code here

	m_Max = newVal;
	m_Scale = abs(m_Min) + abs(m_Max);
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CBlueprint::get_BackgroundColor(OLE_COLOR* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_BackgroundColor;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_BackgroundColor(OLE_COLOR newVal)
{
	// TODO: Add your implementation code here
	m_BackgroundColor = newVal;
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CBlueprint::get_LineColor(OLE_COLOR* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_LineColor;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_LineColor(OLE_COLOR newVal)
{
	// TODO: Add your implementation code here
	m_LineColor = newVal;
	FireViewChange();
	return S_OK;
}


LRESULT CBlueprint::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// TODO: Add your message handler code here and/or call default	// TODO: Add your message handler code here and/or call default

	WORD xPos = LOWORD(lParam);  // horizontal position of cursor
	WORD yPos = HIWORD(lParam);  // vertical position of cursor

	Fire_LeftClick(xPos, yPos);
	return 0;
}


LRESULT CBlueprint::OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// TODO: Add your message handler code here and/or call default

	WORD xPos = LOWORD(lParam);  // horizontal position of cursor
	WORD yPos = HIWORD(lParam);  // vertical position of cursor

	Fire_RightClick(xPos, yPos);
	return 0;
}


STDMETHODIMP CBlueprint::get_ClickCount(SHORT* pVal)
{
	// TODO: Add your implementation code here
	
	*pVal = m_ClickCount;

	return S_OK;
}


STDMETHODIMP CBlueprint::put_ClickCount(SHORT newVal)
{
	// TODO: Add your implementation code here
	if (-1 <= newVal && newVal <= 2)
	{
		m_ClickCount = newVal;
		FireViewChange();

		if (newVal >= 2)
		{
			m_ClickCount = 1;
			return Error(_T("Нельзя больше кликать левой кнопкой мыши"));
		}
		if (newVal <= -1)
		{
			m_ClickCount = 0;
			return Error(_T("Нельзя больше кликать правой кнопкой мыши"));
		}
	}

	return S_OK;
}
