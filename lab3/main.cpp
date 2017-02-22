#include "hookbook.h"

const int SIZE = 12;
int main()
{
    
    string color[] = {"red", "blue", "grey", "white", "orange", "burnt sienna", "puse", "black", "cerulean", "dandelion", "cyan", "mauve"};
    
    HookBook hb;
    
    
    for (int i = 0; i < SIZE; i++) {
        hb.addPirate(i, color[i]+" beard");
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j=0; j < i; j++) {
            if(i != j)
            {
                hb.addFriend(i, j);
            }
        }
    }
    
    hb.print();
    
    
    
    return 0;
}