#include <iostream>
#include <fstream>

using namespace std;
int n=0,v[1000001];
ifstream fin("intrare.in");
void citire()
{
    int i=1,x;
    while(fin >> x)
    {
        v[i]=x;
        n++;
        i++;
    }

}
void printare()
{
    int i;
    for (i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void BubbleSort ()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=n-1;j++)
            if (v[j]>v[j+1])
                swap(v[j],v[j+1]);


}
/*void radixsort()
{
    int r[baza][1009];
    for(int i=0;i<baza;i++)
        {
            int j=1;
            int k=1;
            while(j<=n)
            {
                if(v[j]%10==i)
                {
                    r[v[j]%10][k]=v[j];

                }
            }
        }

}
*/
void testare()
{
    int k=1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n-1;j++)
            if (v[i]>v[j])
                {
                    cout<<"nu e bine";
                    k=0;
                }
    if (n==0)
        cout<<"vid";
    else
        if(k==1)
            cout<<"e bine";


}

int main()
{

    citire();
    BubbleSort();
    printare();
    testare();

    return 0;
}

