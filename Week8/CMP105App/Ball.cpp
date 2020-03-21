#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 1200)
	{
		setPosition(1200, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}
	if (getPosition().y > 675)
	{
		setPosition(getPosition().x, 675);
		velocity.y = -velocity.y;
	}
}

void Ball::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
	velocity.y = -velocity.y;
}