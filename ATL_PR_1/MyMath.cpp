// MyMath.cpp : Implementation of CMyMath

#include "stdafx.h"
#include "MyMath.h"


// CMyMath

STDMETHODIMP CMyMath::Add(DOUBLE x, DOUBLE y, DOUBLE* z)
{
	// TODO: Add your implementation code here
	*z = x + y;

	return S_OK;
}

STDMETHODIMP CMyMath::Subtract(DOUBLE x, DOUBLE y, DOUBLE * z)
{
	// TODO: Add your implementation code here
	*z = x - y;

	return S_OK;
}

STDMETHODIMP CMyMath::Multiply(DOUBLE x, DOUBLE y, DOUBLE * z)
{
	// TODO: Add your implementation code here
	*z = x * y;

	return S_OK;
}

STDMETHODIMP CMyMath::Divide(DOUBLE x, DOUBLE y, DOUBLE * z)
{
	// TODO: Add your implementation code here
	*z = x / y;

	return S_OK;
}
