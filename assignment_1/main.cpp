#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "WindowEntitiesData.h"


int main(int argc, char* argv[])
{

    WindowEntitiesData shapesData;
    shapesData.loadFromFile((std::string)PDIR + (std::string)"shapes_source.txt");

    const int wWidth = shapesData.wWidth;
    const int wHeight = shapesData.wHeight;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works for you!");
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed with code = " << event.key.code << "\n";

            }
        }


            window.clear();

            for (auto& shape : shapesData.shapes)
            {
                sf::Text text(shape.sname, shapesData.font, shapesData.fSize);
                text.setFillColor(sf::Color(shapesData.fr, shapesData.fg, shapesData.fb));
                if (shape.stype == "Circle")
                {
                    float cwidth = shape.circle.getLocalBounds().width;
                    float cheight = shape.circle.getLocalBounds().height;
                    float cPositionX = shape.circle.getPosition().x;
                    float cPositionY = shape.circle.getPosition().y;
                    if (cPositionX <= 0 || (cPositionX + cwidth) >= wWidth)
                    {
                        shape.speedX *= -1.0f;
                    }
                    if (cPositionY <= 0 || (cPositionY + cheight) >= wHeight)
                    {
                        shape.speedY *= -1.0f;
                    }

                    shape.circle.setPosition(shape.circle.getPosition().x + shape.speedX, shape.circle.getPosition().y + shape.speedY);
                    text.setPosition(shape.circle.getPosition().x + shape.circle.getRadius() - (text.getLocalBounds().width / 2) + shape.speedX, shape.circle.getPosition().y + shape.circle.getRadius() - (text.getLocalBounds().height / 2) + shape.speedY);
                    window.draw(shape.circle);
                    window.draw(text);
                }
                else if (shape.stype == "Rectangle")
                {
                    float rwidth = shape.rectangle.getLocalBounds().width;
                    float rheight = shape.rectangle.getLocalBounds().height;
                    float rPositionX = shape.rectangle.getPosition().x;
                    float rPositionY = shape.rectangle.getPosition().y;
                    if (rPositionX <= 0 || (rPositionX + rwidth) >= wWidth)
                    {
                        shape.speedX *= -1.0f;
                    }
                    if (rPositionY <= 0 || (rPositionY + rheight) >= wHeight)
                    {
                        shape.speedY *= -1.0f;
                    }

                    shape.rectangle.setPosition(shape.rectangle.getPosition().x + shape.speedX, shape.rectangle.getPosition().y + shape.speedY);
                    text.setPosition(shape.rectangle.getPosition().x + shape.rectangle.getSize().x / 2 - (text.getLocalBounds().width / 2) + shape.speedX, shape.rectangle.getPosition().y + shape.rectangle.getSize().y / 2 - (text.getLocalBounds().height / 2) + shape.speedY);
                    window.draw(shape.rectangle);
                    window.draw(text);
                }
            }

        
        window.display();
    }
}
