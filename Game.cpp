#include "Game.h"
// -- объявления констант --
const unsigned ANTIALIASING_LEVEL = 8;
const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 600;
const unsigned MAX_FPS = 60;
// Начальная позиция фигурки в пикселях.
static const sf::Vector2f CHARACTER_INITIAL_POSITION = { 100, 0 };

string game_name;
unique_ptr<Creature> main_character;
vector<unique_ptr<Creature>> enemies;

Game::Game(){
}

Game::Game(int gamenum) {
    
    sf::RenderWindow window;
    switch (gamenum) {
    case 1:
        game_name = "PacMan";
        break;
    case 2:
        game_name = "SnakeGame";
        break;
    default:
        break;
    }
    createWindow(window, game_name);
    initializeCreatures(game_name);
    sf::Clock clock;
    while (window.isOpen())
    {
        handleEvents(window);
        update(clock, main_character->shape);
        render(window, main_character->shape);
    }
}

// Функция создаёт окно приложения.
void Game::createWindow(sf::RenderWindow& window, string gamename)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTIALIASING_LEVEL;
    window.create(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        gamename, sf::Style::Default, settings);
    window.setFramerateLimit(MAX_FPS);
}

void Game::initializeCreatures(string name_characters){
    main_character = make_unique<Character>();
    main_character->shape.setPosition(CHARACTER_INITIAL_POSITION);
}

// Функция обрабатывает все события, скопившиеся в очереди событий SFML.
void Game::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            main_character->Creature::handleCreatureKeyPress(event.key);
        }
        else if (event.type == sf::Event::KeyReleased) {
            main_character->Creature::handleCreatureKeyRelease(event.key);
        }
    }
}

// Функция обновляет фигурку.
void Game::update(sf::Clock& clock, sf::CircleShape& shape)
{
    const float elapsedTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    main_character->updateCreature(elapsedTime);
}

// Функция рисует фигуру пакмана.
void Game::render(sf::RenderWindow& window, sf::CircleShape& shape)
{
    window.clear();
    window.draw(shape);
    window.display();
}


