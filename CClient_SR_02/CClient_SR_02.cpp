// CClient_SR_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cguid.h>

BOOL VariantToInt(VARIANTARG* pvarSrc, int* ip)
{
	VARIANTARG varDest;
	VariantInit(&varDest);

	HRESULT hr = VariantChangeType(&varDest, pvarSrc, 0, VT_I4);
	if (FAILED(hr))
	{
		return FALSE;
	}

	*ip = varDest.intVal;

	return TRUE;
}

BOOL VariantToFloat(VARIANTARG* pvarSrc, float* fp)
{
	VARIANTARG varDest;
	VariantInit(&varDest);

	HRESULT hr = VariantChangeType(&varDest, pvarSrc, 0, VT_R4);
	if (FAILED(hr))
	{
		return FALSE;
	}

	*fp = varDest.fltVal;

	return TRUE;
}


BOOL VariantToDouble(VARIANTARG* pvarSrc, double* dp)
{
	VARIANTARG varDest;
	VariantInit(&varDest);

	HRESULT hr = VariantChangeType(&varDest, pvarSrc, 0, VT_R8);
	if (FAILED(hr))
	{
		return FALSE;
	}

	*dp = varDest.dblVal;

	return TRUE;
}


int main()
{
	// Инициализировать библиотеку OLE. 
	HRESULT hr = CoInitialize(NULL);
	// Получить CLSID приложения. 
	wchar_t progid[] = L"SR_ATL2.FN01.1";
	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	// Создать компонент. 
	IDispatch* pIDispatch = NULL;
	hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&pIDispatch);

	DISPID dispid;

	/////////////////////// Fun11 ////////////

	TCHAR nameFn11[] = L"Fun11";

	OLECHAR* OlenameFn11 = nameFn11;
	pIDispatch->GetIDsOfNames(
		IID_NULL,   // Должно быть IID_NULL
		&OlenameFn11,    // Имя функции
		1,    // Число имен
		GetUserDefaultLCID(), // Информация локализации
		&dispid);   // Диспетчерский идентификатор 


	VARIANTARG vargFn11[2];

	VariantInit(&vargFn11[0]); // Инициализировать VARIANT. 
	vargFn11[0].vt = VT_I4;  // Тип данных VARIANT
	vargFn11[0].intVal = 50;// Данные для VARIANT

	VariantInit(&vargFn11[1]); // Инициализировать VARIANT. 
	vargFn11[1].vt = VT_I4;  // Тип данных VARIANT
	vargFn11[1].intVal = 5;// Данные для VARIANT

	DISPPARAMS paramFn11;
	paramFn11.cArgs = 2;   // Два аргумента 
	paramFn11.rgvarg = vargFn11;  // Указатель на аргумент 
	paramFn11.cNamedArgs = 0;  // Нет именованных аргументов 
	paramFn11.rgdispidNamedArgs = NULL;

	VARIANT vResFun11;

	// Простейший вызов Invoke 
	hr = pIDispatch->Invoke(dispid,   // DISPID    
		IID_NULL,   // Должно быть IID_NULL    
		GetUserDefaultLCID(), // Информация локализации    
		DISPATCH_METHOD,  // Метод    
		&paramFn11,  // Аргументы метода   
		&vResFun11,    // Результаты    
		NULL,    // Исключение    
		NULL);


	int resInt = 0;

	VariantToInt(&vResFun11, &resInt);

	printf("Fun11  50+5 = %d\n", resInt);

	///////////////////////  Fun11 //////////////

	TCHAR nameFn12[] = L"Fun12";

	OLECHAR* OlenameFn12 = nameFn12;
	pIDispatch->GetIDsOfNames(
		IID_NULL,   // Должно быть IID_NULL
		&OlenameFn12,    // Имя функции
		1,    // Число имен
		GetUserDefaultLCID(), // Информация локализации
		&dispid);   // Диспетчерский идентификатор 


	VARIANTARG vargFn12[3];

	VariantInit(&vargFn12[0]); // Инициализировать VARIANT. 
	vargFn12[0].vt = VT_I4;  // Тип данных VARIANT
	vargFn12[0].intVal = 3;// Данные для VARIANT

	VariantInit(&vargFn12[1]); // Инициализировать VARIANT. 
	vargFn12[1].vt = VT_I4;  // Тип данных VARIANT
	vargFn12[1].intVal = 6;// Данные для VARIANT

	VariantInit(&vargFn12[2]); // Инициализировать VARIANT. 
	vargFn12[2].vt = VT_I4;  // Тип данных VARIANT
	vargFn12[2].intVal = 9;// Данные для VARIANT

	DISPPARAMS paramFn12;
	paramFn12.cArgs = 3;   // Три аргумента 
	paramFn12.rgvarg = vargFn12;  // Указатель на аргумент 
	paramFn12.cNamedArgs = 0;  // Нет именованных аргументов 
	paramFn12.rgdispidNamedArgs = NULL;

	VARIANT vResFun12;

	// Простейший вызов Invoke 
	hr = pIDispatch->Invoke(dispid,   // DISPID    
		IID_NULL,   // Должно быть IID_NULL    
		GetUserDefaultLCID(), // Информация локализации    
		DISPATCH_METHOD,  // Метод    
		&paramFn12,  // Аргументы метода   
		&vResFun12,    // Результаты    
		NULL,    // Исключение    
		NULL);

	float resFlt = 0.0f;

	VariantToFloat(&vResFun12, &resFlt);

	printf("Fun12  3+6+9 = %lf\n", resFlt);


	///////////////////////  Fun13 //////////////

	TCHAR nameFn13[] = L"Fun13";

	OLECHAR* OlenameFn13 = nameFn13;
	pIDispatch->GetIDsOfNames(
		IID_NULL,   // Должно быть IID_NULL
		&OlenameFn13,    // Имя функции
		1,    // Число имен
		GetUserDefaultLCID(), // Информация локализации
		&dispid);   // Диспетчерский идентификатор 


	VARIANTARG vargFn13[1];

	VariantInit(&vargFn13[0]); // Инициализировать VARIANT. 
	vargFn13[0].vt = VT_R8;  // Тип данных VARIANT
	vargFn13[0].dblVal = 4.0f;// Данные для VARIANT

	DISPPARAMS paramFn13;
	paramFn13.cArgs = 1;   // Один аргумент 
	paramFn13.rgvarg = vargFn13;  // Указатель на аргумент 
	paramFn13.cNamedArgs = 0;  // Нет именованных аргументов 
	paramFn13.rgdispidNamedArgs = NULL;

	VARIANT vResFun13;

	// Простейший вызов Invoke 
	hr = pIDispatch->Invoke(dispid,   // DISPID    
		IID_NULL,   // Должно быть IID_NULL    
		GetUserDefaultLCID(), // Информация локализации    
		DISPATCH_METHOD,  // Метод    
		&paramFn13,  // Аргументы метода   
		&vResFun13,    // Результаты    
		NULL,    // Исключение    
		NULL);

	double resDbl = 0.0f;

	VariantToDouble(&vResFun13, &resDbl);

	printf("Fun13  4*4 = %lf\n", resDbl);

	system("pause");
    return 0;
}

