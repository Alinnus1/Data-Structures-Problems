#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#define NMAX 630

std::vector<int> v[5+NMAX];
int N,M,K,L;
long long int sol=1LL;
long long int findMissingPositive(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (int i = 0; i < size; i++)
        if (arr[i] > 0)
            return i + 1;

    return size + 1;
}


void mex(int linie){

    int x=L;
    int y=1;
    while(x<=M)
    {
        int arr[400000+5];
        memset(arr,0,sizeof(arr));
        int u=0;
        for(int j=y;j<=x;j++)
        {
            for(int k=0;k<K;k++){
                arr[u]=v[linie+k][j];
                u++;
            }
        }
        sol=sol*findMissingPositive(arr,u+1);
        x+=1;
        y+=1;
    }
}

int main()
{
    std::ifstream f("mexitate.in");
    std::ofstream g("mexitate.out");

    f>>N>>M>>K>>L;
    for(int i=1;i<=std::min(N,M);i++)
        v[i].push_back(0);
    if (N>M){
        std::swap(N,M);
        std::swap(K,L);
        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=N;j++)
            {
                int val;
                f>>val;
                v[j].push_back(val);
            }
        }

    }else{
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                int val;
                f>>val;
                v[i].push_back(val);
            }
        }
    }
    for(int i=1;i<=N-K+1;i++)
    {
        mex(i);
    }
    g<<sol%(1000000007);

    return 0;
}
