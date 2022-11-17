ll eulerFunction(ll x) {
  ll ret = x;
  for(ll i = 2; i * i <= x; ++i) {
    if(x % i == 0) {
      ret -= ret / i;
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) ret -= ret / x;
  return ret; 
}

ll eulerPow(ll a, string b, ll mod) {
  ll ret = eulerFunction(mod);
  ll p = 0;
  for(ll i = 0; i < b.size(); ++i) {
    p = (p * 10 + b[i] - '0') % ret;
  }
  p += ret;
  return fastPow(a, p, mod);
}