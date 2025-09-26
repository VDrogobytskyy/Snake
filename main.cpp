#include <iostream>
#include <chrono>
#include <thread>

#include "map.h"
#include "snake.h"



int main(void){
    std::cout << std::endl;

    Snake snake;
    Play_zone zone;

    

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        snake.snake_moving(snake.snake_pozition);
        PairVec temp = snake.get_snake_pos();
        int x_pos = temp[0].first;
        int y_pos = temp[0].second;

        snake.set_snake_pos(x_pos + 1, y_pos);
        

    }

    std::cout << std::endl;
    return 0;
}