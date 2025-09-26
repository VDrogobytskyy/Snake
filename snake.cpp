#include "snake.h"


bool Snake :: is_snake_inside_zone(const PairVec &snake_position){
    for(const auto &index : snake_position){
        int x_pos = index.first;
        int y_pos = index.second;

        if(x_pos <= 0 || x_pos >= 16) return false;
        if(y_pos <= 0 || y_pos >= 21) return false;
    }

    return true;
};


void Snake :: snake_moving(const PairVec &snake_position){
    int x_pos = snake_position[0].first;
    int y_pos = snake_position[0].second;

    if(is_snake_inside_zone(snake_position)){
        zone[x_pos][y_pos] = 9;
    }

    show();
}

void Snake :: set_snake_pos(int x, int y){
    PairVec temp = { {x, y} };

    if(!snake_pozition.empty() && is_snake_inside_zone(temp)){
        snake_pozition[0] = { x, y };
    }else{
        throw "there is no snake";
    }
}
