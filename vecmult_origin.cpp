#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>


int main()
{
    std::fstream inf("vecmult.in");
    std::fstream ouf("vecmulto.out");
    int n;
    inf >> n;
    int * v1 = (int *)aligned_alloc(32, n * sizeof(int));
    int * v2 = (int *)aligned_alloc(32, n * sizeof(int));
    int * res = (int *)aligned_alloc(32, n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        inf >> v1[i];
    }
    for(int i = 0; i < n; i++)
    {
        inf >> v2[i];
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < n; i++)
    {
        res[i] = v1[i] * v2[i];
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    for(int i = 0; i < n; i++)
    {
        ouf << res[i] << " ";
    }

    free(v1);
    free(v2);
    free(res);

    std::cout << "Before AVX acceleration, execution time taken: " << duration.count() << " milliseconds" << std::endl;
}