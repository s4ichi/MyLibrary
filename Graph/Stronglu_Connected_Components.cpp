// test: uva 11054

/*
  #define MAX_V 1000
  SCC<MAX_V> scc(current_size);
*/

template<int V>
struct SCC {
	int size;
	vector<int> g[V],rg[V],re;
	bool f[V];
	int cmp[V];

	SCC(int v):size(v) {};

	void add(int f,int t){
		g[f].push_back(t);
		rg[t].push_back(f);
	}

	void DFS(int v){
		f[v]=true;
		for(int i=0;i<g[v].size();i++){
			if(!f[g[v][i]])DFS(g[v][i]);
		}
		re.push_back(v);
	}

	void RDFS(int v,int k){
		f[v]=true;
		cmp[v]=k;
		for(int i=0;i<rg[v].size();i++){
			if(!f[rg[v][i]])RDFS(rg[v][i],k);
		}
	}

	int build(){
		memset(f,false,sizeof(f));
		re.clear();
		for(int v=0;v<size;v++){
			if(!f[v])DFS(v);
		}
		memset(f,false,sizeof(f));
		int k=0;
		for(int i=re.size()-1;i>=0;i--){
			if(!f[re[i]])RDFS(re[i],k++);
		}
		return k;
	}
};
