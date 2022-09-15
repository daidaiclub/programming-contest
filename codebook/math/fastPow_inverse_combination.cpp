ll fpow(ll a, ll b, ll m){
  ll ret = 1;
  a %= m;
  while(b){
    if(b&1) ret = ret * a % m;
    a = a * a % m;
    b >>= 1; }
  return ret; }

ll fa[MXN], fi[MXN];
void init(){
  fa[0] = 1;
  for(ll i = 1; i < MXN; ++i)
    fa[i] = fa[i - 1] * i % MOD;
  fi[MXN - 1] = fpow(fa[MXN - 1], MOD - 2, MOD);
  for(ll i = MXN - 1; i > 0; --i)
    fi[i - 1] = fi[i] * i % MOD; }

ll c(ll a, ll b){
  return fa[a] * fi[b] % MOD * fi[a - b] % MOD; }