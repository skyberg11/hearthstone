#include "card.h"

MonsterCard::MonsterCard():
        cardType(monster)
    {}

EffectCard::EffectCard():
        cardType(effect)
    {}

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

#endif //PROJECT__CARD_H_
