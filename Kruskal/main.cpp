#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream f ("grafpond.in");
vector<tuple <int, int, int>> ListM;
vector<tuple <int, int, int>> Solutie;
int r[10005],tata[10005],h[10005];
int N,M;
int nrmsel;

void read ()
{
    f>>N>>M;
    for( int i= 0; i<M ; i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        ListM.push_back(make_tuple(x,y,z));
    }
}
void Init (int u) { r[u] = u; }

int Reprez (int u) { return r[u];}

void Reuniune( int u, int v)
{
    int r1,r2;
	r1 = r[u];
	r2 = r[v];

	for(int i = 0; i < N; i++)
		if (r[i] == r1) r[i] = r2;
}

void Init1 (int u) { tata[u] =h[u]=0; }

int Reprez1 (int u)
{
    while(tata[u]!=0)
        u=tata[u];
    return u;
}

void Reuniune1 ( int u, int v)
{
    int r1,r2;
	r1 = Reprez1(u);
	r2 = Reprez1(v);

	if(h[r1] > h[r2])
		tata[r2] = r1;
	else
        {
            tata[r1] = r2;
            if (h[r1] == h[r2])
                h[r2]++;
        }
}

void kruskal()
{
    sort(ListM.begin(), ListM.end(), [](tuple<int,int,int> a, tuple<int,int,int> b)
         {return get<2>(a) < get<2>(b);});
    for (int v =1;v<=N;v++)
        Init(v);
    nrmsel = 0;
    for (int i=0;i<M;i++)
    {
        int u=get<0>(ListM[i]);
        int v=get<1>(ListM[i]);
        if(Reprez(u) != Reprez(v) )
        {
            Solutie.push_back(ListM[i]);
            Reuniune(u,v);
            nrmsel=nrmsel +1;
            if(nrmsel== N-1)
                break;
        }
    }
}
void kruskal1()
{
    sort(ListM.begin(), ListM.end(), [](tuple<int,int,int> a, tuple<int,int,int> b)
         {return get<2>(a) < get<2>(b);});
    for (int v =1;v<=N;v++)
        Init1(v);
    nrmsel = 0;
    for (int i=0;i<M;i++)
    {
        int u=get<0>(ListM[i]);
        int v=get<1>(ListM[i]);
        int Repu =Reprez1(u);
        int Repv =Reprez1(v);

        if(Repu != Repv)
        {
            Solutie.push_back(ListM[i]);
            Reuniune1(Repu,Repv);
            nrmsel=nrmsel +1;
            if(nrmsel== N-1)
                break;
        }
    }
}

int main()
{
    int a,b,c;
    read();
    kruskal1();
    for ( int i=0;i<Solutie.size();i++)
    {
        tie(a,b,c)=Solutie[i];
        cout<<a<<" "<<b<< " "<<c<< " "<<"\n";
    }
    Solutie.clear();

    return 0;
}
