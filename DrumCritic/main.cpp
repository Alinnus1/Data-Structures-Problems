#include<iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <queue>
#define INF 50001
using namespace std;

ifstream f ("activitati.in");

vector<int> Durata;
vector<tuple <int, int>> Intervale;
vector<tuple <int, int, int>> ListM;
vector<int> Sortare;
queue<int> Coada;
int GradInt[INF], d [INF],tata[INF];
int N,M;

void read () {
    f>>N;
    Durata.resize(N+1);
    for( int i =1;i<=N;i++)
        f>>Durata[i];
    f>>M;
    Intervale.resize(M+1);
    for ( int i =1 ; i<=M;i++)
    {
        int x,y;
        f>>x>>y;
        Intervale[i]=make_tuple(x,y);
        GradInt[y]++;
    }

}

void graf() {
    // creez graful adaugand si un varf initial 0 care se leaga de toate celelalte varfuri
    // costul de la 0 la x va fi costul lui x iar costul x y va fi y
    int x,y;
    for ( int i =1 ; i<=N;i++)
        ListM.push_back(make_tuple(0,i,(-1)*Durata[i]));
    for ( int i =1 ; i<=M;i++)
    {
        tie(x,y)=Intervale[i];
        ListM.push_back(make_tuple(x,y,(-1)*Durata[y]));
    }

}

void sortaretop() {

    //adaug deja 0 la sortarea topologica ca el va fi primul varf
    Sortare.push_back(0);
    for(int i=1;i<=N;i++)
        if (GradInt[i]==0)
            Coada.push(i);
    int x,y,z;
    while(!Coada.empty())
    {
        x=Coada.front();
        Coada.pop();
        Sortare.push_back(x);

        for(int i=1;i<=M;i++)
        {
             tie(y,z)=Intervale[i];
             if(y==x)
             {
                 GradInt[z]--;
                 if(GradInt[z]==0)
                    Coada.push(z);
             }
        }
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
    read();
    graf();
    sortaretop();
    /*
    for( int i =1;i<=N;i++)
        cout<<Durata[i]<< " " ;
    cout<< "\n";
    int x,y;
    for ( int i =1 ; i<=M;i++)
    {
        tie(x,y)=Intervale[i];
        cout<< x << " " << y << "\n";
    }
    int a,b,c;


    for ( int i=0;i<ListM.size();i++)
    {
        tie(a,b,c)=ListM[i];
        cout<<a<<" "<<b<< " "<<c<< " "<<"\n";
    }
    for(int i=1;i<=N;i++)
        cout<<GradInt[i]<< " ";
*/
    dijkstra();

    cout<<"Timpul minim este " << (-1)*d[N]<<"\n";
    for ( int i=1;i<=N;i++)
        cout<<i<<":"<<(-1)*d[tata[i]]<<" "<<(-1)*d[i]<<"\n";
    return 0;
}
