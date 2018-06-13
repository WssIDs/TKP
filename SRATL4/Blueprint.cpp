// Blueprint.cpp : Implementation of CBlueprint
#include "stdafx.h"
#include "Blueprint.h"


// CBlueprint
STDMETHODIMP CBlueprint::get_X(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_X;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_X(SHORT newVal)
{
	// TODO: Add your implementation code here
	m_X = newVal;
	FireViewChange();
	return S_OK;
}

STDMETHODIMP CBlueprint::get_Y(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Y;
	return S_OK;
}


STDMETHODIMP CBlueprint::put_Y(SHORT newVal)
{
	// TODO: Add your implementation code here

	m_Y = newVal;
	FireViewChange();
	return S_OK;
}
