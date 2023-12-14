#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>


int main()
{
    std::fstream inf("vmm1.in");
    std::fstream ouf("vmmo1.out");
    int n;
    inf >> n;
    int * v = (int *)aligned_alloc(32, n * sizeof(int));
    int * m = (int *)aligned_alloc(32, n * n * sizeof(int*));
    int * res = (int *)aligned_alloc(32, n * sizeof(int));


    for(int i = 0; i < n * n; i++)
    {
        inf >> m[i];
    }

    for(int i = 0; i < n; i++)
    {
        inf >> v[i];
    }

    for(int i = 0; i < n * n / 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << "*(m + j) is " << *(m) << std::endl; 
            std::cout << "*(v + j) is " << *(v) << std::endl; 
            m++;
            v++;
        }
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    int sum = 0;

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