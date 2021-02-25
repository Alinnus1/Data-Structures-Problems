#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, max = 0;

    string cuvant;
    map<string, int> freq;

    cin>>N;
    while(N--)
    {
        cin >> cuvant;
        sort(cuvant.begin(), cuvant.end());
        freq[cuvant] ++;
    }
    for(auto it: freq)
    {
        if(it.second > max)
            max = it.second;
    }
    cout << max;
}
2 1 2 3 2 3
