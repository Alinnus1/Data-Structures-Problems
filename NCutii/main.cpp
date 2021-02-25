#include<bits/stdc++.h>
using namespace std;

ifstream f ("cutii.in");
int N,M;
vector<vector<int>> v;
vector<vector<int>> adiacenta;
int dp[1000];
bool viz[1000];

void read()
{
    f>> N>> M;
    v.resize(N);
    adiacenta.resize(N);
    for (int i=0;i<N;i++)
    {
        v[i].resize(M);
        for (int j =0 ; j<M;j++)
            f>>v[i][j];
        //sortam dimensiunile in ord cresc
        sort(v[i].begin(),v[i].end());
    }
    //sortam cutiile in ordine lexicograica
    sort(v.begin(),v.end());
}
int testare( int x, int y)
{
    int n1=0,n2=0;
    for (int j =0 ; j<M;j++)
    {
        if (v[x][j] <= v[y][j])
            n1++;

        if (v[x][j] >= v[y][j])
            n2++;
    }

    if (n1==M)
        //cutia x intra in y
        return 1;
    if (n2==M)
        //cutia y intra in x
        return -1;
    //nu poate intra nicio cutie in alta
    return 0;
}

void dfs ( int node )
{
    //facem dfs pe graf
    viz[node]=true;
    for (int i=0;i < adiacenta[node].size();i++)
    {
        if( !viz[adiacenta[node][i]] )
            dfs(adiacenta[node][i]);
        dp[node] = max(dp[node], 1+dp[adiacenta[node][i]]);
    }
}
int findpath()
{
    for (int i = 0; i < N; i++)
    {
        if (!viz[i])
            dfs(i);
    }
    int ans=0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    read();
    for (int i=0;i<N;i++)
    {
        for (int j =0 ; j<M;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    for(int i = 0; i < N -1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            int n= testare(i,j);
            if(n== 1)
                adiacenta[i].push_back(j);
            else if(n == -1)
                adiacenta[j].push_back(i);
        }
    }

    /// pentru exercitiul 3 raspunsul corect este primul algoritm
    /// am ajuns la acest raspuns dupa un research indelungat (https://en.wikipedia.org/wiki/Reverse-delete_algorithm)
    /// avand o complexitate de O(m log n (log log n)3).
    cout << findpath()+1;
    return 0;
}
