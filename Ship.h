#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>

//-----Abstract Class for All Ships and Entities in Game------//

class Ship
{

public:

    Ship();
    Ship( sf::Texture &texture );
    Ship( sf::Texture &texture, sf::Vector2f position );

    ~Ship();

    //Various virtual functions to be overwritten by
    //inheriting classes

    virtual void update( float dt )   = 0;
    virtual void move()               = 0;
    virtual void attack( Ship &ship ) = 0;

    //Various inherited functions

    //void takeDamage( int damage );


    //Various setter methods

    void setShipPosition( float x, float y ) { shipPosition.x = x; shipPosition.y = y; }
    void setVelocity( float x, float y )     { shipVelocity.x = x; shipVelocity.y = y; }

    //Various getter methods

    sf::Texture  &getTexture()  { return *shipTexture; }
    sf::Sprite   &getSprite()   { return *shipSprite; }
    sf::Vector2f  getPosition() { return shipPosition; }
    sf::Vector2f  getVelocity() { return shipVelocity; }

private:


    //Describes the various states of movement the ship will have.
    //More will most likely be added later on.

    enum SHIP_STATE
    {
        STATIONARY,
        LEFT,
        RIGHT,
        UP,
        DOWN,
        FIRING
    };

    //The various different weapons that the ship will have.
    //These enum types are just placeholders for when we actually
    //decide to put more than one weapon in the game to use.

    enum SHIP_WEAPON
    {
      FIRST,
      SECOND,
      THIRD
    };

    sf::Texture  *shipTexture;
    sf::Sprite   *shipSprite;

    sf::Vector2f shipPosition;
    sf::Vector2f shipVelocity;

    unsigned short int shipHealth;
    unsigned short int shipShield;
};

#endif  SHIP_H
