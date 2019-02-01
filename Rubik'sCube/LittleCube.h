#pragma 

#include <Windows.h>	// Windows library (for window functions, menus, dialog boxes, etc)
#include <d3dx9.h>		// Direct 3D library (for all Direct 3D funtions).
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define cube_lenght_ 10.0

class LittleCube{

public:

	
	LittleCube(float x, float y, float z);
	virtual ~LittleCube();

	//Function for initialise the vertex buffer
	HRESULT fillTheCubeVertexBuffer(LPDIRECT3DDEVICE9  g_pd3dDevice);
	
	
	//Function for return the vertex buffer
	LPDIRECT3DVERTEXBUFFER9 returnTheCubeVertexBuffer() { return g_pVertexBufferCube;  }

	//FUnctions for draw the cube
	void drawTheRB(LPDIRECT3DDEVICE9);
	void rotateTheColumn(LPDIRECT3DDEVICE9, float, int);
	void rotateTheRow(LPDIRECT3DDEVICE9, float, int);

	//Change texture functions
	void changeRowTexture(int);
	void changeColumnTexture(int);

	//Load and set texture
	void LoadTextures(LPDIRECT3DDEVICE9);
	int setTexture(LPDIRECT3DDEVICE9,int,int,int,int);
	void readFromFile();
	
	//Functions for calculate the center for the rotations
	D3DXVECTOR3 calculateTheRowCenter(int,int,int);
	D3DXVECTOR3 calculateTheColumnCenter(int, int, int);

	
	
	void cleanVertexBuffer();

	//Functions for the UI

	HRESULT initializeUI(LPDIRECT3DDEVICE9);
	void drawTheUI();
	void setTheBillboard(LPDIRECT3DDEVICE9, int, int);


private:


	float returnx() { return originx_; }
	float returny() { return originy_; }
	float returnz() { return originz_; }
	
	//Cube colour (BLACK)
	const int backgroundColour_ = 0x000000;

	//Coordinate of the first edge of the face
	float originx_;
	float originy_;
	float originz_;

	float g_RotationAngle = 0.0f;

	bool firstTime = true;
	std::vector<int> texture_number;
	ID3DXFont *fontbb1, *fontbb2;
	RECT billboard_rectangle1, billboard_rectangle2;
	std::string billboard1, billboard2;

	//Variable for the UI
	ID3DXFont *font1, *font2;
	RECT title_rectangle, instruction_rectangle, interactive_rectangle;
	std::string title, instruction;

	// Pointer to the Buffer to hold vertices for the face
	LPDIRECT3DVERTEXBUFFER9 g_pVertexBufferCube = NULL;
	//LPDIRECT3DTEXTURE9		g_pTexture1 = NULL; // The texture.
	LPDIRECT3DTEXTURE9		g_pTextures[6];   // Array of pointers for the textures.


	int textures[162];
};