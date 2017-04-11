#include <iostream>

static const int N = 1000;

void quickfind();

int main()
{
	quickfind();
}

void quickfind()
{
	int i, p, q, id[N];
	for (i=0; i<N; i++) id[i]=i;
	while (std::cin >> p >> q)
	{
		int t = id[p];
		if (t == id[q]) continue;
		for (i=0; i<N; i++)
			if (id[i] == t) id[i] = id[q];
		std::cout << " " << p << " " << q << std::endl;
	}
}
