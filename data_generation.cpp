#include<stdio.h>
#include<random>

const int N = 4096 * 4096 * 16;

using namespace std;

int main()
{
    freopen("vecmult.in", "w", stdout);
    int len = N;
    printf("%d\n", len);

    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 32767);

    for(int i = 0; i < len; i ++){
        printf("%d ", u(e));
    }
    printf("\n");

    for(int i = 0; i < len; i ++){
        printf("%d ", u(e));
    }
    printf("\n");
    
    return 0;
}