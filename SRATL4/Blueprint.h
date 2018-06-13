// Blueprint.h : Declaration of the CBlueprint
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
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
		m_X = 0;
		m_Y = 0;
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
		RECT& rc = *(RECT*)di.prcBounds;
		// Set Clip region to the rectangle specified by di.prcBounds
		HRGN hRgnOld = NULL;
		if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
			hRgnOld = NULL;
		bool bSelectOldRgn = false;

		HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);

		if (hRgnNew != NULL)
		{
			bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
		}

		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("Blueprint");
		LPCTSTR pszX = _T("0");
		LPCTSTR pszY = _T("0");

#ifndef _WIN32_WCE
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));

		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			((rc.top + rc.bottom) / 2) + 20,
			(WCHAR*)m_X,
			lstrlen((WCHAR*)m_X));
#else
		ExtTextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			ETO_OPAQUE,
			NULL,
			pszText,
			ATL::lstrlen(pszText),
			NULL);

		ExtTextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			((rc.top + rc.bottom) / 2) + 20,
			ETO_OPAQUE,
			NULL,
			pszX,
			ATL::lstrlen(pszX),
			NULL);
#endif

		if (bSelectOldRgn)
			SelectClipRgn(di.hdcDraw, hRgnOld);

		DeleteObject(hRgnNew);

		return S_OK;
	}

	short m_X;
	short m_Y;


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	STDMETHOD(get_X)(SHORT* pVal);
	STDMETHOD(put_X)(SHORT newVal);
	STDMETHOD(get_Y)(SHORT* pVal);
	STDMETHOD(put_Y)(SHORT newVal);

};

OBJECT_ENTRY_AUTO(__uuidof(Blueprint), CBlueprint)
