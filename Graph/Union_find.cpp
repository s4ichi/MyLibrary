struct UF {
  vector<int> p;
  UF(){} UF(int n):p(n,-1){}

  int find(int x){return p[x]<0 ? x : p[x]=find(p[x]);}
  int same(int a, int b){return find(a)==find(b);}
  int size(int x){return p.size();}

  void unit(int x,int y)
  {
    x=find(x);y=find(y);
    if(x==y)return;
    if(p[x]<p[y])swap(x,y);
    p[y]+=p[x];
    p[x]=y;
  }
};
