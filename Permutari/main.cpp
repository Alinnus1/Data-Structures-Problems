#include <iostream>
#include <vector>
#include <fstream>


#define N_MAX 100001
std::ifstream f("permutariab.in");
std::ofstream g("permutariab.out");

int A[N_MAX],B[N_MAX],S[N_MAX];
long long solutie;
void Interclasare(int s,int d,int mij){

    int loc=0,i=s,j=mij+1;
    while(i<=mij && j<=d)
    {
         if(A[B[i]]<A[B[j]])
        {
            S[++loc]=B[i++];
        }
        else
        {
            S[++loc]=B[j++];
            solutie+=(mij-i+1);
        }

    }
    while(i<=mij)
        S[++loc]=B[i++];
    while(j<=d)
        S[++loc]=B[j++];
    for(i=s, j=1; i<=d; i++, j++)
    {
        B[i]=S[j];
    }

}

void MergeSort(int s,int d)
{
    int mij;
    if(s<d){
        mij=(s+d)/2;
        MergeSort(s,mij);
        MergeSort(mij+1,d);
        Interclasare(s,d,mij);

    }
}

int main()
{
    int N,temp;
    f>>N;
    for(int i=1;i<=N;i++)
    {

        f>>temp;
        A[temp]=i;

    }
    for(int i=1; i<=N; i++)
        f>>B[i];

    MergeSort(1,N);
    g<<solutie;
    return 0;
}
