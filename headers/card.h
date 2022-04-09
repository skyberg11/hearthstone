//
// Created by ztimu on 27.03.2022.
//

#ifndef PROJECT__CARD_H_
#define PROJECT__CARD_H_

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
    int life;
    int attackHit;

    MonsterCard();
};

struct EffectCard : Card {
    Target target;

    EffectCard();
};

class Deck {
    private:
    vector<Card>deck;

    public:
    Deck();

    bool IsAvailable();
    Card GetUpperCard();
};

#endif //PROJECT__CARD_H_
