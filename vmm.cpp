#include <iostream>
#include <immintrin.h>
#include <fstream>
#include <chrono>

/*
[][][][][][][][]
*/

int main() {

    std::fstream inf("vmm.in");
    std::fstream ouf("vmm.out");
    int n;
    inf >> n;
    long long * v = (long long *)aligned_alloc(64, n * sizeof(long long));
    long long * m = (long long *)aligned_alloc(64, n * n * sizeof(long long));
    long long * res = (long long *)aligned_alloc(64, n * sizeof(long long));

    long long * Tmp = (long long *)aligned_alloc(64, 4 * sizeof(long long));

    long long * ttt = v;

    for(int i = 0; i < n * n; i++)
    {
        inf >> m[i];
    }

    for(int i = 0; i < n; i++)
    {
        inf >> v[i];
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    __m256i * v1 = (__m256i*)v;
    __m256i * m1 = (__m256i*)m;
    __m256i * r = (__m256i*)res;
    __m256i * Tmp1 = (__m256i*)Tmp;

    __m256i * temp = v1;

    for(int i = 0; i < n * n / 4; )
    {
        // for(int j = 0; j < 4; j++)
        // {
        //     std::cout << "*(m + j) is " << *(m) << std::endl; 
        //     std::cout << "*(v + j) is " << *(v) << std::endl; 
        //     m++;
        //     if(i * 4 % n == 0)
        //     {
        //         v = ttt;
        //     }
        //     else
        //     {
        //         v++;
        //     }
        // }
        
        *Tmp1 = _mm256_add_epi64(*Tmp1, _mm256_mullo_epi32(*m1, *v1));
        
        m1++;
        i++;
        // std::cout << "i is " << i << std::endl;
        // std::cout << "i * 4 mod n is " << i * 4 % n << std::endl;
        // std::cout << "i * 4 / n is " << i * 4 / n << std::endl;
        if(i * 4 % n == 0)
        {
            v1 = temp;
            for(int k = 0; k < 4; k++)
            { 
                res[i * 4 / n - 1] += Tmp[k];
                Tmp[k] = 0;
                //std::cout << "Now k is " << k << " and Tmp[k] is " << Tmp[k] << std::endl;
            }
        }
        else
        {
            v1++;
        }

    }
    //std::cout << "n is " << n << std::endl;

    // long long * tmp = res;
    // for(int i = 0; i < n; i++)
    // {
    //     //std::cout << "res is " << *(tmp) << std::endl;
    //     tmp++;
    // }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    for (int i = 0; i < n; ++i) {
        ouf << res[i] << " ";
    }

    // free(v);
    // free(m);
    // free(res);

    std::cout << "After AVX acceleration, execution time taken: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
