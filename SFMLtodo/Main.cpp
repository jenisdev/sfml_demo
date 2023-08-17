#include <SFML/Graphics.hpp>    

int main()
{
	//Example for making a rectangle move around
	sf::RenderWindow screen(sf::VideoMode(1024, 768), "Rectangle shape test"); //Create a window
	screen.setFramerateLimit(60); //Limit the frame rate to 60
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("./background.png")) {
		perror("Couldn't load texture \"background.png\".");
	}
	sf::Sprite bgSprite(bgTexture);

	// Ojbect 1
	sf::CircleShape circle_shape1(80); //Instantiate rectangle object
	circle_shape1.setFillColor(sf::Color::Red); //Color the rectangle with blue
	circle_shape1.setPosition(100, 100); //Set the rectangle's position to 100, 100

	sf::Texture texture1;
	if (!texture1.loadFromFile("./circle1.jpg")) {
		perror("Couldn't load texture \"circle1.jpg\".");
	}

	circle_shape1.setTexture(&texture1);

	// Object 2
	sf::CircleShape circle_shape2(80); //Instantiate rectangle object
	circle_shape2.setFillColor(sf::Color::Red); //Color the rectangle with blue
	circle_shape2.setPosition(100, 100); //Set the rectangle's position to 100, 100

	sf::Texture texture2;
	if (!texture2.loadFromFile("./circle2.jpg")) {
		perror("Couldn't load texture \"circle2.jpg\".");
	}

	circle_shape2.setTexture(&texture2);

	while (screen.isOpen()) //loop to update the window
	{
		sf::Event event; //Create an event class

		while (screen.pollEvent(event)) //Poll all possible events
		{
			if (event.type == sf::Event::Closed) //If the user hits the red X button
				screen.close(); //If true, close the window

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user is holding down the key "W"
				circle_shape1.move(0, -5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				circle_shape1.move(-5, 0); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				circle_shape1.move(0, 5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				circle_shape1.move(5, 0); //move the rectangle 5 pixels on the y axis
			//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //If the user is holding down the key "W"
				circle_shape2.move(0, -5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				circle_shape2.move(-5, 0); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				circle_shape2.move(0, 5); //move the rectangle 5 pixels on the y axis

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				circle_shape2.move(5, 0); //move the rectangle 5 pixels on the y axis
		}

		screen.clear(); //Clear the screen of all elements
		screen.draw(bgSprite);
		screen.draw(circle_shape1); //Draw the circle object 1
		screen.draw(circle_shape2); //Draw the circle object 2

		screen.display(); //Display it
	}
}
