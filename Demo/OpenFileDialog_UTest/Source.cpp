#include <iostream>
#include <SFML/Graphics.hpp>
#include <OpenFileDialog/OpenFileDialog_sfml.hpp>

// OênFileDialog Usage Example
int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "TCS SFML");
	sf::RectangleShape shape({ 200, 200 });
	sf::Texture texture;

	while (window.isOpen())
	{
		// Event
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		
		// Open Windows File Dialog (Get Path)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O))
		{
			OpenFileDialog::Filter flags = static_cast<OpenFileDialog::Filter>(OpenFileDialog::Text | OpenFileDialog::ImagePng | OpenFileDialog::ImageJpeg);
			OpenFileDialog ofd(flags);
			if (!ofd.GetFileSaved().empty())
				std::cout << "Fichier selectionne : " << ofd.GetFileSaved() << std::endl;
		}

		// Open SFML File Dialog (Get SFML Element)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			OpenFileDialog::Filter flags = static_cast<OpenFileDialog::Filter>(OpenFileDialog::Text | OpenFileDialog::ImagePng | OpenFileDialog::ImageJpeg);
			sf::OpenFileDialog_sfml<sf::Texture> ofd(flags);
			texture = ofd.GetElement();
			shape.setTexture(&texture);
		}

		// Render
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();
	}
	return 0;
}