#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    if ( n == 0 ){
        return true;
    }

    int livre = 0;
    int i = 0;

    if ( flowerbedSize == 1 ) {
        if ( flowerbed[0] == 0 ) {
            livre++;
            if ( livre == n ) {
                return true;
            }
        }
        return false;
    }

    if ( flowerbedSize == 2 ) {
        if ( flowerbed[0] == 0 && flowerbed[1] == 0 ) {
            livre++;
            if ( livre == n )
                return true;
        }
        return false;
    }

    if ( flowerbedSize >= 3 ) {
        if ( flowerbed[i] == 0 ) {
            if ( flowerbed[i + 1] == 0 ) {
                livre++;
                flowerbed[i] = 1;
                if ( livre == n ) {
                    return true;
                }
            }
        }

        if ( flowerbed[flowerbedSize - 1] == 0 ) {
            i = flowerbedSize - 1;
            if ( flowerbed[i - 1] == 0 ) {
                flowerbed[i] = 1;
                livre++;
                if ( livre == n ) {
                    return true;
                }
            }
        }

        for ( i = 1; i < flowerbedSize - 1; i++ ) {

            if ( flowerbed[i] == 0 ) {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    livre++;
                    if (livre == n)
                        return true;
                }
            }
        }
    }
    return false;
}


int main () 
{

    int flowerbedSize = 5;
    int flowerbed[] = {1,0,0,0,1};
    int n = 1;

    printf( "%d\n", canPlaceFlowers ( flowerbed, flowerbedSize, n ) );

    return 0;
}
