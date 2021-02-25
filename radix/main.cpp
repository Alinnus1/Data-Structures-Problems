#include <iostream>
#include <fstream>
#include <vector>

void RadixSort(std::vector<long long> &v, int baza)
{
    std::vector<long long> bucket(v.size(),0);
    int mmax=0, pozitie=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>mmax)
            mmax = v[i];
    }
    while(mmax/pozitie>0)
    {
        int digitCount[baza] = {0};

        for(int i=0;i<v.size();i++)
            digitCount[v[i]/pozitie%10]++;
        for (int i=1;i<baza;i++)
            digitCount[i]+=digitCount[i-1];
        for(int i=v.size()-1;i>=0;i--)
        {
            bucket[digitCount[v[i]/pozitie%10]-1]=v[i];
            digitCount[v[i]/pozitie%10]--;
        }
        for(int i=0;i<v.size();i++)
            v[i]=bucket[i];
        pozitie*=10;
    }

}


int main()
{

    std::ifstream f("radixsort.in");
    std::ofstream g("radixsort.out");
    int N,A,B,C;
    f>>N>>A>>B>>C;
    std::vector<long long> v;
    v.push_back(B);
    for(int i=1;i<N;i++)
    {
        v.push_back((A * v[i-1] + B) % C);
    }
    RadixSort(v,10);
    for(int i=0;i<N;i+=10)
    {
        g<<v[i]<<' ';
    }


    f.close();
    g.close();



    return 0;
}
