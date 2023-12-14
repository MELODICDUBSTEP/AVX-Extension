#include<stdio.h>
#include<random>

const int N = 4096;

using namespace std;

int main()
{
    freopen("vmm.in", "w", stdout);
    int len = N;
    printf("%d\n", len);

    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 32767);

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++){
            printf("%d ", u(e));
        }
    printf("\n");
    }

    for(int i = 0; i < len; i ++){
        printf("%d ", u(e));
    }
    printf("\n");
    
    return 0;
}