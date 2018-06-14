// Blueprint.h : Declaration of the CBlueprint
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include <wchar.h>
#include "SRATL4_i.h"
#include "_IBlueprintEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;



// CBlueprint
class ATL_NO_VTABLE CBlueprint :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IBlueprint, &IID_IBlueprint, &LIBID_SRATL4Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IOleControlImpl<CBlueprint>,
	public IOleObjectImpl<CBlueprint>,
	public IOleInPlaceActiveObjectImpl<CBlueprint>,
	public IViewObjectExImpl<CBlueprint>,
	public IOleInPlaceObjectWindowlessImpl<CBlueprint>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CBlueprint>,
	public CProxy_IBlueprintEvents<CBlueprint>,
	public ISpecifyPropertyPagesImpl<CBlueprint>,
	public IQuickActivateImpl<CBlueprint>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CBlueprint>,
#endif
	public IProvideClassInfo2Impl<&CLSID_Blueprint, &__uuidof(_IBlueprintEvents), &LIBID_SRATL4Lib>,
	public IObjectSafetyImpl<CBlueprint, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CBlueprint, &CLSID_Blueprint>,
	public CComControl<CBlueprint>
{
public:


	CBlueprint()
	{
		m_Min = -2;
		m_Max = 3;

		m_Scale = abs(m_Min) + abs(m_Max);
		if (m_Scale == 0)
		{
			m_Scale = 1;
		}
		m_BackgroundColor = RGB(255, 255, 255); // белый
		m_LineColor = RGB(0, 0, 0);

		m_bDraw = FALSE;
		m_ClickCount = 0;
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_BLUEPRINT)


BEGIN_COM_MAP(CBlueprint)
	COM_INTERFACE_ENTRY(IBlueprint)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CBlueprint)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CBlueprint)
	CONNECTION_POINT_ENTRY(__uuidof(_IBlueprintEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CBlueprint)
	CHAIN_MSG_MAP(CComControl<CBlueprint>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IBlueprint,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IBlueprint
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{

		RECT& rect = *(RECT*)di.prcBounds;
		// Цвет фона
		HBRUSH hBrush = CreateSolidBrush(m_BackgroundColor);
		SelectObject(di.hdcDraw, hBrush);
		FillRect(di.hdcDraw, &rect, hBrush);
		Rectangle(di.hdcDraw, rect.left, rect.top, rect.right, rect.bottom);

		if (m_bDraw)
		{
			HRGN hRgnOld = NULL;
			if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
				hRgnOld = NULL;
			bool bSelectOldRgn = false;

			HRGN hRgnNew = CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);

			if (hRgnNew != NULL)
			{
				bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
			}


			HDC hdc = di.hdcDraw;

			int clientSizeX = 500;
			int clientSizeY = -1000;

			SetMapMode(hdc, MM_ANISOTROPIC);
			SetWindowExtEx(hdc, clientSizeX, clientSizeY, NULL);
			SetViewportExtEx(hdc, rect.right, rect.bottom, NULL);
			SetViewportOrgEx(hdc, rect.right / 2, rect.bottom / 2, NULL);

			double x = 0;
			double y = 0;
			double y_scr = 0;
			double x_scr = 0;
			int Xscale = 50;
			int YScale = 50;
			int Xoffset = 50;
			int Yoffset = 200;

			double yMin = 0.0f;
			double yMax = 0.0f;

			yMin = 4 * m_Min - 7 * sin(m_Min);
			yMax = 4 * m_Max - 7 * sin(m_Max);


			// Рисование вертикальных линий сетки

			HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
			SelectObject(hdc, hPen);

			x = m_Min;
			while (x <= m_Max)
			{
				x_scr = x * Xscale - Xoffset;

				wchar_t* xc;

				swprintf(xc, TEXT("%0.1f"), x);

				TextOut(hdc, (int)x_scr, clientSizeY / 2 + Yoffset, xc, lstrlen(xc));

				if (x != 0)
				{
					MoveToEx(hdc, x_scr, yMin* YScale - Yoffset, NULL);
					LineTo(hdc, x_scr, yMax* YScale - Yoffset);
				}

				x += 0.5f;
			}

			// Рисование горизонтальных линий сетки


			while (yMin <= yMax)
			{
				y_scr = yMin* YScale - Yoffset;

				wchar_t* yc;

				swprintf(yc, TEXT("%0.0f"), yMin);

				TextOut(hdc, -clientSizeX / 2 + Xoffset, (int)y_scr, yc, lstrlen(yc));


				MoveToEx(hdc, m_Min * Xscale - Xoffset, y_scr, NULL);
				LineTo(hdc, m_Max * Xscale - Xoffset, y_scr);

				yMin = yMin + 3.0f;
			}


			// Рисование осей сетки

			hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			SelectObject(hdc, hPen);

			MoveToEx(hdc, m_Min * Xscale - Xoffset, -Yoffset, NULL);
			LineTo(hdc, m_Max * Xscale - Xoffset, -Yoffset);


			yMin = 4 * m_Min - 7 * sin(m_Min);
			MoveToEx(hdc, -Xoffset, yMin* YScale - Yoffset, NULL);
			LineTo(hdc, -Xoffset, yMax* YScale - Yoffset);


			// Рисование графика

			hPen = CreatePen(PS_SOLID, 5, m_LineColor);
			SelectObject(hdc, hPen);
			x = m_Min;
			x_scr = x * Xscale - Xoffset;
			y = 4 * x - 7 * sin(x);
			y_scr = y * YScale - Yoffset;
			MoveToEx(hdc, (int)x_scr, (int)y_scr, NULL);

			while (x <= m_Max)
			{
				y = 4 * x - 7 * sin(x);
				x_scr = x * Xscale - Xoffset;
				y_scr = y * YScale - Yoffset;
				LineTo(hdc, (int)x_scr, (int)y_scr);
				x += 0.1f;

			}
		}


		return S_OK;
	}

	bool m_bDraw;
	int m_ClickCount;


	short m_Min;
	short m_Max;

	int m_Scale;

	OLE_COLOR m_BackgroundColor;
	OLE_COLOR m_LineColor;

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	STDMETHOD(get_Min)(SHORT* pVal);
	STDMETHOD(put_Min)(SHORT newVal);
	STDMETHOD(get_Max)(SHORT* pVal);
	STDMETHOD(put_Max)(SHORT newVal);

	STDMETHOD(get_BackgroundColor)(OLE_COLOR* pVal);
	STDMETHOD(put_BackgroundColor)(OLE_COLOR newVal);
	STDMETHOD(get_LineColor)(OLE_COLOR* pVal);
	STDMETHOD(put_LineColor)(OLE_COLOR newVal);
	LRESULT OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnRButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

OBJECT_ENTRY_AUTO(__uuidof(Blueprint), CBlueprint)
