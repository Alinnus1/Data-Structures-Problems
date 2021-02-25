#include <fstream>
#include <vector>
#include <algorithm>
#define INF 2000000000;

using namespace std;

int n, m, i, j, k, dim, nrf;
int fort[50001], dist[50001], drum[50001], heap[50001], poz[50001], tata[50001];
vector<pair<int, int>> d[50001];


void read() {
    f >> n >> m >> nrf;
    for(i = 0; i < nrf; i++)
        f >> fort[i];
    while(m)
    {
        f >> i >> j >> k;
        d[i].emplace_back(j, k);
        d[j].emplace_back(i, k);
        m--;
    }
    f.close();
}
void pushup(int p) {
    int dst;

    dst = dist[heap[p]];        /// distanta pana la nodul de pe pozitia p
    while(p > 1 && dst < dist[heap[p / 2]]) {
        poz[heap[p]] = p / 2;   /// pentru ca interschimbam valorile, trebuie sa interschimbam pozitiile in heap
        poz[heap[p / 2]] = p;
        swap(heap[p], heap[p / 2]);
        p /= 2;
    }
}

void pushdown(int p) {
    int fiu;
    fiu = 1;
    while(fiu) {
        fiu = 0;
        if(p * 2 <= dim)
        {                      /// daca avem cel putin un fiu
            fiu = p * 2;
            if(p * 2 + 1 <= dim && dist[heap[p * 2 + 1]] < dist[heap[p * 2]])
                fiu = p * 2 + 1;                /// alegem fiul pentru care avem cost minim
            if(dist[heap[fiu]] > dist[heap[p]]) /// daca fiul cu distanta minima are distanta mai mare decat distanta pana la tatal lui, ne oprim
                fiu = 0;
        }
        if(fiu) {
            swap(heap[fiu], heap[p]);           /// interschimb valorile din fii
            swap(poz[heap[p]], poz[heap[fiu]]); /// interschimb pozitiile din heap ale valorilor
            p = fiu;
        }
    }
}

int main()
{
    ifstream f("catun.in");
    ofstream g("catun.out");

    read();

    sort(fort + 0, fort + nrf);
    dim = 0;    /// dimensiune heap
    for(i = 0; i < nrf; i++)
    {
        drum[fort[i]] = dist[fort[i]] = 0;
        heap[++dim] = fort[i];
        poz[fort[i]] = dim;
        tata[fort[i]] = fort[i];
    }
    j = 0;
    for(i = 1; i <= n; i++)
        if(j == nrf || i < fort[j])
        {
            drum[i] = dist[i] = INF;    /// drumul & distanta minima pana la nodul i
            heap[++dim] = i;                /// construiesc heap-ul
            poz[i] = dim;                   /// pozitia elementului i in heap
            tata[i] = 0;                    /// fortareata de care apartine i
        }
        else if(i == fort[j])
            j++;

    i = heap[1];
    for(k = 1; k <= n; k++) {
        for(j = 0; j < d[i].size(); j++)
            if(drum[i] + d[i][j].second < drum[d[i][j].first])
            {    /// pot micsora distanta ?
                dist[d[i][j].first] = drum[d[i][j].first] = drum[i] + d[i][j].second;
                tata[d[i][j].first] = tata[i];             /// tatal nodului pana la care pot micsora distanta
                pushup(poz[d[i][j].first]);                /// actualizam pozitia nodului in heap
            }
            else if(drum[i] + d[i][j].second == drum[d[i][j].first] && tata[i] < tata[d[i][j].first])
                tata[d[i][j].first] = tata[i];

        dist[i] = INF;    /// cand nodul este folosit, i se atribuie o distanta mare, pentru a reface heap-ul
        pushdown(1);       /// refac heap-ul
        i = heap[1];          /// aleg mereu nodul din heap pana la care am distanta minima
    }

    for(i = 0; i < nrf; i++)
        tata[fort[i]] = 0;
    for(i = 1; i <= n; i++)
        g << tata[i] << ' ';
    g << '\n';
    g.close();

    return 0;
}
