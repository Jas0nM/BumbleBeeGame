// Includes
#include "template.h"

app App;

const float app::playerSpeed = 400.0f;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor(0,0,0 ); // black
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	agk::SetWindowAllowResize(0);
	agk::SetWindowTitle("Bumblebee Game");
	background = agk::LoadSprite("media/background.jpg");
	bumbleBee = agk::LoadSprite("media/bumble.png");
	playerX = agk::GetVirtualWidth() / 2.0f;
	playerY = agk::GetVirtualHeight() / 2.0f;
}

int app::Loop (void)
{
	
	float const moveThisFrame = playerSpeed * agk::GetFrameTime();

	if (agk::GetRawKeyState(AGK_KEY_UP)) {
		playerY -= moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_DOWN)) {
		playerY += moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_LEFT)) {
		playerX -= moveThisFrame;
		agk::SetSpriteFlip(bumbleBee, 1, 0);
	}
	if (agk::GetRawKeyState(AGK_KEY_RIGHT)) {
		playerX += moveThisFrame;
		agk::SetSpriteFlip(bumbleBee, 0, 0);
	}

	const float minX = agk::GetSpriteWidth(bumbleBee) / 2;
	const float maxX = agk::GetVirtualWidth() - minX;
	const float minY = agk::GetSpriteHeight(bumbleBee) / 2;
	const float maxY = agk::GetVirtualHeight() - minY;

	if (playerX < minX) {
		playerX = minX;
	}
	else if (playerX > maxX) {
		playerX = maxX;
	}

	if (playerY < minY) {
		playerY = minY;
	}
	else if (playerY > maxY) {
		playerY = maxY;
	}

	agk::SetSpritePositionByOffset(bumbleBee, playerX, playerY);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
