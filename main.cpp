#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "map.h"
#include "snake.h"



void set_own_terminal_mode() {
    termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void reset_terminal_mode() {
    termios termios_p;
    tcgetattr(STDIN_FILENO, &termios_p);
    termios_p.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
}

void set_nonblocking(bool enable) {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    if (enable) {
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    } else {
        fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
    }
}

char get_input() {
    char buf = 0;
    if (read(STDIN_FILENO, &buf, 1) > 0) {
        return buf; 
    }
    return 0; 
}

int main(void){
    std::cout << std::endl;

    set_own_terminal_mode();
    set_nonblocking(true);

    Snake snake;
    Play_zone zone;


    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        snake.snake_moving(snake.snake_pozition);
        PairVec temp = snake.get_snake_pos();
        int x_pos = temp[0].first;
        int y_pos = temp[0].second;

        char input = get_input();

       if(input == 0){
            
            snake.set_snake_pos(x_pos + 1, y_pos);
        } 
        else if(input == 'd') {
            snake.set_snake_pos(x_pos, y_pos + 1);
        } 
        else if(input == 'a') {
            snake.set_snake_pos(x_pos, y_pos - 1);
        } 
        else if(input == 'w') {
            snake.set_snake_pos(x_pos - 1, y_pos);
        } 
        else if(input == 's') {
            snake.set_snake_pos(x_pos + 1, y_pos);
        }

        snake.snake_moving(snake.snake_pozition);
        


    }


    reset_terminal_mode();
    set_nonblocking(false);

    std::cout << std::endl;
    return 0;
}