#include <iostream>

#include "map.h"
#include "snake.h"


int main(void){
    std::cout << std::endl;

    Snake snake;
    Play_zone zone;

    snake.snake_moving(snake.snake_pozition);

    std::cout << std::endl;
    return 0;
}