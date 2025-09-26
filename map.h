#ifndef MAP_H
#define MAP_H

#include <iostream>

class Play_zone{
    protected:
        int zone[16][21];

    public:
        int (&get_zone())[16][21] { return zone; }
        Play_zone();
        void show();

   
};



#endif 