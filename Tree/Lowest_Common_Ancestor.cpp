#define MAX_V 1000
#define MAX_LOG_V 11

struct LCA{
  vector<int> g[MAX_V];
  int par[MAX_LOG_V][MAX_V],dep[MAX_V];
  int V,root;

  //引数:ノード数,根のノード番号
  LCA(int a,int b):V(a),root(b){}
  void add_edge(int x,int y){
    x--;y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  void dfs(int v,int p){
    par[0][v]=p;
    dep[v]=(p==-1?0:dep[p]+1);
    for(int i=0;i<g[v].size();i++){
      if(g[v][i]!=p)dfs(g[v][i],v);
    }
  }
  void init(){
    dfs(root,-1);
    for(int k=0;k<MAX_LOG_V-1;k++){
      for(int v=0;v<V;v++){
	if(par[k][v]<0)par[k+1][v]=-1;
	else par[k+1][v]=par[k][par[k][v]];
      }
    }
  }
  int build(int u,int v){
    u--;v--;
    if(dep[u]>dep[v])swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++){
      if((dep[v]-dep[u])>>k&1)v=par[k][v];
    }
    if(u==v)return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
	u=par[k][u];
	v=par[k][v];
      }
    }
    return par[0][u];
  }
};
