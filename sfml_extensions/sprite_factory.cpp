
#include "sprite_factory.hpp"

//Constructor
SpriteFactory::SpriteFactory(sf::RenderWindow* renderWindow)
{
    //sets the sf::RenderWindow to attach to
    window = renderWindow;

    //gets and sets the window height and width
    sf::Vector2u windowDimensions = window->getSize();
    windowWidth = windowDimensions.x;
    windowHeight = windowDimensions.y;
}


//Destructor
SpriteFactory::~SpriteFactory()
{
    //make it easier to reference the iterators for the textures and maps
    typedef std::map<std::string, sf::Sprite*>::iterator sIterator;
    typedef std::map<std::string, sf::Texture*>::iterator tIterator;

    //iterate through sprites and free the dynamically allocated memory used by them
    for(sIterator spritesIterator = sprites.begin(); spritesIterator != sprites.end(); spritesIterator++)
    {
        delete spritesIterator->second;
    }

    //iterate through the textures and free the dynamically allocated memory used by them
    for(tIterator texturesIterator = textures.begin(); texturesIterator != textures.end(); texturesIterator++)
    {
        delete texturesIterator->second;
    }
}



//Function to create a sprite from an image file
void SpriteFactory::createSprite(std::string filename, std::string spriteName)
{
    //dynamically allocate memory for a texture
    sf::Texture* texture = new sf::Texture();
    //load the texture into said memory from specified file
    texture->loadFromFile(filename);
    //insert texture into the textures map
    textures.insert(std::pair<std::string, sf::Texture*>(spriteName, texture));
    //dynamically allocate memory for a sprite that uses the above texture
    sf::Sprite* sprite = new sf::Sprite(*textures[spriteName]);
    //insert sprite into the sprites map
    sprites.insert(std::pair<std::string, sf::Sprite*>(spriteName, sprite));
}


//draws the specified sprite at its pre-set position in the window
void SpriteFactory::drawSprite(std::string name)
{
    window->draw(*sprites[name]);
}


//draws the specified sprite at the specified position
void SpriteFactory::drawSprite(std::string name, int posX, int posY)
{
    sprites[name]->setPosition(posX, posY);
    window->draw(*sprites[name]);
}


//returns a pointer to the specified sprite
sf::Sprite* SpriteFactory::getSprite(std::string name)
{
    return sprites[name];
}

//frees the dynamically allocated memory for the sprite and texture associated
//with the specified sprite and removes them from their maps
void SpriteFactory::deleteSprite(std::string name)
{
    delete sprites[name];
    delete textures[name];

    sprites.erase(name);
    textures.erase(name);
}

//centers the specified sprite horizontally in the window
void SpriteFactory::centerSpriteHorizontally(std::string name)
{

    sf::FloatRect spriteDimensions = sprites[name]->getGlobalBounds();
    int x = ((windowWidth / 2) - (spriteDimensions.width / 2));
    int y = sprites[name]->getPosition().y;
    sprites[name]->setPosition(x, y);


}

//centers the specified sprite vertically in the window
void SpriteFactory::centerSpriteVertically(std::string name)
{
    sf::FloatRect spriteDimensions = sprites[name]->getGlobalBounds();
    int y = ((windowHeight / 2) - (spriteDimensions.height / 2));
    int x = sprites[name]->getPosition().x;
    sprites[name]->setPosition(x, y);
}

//centers the specified sprite both horizontally and vertically
void SpriteFactory::centerSprite(std::string name)
{
    sf::FloatRect spriteDimensions = sprites[name]->getGlobalBounds();
    int x = ((windowWidth / 2) - (spriteDimensions.width / 2));
    int y = ((windowHeight / 2) - (spriteDimensions.height / 2));
    sprites[name]->setPosition(x, y);
}
