#define STRICT
#define WIN32_LEAN_AND_MEAN

using namespace std;

#include <windows.h>
#include <dhFPSTimer.h>
#include <commctrl.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ident.h"
#include "structures.h"
#include "variables.h"
#include "prototypes.h"
#include "functions.h"





//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR     lpCmdLine,
                    int       nCmdShow )
{          
	WNDCLASSEX winClass;
	MSG        uMsg;

    memset(&uMsg,0,sizeof(uMsg));

	winClass.lpszClassName = "MY_WINDOWS_CLASS";
	winClass.cbSize        = sizeof(WNDCLASSEX);
	winClass.style         = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc   = WindowProc;
	winClass.hInstance     = hInstance;
	winClass.hIcon	       = LoadIcon(hInstance,IDI_APPLICATION );
    winClass.hIconSm	   = LoadIcon(hInstance,IDI_APPLICATION );
	winClass.hCursor       = LoadCursor(NULL,IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)+1;
	winClass.lpszMenuName  = MAKEINTRESOURCE(M3D_MENU);
	winClass.cbClsExtra    = 0;
	winClass.cbWndExtra    = 0;
	if( !RegisterClassEx(&winClass) )
		return E_FAIL;

	g_hWnd = CreateWindowEx( 0, "MY_WINDOWS_CLASS", 
                             "Blob2D",
						     WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					         0, 0, 1366, 768, NULL, NULL, hInstance, NULL );

	if( g_hWnd == NULL )
		return E_FAIL;

    ShowWindow( g_hWnd, nCmdShow );
    UpdateWindow( g_hWnd );

	init();

	while( uMsg.message != WM_QUIT )
	{
		if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
		{ 
			TranslateMessage( &uMsg );
			DispatchMessage( &uMsg );
		}
        else
		    render();
	}

	shutDown();

    UnregisterClass( "MY_WINDOWS_CLASS", winClass.hInstance );

	return uMsg.wParam;
}

