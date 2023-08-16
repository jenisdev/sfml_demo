#include <SFML/Graphics.hpp>    

int main()
{
	//Example for making a rectangle move around
	sf::RenderWindow screen(sf::VideoMode(1024, 768), "Rectangle shape test"); //Create a window
	screen.setFramerateLimit(60); //Limit the frame rate to 60

	sf::CircleShape circle_shape(80); //Instantiate rectangle object
	circle_shape.setFillColor(sf::Color::Red); //Color the rectangle with blue
	circle_shape.setPosition(100, 100); //Set the rectangle's position to 100, 100
	while (screen.isOpen()) //loop to update the window
	{
		sf::Event event; //Create an event class

		while (screen.pollEvent(event)) //Poll all possible events
		{
			if (event.type == sf::Event::Closed) //If the user hits the red X button
				screen.close(); //If true, close the window

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user is holding down the key "W"
				circle_shape.move(0, -5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				circle_shape.move(-5, 0); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				circle_shape.move(0, 5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				circle_shape.move(5, 0); //move the rectangle 5 pixels on the y axis
		}

		screen.clear(); //Clear the screen of all elements

		screen.draw(circle_shape); //Draw the rectangle

		screen.display(); //Display it
	}
}
