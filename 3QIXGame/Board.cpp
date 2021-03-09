#include "DXUT.h"
#include "Board.h"

int Board::CheckBoard(int _posX, int _posY)
{
	int score = 0;
	if ((pixels[_posX][_posY]->state == CLEARED) || (pixels[_posX][_posY]->state == WALL) || (pixels[_posX][_posY]->state == PATH))
	{
		checkedPixels[_posX][_posY] = true;
	}

	score += CheckBoard(_posX + 1, _posY);
	score += CheckBoard(_posX - 1, _posY);
	score += CheckBoard(_posX, _posY + 1);
	score += CheckBoard(_posX, _posY - 1);

	return score;
}

Board::Board(void)
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			pixels[i][j] = new Pixel();
			pixels[i][j]->position =
			{ 300 + ((float)i * 13),
			  20 + ((float)j * 13) };
			pixels[i][j]->state = NONE;
		}
	}

	for (int i = 0; i < 50; ++i)
	{
		pixels[i][0]->state = WALL;
		pixels[i][49]->state = WALL;
		pixels[0][i]->state = WALL;
		pixels[49][i]->state = WALL;
	}

	layer = -1;
	SetTexture(L"Pixel.png");
}

Board::~Board(void)
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			delete pixels[i][j];
		}
	}
}

void Board::Update(void)
{
	if (DXUTIsKeyDown('W'))
	{
		backposX = playerX;
		backposY = playerY;
		playerY -= 1;
		if (playerY < 0)
			playerY = 0;
	}
	else if (DXUTIsKeyDown('S'))
	{
		backposX = playerX;
		backposY = playerY;
		playerY += 1;
		if (playerY > 49)
			playerY = 49;
	}
	else if (DXUTIsKeyDown('A'))
	{
		backposX = playerX;
		backposY = playerY;
		playerX -= 1;
		if (playerX < 0)
			playerX = 0;
	}
	else if (DXUTIsKeyDown('D'))
	{
		backposX = playerX;
		backposY = playerY;
		playerX += 1;
		if (playerX > 49)
			playerX = 49;
	}

	if (isCutting == false && pixels[playerX][playerY]->state == NONE)
	{
		isCutting = true;
		pathStartposX = backposX;
		pathStartposY = backposY;
	}

	if (isCutting == true)
	{
		if (pixels[backposX][backposY]->state == NONE)
			pixels[backposX][backposY]->state = PATH;

		if (pixels[playerX][playerY]->state == PATH)
		{
			playerX = pathStartposX;
			playerY = pathStartposY;
			isCutting = false;
			
			// PATH 초기화
			for (int i = 0; i < 50; ++i)
			{
				for (int j = 0; j < 50; ++j)
				{
					if (pixels[i][j]->state == PATH)
					{
						pixels[i][j]->state = NONE;
					}
				}
			}
		}

		if ((pixels[playerX][playerY]->state == WALL) || (pixels[playerX][playerY]->state == CLEARED))
		{
			isCutting = false;
			// 임의의 path 하나 설정해서
			// 위 아래 탐색 -> flood fill
		}
	}

	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			switch (pixels[i][j]->state)
			{
			case NONE:
				pixels[i][j]->color = D3DCOLOR_RGBA(255, 255, 255, 255);
				break;
			case WALL:
				pixels[i][j]->color = D3DCOLOR_RGBA(255, 0, 0, 255);
				break;
			case PATH:
				pixels[i][j]->color = D3DCOLOR_RGBA(0, 255, 0, 255);
				break;
			case CLEARED:
				pixels[i][j]->color = D3DCOLOR_RGBA(0, 0, 255, 255);
				break;
			default:
				break;
			}
		}
	}

	if (showplayerpos == true)
		pixels[playerX][playerY]->color = D3DCOLOR_RGBA(100, 100, 100, 255);

	if (DXUTWasKeyPressed('L'))
		showplayerpos = !showplayerpos;

	cout << backposX << " " << backposY << endl;
}
