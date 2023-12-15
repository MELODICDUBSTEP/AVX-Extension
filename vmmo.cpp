#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>


int main()
{
    std::fstream inf("vmm.in");
    std::fstream ouf("vmmo.out");
    int n;
    inf >> n;
    long long * v = (long long *)aligned_alloc(64, n * sizeof(long long));
    long long * m = (long long *)aligned_alloc(64, n * n * sizeof(long long));
    long long * res = (long long *)aligned_alloc(64, n * sizeof(long long));


    for(int i = 0; i < n * n; i++)
    {
        inf >> m[i];
    }

    for(int i = 0; i < n; i++)
    {
        inf >> v[i];
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += m[i * n + j] * v[j];
        }    
        res[i] = sum;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    for(int i = 0; i < n; i++)
    {
        ouf << res[i] << " ";
    }

    free(v);
    free(m);
    free(res);

    std::cout << "Before AVX acceleration, execution time taken: " << duration.count() << " milliseconds" << std::endl;
}