struct Game {

    void ChangeHpON(auto* target, int value) {
        target->hp += value;
    }

    void SetHpOn(auto* target, int value) {
        target->hp = value;
    }

    void ChangeDamageOn(auto* target, int value) {
        target->damage += value;
    }

    void SetDamageOn(auto* target, int value) {
        target->damage = value;
    }

    void AddMana(Player* player, int value) {
        player->mana += value;
    }

};