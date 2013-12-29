#include <SFML/Graphics.hpp>

int main(int argv, char* argc[])
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Strikers Clone");

    sf::Event event;

    window.setFramerateLimit(60);

    window.clear(sf::Color(0, 0, 0));

    enum GAME_STATE {INTRO, MENU, GAME, OPTIONS, HIGH_SCORE, END};
    GAME_STATE gameState = INTRO;

    while(window.isOpen())
    {

        switch(gameState)
        {
            case INTRO:
            {
                //load the SFML logo into a texture
                sf::Texture* textureSFMLLogo = new sf::Texture();
                textureSFMLLogo->loadFromFile("images/intro.png");

                //apply the SFML logo texture to the sprite
                sf::Sprite* spriteSFMLLogo = new sf::Sprite(*textureSFMLLogo);

                //get the width and height of the sprite
                sf::FloatRect spriteDimensions = spriteSFMLLogo->getGlobalBounds();
                int spriteH = spriteDimensions.height;
                int spriteW = spriteDimensions.width;

                //get the width and height of the window
                sf::Vector2u windowDimensions = window.getSize();
                int windowH = windowDimensions.y;
                int windowW = windowDimensions.x;

                //center the sprite in the window
                spriteSFMLLogo->setPosition(((windowW / 2) - (spriteW / 2)), ((windowH / 2) - (spriteH / 2)));

                //fade in
                spriteSFMLLogo->setColor(sf::Color(255, 255, 255, 0));
                for(int x = 0; x <= 255; x+= 4)
                {
                    window.clear(sf::Color(0, 0, 0));
                    spriteSFMLLogo->setColor(sf::Color(255, 255, 255, x));
                    window.draw(*spriteSFMLLogo);
                    window.display();
                }

                //fade out
                for(int x = 255; x >= 0; x -= 4)
                {
                    window.clear(sf::Color(0, 0, 0));
                    spriteSFMLLogo->setColor(sf::Color(255, 255, 255, x));
                    window.draw(*spriteSFMLLogo);
                    window.display();
                }

                //Free up memory allocated to the sprite and texture
                delete spriteSFMLLogo;
                delete textureSFMLLogo;

                //switch the current game state to the main menu
                gameState = MENU;

            }
                break;



            case END:
                window.close();
                break;

            default:
                break;
        }








        while(window.pollEvent(event))
        {

            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            gameState = END;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

        }

        //window.display();

    }



    return 0;

}
