#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#define INF 50001


using namespace std;
ifstream f ("grafpond.in");
vector<tuple <int, int, int>> ListM;
queue<int> Coada;
int GradInt[INF], d [INF],tata[INF];
int N,M;


void read()
{
    f>>N>>M;
    int x,y,z;
    for( int i= 0; i<M ; i++)
    {
        f>>x>>y>>z;
        ListM.push_back(make_tuple(x,y,z));
    }
}

void dijkstra() {

    queue<int> q;

    for ( int i=0;i<Sortare.size();i++)
    {
        q.push(Sortare[i]);
    }
    for(int i=0;i<=N;i++)
    {
        d[i]=INF;
        tata[i]=0;
    }
    d[0]=0;
    int u,a,b,c;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0;i<ListM.size();i++)
        {
            tie(a,b,c)=ListM[i];

            if(a==u)
            {
                if(d[a]+c<d[b])
                {
                    d[b]=d[a]+c;
                    tata[b]=a;

                }
            }
        }
        cout<<"\n";

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
