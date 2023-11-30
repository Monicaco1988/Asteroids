#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Rigidbody.h"
#include "Asteroid.h"
#include "Ship.h"

int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;

int asteroidAmount = 5;

RigidBody** rigidbody; // look this up online

//RigidBody *rigidbody = nullptr;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );

	rigidbody = new RigidBody * [asteroidAmount +2]; // allocating space in RigidBody in memory Only delete what you allocate with new.
	rigidbody[0] = new Ship(); // int the allocated dynamic memory the first space is made for the array, jag kommer anv�nda detta som min instantierade
	// "ship" d� jag kalla alla mina object f�r rigidBodies! Only delete what you allocate with new.
	
	//rigidbody[1] = new Asteroid();

	for (int i = 1; i <= asteroidAmount; i++)
	{
		rigidbody[i] = new Asteroid();
	}
	//delete rigidBody; Ask about this ----------------------------------------
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack );

	for (int i = 1; i <= asteroidAmount; i++)
	{
		rigidbody[i]->DrawObject();

		rigidbody[i]->SpeedObject();

		rigidbody[i]->PhysicsGameUpdate();

	};

	Play::CentreSpriteOrigin("Asteroid");
	
	//Ship [0]

	rigidbody[0]->PhysicsGameUpdate();
	
	rigidbody[0]->DrawObject(); // using the arrow points to the function of the specific place in memory, kolla upp hur -> funkar ocks�, n�r jag kan och inte kan anv�nda dem

	Play::CentreSpriteOrigin("Ship"); // Nice

	Play::PresentDrawingBuffer();
	
	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	
	Play::DestroyManager();
	return PLAY_OK;
}



