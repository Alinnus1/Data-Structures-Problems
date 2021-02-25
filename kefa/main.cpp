#include<iostream>
#include<algorithm>
using namespace std;

struct Prieten{
    int m;
    int s;
};

bool cmp(Prieten a, Prieten b) {
    return a.m < b.m;
}

int main ()
{
    int n, d;
    cin >> n >> d;
    Prieten a[100005];
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].m >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    long long sum[100005] = {0};
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].s;
    }
    int l = 1, r = 1;
    long long rez = 0;
    while (l <= n) {
        while (a[r].m - a[l].m < d && r <= n) {
            r ++;
        }
        r--;
       rez = max(sum[r] - sum[l - 1], rez);

        l++;
    }
    cout <<rez;
    return 0;
}
