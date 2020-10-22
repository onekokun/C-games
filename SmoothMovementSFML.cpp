#include<SFML/Graphics.hpp>
#include<iostream>

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;
bool playerUp = false, playerDown = false, playerLeft = false , playerRight = false;;

class PlayerClass
{
    public:
        bool playerfaceRight;

        float xvel;
        float yvel;
        float xpos;
        float ypos;

        PlayerClass()
        {
            std::cout<<"Im inside playerClass"<<std::endl;
            xvel = 0;
            yvel = 0;
            xpos = 0;
            ypos = 0;
        }

        void update(bool playerUp,bool playerDown,bool playerLeft,bool playerRight)
        {
            if(playerUp)
            {
                yvel = -1;
            }
            
            if(playerDown)
            {
                yvel = 1;
            }

            if(playerRight)
            {
                playerfaceRight = true;
                xvel = 1;
            }

            if(playerLeft)
            {
                playerfaceRight = false;
                xvel = -1;
            }

            if(!(playerRight||playerLeft))
            {
                xvel = 0;
            }

            if(!(playerUp||playerDown))
            {
                yvel = 0;
            }
            

            xpos += xvel;
            ypos += yvel;

           std::cout<<"("<<xpos<<","<<ypos<<")"<<std::endl;
        }

};

int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "SFML rocks!");
    PlayerClass playerObject;

    sf::Texture snailtexture;
    snailtexture.loadFromFile("snail.png");

    sf::Sprite snailSprite;
    snailSprite.setTexture(snailtexture);
    snailSprite.setScale(sf::Vector2f(0.1,0.1));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed : window.close(); break;

                case sf::Event::KeyPressed:

                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up : 
                            playerUp = true; 
                            std::cout<<"Up key pressed"<<std::endl;
                            
                        break;
                        
                        case sf::Keyboard::Down : 
                            playerDown = true; 
                            std::cout<<"down key pressed"<<std::endl;
                        
                        break;
                        
                        case sf::Keyboard::Left : 
                            playerLeft = true; 
                            std::cout<<"left key pressed"<<std::endl;
                           
                        break;
                        
                        case sf::Keyboard::Right : 
                            playerRight = true; 
                            std::cout<<"right key pressed"<<std::endl;
                           
                        break;
                    }

                break;

                 case sf::Event::KeyReleased:

                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up : 
                            playerUp = false; 
                            std::cout<<"not Up key pressed"<<std::endl;
                            
                        break;
                        
                        case sf::Keyboard::Down : 
                            playerDown = false; 
                            std::cout<<"not down key pressed"<<std::endl;
                        
                        break;
                        
                        case sf::Keyboard::Left : 
                            playerLeft = false; 
                            std::cout<<"not left key pressed"<<std::endl;
                           
                        break;
                        
                        case sf::Keyboard::Right : 
                            playerRight = false; 
                            std::cout<<"not right key pressed"<<std::endl;
                           
                        break;
                    }

                break;

            }
        }

        //clear screen
        window.clear();
        
        //draw sprites
        window.draw(snailSprite);
        playerObject.update(playerUp,playerDown,playerLeft,playerRight);
        snailSprite.move(playerObject.xvel,playerObject.yvel);
        
            

        //Redisplay window after clearing the screen
        window.display();

        
    }

    return EXIT_SUCCESS;
}
