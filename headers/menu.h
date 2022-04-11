 namespace Game {
     
    void Builder() {


    }

    enum WhosMove {
        first,
        second,
        idle
    };

    static game_status = idle;

    bool IsGameEnd() {
        return first.IsDead() || second.IsDead();
    }

    void StartGame() {
        Builder();
        while(IsGameEnd()) {
            Player& current_player;
            switch(game_status) {
                case idle:
                    game_status = first;
                    current_player = first;
                    break;
                case first:
                    game_status = second;
                    current_player = second;
                    break;
                default:
                    game_status = first;
                    current_player = first;
                    break;
            }
            current_player::Move();
        }
    }
}