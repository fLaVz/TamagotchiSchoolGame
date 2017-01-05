#include "text.h"

using namespace std;
using namespace sf;


text::text() {

    myfont.loadFromFile("arial.ttf");
    mytext.setFont(myfont);   
  	mytext.setString("DEFAULT");

}


text::text(string m_text, Color mycolor, int x, int y) {


    myfont.loadFromFile("arial.ttf");

    mytext.setString(m_text);
    mytext.setFont(myfont);
    mytext.setColor(mycolor);
    mytext.setCharacterSize(30);
    mytext.setPosition(x, y);
}



void text::drawText(RenderWindow & window) {

	window.draw(mytext);
}


void text::addText(string add) {

    string done = mytext.getString();
    done.replace(5, 3, add);
    mytext.setString(done);
}