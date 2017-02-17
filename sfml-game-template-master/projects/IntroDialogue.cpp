#include "IntroDialogue.h"


IntroDialogue::IntroDialogue()
{
     txt.open(resourcePath() + "assets/StartDia.txt");
     font.loadFromFile(resourcePath() + "assets/BASKVILL.TTF");
     text1.setFont(font);
     text1.setCharacterSize(30);
     text1.setColor(sf::Color::Cyan);
     text1.setPosition(20.0, 600.0);
     text2.setFont(font);
     text2.setCharacterSize(30);
     text2.setColor(sf::Color::Cyan);
     text2.setPosition(20.0, 550.0);

}
void IntroDialogue::readDialogue(sf::RenderWindow &window)
{
     //test to see if the inputfile exists
     if (!txt.is_open())
     {
          std::cout << "Cannot open the startDia.txt!!\n";
     }
     //press space bar to move through the dialogues
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
     {
          isPressed = true;
     }
     if (isPressed && !wasPressed)
     {
          text2.setString(text1.getString()); //store previous string
          if (!getline(txt, dialogue1))
          {
               endDia = true;
               text2.setString("");
               text1.setString("");
          }
          else
          {
               text1.setString(dialogue1); //store current string
          }
     }
     
     printDialogue(window, text1, text2);

     wasPressed = isPressed;

     if (wasPressed)
     {
          isPressed = false;
     }
}
void IntroDialogue::printDialogue(sf::RenderWindow &window, sf::Text text1, sf::Text text2)
{
     window.clear();
     window.draw(text1);
     window.draw(text2);
     window.display();
}