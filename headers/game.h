class Mortal {
    private:
    int life;
    size_t damage

    public:
    void DealDamage(Mortal* target) {
        Game::ChangeHpON(target, -damage);
    }

}


struct Game {

    void GarbageCollector(Player* first, Player* second) {
        for(auto it : first->laid_cards) {
            if(it->life <= 0) {
                first->laid_cards.erase(it);
            }
        }
        for(auto it : second->laid_cards) {
            if(it->life <= 0) {
                second->laid_cards.erase(it);
            }
        }
        return
    }


    void ChangeHpON(Mortal* target, int value) {
        target->hp += value;
    }

    void SetHpOn(Mortal* target, int value) {
        target->hp = value;
    }

    void ChangeDamageOn(Mortal* target, int value) {
        target->damage += value;
    }

    void SetDamageOn(Mortal* target, int value) {
        target->damage = value;
    }

    void AddMana(Player* player, int value) {
        player->mana += value;
    }

};