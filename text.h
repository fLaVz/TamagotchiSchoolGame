#ifndef text_H
#define text_H

#include <iostream>
#include <SFML/Graphics.hpp>

class text {

	sf::Font myfont;
	sf::Text mytext;


public:

	text();
	text(std::string m_text, sf::Color mycolor, int x, int y);

	void drawText(sf::RenderWindow & window);


};

#endif