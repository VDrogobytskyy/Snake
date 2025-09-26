#include "map.h"

Play_zone :: Play_zone(){

    for(int i = 0; i < 16; i++){
        for(int k = 0; k < 21; k++){

            if(i == 0 || i == 15 || k == 0 || k == 20){
                zone[i][k] = 7;

            }else{
                zone[i][k] = 0;
            }
        }
    }

    
    
}

void Play_zone :: show(){
    clear_screen();
    for(int i = 0; i < 16; i++){
        for(int k = 0; k < 21; k++){


            if(zone[i][k] == 0) {
                std::cout << "  ";
                continue;
            }

            std::cout << zone[i][k] << " ";
        }
        std::cout << std::endl;
    }

}