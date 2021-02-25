#include <iostream>
#include <stdio.h>
#include <fstream>

#define maxn 5000010

int N, K;
int A[maxn], Deque[maxn];
int Front, Back;
long long Sum;

int main(){

	std::ifstream f("deque.in");
	std::ofstream g("deque.out");

	int i;
    f>>N>>K;

	// Citesc sirul dat

	for (i = 1; i <= N; i++)
		f>>A[i];
	Front = 1, Back = 0; //	Initializare, Back < Front => deque-ul este vid

	for (i = 1; i <= N; i++)
	{
		// Cat timp elementul curent este mai mic decat ultimul element din deque, eliminam pozitia ultimului element din deque
		while (Front <= Back && A[i] <= A[ Deque[Back] ])
            Back--;
		// Adaugam pozitia elementului curent in deque
		Deque[++Back] = i;

		// Daca elementul minim coincide cu cel de pe pozita i-K, ii eliminam pozitia din deque, deoarece acesta nu mai conteaza pentru pasii >= i
		if (Deque[Front] == i-K)
            Front++;

		// Afisam minimul, acesta aflandu-se in varful deque-ului
		if (i >= K)
            Sum += A[ Deque[Front]];
	}

	g<<Sum;

	return 0;
}
