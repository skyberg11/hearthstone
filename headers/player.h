#include <vector>
#include "effects.h"
#include "card.h"

enum life {
    alive = true,
    dead = false
};

class Player {
    private:
    bool status;
    int life;
    int damage;

    std::vector<Effect> effects;
    void CastCard(const Card& cast) {

    };

    class Hand {
        std::vector<Card> cards;
        void push(const Card& card) {
            cards.push_back(card);
        }
    };

    public:

    Player():
        life(30),
        effects(std::vector<Effect>()),
        status(alive)
    {}

    ~Player();

    bool IsDead const {
        return status;
    };

    void Move();
};
