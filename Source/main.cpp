/***************************************************************************
    Hero Aqurium. Watch heros going about their lives
    Copyright (C) 2016  Wesley Azzuolo

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.hpp"

using std::cout;
using std::endl;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(256, 128), "Tilemap");

    // define the level with an array of tile indices
    const int level[] =
    {
        53, 53, 53, 53, 53, 53, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
        53, 55, 55, 55, 55, 55, 55, 53, 53, 53, 53, 57, 53, 53, 53, 53,
        55, 55, 53, 53, 53, 53, 53, 53, 50, 50, 50, 50, 50, 50, 50, 50,
        53, 55, 53, 53, 57, 53, 50, 50, 50, 53, 55, 55, 55, 53, 53, 53,
        53, 55, 55, 53, 50, 50, 50, 53, 53, 53, 55, 55, 55, 57, 53, 53,
        53, 53, 55, 53, 50, 53, 57, 57, 53, 53, 55, 55, 55, 55, 57, 53,
        57, 53, 55, 53, 50, 53, 57, 57, 57, 53, 55, 55, 55, 55, 55, 55,
        53, 53, 55, 53, 50, 57, 57, 57, 53, 53, 53, 53, 55, 55, 55, 55,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("img/16x16_Jerom_CC-BY-SA-3.0_0.png", sf::Vector2u(16, 16), level, 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
