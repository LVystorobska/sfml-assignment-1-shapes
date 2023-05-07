#include "WindowEntitiesData.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

void WindowEntitiesData::loadFromFile(const std::string& filename)
{
        std::ifstream fin(filename);
        std::string entityType;
        std::string fFileName;
        float speedX = 0.1;
        float speedY = 0.1;
        std::string stype = "";
        std::string sname = "";
        int r, g, b;
        int posX = 0;
        int posY = 0;

        while (fin >> entityType)
        {
            if (entityType == "Window")
            {
                fin >> wWidth;
                fin >> wHeight;
            }
            else if (entityType == "Font")
            {
                fin >> fFileName >> fSize >> fr >> fg >> fb;
                if (!font.loadFromFile(PDIR + fFileName))
                {
                    std::cerr << "Could not load the font!\n";
                    exit(-1);
                }
            }
            else
            {
                fin >> sname >> posX >> posY >> speedX >> speedY >> r >> g >> b;
                Entity shape(entityType, sname, speedX + 0.4, speedY + 0.4);
                if (entityType == "Circle")
                {
                    int radius = 0;
                    fin >> radius;
                    shape.circle.setRadius(radius);
                    shape.circle.setPosition(posX, posY);
                    shape.circle.setFillColor(sf::Color(r, g, b));
                    shapes.push_back(shape);
                }
                else if (entityType == "Rectangle")
                {
                    int rWidth = 0;
                    int rHeight = 0;
                    fin >> rWidth >> rHeight;
                    shape.rectangle.setSize(sf::Vector2f(rWidth, rHeight));
                    shape.rectangle.setPosition(posX, posY);
                    shape.rectangle.setFillColor(sf::Color(r, g, b));
                    shapes.push_back(shape);
                }
            }
        }

}