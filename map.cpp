#include "map.h"

Play_zone :: Play_zone(){

    for(int i = 0; i < 15; i++){
        for(int k = 0; k < 20; k++){

            if(i == 0 || i == 14 || k == 0 || k == 19){
                zone[i][k] = 7;

            }else{
                zone[i][k] = 0;
            }
        }
    }
}

void Play_zone :: show(){

    for(int i = 0; i < 15; i++){
        for(int k = 0; k < 20; k++){

            if(zone[i][k] == 0) {
                std::cout << "  ";
                continue;
            }

            std::cout << zone[i][k] << " ";
        }
        std::cout << std::endl;
    }

}