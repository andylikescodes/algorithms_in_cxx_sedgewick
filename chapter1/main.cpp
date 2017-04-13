#include <iostream>

static const int N = 1000;

void quickfind();
void quickunion();
void weighted_quickunion();
void path_compression_wquickunion();

int main(int argc, char *argv[])
{
	if (std::string(argv[1]) == "quickfind") {quickfind();}
	if (std::string(argv[1]) == "quickunion") {quickunion();}
	if (std::string(argv[1]) == "weighted") {weighted_quickunion();}
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

void quickunion()
{
	int i, j, p, q, id[N];
	for (i=0; i<N; i++) id[i]=i;
	while (std::cin >> p >> q)
	{
		for (i=p; i!=id[i]; i=id[i]);
		for (j=q; j!=id[j]; j=id[j]);
		if (i==j) continue;
		id[i]=j;
		std::cout << " " << p << " " << q << std::endl;
	}
}

void weighted_quickunion()
{
	int i, j, p, q, id[N], sz[N];
	for (i=0; i<N; i++)
	{ id[i]=i; sz[i]=1; }
	while (std::cin >> p >> q)
	{
		for (i=p; i!=id[i]; i=id[i]);
		for (j=q; j!=id[j]; j=id[j]);
		if (i==j) continue;
		// improve the traves time by keeping
		// track of the tree size and only
		// add to the smaller side
		if (sz[i] < sz[j])
			{id[i] = j; sz[j] += sz[i];}
		else
			{id[j] = i; sz[i] += sz[j];}
		std::cout << " " << p << " " << q << std::endl;
	}
}

void path_compression_wquickunion()
{
	int i, j, p, q id[N], sz[N];
	for (i=0; i<N; i++)
		{ id[i]=i; sz[i]=1; }
	while (std::cin >> p >> q)
	{
		//path compression by halving
		for (i=p; i!=id[i]; i=id[i]);
			id[i] = id[id[i]];
		for (j=q; i!=id[j]; j=id[j]);
			id[j] = id[id[j]];
		if (i=j) continue;
		if (sz[i] < sz[j])
			{id[i] = j; sz[j] += sz[i];}
		else
			{id[j] = i; sz[i] += sz[j];}
		std::cout << " " << p << " " << std::endl;
	}
}
