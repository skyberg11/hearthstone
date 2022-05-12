#pragma once

#include "field.h"

Deck::Deck() {
    freopen("../data/cards", "r", stdin);
    while (!feof(stdin)) {
        std::string card_name;
        std::cin >> card_name;
        int card_hp, card_mana, card_dmg;
        std::cin >> card_mana >> card_hp >> card_dmg;
        std::string ability_name;
        std::cin >> ability_name;
        int change_hp, change_damage;
        size_t add_mana;
        bool hero_friendly, hero_bad;
        std::cin >> change_hp >> change_damage >> 
        add_mana >> hero_friendly >> hero_bad;
        Ability ability(ability_name, change_hp, change_damage, add_mana, hero_friendly, hero_bad);
        MonsterCard* card = new MonsterCard(card_name, card_mana, card_hp, card_dmg, ability);
        deck.push_back(reinterpret_cast<Card*>(card));
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    fclose(stdin);
}

bool Deck::IsAvailable() {
    return deck.empty();
}

Card* Deck::GetUpperCard() {
    Card* tmp = deck.back();
    deck.pop_back();
    return tmp;
}
