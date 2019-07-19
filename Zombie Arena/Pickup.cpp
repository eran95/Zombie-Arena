#include "Pickup.h"
#include "TextureHolder.h"

Pickup::Pickup(int type)
{
	// Store this pickup's type
	m_Type = type;
	// Associate the texture with the right sprite
	if (m_Type == 1)
	{
		m_Sprite =
			Sprite(TextureHolder::GetTexture("Graphics/health_pickup.png"));
		// How much this pickup is worth
		m_Value = HEALTH_START_VALUE;
	}
	else
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/ammo_pickup.png"));
		// How much is pickup worth
		m_Value = AMMO_START_VALUE;
	}
	m_SecondsToLive = START_SECONDS_TO_LIVE;
	m_SecondsToWait = START_WAIT_TIME;
}

void Pickup::setArena(IntRect arena)
{
	// Copy the details of the arena to the pickup's m_Arena
	m_Arena.left = arena.left + 50;
	m_Arena.width = arena.width - 50;
	m_Arena.top = arena.top + 50;
	m_Arena.height = arena.height - 50;
	spawn();
}

void Pickup::spawn()
{
	// Spawn at a random location
	srand((int)time(0) / m_Type);
	int x = (rand() % m_Arena.width);
	srand((int)time(0) * m_Type);
	int y = (rand() % m_Arena.height);
	m_SecondsSinceSpawn = 0;
	m_Spawned = true;
	m_Sprite.setPosition(x, y);
}
{
	return m_Sprite.getGlobalBounds();
}
Sprite Pickup::getSprite()
{
	return m_Sprite;
}
bool Pickup::isSpawned()
{
	return m_Spawned;
}
{
	m_Spawned = false;
	m_SecondsSinceDeSpawn = 0;
	return m_Value;
}
{
	if (m_Type == 1)
	{
		m_Value += (HEALTH_START_VALUE * .5);
	}
	else
	{
		m_Value += (AMMO_START_VALUE * .5);
	}
	// Make them more frequent and last longer
	m_SecondsToLive += (START_SECONDS_TO_LIVE / 10);
	m_SecondsToWait -= (START_WAIT_TIME / 10);
}