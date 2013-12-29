#include <SFML/Graphics.hpp>
#include "sfml_extensions/sprite_factory.hpp"

int main(int argv, char* argc[])
{

    //create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Strikers Clone");

    //for event handling
    sf::Event event;

    //creates and manages images
    SpriteFactory spriteFactory = SpriteFactory(&window);

    //set the framerate to 60 fps
    window.setFramerateLimit(60);

    //clear the window to black
    window.clear(sf::Color(0, 0, 0));

    //for holding and maintaining the gamestate
    enum GAME_STATE {INTRO, MENU, GAME, OPTIONS, HIGH_SCORE, END};
    GAME_STATE gameState = INTRO;



    while(window.isOpen())
    {

        switch(gameState)
        {
            //Intro screen(s)
            case INTRO:
            {

                //create a sprite of the SFML logo and center it
                spriteFactory.createSprite("images/intro.png", "SFML_Logo");
                spriteFactory.centerSprite("SFML_Logo");

                //fade in
                for(int x = 0; x <= 255; x+= 4)
                {
                    window.clear(sf::Color(0, 0, 0));
                    spriteFactory.getSprite("SFML_Logo")->setColor(sf::Color(255, 255, 255, x));
                    spriteFactory.drawSprite("SFML_Logo");
                    window.display();
                }

                //fade out
                for(int x = 255; x >= 0; x -= 4)
                {
                    window.clear(sf::Color(0, 0, 0));
                    spriteFactory.getSprite("SFML_Logo")->setColor(sf::Color(255, 255, 255, x));
                    spriteFactory.drawSprite("SFML_Logo");
                    window.display();
                }

                //Free up memory allocated to the sprite and texture
                spriteFactory.deleteSprite("SFML_Logo");

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
