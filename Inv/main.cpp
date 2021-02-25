#include <iostream>
#include <fstream>

using namespace std;
long merge(long arr[], long left, long mid, long right)
{
    long count = 0;
    long i, j, k;
    //construim arr stang si arr drept
    long temp1 = mid - left + 1;
    long temp2 = right - mid;

    long* L = new long[temp1];
    long* R = new long[temp2];

    for (i = 0; i < temp1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < temp2; j++)
        R[j] = arr[mid + 1 + j];

    for (i = 0; i < temp1; i++)
        cout<<L[i]<<" ";
    cout<<endl;
    for (j = 0; j < temp2; j++)
        cout<<R[j]<<" ";
    cout<<"gata un merge \n";
    //se presupune ca cele doua array-uri sunt sortate

    k = left;
    i = 0;
    j = 0;

    while (i < temp1 && j < temp2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            count += temp1 - i;
        }
        k++;
    }
    while (i < temp1)
        arr[k++] = L[i++];
    while (j < temp2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;

    return count;
}
long mergeSort(long arr[], long left, long right)
{
    if (left == right)
        return 0;
    long nr_inv = 0;
    if (left < right)
    {
        long mij = (left + right) / 2;
        cout<<"mij cur este"<<mij<<"\n";
        nr_inv += mergeSort(arr, left, mij);
        cout<<"1a\n";
        nr_inv += mergeSort(arr, mij + 1, right);
        cout<<"2a\n";
        nr_inv += merge(arr, left, mij, right);
        cout<<"3a\n";
    }
    return nr_inv;
}

int main()
{
    ifstream f("inv.in");
    ofstream g("inv.out");

    long n, S[100001];
    f >> n;
    for (long i = 0; i < n; i++)
        f >> S[i];
    long solutie = mergeSort(S, 0, n - 1);
    for (long i = 0; i < n; i++)
        cout<<S[i]<<" ";
    g << solutie % 9917;

    return 0;
}
