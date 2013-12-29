#include "Player.h"

void Player::update( float dt )
{
    //The position from the previous frame is now
    //the old position

    shipPrevPosition = shipCurrPosition;

    //The ship now has a new position if there was movement.
    //Delta time is used to ensure consistent speed on all types
    //of hardware game is played on.

    shipCurrPosition.x += ( shipVelocity.x * dt );
    shipCurrPosition.y += ( shipVelocity.y * dt );

    //Check physics

    updateRect();

    //Display player
}

void Player::move()
{
    //Move player around according to key pressed

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
    {
        shipVelocity.x -= 2.0f;
    }

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
    {
        shipVelocity.x += 2.0f;
    }

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
    {
        shipVelocity.y -= 2.0f;
    }

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
    {
        shipVelocity.y += 2.0f;
    }
}

void Player::attack( Ship &ship )
{
    //Attack an enemy with the current equipped weapon

    switch ( shipWeapon )
    {
    case FIRST:
        {
            //ship.takeDamage( xxx );
        }
        break;

    case SECOND:
        {
            //ship.takeDamage( xxx );
        }
        break;

    case THIRD:
        {
            //ship.takeDamage( xxx );
        }
        break;

    default:
        break;
    }
}
