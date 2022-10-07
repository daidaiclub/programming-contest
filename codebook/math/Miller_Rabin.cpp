// magic numbers when n <
// 4,759,123,141     : 2, 7, 61
// 1,122,004,669,633 : 2, 13, 23, 1662803
// 3,474,749,660,383 : 2, 3, 5, 7, 11, 13
// 2^64              : 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if you want to use magic.
vector<ll> magic = {};
bool witness(ll a, ll n, ll u, ll t){
  if(!a) return 0;
  ll x = fpow(a, u, n);
  while(t--) {
    ll nx = x * x % n;
    if(nx == 1 && x != 1 && x != n - 1) return 1;
    x = nx; }
  return x != 1; }
bool isprime(ll n) {
  if(n < 2) return 0;
  if(~n & 1) return n == 2;
  ll u = n - 1, t = 0;
  while(~u & 1) u >>= 1, t++;
  for(auto i : magic){
    ll a = i % n;
    if(witness(a, n, u, t)) return 0; }
  return 1; }
