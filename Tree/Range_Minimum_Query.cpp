#define INt_MAX 0xfffff;

struct RMQ{
  int size;
  vector<int> val;
  void init(int k){
    val=vector<int>(2*k-1,INT_MAX);
    size=k;
  }

  void update(int k,int t){
    k+=size-1;
    val[k]=t;
    while(k>0){
      k=(k-1)/2;
      val[k]=min(val[k*2+1],val[k*2+2]);
    }
  }

  int _query(int a,int b,int k,int l, int r){
    if(r<=a||b<=l)return INT_MAX;
    if(a<=l&&r<=b)return val[k];
    else{
      int vl=_query(a,b,k*2+1,l,(l+r)/2);
      int vr=_query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }

  int query(int a,int b){
    return _query(a,b,0,0,size);
  }
};
