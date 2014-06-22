#define MAX_V 10000

struct scc{
  int V;
  vector<int> g[MAX_V],rg[MAX_V],re;
  bool f[MAX_V];
  int cmp[MAX_V];

  scc(int v):V(v){};

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
    for(int v=0;v<V;v++){
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
