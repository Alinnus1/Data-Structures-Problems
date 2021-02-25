#include <fstream>
#include <iostream>

int v[100001];
int bsearch0(int start, int final, int val)
{
	int mij;
	while (start < final)
	{
		mij = (start + final) / 2;
		if (v[mij] <= val)
			start = mij + 1;
		else
			final = mij - 1;
	}
	mij = (start + final) / 2;
	if (v[mij] > val)
        mij--;
	if (v[mij] == val)
        return mij+1;
	return -1;
}

int bsearch1(int start, int final, int val)
{
	int mij;
	while (start < final)
	{
		mij = (start + final) / 2;
		if (v[mij] <= val)
			start = mij + 1;
		else
			final = mij;
	}
	mij = (start + final) / 2;
	if (v[mij] > val)
		--mij;
	return mij+1;
}

int bsearch2(int start, int final, int val)
{
	int mij;

	while (start < final)
	{
		mij = (start + final) / 2;
		if (v[mij] < val)
			start = mij + 1;
		else
			final = mij;
	}
	mij = (start + final) / 2;
	if (v[mij] < val)
        ++mij;
	return mij+1;
}
int main()
{
    std::ifstream f("cautbin.in");
    std::ofstream g("cautbin.out");
    int N,M;

	f >> N;
	for (int i = 0; i < N; i++)
		f >> v[i];
	f >> M;
	while (M--)
	{
		int tip, x;
		f >> tip;
		f >> x;
		if (tip == 0)
		{
			g << bsearch0(0, N - 1, x) << '\n';
		}
		if (tip == 1) {
			g << bsearch1(0, N - 1, x) << '\n';
		}
		if (tip == 2) {
			g << bsearch2(0, N - 1, x) << '\n';
		}

	}
}
