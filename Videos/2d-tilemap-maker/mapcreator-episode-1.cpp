#define GLM_ENABLE_EXPERIMENTAL
#include "gameLayer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "platformInput.h"
#include "imgui.h"
#include <iostream>
#include <sstream>
#include "imfilebrowser.h"
#include <gl2d/gl2d.h>
#include <platformTools.h>
#include <IconsForkAwesome.h>
#include <imguiTools.h>
#include <logs.h>

#define MAP_TILE_COUNT 17

#define MAP_WIDTH 100
#define MAP_HEIGHT 100
#define TILE_SIZE 64

int map[MAP_WIDTH][MAP_HEIGHT] = {};

struct GameData
{
	glm::vec2 rectPos = {100,100};

}gameData;

gl2d::Renderer2D renderer;
gl2d::Texture tiles[MAP_TILE_COUNT];

int selectedtile = 0;

void exportMap()
{
	std::cout << "# Start Map\n";

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			int tile = map[i][j];

			std::cout << tile;
			std::cout << " ";
		}

		std::cout << "\n";
	}

	std::cout << "# Start End\n";
}

bool initGame()
{
	//initializing stuff for the renderer
	gl2d::init();
	renderer.create();

	//loading the saved data. Loading an entire structure like this makes savind game data very easy.
	platform::readEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

	platform::log("Init");

	tiles[1].loadFromFile(RESOURCES_PATH "map/floor_1.png");
	tiles[2].loadFromFile(RESOURCES_PATH "map/floor_2.png");
	tiles[3].loadFromFile(RESOURCES_PATH "map/floor_3.png");
	tiles[4].loadFromFile(RESOURCES_PATH "map/floor_4.png");
	tiles[5].loadFromFile(RESOURCES_PATH "map/floor_5.png");
	tiles[6].loadFromFile(RESOURCES_PATH "map/floor_6.png");
	tiles[7].loadFromFile(RESOURCES_PATH "map/floor_7.png");
	tiles[8].loadFromFile(RESOURCES_PATH "map/floor_8.png");
	tiles[9].loadFromFile(RESOURCES_PATH "map/floor_9.png");
	tiles[10].loadFromFile(RESOURCES_PATH "map/floor_10.png");
	tiles[11].loadFromFile(RESOURCES_PATH "map/wall_bottom.png");
	tiles[12].loadFromFile(RESOURCES_PATH "map/wall_top_inner_left_2.png");
	tiles[13].loadFromFile(RESOURCES_PATH "map/wall_top_inner_right_2.png");
	tiles[14].loadFromFile(RESOURCES_PATH "map/wall_top_left.png");
	tiles[15].loadFromFile(RESOURCES_PATH "map/wall_top_right.png");
	tiles[16].loadFromFile(RESOURCES_PATH "map/wall_top_1.png");

	return true;
}


//IMPORTANT NOTICE, IF YOU WANT TO SHIP THE GAME TO ANOTHER PC READ THE README.MD IN THE GITHUB
//https://github.com/meemknight/cmakeSetup
//OR THE INSTRUCTION IN THE CMAKE FILE.
//YOU HAVE TO CHANGE A FLAG IN THE CMAKE SO THAT RESOURCES_PATH POINTS TO RELATIVE PATHS
//BECAUSE OF SOME CMAKE PROGBLMS, RESOURCES_PATH IS SET TO BE ABSOLUTE DURING PRODUCTION FOR MAKING IT EASIER.

bool gameLogic(float deltaTime, platform::Input &input)
{
#pragma region init stuff
	int w = 0; int h = 0;
	w = platform::getFrameBufferSizeX(); //window w
	h = platform::getFrameBufferSizeY(); //window h
	
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT); //clear screen

	renderer.updateWindowMetrics(w, h);
#pragma endregion

	int MouX = input.mouseX;
	int MouY = input.mouseY;

	//you can also do platform::isButtonHeld(platform::Button::Left)

	/*if (input.isButtonHeld(platform::Button::Left))
	{
		gameData.rectPos.x -= deltaTime * 100;
	}
	if (input.isButtonHeld(platform::Button::Right))
	{
		gameData.rectPos.x += deltaTime * 100;
	}
	if (input.isButtonHeld(platform::Button::Up))
	{
		gameData.rectPos.y -= deltaTime * 100;
	}
	if (input.isButtonHeld(platform::Button::Down))
	{
		gameData.rectPos.y += deltaTime * 100;
	}

	gameData.rectPos = glm::clamp(gameData.rectPos, glm::vec2{0,0}, glm::vec2{w - 100,h - 100});
	renderer.renderRectangle({gameData.rectPos, 100, 100}, Colors_Blue);*/


	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			int tile = map[i][j];

			if (tile == 0)
			{
				renderer.renderRectangle({ i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE },
					Colors_Black);
				continue;
			}

			renderer.renderRectangle({ i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE },
				tiles[tile],
				Colors_White, {});
		}
	}

	// Draw the Map
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			int tileX = MouX / TILE_SIZE;
			int tileY = MouY / TILE_SIZE;

			if (tileX >= 0 && tileX < MAP_WIDTH &&
				tileY >= 0 && tileY < MAP_HEIGHT)
			{
				if (input.rMouse.held)
				{
					renderer.renderRectangle({ tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE },
						Colors_Blue);
					map[tileX][tileY] = selectedtile;
					continue;
				}
				renderer.renderRectangle({ tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE },
					Colors_Red);
			}	
		}
	}

	renderer.flush();


	//ImGui::ShowDemoWindow();
	ImGui::PushMakeWindowNotTransparent();
	ImGui::Begin("Tile Selector");

	for (int i = 0; i < MAP_TILE_COUNT; i++)
	{
		std::string idname = std::string("##tile_") + std::to_string(i);

		if (ImGui::ImageButton(idname.c_str(),
			(ImTextureID)(intptr_t)tiles[i].id,
			ImVec2(64, 64)
		))
		{
			selectedtile = i;
		}

		if ((i + 1) % 4 != 0)
		{
			ImGui::SameLine();
		}
	}

	ImGui::End();

	ImGui::Begin("Debug");
	ImGui::Text("Selected Tile %i", selectedtile);
	if (ImGui::Button("Export Map"))
	{
		exportMap();
	}
	ImGui::End();

	ImGui::PopMakeWindowNotTransparent();

	return true;
#pragma endregion

}

//This function might not be be called if the program is forced closed
void closeGame()
{

	//saved the data.
	platform::writeEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

}
