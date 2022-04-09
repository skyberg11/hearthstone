//
// Created by ztimu on 27.03.2022.
//
#include <vector>
#include "effects.h"
#include "card.h"
#ifndef PROJECT__PLAYER_H_
#define PROJECT__PLAYER_H_

enum life : bool {
    alive = true,
    dead = false;
};

class Player {
    private:
    bool status;
    int life;
    std::vector<Effect> effects;
    void CastCard(const Card& cast) {

    };
    class Hand {
        std::vector<Card> cards;
        void push(const Card& card);
    };

    public:

    Player();

    ~Player();

    bool IsDead const;

    void Move();
};

#endif //PROJECT__PLAYER_H_
