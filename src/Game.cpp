#include <./include/Game.h>
#include <SFML/Graphics.hpp>

using namespace sf;

#define CUTE_C2_IMPLEMENTATION
#include <./include/cute_c2.h>

sf::RenderWindow* window = new RenderWindow(sf::VideoMode(800, 600), "Launching...");


sf::Texture player_texture;
sf::Texture npc_texture;

sf::Sprite player_sprite;
sf::Sprite npc_sprite;

sf::CircleShape CircleCollide;

Game::Game(){}

void Game::initialize()
{
	player = new Player();
	npc = new NPC();

	window->setSize(sf::Vector2u(640, 480));
	window->setTitle("Game");

	player->x = 200;//x pos
	player->y = 200;//y pos
	player->w = 0;// width
	player->h = 0;// height
	player->r = 0;// radius

	player_sprite.setPosition(player->x,player->y);

	npc->x = 0;
	npc->y = 0;
	npc->w = 0;
	npc->h = 0;
	npc->r = 0;

	CircleCollide.setPosition(600,50);
	CircleCollide.setRadius(50);
	CircleCollide.setFillColor(sf::Color::Yellow);

	player_texture.loadFromFile(".//images//player//Player.png");
	npc_texture.loadFromFile(".//images//npc//npc.png");

	player_sprite.setTexture(player_texture);
	npc_sprite.setTexture(npc_texture);
}

void Game::run()
{
	initialize();

	while (window->isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		player->update();
		npc->update();

		// Move the player
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player_sprite.move(sf::Vector2f(0.0f, -4.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player_sprite.move(sf::Vector2f(0.0f, 4.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player_sprite.move(sf::Vector2f(-4.0f, 0.0f));
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player_sprite.move(sf::Vector2f(4.0f, 0.0f));
		}

		//Setup NPC AABB
		c2AABB aabb_npc;
		aabb_npc.min = c2V(npc_sprite.getPosition().x, npc_sprite.getPosition().y);
		aabb_npc.max = c2V(
			npc_sprite.getPosition().x +
			npc_sprite.getGlobalBounds().width, 
			npc_sprite.getPosition().y +
			npc_sprite.getGlobalBounds().height);
			
		//Setup Player AABB
		c2AABB aabb_player;
		aabb_player.min = c2V(player_sprite.getPosition().x,player_sprite.getPosition().y);
		aabb_player.max = c2V(player_sprite.getGlobalBounds().width, player_sprite.getGlobalBounds().height);

		c2Capsule c2Capsule_player;
		//c2Capsule_player.a = c2V(300,100);
		//c2Capsule_player.b = c2V(350,100);
		c2Capsule_player.a.x = 100;
		c2Capsule_player.a.y = 200;
		c2Capsule_player.b.x = 100;
		c2Capsule_player.b.y = 200;

		c2Capsule_player.r = 50;

		c2Circle c2Circle_player;
		c2Circle_player.p.x = 400;
		c2Circle_player.p.y = 50;
		c2Circle_player.r = 50;

		if(c2AABBtoCapsule(aabb_player,c2Capsule_player))
		{
			cout << "Player capsule collide" << endl;
			player_sprite.setColor(sf::Color::Green);
		}

		if(c2AABBtoAABB(aabb_npc, aabb_player)){
			cout << "NPC and Player are in Collision" << endl;
			player_sprite.setColor(sf::Color::Red);
		}

		if(c2CircletoAABB(c2Circle_player, aabb_player))
		{
			cout << "Circle player collide" << endl;
			player_sprite.setColor(sf::Color::Blue);
			CircleCollide.setFillColor(sf::Color::White);
		}
	}
}

void Game::draw()
{
	window->clear();
	window->draw(player_sprite);
	window->draw(npc_sprite);
	window->draw(CircleCollide);
	//player->draw();
	//npc->draw();
	window->display();
}


