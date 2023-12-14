#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>


int main()
{

    auto start_time = std::chrono::high_resolution_clock::now();

    std::fstream inf("vecmult.in");
    std::fstream ouf("vecmulto.out");
    int n;
    inf >> n;
    int * v1 = (int *)aligned_alloc(32, n * sizeof(int));
    int * v2 = (int *)aligned_alloc(32, n * sizeof(int));
    int * res = (int *)aligned_alloc(32, n * sizeof(int));

    int tmp;
    for(int i = 0; i < n; i++)
    {
        inf >> v1[i];
    }
    for(int i = 0; i < n; i++)
    {
        inf >> v2[i];
    }
    int result;

    for(int i = 0; i < n; i++)
    {
        ouf << v1[i] * v2[i] << " ";
    }

    free(v1);
    free(v2);
    free(res);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Before AVX acceleration, time taken: " << duration.count() << " milliseconds" << std::endl;
}