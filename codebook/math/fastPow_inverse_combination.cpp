ll fpow(ll a, ll b, ll mod){
  ll ret = 1;
  while(b){
    if(b&1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1; }
  return ret; }

ll fac[MXN], inv[MXN];
fac[0] = 1;
for(ll i = 1; i < MXN; ++i)
  fac[i] = fac[i-1] * i % MOD;
inv[MXN-1] = fpow(fac[MXN-1], MOD-2, MOD);
for(ll i = MXN; i > 0; --i)
  inv[i-1] = inv[i] * i % MOD;

ll c(ll a, ll b){
  return fac[a] * inv[b] % MOD * inv[x-y] % MOD; }