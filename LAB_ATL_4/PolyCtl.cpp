// PolyCtl.cpp : Implementation of CPolyCtl
#include "stdafx.h"
#include "PolyCtl.h"


// CPolyCtl


STDMETHODIMP CPolyCtl::get_Sides(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_nSides;
	return S_OK;
}


STDMETHODIMP CPolyCtl::put_Sides(SHORT newVal)
{
	// TODO: Add your implementation code here
	if (2 < newVal && newVal < 10)
	{
		m_nSides = newVal;
		return S_OK;
	}
	else
	{
		return Error(("Shape must have between 3 and 10 sides"));
	}
}

void CPolyCtl::CalcPoints(const RECT & rc)
{
	const double pi = 3.14159365358979;
	POINT ptCenter;
	double dblRadiusX = (rc.right - rc.left) / 2;
	double dblRadiusY = (rc.bottom - rc.top) / 2;
	double dblAngle = 3 * pi / 2;

	double dblDiff = 2 * pi / m_nSides;

	ptCenter.x = (rc.left + rc.right) / 2;
	ptCenter.y = (rc.top + rc.bottom) / 2;

	for (int i = 0; i < m_nSides; i++)
	{
		m_arrPoint[i].x = (long)(dblRadiusX * cos(dblAngle) + ptCenter.x + 0.5);
		m_arrPoint[i].y = (long)(dblRadiusY * cos(dblAngle) + ptCenter.y + 0.5);
		dblAngle += dblDiff;
	}
}
