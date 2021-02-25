#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;


int n,k;

long long BinarySearch(int x,int v[]) {
	long long out=1e18, val = 0;
	for (int i=0;i<n;i++) {
		val += abs(v[i] - x);
		if (i >= k) {
			val -= 	abs(v[i - k] - x);
		}
		if (i>=k-1)
			out=min(out,val);
	}
	return out;
}



int main(){

	ifstream f("pikachu.in");
	ofstream g("pikachu.out");
	f>>n>>k;
	int v[n],st=0,dr=2e9;

	for (int i=0;i<n;i++){
		f>>v[i];
	}


	while (st<=dr){
		int mij = (st+dr)/2;//mij pt cautare binara

		if (BinarySearch(mij-1,v)>BinarySearch(mij+1,v))
			st=mij+1;
		else
			dr=mij-1;
	}

	g<<BinarySearch(st,v);





}
