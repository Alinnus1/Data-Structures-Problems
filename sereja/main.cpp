#include <iostream>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    int a[100002], l[100002] = {0};
    bool v[100002];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--)
    {
        if (!v[a[i]])
          l[i]++;
        v[a[i]] = true;
    }

    for (int i = n; i >= 1; i--)
        l[i] += l[i + 1];

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << l[x] << endl;
    }

    return 0;
}
