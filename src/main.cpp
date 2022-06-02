#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(1000, 800), "draw");
int pressCount;
sf::Text countAsText;

class Button{
    private:
        sf::Color color;

        int x_pos, y_pos;

    public:
        sf::RectangleShape button;

        Button(float x_arg_pos, float y_arg_pos){
            this->x_pos = x_arg_pos;
            this->y_pos = y_arg_pos;

            setButtonProperties();
        }

        void setButtonProperties(){
            this->button.setSize(sf::Vector2f(100, 100));
            this->button.setFillColor(this->color);
            this->button.setPosition(this->x_pos, this->y_pos);
            this->button.setOrigin(this->x_pos / 2, this->y_pos / 2);
        }
};

class Text{
    private:
        sf::Font font;
        void loadAndSetProperties(){
            if(!font.loadFromFile("assets\\fonts\\Ubuntu-Medium.ttf")){
                std::cerr << "ERROR: unable to load font";
            }
            countAsText.setFont(font);
            countAsText.setCharacterSize(100);
            countAsText.setFillColor(sf::Color::Black);
        }

    public:
        Text(){
            loadAndSetProperties();
        }
};

int main(void){
    Button theButton((window.getSize().x / 2), (window.getSize().y / 2));
    Text clickText;

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:{
                        // Credit for this button check goes to https://gamedev.stackexchange.com/users/40264/vaillancourt
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePosFloat(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        if ( theButton.button.getGlobalBounds().contains( mousePosFloat ) ){
                            pressCount++;
                        }
                        break;
                }
            }
        }
        window.clear(sf::Color(42, 42, 42));

        window.draw(theButton.button);

        std::string stringcount = std::to_string(pressCount);
        countAsText.setString(stringcount);
        window.draw(countAsText);

        window.display();
    }


    return 0;
}