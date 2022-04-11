#include "card.h"
#include "player.h"

struct Target {
    vector<Player*> players;
    vector<card*> cards;
};

struct Ability {
    Target targets;
    int change_HP_on;
    int set_HP_on;
    int change_damage_on;
    int set_damage_on;
    int set_mana;
};