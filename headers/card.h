#include <bits/stdc++.h>

enum CardType {
    effect,
    monster
};

struct Card {
    CardType cardType;
};

struct Target {
    player,
    monster
};

struct MonsterCard : Card {
    size_t mana_cost;
    int life;
    size_t damage;

    MonsterCard():
        cardType(monster)
    {}
};

struct EffectCard : Card {
    Target target;

    EffectCard():
        cardType(effect)
    {}
};

class Deck
{
    protected:

    vector<Card>deck;

    Deck():
    {
        //Generation of Deck;
    }

    static Deck* deck_;

    public:
    Deck(Deck &other) = delete;
    void operator=(const Deck &) = delete;

    bool IsAvailable() {
        return deck_.empty();
    }
    Card GetUpperCard() {
        Card tmp = deck_.back();
        deck_.pop_back();
        return tmp;
    }
};
