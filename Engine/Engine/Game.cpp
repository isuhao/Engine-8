#include "Game.hpp"



//PUBLIC FUNCTIONS

Game::Game(){}

Game::~Game(){}

void Game::initialize(const std::string& configFile, const std::string& mapFile, const std::string& saveFile, const bool& doLoadScreen)
{
	loadGameConfig(configFile);

	windowPtr = boost::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(renderSize.x, renderSize.y), windowName));
	
	//load Resources
	//load Objects
	//load Map

	//thats all for now folks

}

void Game::begin()
{
	//sfml main loop
	sf::RenderWindow& window = *windowPtr;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		update();
		draw();

		window.display();
	}
}


//PRIVATE FUNCTIONS

void Game::draw()
{

}

void Game::update()
{
	//for each layer
		//get draw bounds for layer
		//remove out of bound objects
		//add new in-bound objects
}

void Game::loadGameConfig(const std::string& configFile)
{
	INIParser parser(configFile);
	windowName = "Squirrel Game";
	renderSize = sf::Vector2i(960, 540);
	maxFPS = 0;

	parser.setSection("Render_Options");
	parser.readValue<std::string>("Window_Name", windowName);
	parser.readValue<int>("Res_X", renderSize.x); parser.readValue<int>("Res_Y", renderSize.y);
	parser.readValue<int>("FPS_Cap", maxFPS);

}

void Game::loadResources()
{
	//load basic game resources
}

void Game::loadObjects()
{
	//initialize base object types
}

void Game::loadMap()
{
	//load and initialize layers

}


