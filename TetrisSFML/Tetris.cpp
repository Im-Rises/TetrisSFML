#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
//#include <iostream>
//#include <string>

Tetris::Tetris() {
}

void Tetris::start() {
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE, CELL_SIZE * ROWS * SCREEN_SIZE), PROJECT_NAME);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));

	sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	std::vector<std::vector<unsigned char>> matrix(COLUMNS, std::vector<unsigned char>(ROWS, 0));

	while (window.isOpen()) {
		for (auto x = 0; x < COLUMNS; x++) {
			for (auto y = 0; y < ROWS; y++) {
				if (matrix[x][y] == 0) {
					cell.setFillColor(sf::Color::Red);
				}
				else {
					cell.setFillColor(sf::Color::White);
				}
				cell.setPosition(CELL_SIZE * x + 1, CELL_SIZE * y + 1);
				window.draw(cell);
			}
		}

		window.display();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			case sf::Event::MouseButtonPressed:
				std::cout << "Mouse button event" << std::endl;
				auto mousePositionX = sf::Mouse::getPosition(window).x / CELL_SIZE / SCREEN_SIZE;
				auto mousePositionY = sf::Mouse::getPosition(window).y / CELL_SIZE / SCREEN_SIZE;
				matrix[mousePositionX][mousePositionY] = 1 - matrix[mousePositionX][mousePositionY];
				break;
			}
		}
	}
}
