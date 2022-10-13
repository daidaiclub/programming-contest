const int MXN = 1e6+5;
struct BIT{
  ll n, a[MXN];
  void init(int _n){ n = _n; MEM(a, 0); }
  void add(int i, int x){
    for(; i <= n; i += i & -i) a[i] += x; }
  int sum(int i){
    int ret = 0;
    for(; i > 0; i -= i & -i) ret += a[i];
    return ret; }
  int kth(int k){
    int res = 0;
    for(int i = 1 << __lg(n); i > 0; i >>= 1)
      if(res + i <= n && a[res+i] < k) k -= a[res+=i];
    return res; } };