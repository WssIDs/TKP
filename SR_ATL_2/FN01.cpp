// FN01.cpp : Implementation of CFN01

#include "stdafx.h"
#include "FN01.h"


// CFN01

STDMETHODIMP CFN01::Fun11(int a, int b, int* pResult)
{
	*pResult = a + b;
	return S_OK;
}

STDMETHODIMP CFN01::Fun12(int a, int b, int c, float* pResult)
{
	*pResult = (float)a + (float)b + (float)c;
	return S_OK;
}

STDMETHODIMP CFN01::Fun13(double inValue, double *pResult)
{
	*pResult = inValue * inValue;
	return S_OK;
}