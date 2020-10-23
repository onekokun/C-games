#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


const int SCREEN_HEIGHT = 800;
const int SCREEN_WIDTH = 800;

bool spaceshipLeft=false,spaceshipRight=false,spaceshipUp=false,spaceshipDown=false,missileFire=false;

class Spaceship
{
   
    public:
        int xpos;
        int ypos;
        int xvel;
        int yvel;

        Spaceship()
        {
            xpos = 0;
            ypos = 0;
            xvel = 0;
            yvel = 0;
        }

        void update(bool spaceshipLeft, bool spaceshipRight, bool spaceshipUp, bool spaceshipDown)
        {
            if(spaceshipLeft)
            {
                xvel = -1;
            }

            if(spaceshipRight)
            {
                xvel = 1;
            }

            if(!(spaceshipLeft || spaceshipRight))
            {
                xvel = 0;
            }

            xpos+=xvel;
            ypos+=yvel;

           std::cout<<"("<<xpos<<","<<ypos<<")"<<std::endl;
        }
};


int main(void)
{
    //window 
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"NinVaders",sf::Style::Default);

    //adding music
    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("background.ogg");

    //object textures
    sf::Texture ufoTexture;
    ufoTexture.loadFromFile("data/images/ufo.png");

    sf::Texture spaceshipTexture;
    spaceshipTexture.loadFromFile("data/images/rocket.png");

    sf::Texture missileTexture;
    missileTexture.loadFromFile("data/images/missile.png");

    sf::Texture spaceTxeture;
    spaceTxeture.loadFromFile("data/images/space.jpg");

    //object sprites
    sf::Sprite ufoSprite;
    sf::Sprite spaceshipSprite;
    sf::Sprite missileSprite;
    sf::Sprite spaceSprite;

    ufoSprite.setTexture(ufoTexture);

    spaceshipSprite.setTexture(spaceshipTexture);
    spaceshipSprite.setScale(0.15,0.2);
    spaceshipSprite.setPosition(sf::Vector2f(0,700));

    missileSprite.setTexture(missileTexture);
    missileSprite.setScale(0.1,0.15);

    spaceSprite.setTexture(spaceTxeture);
    spaceSprite.setScale(0.49,0.9);

    Spaceship spaceship;
    
    backgroundMusic.play();

    //game loop
    while(window.isOpen())
    {
        sf::Event event;

        //polling event
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed : window.close(); break;

                case sf::Event::KeyPressed : 

                switch(event.key.code)
                {
                    case sf::Keyboard::Up : 
                        spaceshipUp = true;
                    break;

                    case sf::Keyboard::Down :
                        spaceshipDown = true;
                    break;

                    case sf::Keyboard::Left :
                        spaceshipLeft = true;
                    break;

                    case sf::Keyboard::Right :
                        spaceshipRight = true;
                    break; 

                    case sf::Keyboard::Space :
                        missileFire=true;
                    break;
                }

                break;

                case sf::Event::KeyReleased : 

                 switch(event.key.code)
                {
                    case sf::Keyboard::Up : 
                        spaceshipUp = false;
                    break;

                    case sf::Keyboard::Down :
                        spaceshipDown = false;
                    break;

                    case sf::Keyboard::Left :
                        spaceshipLeft = false;
                    break;

                    case sf::Keyboard::Right :
                        spaceshipRight = false;
                    break; 
                }                    

                break;
            }
        }
  
        window.clear();

        //sprites
        window.draw(spaceSprite);
        
        if(missileFire)
            window.draw(missileSprite);

        window.draw(spaceshipSprite);
        spaceship.update(spaceshipLeft, spaceshipRight, spaceshipUp,spaceshipDown);

        if(spaceship.xpos>=0 && spaceship.xpos<=720)
            spaceshipSprite.move(spaceship.xvel,spaceship.yvel);

      //  window.draw(ufoSprite);

        window.display();
    }

    return EXIT_SUCCESS;
}
