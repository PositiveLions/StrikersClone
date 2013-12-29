#include "Ship.h"

Ship::Ship()
{
    //Default constructor

    shipTexture  = 0;
    shipSprite   = 0;
    shipCurrPosition = sf::Vector2f( 0, 0 );
    shipPrevPosition = sf::Vector2f( 0, 0 );
    shipVelocity = sf::Vector2f( 0, 0 );

    //Default values for health and shields

    shipHealth = 100;
    shipShield = 100;

    shipState  = STATIONARY;
    shipWeapon = FIRST;

    shipRectPosition = sf::Vector2i( shipCurrPosition.x, shipCurrPosition.y );
    shipRectSize     = sf::Vector2i( 1, 1 );
    shipRect         = sf::IntRect( shipRectPosition, shipRectSize );
}

Ship::Ship( sf::Texture &texture )
{
    shipTexture = new sf::Texture( texture );           //Sets the objects texture
    shipSprite  = new sf::Sprite( *shipTexture );        //Sets the texture to the sprite object

    shipCurrPosition = sf::Vector2f( 0, 0 );
    shipPrevPosition = sf::Vector2f( 0, 0 );
    shipVelocity     = sf::Vector2f( 0, 0 );

    shipHealth = 100;
    shipShield = 100;

    shipState  = STATIONARY;
    shipWeapon = FIRST;

    shipRectPosition = sf::Vector2i( shipCurrPosition.x, shipCurrPosition.y );
    shipRectSize     = sf::Vector2i( shipTexture -> getSize().x, shipTexture -> getSize().y );
    shipRect         = sf::IntRect( shipRectPosition, shipRectSize );
}

Ship::Ship( sf::Texture &texture, sf::Vector2f position )
{
    shipTexture = new sf::Texture( texture );
    shipSprite  = new sf::Sprite( *shipTexture );

    shipCurrPosition = position;
    shipPrevPosition = sf::Vector2f( 0, 0 );
    shipVelocity     = sf::Vector2f( 0, 0 );

    shipHealth = 100;
    shipShield = 100;

    shipState  = STATIONARY;
    shipWeapon = FIRST;

    shipRectPosition = sf::Vector2i( shipCurrPosition.x, shipCurrPosition.y );
    shipRectSize     = sf::Vector2i( shipTexture -> getSize().x, shipTexture -> getSize().y );
    shipRect         = sf::IntRect( shipRectPosition, shipRectSize );
}

Ship::~Ship()
{
    //Checks to see if any memory needs to be freed after program ends
    //Remember: Last in, First out ;)

    if ( shipSprite )
    {
        delete shipSprite;
        shipSprite = 0;
    }

    if ( shipTexture )
    {
        delete shipTexture;
        shipTexture = 0;
    }
}

void Ship::takeDamage( int damage )
{
    //calculate how much damage the ship's shields and health take

    //First checks to see if the ship has any shielding. If it does it
    //takes damage to it accordingly. If the damage amount exceeds the
    //shields available, the remainder of the damage is applied to the
    //ships health. If no shields are available to begin with, then the
    //entire damage amount is taken by the health.

    if ( shipShield > 0 )
    {
        shipShield -= damage;

        if ( shipShield < 0 )
        {
            shipHealth += shipShield;

            shipShield = 0;
        }
    }

    else
    {
        shipHealth -= damage;

        if ( shipHealth <= 0 )
        {
            shipState = DEAD;
        }
    }
}


void Ship::updateRect()
{
    shipRectPosition = sf::Vector2i( shipCurrPosition.x, shipCurrPosition.y );
    shipRectSize     = sf::Vector2i( shipTexture -> getSize().x, shipTexture -> getSize().y );
    shipRect         = sf::IntRect( shipRectPosition, shipRectSize );
}
