#include "LittleCube.h"


struct CUSTOMVERTEX {

	D3DXVECTOR3 position;	// Position
	D3DXVECTOR3 normal;		// Vertex normal
	
	FLOAT u, v;				// Texture co-ordinates.
	DWORD colour;


};


#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 )


LittleCube::LittleCube(float x, float y, float z) : originx_(x), originy_(y), originz_(z){
	readFromFile();
}

LittleCube::~LittleCube()
{
	 if (g_pVertexBufferCube != NULL) g_pVertexBufferCube -> Release();
	
	 for (int i(0); i < 6; ++i)
	 {
		 if (g_pTextures[i] != NULL) g_pTextures[i]->Release();
	 }
}

HRESULT LittleCube::fillTheCubeVertexBuffer(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	int Vertices = 2 * 3 * 6;
	int BufferSize = Vertices * sizeof(CUSTOMVERTEX);


	if (FAILED(g_pd3dDevice->CreateVertexBuffer(BufferSize, 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVertexBufferCube, NULL)))
	{
		return E_FAIL; // if the vertex buffer culd not be created.
	}


	CUSTOMVERTEX* pVertices;
	if (FAILED(g_pVertexBufferCube->Lock(0, 0, (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	// Side 1 - Front face
	pVertices[0].position.x = 0;	// Vertex co-ordinate.
	pVertices[0].position.y = 0;
	pVertices[0].position.z = 0;
	pVertices[0].normal.x = 0;		// Vertex normal.
	pVertices[0].normal.y = 0;
	pVertices[0].normal.z = -1;
	pVertices[0].u = 0;
	pVertices[0].v = 0;
	pVertices[0].colour = backgroundColour_;


	pVertices[1].position.x = 0;
	pVertices[1].position.y = cube_lenght_;
	pVertices[1].position.z = 0;
	pVertices[1].normal.x = 0;
	pVertices[1].normal.y = 0;
	pVertices[1].normal.z = -1;
	pVertices[1].u = 0;
	pVertices[1].v = 1;
	pVertices[1].colour = backgroundColour_;

	pVertices[2].position.x = cube_lenght_;
	pVertices[2].position.y = cube_lenght_;
	pVertices[2].position.z = 0;
	pVertices[2].normal.x = 0;
	pVertices[2].normal.y = 0;
	pVertices[2].normal.z = -1;
	pVertices[2].u = 1;
	pVertices[2].v = 1;
	pVertices[2].colour = backgroundColour_;

	pVertices[3].position.x = cube_lenght_;
	pVertices[3].position.y = 0;
	pVertices[3].position.z = 0;
	pVertices[3].normal.x = 0;
	pVertices[3].normal.y = 0;
	pVertices[3].normal.z = -1;
	pVertices[3].u = 1;
	pVertices[3].v = 0;
	pVertices[3].colour = backgroundColour_;

	pVertices[4].position.x = 0;
	pVertices[4].position.y = 0;
	pVertices[4].position.z = 0;
	pVertices[4].normal.x = 0;
	pVertices[4].normal.y = 0;
	pVertices[4].normal.z = -1;
	pVertices[4].u = 0;
	pVertices[4].v = 0;
	pVertices[4].colour = backgroundColour_;

	pVertices[5].position.x = cube_lenght_;
	pVertices[5].position.y = cube_lenght_;
	pVertices[5].position.z = 0;
	pVertices[5].normal.x = 0;
	pVertices[5].normal.y = 0;
	pVertices[5].normal.z = -1;
	pVertices[5].u = 1;
	pVertices[5].v = 1;
	pVertices[5].colour = backgroundColour_;

	// Side 2 - Right face
	pVertices[6].position.x = cube_lenght_;
	pVertices[6].position.y = 0;
	pVertices[6].position.z = 0;
	pVertices[6].normal.x = 1;
	pVertices[6].normal.y = 0;
	pVertices[6].normal.z = 0;
	pVertices[6].u = 0;
	pVertices[6].v = 0;
	pVertices[6].colour = backgroundColour_;

	pVertices[7].position.x = cube_lenght_;
	pVertices[7].position.y = cube_lenght_;
	pVertices[7].position.z = 0;
	pVertices[7].normal.x = 1;
	pVertices[7].normal.y = 0;
	pVertices[7].normal.z = 0;
	pVertices[7].u = 0;
	pVertices[7].v = 1;
	pVertices[7].colour = backgroundColour_;

	pVertices[8].position.x = cube_lenght_;
	pVertices[8].position.y = cube_lenght_;
	pVertices[8].position.z = cube_lenght_;
	pVertices[8].normal.x = 1;
	pVertices[8].normal.y = 0;
	pVertices[8].normal.z = 0;
	pVertices[8].u = 1;
	pVertices[8].v = 1;
	pVertices[8].colour = backgroundColour_;

	pVertices[9].position.x = cube_lenght_;
	pVertices[9].position.y = 0;
	pVertices[9].position.z = cube_lenght_;
	pVertices[9].normal.x = 1;
	pVertices[9].normal.y = 0;
	pVertices[9].normal.z = 0;
	pVertices[9].u = 1;
	pVertices[9].v = 0;
	pVertices[9].colour = backgroundColour_;

	pVertices[10].position.x = cube_lenght_;
	pVertices[10].position.y = 0;
	pVertices[10].position.z = 0;
	pVertices[10].normal.x = 1;
	pVertices[10].normal.y = 0;
	pVertices[10].normal.z = 0;
	pVertices[10].u = 0;
	pVertices[10].v = 0;
	pVertices[10].colour = backgroundColour_;

	pVertices[11].position.x = cube_lenght_;
	pVertices[11].position.y = cube_lenght_;
	pVertices[11].position.z = cube_lenght_;
	pVertices[11].normal.x = 1;
	pVertices[11].normal.y = 0;
	pVertices[11].normal.z = 0;
	pVertices[11].u = 1;
	pVertices[11].v = 1;
	pVertices[1].colour = backgroundColour_;

	// Side 3 - Rear face
	pVertices[12].position.x = cube_lenght_;
	pVertices[12].position.y = 0;
	pVertices[12].position.z = cube_lenght_;
	pVertices[12].normal.x = 0;
	pVertices[12].normal.y = 0;
	pVertices[12].normal.z = 1;
	pVertices[12].u = 0;
	pVertices[12].v = 0;
	pVertices[12].colour = backgroundColour_;

	pVertices[13].position.x = cube_lenght_;
	pVertices[13].position.y = cube_lenght_;
	pVertices[13].position.z = cube_lenght_;
	pVertices[13].normal.x = 0;
	pVertices[13].normal.y = 0;
	pVertices[13].normal.z = 1;
	pVertices[13].u = 0;
	pVertices[13].v = 1;
	pVertices[13].colour = backgroundColour_;

	pVertices[14].position.x = 0;
	pVertices[14].position.y = cube_lenght_;
	pVertices[14].position.z = cube_lenght_;
	pVertices[14].normal.x = 0;
	pVertices[14].normal.y = 0;
	pVertices[14].normal.z = 1;
	pVertices[14].u = 1;
	pVertices[14].v = 1;
	pVertices[14].colour = backgroundColour_;

	pVertices[15].position.x = 0;
	pVertices[15].position.y = 0;
	pVertices[15].position.z = cube_lenght_;
	pVertices[15].normal.x = 0;
	pVertices[15].normal.y = 0;
	pVertices[15].normal.z = 1;
	pVertices[15].u = 1;
	pVertices[15].v = 0;
	pVertices[15].colour = backgroundColour_;

	pVertices[16].position.x = cube_lenght_;
	pVertices[16].position.y = 0;
	pVertices[16].position.z = cube_lenght_;
	pVertices[16].normal.x = 0;
	pVertices[16].normal.y = 0;
	pVertices[16].normal.z = 1;
	pVertices[16].u = 0;
	pVertices[16].v = 0;
	pVertices[16].colour = backgroundColour_;

	pVertices[17].position.x = 0;
	pVertices[17].position.y = cube_lenght_;
	pVertices[17].position.z = cube_lenght_;
	pVertices[17].normal.x = 0;
	pVertices[17].normal.y = 0;
	pVertices[17].normal.z = 1;
	pVertices[17].u = 1;
	pVertices[17].v = 1;
	pVertices[17].colour = backgroundColour_;

	// Side 4 1- Left face
	pVertices[18].position.x = 0;
	pVertices[18].position.y = 0;
	pVertices[18].position.z = cube_lenght_;
	pVertices[18].normal.x = -1;
	pVertices[18].normal.y = 0;
	pVertices[18].normal.z = 0;
	pVertices[18].u = 0;
	pVertices[18].v = 0;
	pVertices[18].colour = backgroundColour_;

	pVertices[19].position.x = 0;
	pVertices[19].position.y = cube_lenght_;
	pVertices[19].position.z = cube_lenght_;
	pVertices[19].normal.x = -1;
	pVertices[19].normal.y = 0;
	pVertices[19].normal.z = 0;
	pVertices[19].u = 0;
	pVertices[19].v = 1;
	pVertices[19].colour = backgroundColour_;

	pVertices[20].position.x = 0;
	pVertices[20].position.y = cube_lenght_;
	pVertices[20].position.z = 0;
	pVertices[20].normal.x = -1;
	pVertices[20].normal.y = 0;
	pVertices[20].normal.z = 0;
	pVertices[20].u = 1;
	pVertices[20].v = 1;
	pVertices[20].colour = backgroundColour_;

	pVertices[21].position.x = 0;
	pVertices[21].position.y = 0;
	pVertices[21].position.z = 0;
	pVertices[21].normal.x = -1;
	pVertices[21].normal.y = 0;
	pVertices[21].normal.z = 0;
	pVertices[21].u = 1;
	pVertices[21].v = 0;
	pVertices[21].colour = backgroundColour_;

	pVertices[22].position.x = 0;
	pVertices[22].position.y = 0;
	pVertices[22].position.z = cube_lenght_;
	pVertices[22].normal.x = -1;
	pVertices[22].normal.y = 0;
	pVertices[22].normal.z = 0;
	pVertices[22].u = 0;
	pVertices[22].v = 0;
	pVertices[22].colour = backgroundColour_;

	pVertices[23].position.x = 0;
	pVertices[23].position.y = cube_lenght_;
	pVertices[23].position.z = 0;
	pVertices[23].normal.x = -1;
	pVertices[23].normal.y = 0;
	pVertices[23].normal.z = 0;
	pVertices[23].u = 1;
	pVertices[23].v = 1;
	pVertices[23].colour = backgroundColour_;

	// Side 5 - Top face

	pVertices[24].position.x = 0;
	pVertices[24].position.y = cube_lenght_;
	pVertices[24].position.z = 0;
	pVertices[24].normal.x = 0;
	pVertices[24].normal.y = 1;
	pVertices[24].normal.z = 0;
	pVertices[24].u = 0;
	pVertices[24].v = 0;
	pVertices[24].colour = backgroundColour_;

	pVertices[25].position.x = 0;
	pVertices[25].position.y = cube_lenght_;
	pVertices[25].position.z = cube_lenght_;
	pVertices[25].normal.x = 0;
	pVertices[25].normal.y = 1;
	pVertices[25].normal.z = 0;
	pVertices[25].u = 0;
	pVertices[25].v = 1;
	pVertices[25].colour = backgroundColour_;

	pVertices[26].position.x = cube_lenght_;
	pVertices[26].position.y = cube_lenght_;
	pVertices[26].position.z = 0;
	pVertices[26].normal.x = 0;
	pVertices[26].normal.y = 1;
	pVertices[26].normal.z = 0;
	pVertices[26].u = 1;
	pVertices[26].v = 0;
	pVertices[26].colour = backgroundColour_;

	pVertices[27].position.x = cube_lenght_;
	pVertices[27].position.y = cube_lenght_;
	pVertices[27].position.z = 0;
	pVertices[27].normal.x = 0;
	pVertices[27].normal.y = 1;
	pVertices[27].normal.z = 0;
	pVertices[27].u = 1;
	pVertices[27].v = 0;
	pVertices[27].colour = backgroundColour_;

	pVertices[28].position.x = 0;
	pVertices[28].position.y = cube_lenght_;
	pVertices[28].position.z = cube_lenght_;
	pVertices[28].normal.x = 0;
	pVertices[28].normal.y = 1;
	pVertices[28].normal.z = 0;
	pVertices[28].u = 0;
	pVertices[28].v = 1;
	pVertices[28].colour = backgroundColour_;

	pVertices[29].position.x = cube_lenght_;
	pVertices[29].position.y = cube_lenght_;
	pVertices[29].position.z = cube_lenght_;
	pVertices[29].normal.x = 0;
	pVertices[29].normal.y = 1;
	pVertices[29].normal.z = 0;
	pVertices[29].u = 1;
	pVertices[29].v = 1;
	pVertices[0].colour = backgroundColour_;

	// Side 6 - Bottom face

	pVertices[30].position.x = 0;
	pVertices[30].position.y = 0;
	pVertices[30].position.z = 0;
	pVertices[30].normal.x = 0;
	pVertices[30].normal.y = -1;
	pVertices[30].normal.z = 0;
	pVertices[30].u = 0;
	pVertices[30].v = 0;
	pVertices[30].colour = backgroundColour_;

	pVertices[31].position.x = 0;
	pVertices[31].position.y = 0;
	pVertices[31].position.z = cube_lenght_;
	pVertices[31].normal.x = 0;
	pVertices[31].normal.y = -1;
	pVertices[31].normal.z = 0;
	pVertices[31].u = 0;
	pVertices[31].v = 1;
	pVertices[31].colour = backgroundColour_;

	pVertices[32].position.x = cube_lenght_;
	pVertices[32].position.y = 0;
	pVertices[32].position.z = 0;
	pVertices[32].normal.x = 0;
	pVertices[32].normal.y = -1;
	pVertices[32].normal.z = 0;
	pVertices[32].u = 1;
	pVertices[32].v = /*1*/0;
	pVertices[32].colour = backgroundColour_;

	pVertices[33].position.x = cube_lenght_;
	pVertices[33].position.y = 0;
	pVertices[33].position.z = 0;
	pVertices[33].normal.x = 0;
	pVertices[33].normal.y = -1;
	pVertices[33].normal.z = 0;
	pVertices[33].u = 1;
	pVertices[33].v = 0;
	pVertices[33].colour = backgroundColour_;

	pVertices[34].position.x = 0;
	pVertices[34].position.y = 0;
	pVertices[34].position.z = cube_lenght_;
	pVertices[34].normal.x = 0;
	pVertices[34].normal.y = -1;
	pVertices[34].normal.z = 0;
	pVertices[34].u = 0;
	pVertices[34].v = 1;
	pVertices[34].colour = backgroundColour_;

	pVertices[35].position.x = cube_lenght_;
	pVertices[35].position.y = 0;
	pVertices[35].position.z = cube_lenght_;
	pVertices[35].normal.x = 0;
	pVertices[35].normal.y = -1;
	pVertices[35].normal.z = 0;
	pVertices[35].u = 1;
	pVertices[35].v = 1;
	pVertices[35].colour = backgroundColour_;


	// Unlock the vertex buffer...
	g_pVertexBufferCube->Unlock();

	//Initialise the textures
	LoadTextures(g_pd3dDevice);

	initializeUI(g_pd3dDevice);
}

///Function to draw the entire Rubik's Cube
void LittleCube::drawTheRB(LPDIRECT3DDEVICE9 g_pd3dDevice){
	
	D3DXMATRIX      TransformMatrix;
	D3DXQUATERNION  qR;
	D3DXVECTOR3 centerRotation;
	D3DXMatrixIdentity(&TransformMatrix);

	drawTheUI();

	g_pd3dDevice->SetStreamSource(0, returnTheCubeVertexBuffer(), 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);


	for (int floor = 0; floor < 3; floor++) {
		for (int row = 0; row < 3; row++)	{
			for (int col = 0; col < 3; col++) {

				if (col == 2) {
					centerRotation = calculateTheColumnCenter(floor, row, col);

					D3DXMatrixTransformation(&TransformMatrix, NULL, NULL, NULL, NULL, NULL, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &TransformMatrix);

					for (int i = 0; i < 6; ++i) {

						setTexture(g_pd3dDevice, floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive

					}

				}
				else {
					D3DXMatrixTransformation(&TransformMatrix, NULL, NULL, NULL, NULL, NULL, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &TransformMatrix);

					for (int i = 0; i < 6; ++i) {

						setTexture(g_pd3dDevice, floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive

					}

				}


				}
			}
		}
	}

void LittleCube::rotateTheColumn(LPDIRECT3DDEVICE9 g_pd3dDevice, float g_RotationAngle, int c)
{
	D3DXMATRIX      TransformMatrix;
	D3DXQUATERNION  qR;
	D3DXMatrixIdentity(&TransformMatrix);
	D3DXMATRIX matTranslate, rowCenter, originalPos, newPos;    // a matrix to store the translation informations
	D3DXMatrixIdentity(&matTranslate);
	D3DXMATRIX matRotateX;    // a matrix to store the rotation information
	D3DXVECTOR3 centerRotation;

	drawTheUI();

	g_pd3dDevice->SetStreamSource(0, returnTheCubeVertexBuffer(), 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);

	for (int floor = 0; floor < 3; floor++) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {

				//calculate the D3DXVECTOR3 with the coordinate of the rotation center
				centerRotation = calculateTheColumnCenter(floor, row, col);

				if (row == c) {

					D3DXQuaternionRotationAxis(&qR, &D3DXVECTOR3(0.0f, 0.0f, 1.0f), (-g_RotationAngle)*0.15);
					D3DXMatrixTranslation(&originalPos, originx_, originy_, originz_);
					D3DXMatrixMultiply(&matTranslate, &matTranslate, &rowCenter);
					D3DXMatrixIdentity(&matTranslate);
					D3DXMatrixMultiply(&matTranslate, &matTranslate, &originalPos);
					D3DXMatrixTransformation(&matTranslate, NULL, NULL, NULL, &centerRotation, &qR, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &matTranslate);


					for (int i = 0; i < 6; ++i) {


						setTexture(g_pd3dDevice,floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive
					}
		     	}

				else {

					D3DXMatrixTransformation(&TransformMatrix, NULL, NULL, NULL, NULL,  NULL, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &TransformMatrix);


					for (int i = 0; i < 6; ++i) {
						setTexture(g_pd3dDevice, floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive

					}

				}
			}
		}
	}


}

void LittleCube::rotateTheRow(LPDIRECT3DDEVICE9 g_pd3dDevice,float g_RotationAngle, int r)
{
	D3DXMATRIX      TransformMatrix;
	D3DXQUATERNION  qR;
	D3DXMatrixIdentity(&TransformMatrix);
	D3DXMATRIX matTranslate, rowCenter, originalPos, newPos;    // a matrix to store the translation informations
	D3DXMatrixIdentity(&matTranslate);
	D3DXMATRIX matRotateX;    // a matrix to store the rotation information
	D3DXVECTOR3 centerRotation;

	drawTheUI();

	g_pd3dDevice->SetStreamSource(0, returnTheCubeVertexBuffer(), 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);

	for (int floor = 0; floor < 3; floor++) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {

				//calculate the D3DXVECTOR3 with the coordinate of the rotation center
				centerRotation = calculateTheRowCenter(floor, row, col);

				if (floor == r) {

					D3DXQuaternionRotationAxis(&qR, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), g_RotationAngle*0.15);
					D3DXMatrixTranslation(&originalPos, originx_, originy_, originz_);
					D3DXMatrixMultiply(&matTranslate, &matTranslate, &rowCenter);
					D3DXMatrixIdentity(&matTranslate);
					D3DXMatrixMultiply(&matTranslate, &matTranslate, &originalPos);
					D3DXMatrixTransformation(&matTranslate, NULL, NULL, NULL, &centerRotation, &qR, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &matTranslate);
		

					for (int i = 0; i < 6; ++i) {

						setTexture(g_pd3dDevice,floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive
					}
				}

				else {
					D3DXMatrixTransformation(&TransformMatrix, NULL, NULL, NULL, NULL, NULL, &D3DXVECTOR3(originx_ + cube_lenght_*(float)col, originy_ + cube_lenght_*(float)floor, originz_ + cube_lenght_*(float)row));
					g_pd3dDevice->SetTransform(D3DTS_WORLD, &TransformMatrix);

					for (int i = 0; i < 6; ++i) {
						setTexture(g_pd3dDevice, floor, row, col, i);
						g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, i * 6, 2);  // using a D3DPT_TRIANGLELIST primitive

					}
				}
			}
		}
	}
	
}

void LittleCube::LoadTextures(LPDIRECT3DDEVICE9 g_pd3dDevice)
{

	D3DXCreateTextureFromFile(g_pd3dDevice, "Green_def.png",  &g_pTextures[0]);
	D3DXCreateTextureFromFile(g_pd3dDevice, "Red_def.png",    &g_pTextures[1]);
	D3DXCreateTextureFromFile(g_pd3dDevice, "White_def.png",  &g_pTextures[2]);
	D3DXCreateTextureFromFile(g_pd3dDevice, "Blue_def.png",   &g_pTextures[3]);
	D3DXCreateTextureFromFile(g_pd3dDevice, "Yellow_def.png", &g_pTextures[4]);
	D3DXCreateTextureFromFile(g_pd3dDevice, "Black_def.png",  &g_pTextures[5]);
}

HRESULT LittleCube::initializeUI(LPDIRECT3DDEVICE9 g_pd3dDevice)
{
	//Set the title
	font1 = NULL;
	D3DXCreateFont(g_pd3dDevice, 40, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font1);

	SetRect(&title_rectangle, 40, 70, 700, 700);
	title = "THE RUBIK'S CUBE ";


	//Set the instructions
	font2 = NULL;
	D3DXCreateFont(g_pd3dDevice, 17, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font2);

	SetRect(&instruction_rectangle, 40, 120, 800, 800);
	instruction = "Press the left and right arrows to change the column, press the up and down arrows to change the row \nPress 'R' to rotate the row, press 'C' to rotate the column ";


	return S_OK;
}

void LittleCube::drawTheUI()
{
	font1->DrawTextA(NULL, title.c_str(), -1, &title_rectangle, DT_LEFT, D3DCOLOR_XRGB(255, 255, 0));
	font2->DrawTextA(NULL, instruction.c_str(), -1, &instruction_rectangle, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	fontbb1->DrawTextA(NULL, billboard1.c_str(), -1, &billboard_rectangle1, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	fontbb2->DrawTextA(NULL, billboard2.c_str(), -1, &billboard_rectangle2, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
}

void LittleCube::setTheBillboard(LPDIRECT3DDEVICE9 g_pd3dDevice, int col, int row)
{
	///Set the row
	fontbb1 = NULL;
	D3DXCreateFont(g_pd3dDevice, 17, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &fontbb1);

	SetRect(&billboard_rectangle1, 40, 160, 800, 800);

	if (row == 0)
		billboard1 = "You are selecting the row number: 1";
	else if (row == 1)
		billboard1 = "You are selecting the row number: 2";
	else if (row == 2)
		billboard1 = "You are selecting the row number: 3";

	///Set the col
	fontbb2 = NULL;
	D3DXCreateFont(g_pd3dDevice, 17, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &fontbb2);

	SetRect(&billboard_rectangle2, 40, 175, 800, 800);

	if (col == 0)
		billboard2 = "You are selecting the col number: 1";
	else if (col == 1)
		billboard2 = "You are selecting the col number: 2";
	else if (col == 2)
		billboard2 = "You are selecting the col number: 3";
}

void LittleCube::cleanVertexBuffer()
{
	if (g_pVertexBufferCube != NULL) g_pVertexBufferCube->Release();
	if (g_pTextures != NULL) g_pTextures[6]->Release();
}

void LittleCube::readFromFile()

{
	std::string line;
	std::ifstream file;
	int x;
	file.open("textures.txt");
	int counter = 0;

	while (getline(file, line)) {

		std::istringstream is(line);
		is >> x;
		//texture_number.push_back(x);
		textures[counter] = x;
		++counter;

		if (counter == 12)
			int y = 0;
	}


	file.close();


}


int LittleCube::setTexture(LPDIRECT3DDEVICE9 g_pd3dDevice,int floor, int row, int col, int i )
{
	int n = 0;
	int cont = (((floor * 54) + (row * 18) + (col * 6)) + i);
	n = textures[cont];
	g_pd3dDevice->SetTexture(0, g_pTextures[n]);

	

	return n;
}

///Calculate the center of the selected row for the rotation
D3DXVECTOR3 LittleCube::calculateTheRowCenter(int floor, int row, int col)
{
	float centerx_ = 0.0f, centery_ = 0.0f, centerz_ = 0.0f;
	if (col == 0)
		centerx_ = 15.0f;
	else if(col == 1)
		centerx_ = 5.0f;
	else if (col == 2)
		centerx_ = -5.0f;

	if(row == 0)
		centerz_ = 15.0f;
	else if (row == 1)
		centerz_ = 5.0f;
	else if (row == 2)
		centerz_ = -5.0f;

	centery_ = 5.0;

	return D3DXVECTOR3(centerx_, centery_, centerz_);
}

///Calculate the center of the selected column for the rotation
D3DXVECTOR3 LittleCube::calculateTheColumnCenter(int floor, int row, int col)
{
	float centerx_ = 0.0f, centery_ = 0.0f, centerz_ = 0.0f;
	if (col == 0)
		centerx_ = 15.0f;
	else if (col == 1)
		centerx_ = 5.0f;
	else if (col == 2)
		centerx_ = -5.0f;

	if (floor == 0)
		centery_ = 15.0f;
	else if (floor == 1)
		centery_ = 5.0f;
	else if (floor == 2)
		centery_ = -5.0f;

	centerz_ = 5.0;

	return D3DXVECTOR3(centerx_, centery_, centerz_);
}

///Function to switch the texture of a row after the rotation
void LittleCube::changeRowTexture(int t)
{
	int counter = 54 * t;
	int c = 0;
	int index;

	int temp0, temp1, temp2, temp3, temp4, temp5;
	int temp10, temp11, temp12, temp13, temp14, temp15;

	for (int i = 0; i < 8; ++i) {

		if (i == 0) {

			//store old texture at index 2 in a temporary variable
			index = counter + 36 + 2;
			temp2 = textures[index];
			//new texture
			textures[index] = textures[counter + 3];

			//store old texture at index 3 in a temporary variable
			index = counter + 36 + 3;
			temp3 = textures[index];
			//new texture
			textures[index] = textures[counter];

			
			if (t == 2) {
				//store old texture at index 4 in a temporary variable
				index = counter + 36 + 4;
				temp4 = textures[index];
				//new texture 
				textures[index] = textures[counter + 4];
			}
			

			else if (t == 0) {
				//store old texture at index 5 in a temporary variable
				index = counter + 36 + 5;
				temp5 = textures[index];
				//new texture 
				textures[index] = textures[counter + 5];
			}


		}

		else if (i == 1) {


			//store old texture at index 2 in a temporary variable
			index = counter + 48 + 2;
			temp12 = textures[index];
			//new texture
			textures[index] = temp3;

			//store old texture at index 1 in a temporary variable
			index = counter + 48 + 1;
			temp11 = textures[index];
			//new texture
			textures[index] = temp2;

			
			if (t == 2) {
				//store old texture at index 4 in a temporary variable
				index = counter + 48 + 4;
				temp14 = textures[index];
				//new texture
				textures[index] = temp4;
			}

			else if (t == 0) {
				//store old texture at index 5 in a temporary variable
				index = counter + 48 + 5;
				temp15 = textures[index];
				//new texture
				textures[index] = temp5;

			}


		}

		else if (i == 2) {

			//store old texture at index 0 in a temporary variable
			index = counter + 12;
			temp0 = textures[index];
			//new texture
			textures[index] = temp11;

			//store old texture at index 1 in a temporary variable
			index = counter + 12 + 1;
			temp1 = textures[index];
			//new texture
			textures[index] = temp12;

			if (t == 2) {
				//store old texture at index 4 in a temporary variable
				index = counter + 12 + 4;
				temp4 = textures[index];
				//new texture
				textures[index] = temp14;
			}

			else if (t == 0) {
				//store old texture at index 5 in a temporary variable
				index = counter + 12 + 5;
				temp5 = textures[index];
				//new texture
				textures[index] = temp15;
			}
		}

		else if (i == 3) {			

			index = counter + 3;
			textures[index] = temp0;

			index = counter;
			textures[index] = temp1;

			
			if (t == 2) {
				index = counter + 4;
				textures[index] = temp4;
			}
				

			else if (t == 0) {
				index = counter + 5;
				textures[index + 1] = temp5;
			}
				

		}


		else if (i == 4) {

			//store old texture at index 3 in a temporary variable
			index = counter + 18 + 3;
			temp3 = textures[index];
			//new texture
			textures[index] = textures[counter + 6];

			

				if (t == 2) {
					index = counter + 18 + 4;
					temp4 = textures[index];
					//new texture 
					textures[index] = textures[counter + 6 + 4];
				}

				else if (t == 0) {
					//store old texture at index 5 in a temporary variable
					index = counter + 18 + 5;
					temp5 = textures[index];
					//new texture 
					textures[index] = textures[counter + 6 + 5];
				}
		}

		else if (i == 5) {

			//store old texture at index 2 in a temporary variable
			index = counter + 42 + 2;
			temp12 = textures[index];
			//new texture 
			textures[index] = temp3;

			
			if (t == 2) {
				//store old texture at index 4 in a temporary variable
				index = counter + 42 + 4;
				temp14 = textures[index];
				//new texture 
				textures[index] = temp4;
			}
			else if (t == 0) {
				//store old texture at index 5 in a temporary variable
				index = counter + 42 + 5;
				temp15 = textures[index];
				//new texture 
				textures[index + 1] = temp5;
			}
		}

		else if (i == 6) {

			//store old texture at index 1 in a temporary variable
			index = counter + 30 + 1;
			temp1 = textures[index];
			//new texture 
			textures[index] = temp12;

			if (t == 2) {
				//store old texture at index 4 in a temporary variable
				index = counter + 30 + 4;
				temp4 = textures[index];
				//new texture 
				textures[index] = temp14;
			}

			else if (t == 0) {
				//store old texture at index 4 in a temporary variable
				index = counter + 30 + 5;
				temp5 = textures[index];
				//new texture 
				textures[index] = temp15;
			}

		}

		else if (i == 7) {

			index = counter + 6;
			textures[index] = temp1;

			index = counter + 6 + 4;

			if (t == 2) {
				
				textures[index] = temp4;
			}
			

			else if (t == 0)
				
				textures[index + 1] = temp5;
		}
		
	}
}

///Function to switch the texture of a column after the rotation
void LittleCube::changeColumnTexture(int i)
{
	int counter = 18 * i;
	int c = 0;
	int index;

	int temp0, temp1, temp2, temp3, temp4, temp5;
	int temp10, temp11, temp12, temp13, temp14, temp15;


	for (int i = 0; i < 8; ++i) {
	
		if (i == 0) {
			//store old texture at index 0
			index = counter + 108;
			temp0 = textures[index];
			//new texture
			textures[index] = textures[counter];

			//store old texture at index 3
			index = counter + 108 + 3;
			temp3 = textures[index];
			//new texture
			textures[index] = textures[counter + 5];

			//store old texture at index 4
			index = counter + 108 + 4;
			temp4 = textures[index];
			//new texture
			textures[index] = textures[counter + 3];
		}

		else if (i == 1) {
			//store old texture at index 0
			index = counter + 120;
			temp10 = textures[index];
			//new texture
			textures[index] = temp0;

			//store old texture at index 4
			index = counter + 120 + 4;
			temp14 = textures[index];
			//new texture
			textures[index] = temp3;

			//store old texture at index 1
			index = counter + 120 + 1;
			temp11 = textures[index];
			//new texture
			textures[index] = temp4;
		}

		else if (i == 2) {
			//store old texture at index 0
			index = counter + 12;
			temp0 = textures[index];
			//new texture
			textures[index] = temp10;

			//store old texture at index 1
			index = counter + 12 + 1;
			temp1 = textures[index];
			//new texture
			textures[index] = temp14;

			//store old texture at index 5
			index = counter + 12 + 5;
			temp5 = textures[index];
			//new texture
			textures[index] = temp11;
		}

		else if (i == 3) {

			index = counter;
			textures[index] = temp0;
			textures[index + 3] = temp5;
			textures[index + 5] = temp1;

		}

		else if (i == 4) {
			//store old texture at index 0
			index = counter + 114;
			temp0 = textures[index];
			//new texture
			textures[index] = textures[counter + 54];

			//store old texture at index 4
			index = counter + 114 + 4;
			temp4 = textures[index];
			//new texture
			textures[index] = textures[counter + 3 + 54];
		}

		else if (i == 5) {
			//store old texture at index 0
			index = counter + 66;
			temp10 = textures[index];
			//new texture
			textures[index] = temp0;

			//store old texture at index 1
			index = counter + 66 + 1;
			temp11 = textures[index];
			//new texture
			textures[index] = temp4;
			
		}

		else if (i == 6) {
			//store old texture at index 0
			index = counter + 6;
			temp0 = textures[index];
			//new texture
			textures[index] = temp10;

			//store old texture at index 5
			index = counter + 6 + 5;
			temp5 = textures[index];
			//new texture
			textures[index] = temp11;

		}

		else if (i == 7) {

			index = counter + 54;
			textures[index] = temp0;
			textures[index + 3] = temp5;

		}
	}

}

