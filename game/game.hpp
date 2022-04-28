#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "map.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include "movingenemy.hpp"
#include "hostage.hpp"
#include "constants.hpp"
#include <vector>
#include <string>

class Game
{
    public: 
        Game(const std::string map_file_name);
        void render();
        void run(int round);
        void handle_key_press(int dir);
        bool process_event();
        void create_enemies();
        void spaceship_hit_enemy();
        void enemies_hit_spaceship();
        void spaceship_hit_hostage();
        void kill_enemy(int index);
        bool can_enemies_shoot();
        void enemies_shoot();
        void enemies_bullets_move();
        void spaceship_touch_others();
        void spaceship_touch_enemy();
        void spaceship_touch_hostage();
        void move_enemies();
        void player_lose();
        void player_win();
        bool is_lost();
        void win_check(int cur_round);
        void end();
        bool get_result() { return result; }       
        int get_rounds() { return rounds; }
        void translate_map(Map &map, int offset);
        void init_round(int round);
        void receive_initial_data(std::vector<std::string> map_lines);
        void create_object(int type, MapScale scale);
    private:
        Map map;
        Window* win;
        int columns;
        int rows;
        int counter;
        int rounds;
        int objects_number;
        Spaceship spaceship;
        std::vector<Enemy*> enemies;
        std::vector<Hostage*> hostages;
        int result;
};
#endif