#ifndef SPRITE_FACTORY_HPP
#define SPRITE_FACTORY_HPP

#include <map>
#include <SFML/Graphics.hpp>


class SpriteFactory
{

    private:
        sf::RenderWindow* window;   //the window to render sprites in
        std::map<std::string, sf::Sprite*> sprites;     //holds all of the sprites
        std::map<std::string, sf::Texture*> textures;   //holds all of the textures
        int windowHeight;   //height of the window
        int windowWidth;    //width of the window


    public:
        //constructors and destructors
        SpriteFactory(sf::RenderWindow*);
        ~SpriteFactory();

        void createSprite(std::string, std::string);    //creates a sprite from an image with the specified name
        void drawSprite(std::string);                   //draws a sprite at its pre-set location
        void drawSprite(std::string, int, int);         //draws a sprite at a specified location
        sf::Sprite* getSprite(std::string);             //returns a pointer to the specified sprite
        void deleteSprite(std::string);                 //delete a sprite from memory
        void centerSpriteVertically(std::string);       //centers the sprite vertically only
        void centerSpriteHorizontally(std::string);     //centers the sprite horizontally only
        void centerSprite(std::string);                 //centers the specified sprite horizontally and vertically



};


#endif
