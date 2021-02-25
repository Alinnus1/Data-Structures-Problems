#include <iostream>
#include <fstream>

using namespace std;

int k;

///Numarul de zerouri dintr-un numar factorial
///este reprezentat de suma puterilor lui 5 din numerele mai mici
///sau egale cu numarul
int NrZ(int n)
{
    cout<<"nr:";
    int p, cnt = 0;
    for (p=5; p <= n; p *= 5)
        {
            cnt += (n / p);
            cout<<cnt<<endl;
        }


    return cnt;
}

int binarysearch()
{
    int st, dr, sol, m, x;
    if (k == 0) return 1;
    st = 1; dr = 1000000000;
    sol = -1;
    while (st <= dr)
    {
        m=(dr-st)/2 + st;
        x = NrZ(m);
        if (x == k) { sol = m; dr = m - 1;}
        else if (x > k) dr = m - 1;


        else st = m + 1;
    }
    return sol;
}

int main()
{

    int x;

    cin >> k;
    x=binarysearch();
    cout<< x << "\n";
    return 0;
}
