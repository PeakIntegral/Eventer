#include "Utilities.h"
#include "Creature.h"
#include "Character.h"
#include "NPC.h"
#include <SFML/Graphics.hpp>
class Game {
public:
    Game();
    Game(int gamenum);

    // -- предварительные объ€влени€ функций (всех, кроме main) --
    void createWindow(sf::RenderWindow& window, string gamename);
    void initializeCreatures(string name_characters);
    void handleEvents(sf::RenderWindow& window);
    void update(sf::Clock& clock, sf::CircleShape& shape);
    void render(sf::RenderWindow& window, sf::CircleShape& shape);
    
};