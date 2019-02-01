//Project made by Tiziano Casu - 4/2018 during the Graphics and Animation course 
//------------------------------Rubik's cube-----------------------------------------

// Blank Direct 3D Application
#define STRICT
#define DIRECTINPUT_VERSION 0x0800

#define D3D_DEBUG_INFO	// Enable debugging information, so the .NET environment can help you.

//-----------------------------------------------------------------------------
// Include these files

#include <Windows.h>	// Windows library (for window functions, menus, dialog boxes, etc)
#include <d3dx9.h>		// Direct 3D library (for all Direct 3D funtions).
#include "LittleCube.h"
#include <dinput.h>		// Direct Input library (for Direct Input functions)


//-----------------------------------------------------------------------------
// Global variables

LPDIRECT3D9             g_pD3D           = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice     = NULL; // The rendering device

LPDIRECTINPUT8			g_lpDI = NULL; // Pointer to the Direct Input object
LPDIRECTINPUTDEVICE8	g_pDIKeyboardDevice = NULL; // The Direct Input device - Keyboard.

float g_RotationAngle = 0.5f;
LittleCube lc(0,-10, 0);

float rotateRow = false;
float rotateCol = false;
bool moving = false;
int col = 1;
int row = 1;
float timer = 0;


// Function prototypes.
void WINAPI CleanupDirectInput();

//-----------------------------------------------------------------------------
// Initialise Direct 3D.
// Requires a handle to the window where the graphics will be drawn.

HRESULT SetupD3D(HWND hWnd)
{
	
    // Create the D3D object, return failure if this can't be done.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) return E_FAIL;

    // Set up the structure used to create the D3DDevice
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    // Create the D3DDevice
    if (FAILED(g_pD3D -> CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_HARDWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

	// Turn on the Z buffer
	g_pd3dDevice -> SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	// Turn on culling.
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, TRUE);


	lc.fillTheCubeVertexBuffer(g_pd3dDevice);

    return S_OK;
}

//-----------------------------------------------------------------------------
// Release (delete) all the resources used by this program.
// Only release things if they are valid (i.e. have a valid pointer).
// If not, the program will crash at this point.

void CleanUp()
{
	CleanupDirectInput();


    if (g_pd3dDevice != NULL) g_pd3dDevice -> Release();
    if (g_pD3D != NULL)		  g_pD3D -> Release();
}

//-----------------------------------------------------------------------------
// Set up the view - the view and projection matrices.

void SetupViewMatrices()
{
	// Set up the view matrix.
	// This defines which way the 'camera' will look at, and which way is up.
	D3DXVECTOR3 vCamera( 60.0f, 75.0f, -110.0f);
	D3DXVECTOR3 vLookat(-20.0f, 30.0f,10.0f);
	D3DXVECTOR3 vUpVector(0.0f, 1.0f, 0.0f);
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView, &vCamera, &vLookat, &vUpVector);
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);



	// Set up the projection matrix.
	// This transforms 2D geometry into a 3D space.
	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 300.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);

	
}


//-----------------------------------------------------------------------------

void SetupLightsAndMaterial()
{
	// Define a material.
	// Reflects only diffuse colour.
	D3DMATERIAL9 Mtl;
	ZeroMemory(&Mtl, sizeof(D3DMATERIAL9));
	Mtl.Diffuse.r = 1.0f;
	Mtl.Diffuse.g = 1.0f;
	Mtl.Diffuse.b = 1.0f;
	Mtl.Diffuse.a = 1.0f;
	g_pd3dDevice->SetMaterial(&Mtl);

	// Define a light.
	// Possesses only a diffuse colour.
	D3DLIGHT9 Light1;
	ZeroMemory(&Light1, sizeof(D3DLIGHT9));
	Light1.Type = D3DLIGHT_POINT;

	Light1.Diffuse.r = 1.2f;
	Light1.Diffuse.g = 1.2f;
	Light1.Diffuse.b = 1.2f;

	Light1.Position.x = 0.0f;
	Light1.Position.y = 50.0f;
	Light1.Position.z = -50.0f;

	Light1.Attenuation0 = 1.0f;
	Light1.Attenuation1 = 0.0f;
	Light1.Attenuation2 = 0.0f;

	Light1.Range = 500.0f;

	// Select and enable the light.
	g_pd3dDevice->SetLight(0, &Light1);
	g_pd3dDevice->LightEnable(0, TRUE);
}

//-----------------------------------------------------------------------------
// Render the frame to the back buffer.

void Render()
{
	
	DWORD BackgroundColour = 0x000033;
	
	// Clear the backbuffer and the z buffer.
    //g_pd3dDevice -> Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, BackgroundColour, 1.0f, 0);
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, BackgroundColour, 1.0f, 0);


    // Begin rendering the scene.
    if (SUCCEEDED(g_pd3dDevice -> BeginScene()))

	{

	

		if (rotateRow == false && rotateCol == false) 
			lc.drawTheRB(g_pd3dDevice);
			
		///Rotate the row
		else if (rotateRow == true){
			lc.rotateTheRow(g_pd3dDevice, g_RotationAngle, row);
			g_RotationAngle += 0.5;
		}

		///Rotate the column
		else if (rotateCol == true) {
			lc.rotateTheColumn(g_pd3dDevice, g_RotationAngle, col);
			g_RotationAngle += 0.5;
		}
			
		///When the rotation is complete
		if (g_RotationAngle == 10) {
			g_RotationAngle = 0.5;
			moving = false;

			///Switch the texture of the row
			if (rotateRow == true) {
				rotateRow = false;
				lc.changeRowTexture(row);
			}

			///Switch the texture of the column
			else if (rotateCol == true){
				rotateCol = false;
				lc.changeColumnTexture(col);
			}
		
		}
			
					
        g_pd3dDevice -> EndScene();

    }

    // Present the backbuffer to the display.
    g_pd3dDevice -> Present(NULL, NULL, NULL, NULL);
}

//-----------------------------------------------------------------------------
// Terminate Direct Input and clean up...
void WINAPI CleanupDirectInput()
{
	if (g_lpDI)
	{
		if (g_pDIKeyboardDevice)
		{
			// Always unacquire device before calling Release(). 
			g_pDIKeyboardDevice->Unacquire();
			g_pDIKeyboardDevice->Release();
			g_pDIKeyboardDevice = NULL;
		}
		g_lpDI->Release();
		g_lpDI = NULL;
	}
}

//------------------------------------------------------------------------------
// Initialise Direct Input
BOOL WINAPI SetupDirectInput(HINSTANCE g_hinst, HWND g_hwndMain)
{
	HRESULT hr;

	// Create the DirectInput object. 
	hr = DirectInput8Create(g_hinst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_lpDI, NULL);

	if FAILED(hr) return FALSE;

	// Retrieve a pointer to an IDirectInputDevice8 interface.
	hr = g_lpDI->CreateDevice(GUID_SysKeyboard, &g_pDIKeyboardDevice, NULL);

	if FAILED(hr)
	{
		CleanupDirectInput();
		return FALSE;
	}


	// Set the data format using the predefined keyboard data format.
	hr = g_pDIKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	if FAILED(hr)
	{
		CleanupDirectInput(); // Terminate Direct Input initialisation if an error is detected.
		return FALSE;
	}

	// Set the cooperative level 
	hr = g_pDIKeyboardDevice->SetCooperativeLevel(g_hwndMain, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if FAILED(hr)
	{
		CleanupDirectInput();
		return FALSE;
	}

	g_pDIKeyboardDevice->Acquire();

	return TRUE;
}

//------------------------------------------------------------------------------------------
// Process keyboard inputs...
void WINAPI ProcessKeyboardInput()
{
	// Define a macro to represent the key detection predicate.
#define KEYDOWN(name, key) (name[key] & 0x80) 

	// Create a buffer (memory space) to contain the key press data from the keyboard.
	char     buffer[256];
	HRESULT  hr;

	// Clear the buffer for keyboard data - just in case.
	ZeroMemory(&buffer, 256);

	hr = g_pDIKeyboardDevice->GetDeviceState(sizeof(buffer), (LPVOID)&buffer);
	if FAILED(hr)
	{
		// If this failed, the device has probably been lost.
		// Check for (hr == DIERR_INPUTLOST) and attempt to reacquire it here.
		hr = g_pDIKeyboardDevice->Acquire();
		while (hr == DIERR_INPUTLOST) hr = g_pDIKeyboardDevice->Acquire();

		hr = g_pDIKeyboardDevice->GetDeviceState(sizeof(buffer), (LPVOID)&buffer);
	}

	if (KEYDOWN(buffer, DIK_Q))
	{
		// 'Q' has been pressed - so tell the application to exit.
		PostQuitMessage(0);
	}

	if (KEYDOWN(buffer, DIK_R))
	{
		rotateRow = true;
		timer = 0;
	}

	if (KEYDOWN(buffer, DIK_C))
	{
		rotateCol = true;
		timer = 0;
	}

	if (KEYDOWN(buffer, DIK_UP))
	{
		if (timer == 0){
			if (rotateRow == false)
				if (row != 2) {
					++row;
					lc.setTheBillboard(g_pd3dDevice, col, row);
					timer += 0.1;
				}
		}
		else {
			timer += 0.1;
			if (timer >= 1.4)
				timer = 0;
		}

	}

	if (KEYDOWN(buffer, DIK_DOWN))
	{
		if (timer == 0) {
			if (rotateRow == false)
				if (row != 0) {
					--row;
					lc.setTheBillboard(g_pd3dDevice, col, row);
					timer += 0.1;
				}
		}
		else {
			timer += 0.1;
			if (timer >= 1.4)
				timer = 0;
		}
		
	}

	if (KEYDOWN(buffer, DIK_LEFT))
	{
		if (timer == 0) {
			if (rotateCol == false)
				if (col != 0) {
					--col;
					lc.setTheBillboard(g_pd3dDevice, col, row);
					timer += 0.1;
				}
		}
		else {
			timer += 0.1;
			if (timer >= 1.4)
				timer = 0;
		}
	}

	if (KEYDOWN(buffer, DIK_RIGHT))
	{
		if (timer == 0) {
			if (rotateCol == false)
				if (col != 2) {
					++col;
					lc.setTheBillboard(g_pd3dDevice, col, row);
					timer += 0.1;
				}
		}
		else {
			timer += 0.1;
			if (timer >= 1.4)
				timer = 0;
		}
	}

}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// The window's message handling function.

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
		{
			PostQuitMessage(0);
            return 0;
		}
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

//-----------------------------------------------------------------------------
// WinMain() - The application's entry point.
// This sort of procedure is mostly standard, and could be used in most
// DirectX applications.

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
    // Register the window class
    WNDCLASSEX wc = {sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "Blank", NULL};
    RegisterClassEx(&wc);

    // Create the application's window
    HWND hWnd = {CreateWindow( "Blank", "Rubik's Cube", WS_OVERLAPPEDWINDOW, 100, 100, 900, 800, GetDesktopWindow(), NULL, wc.hInstance, NULL)};

    // Initialize Direct3D
    if (SUCCEEDED(SetupD3D(hWnd)))
    {
		// Initialise Direct Input and acquire the keyboard
		if (SUCCEEDED(SetupDirectInput(hInst, hWnd))) 
		{
			// Show the window
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			UpdateWindow(hWnd);
			lc.setTheBillboard(g_pd3dDevice, col, row);

			// Set up the light.
			SetupLightsAndMaterial();

			// Define the viewpoint.
			SetupViewMatrices();

			// Enter the message loop
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));

			// Respond to messages until a 'WM_QUIT' message is received.
			while (msg.message != WM_QUIT)
			{
				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else {
					ProcessKeyboardInput();
					Render();
				
				}

			}
		}
		
		CleanUp();	// Delete any resources that DX has created/used.
		lc.cleanVertexBuffer();
    }

    UnregisterClass("Blank", wc.hInstance);
    return 0;
}
