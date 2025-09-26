#ifndef SNAKE_H
#define SNAKE_H


#include "map.h"
#include <vector>
#include <utility>

typedef std::vector<std::pair<int, int>> PairVec;

class Snake : public Play_zone{
    public:
        
        PairVec snake_pozition;
        bool is_snake_inside_zone(const PairVec &snake_pozition);
        Snake() : snake_pozition{ std::make_pair(7,6) } {}
        void snake_moving(const PairVec &snake_position);

        PairVec get_snake_pos(){
            return snake_pozition;
        }

        void set_snake_pos(int x, int y);
};



#endif