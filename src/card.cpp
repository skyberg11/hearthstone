#include "card.h"

MonsterCard::MonsterCard():
        cardType(monster)
    {}

EffectCard::EffectCard():
        cardType(effect)
    {}

Deck::Deck():
        deck(GetRandomPreset())
    {}
bool Deck::IsAvailable() {
    return deck.empty();
}

Card Deck::GetUpperCard() {
    Card tmp = deck.back();
    deck.pop_back();
    return tmp;
}

#endif //PROJECT__CARD_H_
