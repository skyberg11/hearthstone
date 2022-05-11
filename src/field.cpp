#pragma once

#include <iostream>
#include <fstream>
#include "field.h"

// using std::filesystem::current_path;

Deck::Deck() {
    std::ifstream d_file;
    d_file.open("../../data/card");
    // freopen("../../data/card", "r", stdin);
    // stdin=fopen("../../data/card", "r");
    while (d_file) {
        std::string card_name;
        d_file >> card_name;
        std::cout << card_name << ' ';
        int card_hp, card_mana, card_dmg;
        d_file >> card_mana >> card_hp >> card_dmg;
        std::string ability_name;
        d_file >> ability_name;
        int change_hp, change_damage;
        size_t add_mana;
        bool hero_friendly, hero_bad;
        d_file >> change_hp >> change_damage >> 
        add_mana >> hero_friendly >> hero_bad;
        Ability ability(ability_name, change_hp, change_damage, add_mana, hero_friendly, hero_bad);
        MonsterCard* card = new MonsterCard(card_name, card_mana, card_hp, card_dmg, ability);
        deck.push_back(reinterpret_cast<Card*>(card));
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    d_file.close();
}

bool Deck::IsAvailable() {
    return deck.empty();
}

Card* Deck::GetUpperCard() {
    Card* tmp = deck.back();
    deck.pop_back();
    return tmp;
}
