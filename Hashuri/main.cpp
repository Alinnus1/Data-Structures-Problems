#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;
#define MOD 666013

int N;
vector<int> G[MOD];

inline vector<int>::iterator find(int x)
{
    int list = x % MOD;
    vector<int>::iterator it;

    for (it = G[list].begin(); it != G[list].end(); ++it)
        if (*it == x)
            return it;
    return G[list].end();
}

inline void insert(int x)
{
    int list = x % MOD;
    if (find(x) == G[list].end())
        G[list].push_back(x);
}

inline void erase(int x)
{
    int list = x % MOD;
    vector<int>::iterator it = find(x);

    if (it != G[list].end())
        G[list].erase(it);
}

int main()
{
    ifstream f("hashuri.in");
    ofstream g("hashuri.out");
    int op, x;

    for (f>>N; N; --N)
    {
        f>>op>>x;
        if (op == 1) // inserare
        {
            insert(x);
            continue;
        }

        if (op == 2) // stergere
        {
            erase(x);
            continue;
        }
        if(op ==3)
        {
            if(find(x) == G[x % MOD].end())
                g<<"0\n";
            else
                g<<"1\n";
            continue;
        }
    }
    return 0;
}
