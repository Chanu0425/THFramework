#include "DXUT.h"
#include "Board.h"

void Board::CheckBoard(int _posX, int _posY, int _index)
{
	if (checkedPixels[_posX][_posY] == true)
		return;

	checkedPixels[_posX][_posY] = true;

	if ((pixels[_posX][_posY]->state == CLEARED) ||
		(pixels[_posX][_posY]->state == WALL) ||
		(pixels[_posX][_posY]->state == PATH) ||
		(pixels[_posX][_posY]->state == OBSTICLE))
	{
		return;
	}

	if (_index == 0)
		clear1.emplace_back(pixels[_posX][_posY]);
	else
		clear2.emplace_back(pixels[_posX][_posY]);

	CheckBoard(_posX + 1, _posY, _index);
	CheckBoard(_posX - 1, _posY, _index);
	CheckBoard(_posX, _posY + 1, _index);
	CheckBoard(_posX, _posY - 1, _index);

	return;
}

void Board::SpawnObsticle(int _posX, int _posY, OBSTICLETAG _tag)
{
	switch (_tag)
	{
	case OBRECT:
		pixels[_posX][_posY]->state = OBSTICLE;
		pixels[_posX + 1][_posY]->state = OBSTICLE;
		pixels[_posX][_posY + 1]->state = OBSTICLE;
		pixels[_posX + 1][_posY + 1]->state = OBSTICLE;
		break;
	case OBT:
		pixels[_posX][_posY]->state = OBSTICLE;
		pixels[_posX + 1][_posY]->state = OBSTICLE;
		pixels[_posX + 2][_posY]->state = OBSTICLE;
		pixels[_posX + 1][_posY + 1]->state = OBSTICLE;
		break;
	case OBI:
		pixels[_posX][_posY]->state = OBSTICLE;
		pixels[_posX + 1][_posY]->state = OBSTICLE;
		pixels[_posX + 2][_posY]->state = OBSTICLE;
		pixels[_posX + 3][_posY]->state = OBSTICLE;
		break;
	default:
		break;
	}
}

void Board::CheckPathAndVirusCollision(std::vector<std::pair<int, int>> _viruspos)
{
	for (auto& it : paths)
	{
		for (int i = 0; i < _viruspos.size(); ++i)
		{
			if (it->indexX == _viruspos[i].first &&
				it->indexY == _viruspos[i].second)
			{
				playerX = pathStartposX;
				playerY = pathStartposY;
				--vim->HP;
				isCutting = false;

				for (auto& it : paths)
					it->state = NONE;

				paths.clear();
				return;
			}
		}
	}
}

Board::Board(void)
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			pixels[i][j] = new Pixel();
			pixels[i][j]->indexX = i;
			pixels[i][j]->indexY = j;
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

	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			checkedPixels[i][j] = false;
		}
	}

	// 200 = 4 * 50 �� ��ֹ��� �� 10���� �����ϴ�.

	for (int i = 0; i < 10; ++i)
	{
		int x = 4 + (rand() % 41);
		int y = 4 + (rand() % 41);
		int tag = rand() % 3;
		SpawnObsticle(x, y, (OBSTICLETAG)tag);
	}

	vim = new VIM();

	layer = -1; // �Ű澲������
	SetTexture(L"Pixel.png"); // �Ű澲������ ��������

	item[0] = 3;
	item[1] = 3;
	item[2] = 1;
	item[3] = 2;
	item[4] = 5;

	ItemManager::GetInstance()->CreateItem();
	VirusManager::GetInstance()->CreateVirus();

	VirusManager::GetInstance()->SpawnVirus(pixels[0][20]->position, pixels[0][20]->indexX, pixels[0][20]->indexY, SPEEDVIRUS);
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
	delete vim;
	ItemManager::GetInstance()->DeleteItem();
	VirusManager::GetInstance()->DeleteVirus();
}

void Board::Update(void)
{
	ItemManager::GetInstance()->CheckItem(playerX, playerY, vim);
	std::vector<std::pair<int, int>> viruspos = VirusManager::GetInstance()->GetVirusPositions();

	if (deltatime <= 0)
	{
		if (DXUTIsKeyDown('W'))
		{
			backposX = playerX;
			backposY = playerY;
			direction = UPDOWN;
			playerY -= 1;
			if (playerY < 0)
				playerY = 0;
		}
		else if (DXUTIsKeyDown('S'))
		{
			backposX = playerX;
			backposY = playerY;
			direction = UPDOWN;
			playerY += 1;
			if (playerY > 49)
				playerY = 49;
		}
		else if (DXUTIsKeyDown('A'))
		{
			backposX = playerX;
			backposY = playerY;
			direction = LEFTRIGHT;
			playerX -= 1;
			if (playerX < 0)
				playerX = 0;
		}
		else if (DXUTIsKeyDown('D'))
		{
			backposX = playerX;
			backposY = playerY;
			direction = LEFTRIGHT;
			playerX += 1;
			if (playerX > 49)
				playerX = 49;
		}
		deltatime = vim->movementspeed;
	}
	else
	{
		deltatime -= DXUTGetElapsedTime();
	}

	if (isCutting == false && pixels[playerX][playerY]->state == NONE)
	{
		// �ڸ��� �����ߴ�!
		isCutting = true;
		pathStartposX = backposX;
		pathStartposY = backposY;
	}

	if (isCutting == true)
	{
		CheckPathAndVirusCollision(viruspos); // ���⼭ path Ŭ����κп��� ����. ���ľ���

		if (pixels[backposX][backposY]->state == NONE)
		{
			pixels[backposX][backposY]->state = PATH;
			pixels[backposX][backposY]->direction = direction;
			paths.emplace_back(pixels[backposX][backposY]);
		}

		if (pixels[playerX][playerY]->state == PATH || pixels[playerX][playerY]->state == OBSTICLE)
		{
			// HP ���
			if (pixels[playerX][playerY]->state == OBSTICLE)
				--vim->HP;

			playerX = pathStartposX;
			playerY = pathStartposY;
			isCutting = false;

			// PATH �ʱ�ȭ
			for (auto& it : paths)
			{
				it->state = NONE;
			}

			paths.clear();
		}
	}

	if (pixels[playerX][playerY]->state == OBSTICLE)
	{
		playerX = backposX;
		playerY = backposY;
	}

	if (isCutting == true && (pixels[playerX][playerY]->state == WALL) || (pixels[playerX][playerY]->state == CLEARED))
	{
		isCutting = false;
		for (auto& it : paths)
		{
			bool check = false;
			if (it->direction == UPDOWN)
			{
				// �翷�� ��������� �� �ȼ��� �߽����� Ž��
				if ((pixels[it->indexX + 1][it->indexY]->state == NONE) &&
					(pixels[it->indexX - 1][it->indexY]->state == NONE))
				{
					check = true;
				}
			}
			else
			{
				// ���Ʒ��� ��������� �� �ȼ��� �߽����� Ž��
				if ((pixels[it->indexX][it->indexY + 1]->state == NONE) &&
					(pixels[it->indexX][it->indexY - 1]->state == NONE))
				{
					check = true;
				}
			}

			if (check == true)
			{
				if (it->direction == UPDOWN)
				{
					CheckBoard(it->indexX + 1, it->indexY, 0);
					CheckBoard(it->indexX - 1, it->indexY, 1);
				}
				else
				{
					CheckBoard(it->indexX, it->indexY + 1, 0);
					CheckBoard(it->indexX, it->indexY - 1, 1);
				}

				if (clear1.size() > clear2.size()) // �� ������ ä���!!
				{
					// ���� Cleared�� pixel���� ����
					score += clear2.size();
					for (auto& it : clear2)
					{
						it->state = CLEARED;
					}

					// �ϴ� ���� �� �����Ǿ�������
					if (item[0] == 0 &&
						item[1] == 0 &&
						item[2] == 0 &&
						item[3] == 0 &&
						item[4] == 0)
					{
						// ������ ������ �ȵ�. ���� ����ְ������ ����ٰ�
					}
					// �������� �� �� �������� ���� �� ������
					// �װ� �ƴ϶� �������� �̹� �� �����Ǿ������� �ٽ� ������
					else
					{
						int ind = rand() % 5;
						while (item[ind] == 0)
						{
							ind = rand() % 5;
							if (item[ind] != 0)
								break;
						}
						--item[ind];
						// index�� �ش��ϴ� ������ ����
						auto iter = paths.front();
						ItemManager::GetInstance()->SpawnItem(iter->position, iter->indexX, iter->indexY, (ITEMTAG)ind);
					}
				}
				else
				{
					// ���� Cleared�� pixel���� ����
					score += clear1.size();
					for (auto& it : clear1)
					{
						it->state = CLEARED;
					}

					if (item[0] == 0 &&
						item[1] == 0 &&
						item[2] == 0 &&
						item[3] == 0 &&
						item[4] == 0)
					{
						// ������ ���� �ȵ�.
					}
					// �������� �� �� �������� ���� �� ������
					// �װ� �ƴ϶� �������� �̹� �� �����Ǿ������� �ٽ� ������
					else
					{
						int ind = rand() % 5;
						while (item[ind] == 0)
						{
							ind = rand() % 5;
							if (item[ind] != 0)
								break;
						}
						--item[ind];
						// ������ ����
						auto iter = paths.front();
						ItemManager::GetInstance()->SpawnItem(iter->position, iter->indexX, iter->indexY, (ITEMTAG)ind);
					}
				}

				clear1.clear();
				clear2.clear();

				for (int i = 0; i < 50; ++i)
				{
					for (int j = 0; j < 50; ++j)
					{
						checkedPixels[i][j] = false;
					}
				}
			}
		}

		// ���� Cleared�� pixel���� ����
		score += paths.size();
		for (auto& it : paths)
		{
			it->state = CLEARED;
		}
		paths.clear();
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
			case OBSTICLE:
				pixels[i][j]->color = D3DCOLOR_RGBA(255, 0, 255, 255);
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

	for (auto& it : paths)
	{
		if (it->direction == UPDOWN)
		{
			it->color = D3DCOLOR_RGBA(0, 0, 255, 255);
		}
		else
		{
			it->color = D3DCOLOR_RGBA(200, 200, 0, 255);
		}
	}

	for (int i = 0; i < viruspos.size(); ++i)
	{
		pixels[viruspos[i].first][viruspos[i].second]->color = D3DCOLOR_RGBA(128, 0, 128, 255);
	}

	if (DXUTWasKeyPressed('L'))
		showplayerpos = !showplayerpos;

	if (DXUTWasKeyPressed('O'))
	{
		std::cout << "----" << std::endl;
		for (int i = 0; i < 5; ++i)
			std::cout << i << " " << item[i] << std::endl;
		std::cout << "----" << std::endl;
	}

	//isCutting == true ? cout << "YES" << endl : cout << "NO" << endl;
	if (score >= 2000) //��ֹ��� 2500���� �ȼ��� �ӿ��� 500�� �̸��̾����.
	{
		std::cout << "CLEAR" << std::endl;
	}
}

void Board::SetDifficulty(int _val)
{
	difficulty = _val;
	VirusManager::GetInstance()->SetDifficulty(_val);
}
