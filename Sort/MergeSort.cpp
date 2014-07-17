//mode
// -true : descending
// -false : ascending
void mergesort(vector<int> &a, mode) {
  int n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    mergesort(b, mode);
    mergesort(c, mode);
    for (int i = 0, j = 0, k = 0; i < n; ++i){
      if (k == c.size()){
        a[i] = b[j++];
      }else if(j == b.size()){
        a[i] = c[k++];
      }else if(b[j] > c[k] && !mode){
        a[i] = b[j++];
      }else if(b[j] < c[k] && mode){
        a[i] = b[j++];
      }else{
        a[i] = c[k++];
      }
    }
  }
}