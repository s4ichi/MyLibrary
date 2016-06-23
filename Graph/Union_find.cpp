struct UF {
	vector<int> p;
	UF(int n):p(n,-1){}

	int find(int x){
		return p[x]<0 ? x : p[x] = find(p[x]);
	}

	int same(int a, int b){
		return find(a) == find(b);
	}

	int size(int x){
		return -p[find(x)];
	}

	bool unite(int x, int y)
	{
		x = find(x); y = find(y);
		if(x == y) return false;
		if(p[y] < p[x]) swap(x,y);
		p[x] += p[y];
		p[y] = x;
		return true;
	}
};
