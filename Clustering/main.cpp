#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;


ifstream f ("cuvinte.in");
vector<string> words;
vector<tuple <int, int, int>> ListM;
vector<tuple <int, int, int>> Solutie;
int r[10005],tata[10005],h[10005];
int nrmsel;

string tail(string a) {
    return a.substr(1,a.size()-1);
}

int lev(string a , string b)
{
    if(!a.size())return b.size();
    if(!b.size())return a.size();
    if(a[0]==b[0]) return lev(tail(a),tail(b));
    return 1+min({lev(tail(a),b),lev(a,tail(b)),lev(tail(a),tail(b))});
}

void Init (int u) { r[u] = u; }

int Reprez (int u) { return r[u];}

void Reuniune( int u, int v)
{
    int r1,r2;
	r1 = r[u];
	r2 = r[v];

	for(int i = 0; i < words.size(); i++)
		if (r[i] == r1) r[i] = r2;
}
void kruskal()
{
    sort(ListM.begin(), ListM.end(), [](tuple<int,int,int> a, tuple<int,int,int> b)
         {return get<2>(a) < get<2>(b);});
    for (int v =1;v<=words.size();v++)
        Init(v);
    nrmsel = 0;
    for (int i=0;i<ListM.size();i++)
    {
        int u=get<0>(ListM[i]);
        int v=get<1>(ListM[i]);
        if(Reprez(u) != Reprez(v) )
        {
            Reuniune(u,v);
            Solutie.push_back(ListM[i]);
            nrmsel=nrmsel +1;
            if(nrmsel== words.size()-1)
                break;
        }
    }
}
int main()
{
    int k;
    cin>>k;
    while(!f.eof())
    {
        string word;
        f>> word;
        words.push_back(word);
    }
    for(int i=0;i<words.size()-1;i++)
        for(int j=i+1;j<words.size();j++)
            ListM.push_back(make_tuple(i+1,j+1,lev(words[i],words[j])));


    int a ,b,c;
    for ( int i=0;i<ListM.size();i++)
    {
        tie(a,b,c)=ListM[i];
        cout<<a<<" "<<b<< " "<<c<< " "<<"\n";
    }
    cout<<words.size();
    kruskal();

    Solutie.erase(Solutie.begin() + Solutie.size() - k +1,Solutie.end() ); // stergem cele n-k muchii pentru a obtine clusterele
    for ( int i=0;i<Solutie.size();i++)
    {
        tie(a,b,c)=Solutie[i];
        cout<<words[a-1]<<" "<<words[b-1]<< " "<<c<< " "<<"\n";

    }

    // tot ce mai ramane este sa facem un dfs pentru a afla componentele conexe si a afisa
    return 0;
}
