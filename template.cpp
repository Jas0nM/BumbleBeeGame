// Includes
#include "template.h"

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor(0,0,0 ); // black
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	background = agk::LoadSprite("media/background.jpg");
	bumbleBee = agk::LoadSprite("media/bumble.png");
}

int app::Loop (void)
{
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
