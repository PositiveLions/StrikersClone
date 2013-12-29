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

    void takeDamage( int damage );
    void updateRect();


    //Describes the various states of the ship will have.
    //More will most likely be added later on.

    enum SHIP_STATE
    {
        STATIONARY,
        LEFT,
        RIGHT,
        UP,
        DOWN,
        FIRING,
        DEAD
    };

    //The various different weapons that the ship will have.
    //These enum types are just placeholders for when we actually
    //decide to put more than one weapon in the game to use.
    //Eventually want to make a Weapon Class that will have
    //different weapons of different powers.

    enum SHIP_WEAPON
    {
      FIRST,
      SECOND,
      THIRD
    };


    //Various setter methods

    void setShipTexture( sf::Texture &texture )     { shipTexture = &texture; }
    void setShipSprite( sf::Sprite &sprite )        { shipSprite  = &sprite; }
    void setShipPosition( float x, float y )        { shipCurrPosition.x = x; shipCurrPosition.y = y; }
    void setShipVelocity( float x, float y )        { shipVelocity.x = x; shipVelocity.y = y; }
    void setShipHealth( unsigned short int health ) { shipHealth = health; }
    void setShipShield( unsigned short int shield ) { shipShield = shield; }
    void setShipState( SHIP_STATE state )           { shipState = state; }
    void setShipWeapon( SHIP_WEAPON weapon )        { shipWeapon = weapon; }

    //Various getter methods

    sf::Texture       &getTexture()      { return *shipTexture; }
    sf::Sprite        &getSprite()       { return *shipSprite; }
    sf::Vector2f       getCurrPosition() { return shipCurrPosition; }
    sf::Vector2f       getPrevPosition() { return shipPrevPosition; }
    sf::Vector2f       getVelocity()     { return shipVelocity; }
    unsigned short int getHealth()       { return shipHealth; }
    unsigned short int getShield()       { return shipShield; }
    unsigned short int getState()        { return shipState; }
    unsigned short int getWeapon()       { return shipWeapon; }
    sf::IntRect       &getRect()         { return shipRect; }

protected:


    sf::Texture       *shipTexture;
    sf::Sprite        *shipSprite;

    sf::Vector2f       shipCurrPosition;
    sf::Vector2f       shipPrevPosition;
    sf::Vector2f       shipVelocity;

    unsigned short int shipHealth;
    unsigned short int shipShield;

    SHIP_STATE         shipState;
    SHIP_WEAPON        shipWeapon;

    sf::IntRect        shipRect;
    sf::Vector2i       shipRectPosition;
    sf::Vector2i       shipRectSize;
};

#endif
