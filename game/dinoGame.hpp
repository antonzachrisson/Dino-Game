#pragma once

#include <papaya.hpp>

#include "dino.hpp"
#include "bg.hpp"
#include "smallobstacle.hpp"
#include "bigobstacle.hpp"

using namespace papaya;

class dinoGame
{
public:
	dinoGame(Runtime& runtime);
	~dinoGame();
	enum State_
	{
		menu,
		play,
		dead
	};
	bool Update(float deltatime);
	void Render();
	void setState(dinoGame::State_ state_);
	dinoGame::State_ getState();
	Runtime runtime_;
	int score[5];
	int score_;
	Key interactionKey;
	Vertex verticesNum[5][4];
	Vertex verticesHigh[5][4];
	dino* dino_;
	bg* bg_;
	bigobstacle* bigs[10];
	smallobstacle* smalls[10];
	const Texture* numTextures[5];
	const Texture* highTextures[5];
private:
	State_ state;
	void jump();
	void spawn();
	void moveObs();
	void checkCollision();
	void Score();
	bool Init();
	Vector2 pos;
	Sprite dinoSprite;
	Transform dinoTransform;
	float elapsedJump;
	float elapsed;
	float elapsedSpawn;
	float elapsedScore;
	float distance;
	float randSpawn;
	Random rand;
	bool jumping;
	int numBig;
	int numSmall;
	const Texture* dinoTexture;
	const Texture* bgTexture;
	const Texture* groundTexture;
	const Texture* bigTexture;
	const Texture* smallTexture;
	const Texture* menuTexture;
	const Texture* deadTexture;
};
