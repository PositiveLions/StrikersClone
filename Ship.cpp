#include "Ship.h"

Ship::Ship()
{
    //Default constructor

    shipTexture  = 0;
    shipSprite   = 0;
    shipPosition = sf::Vector2f( 0, 0 );
    shipVelocity = sf::Vector2f( 0, 0 );

    //Default values for health and shields

    shipHealth = 100;
    shipShield = 100;
}

Ship::Ship( sf::Texture &texture )
{
    shipTexture = new sf::Texture( texture );           //Sets the objects texture
    shipSprite  = new sf::Sprite( *shipTexture );        //Sets the texture to the sprite object

    shipPosition = sf::Vector2f( 0, 0 );
    shipVelocity = sf::Vector2f( 0, 0 );

    shipHealth = 100;
    shipShield = 100;
}

Ship::Ship( sf::Texture &texture, sf::Vector2f position )
{
    shipTexture = new sf::Texture( texture );
    shipSprite = new sf::Sprite( *shipTexture );

    shipPosition = position;
    shipVelocity = sf::Vector2f( 0, 0 );

    shipHealth = 100;
    shipShield = 100;
}

Ship::~Ship()
{
    //Checks to see if any memory needs to be freed after program ends

    if ( shipTexture )
    {
        delete shipTexture;
        shipTexture = 0;
    }

    if ( shipSprite )
    {
        delete shipSprite;
        shipSprite = 0;
    }
}
