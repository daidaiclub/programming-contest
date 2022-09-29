ll mul(ll x,ll y,ll mod){
	ll ret=x*y-(ll)((long double)x/mod*y)*mod;
	// ll ret=x*y-(ll)((long double)x*y/mod+0.5)*mod;
	return ret<0?ret+mod:ret;
}
ll mul(ll a, ll b, ll n){
  ll ret = 0;
  a %= n;
  while(b){
    if(b&1) ret = (ret+a)%n;
    a = a*2%n;
    b >>= 1;}
  return ret;}
ll mypow(ll a, ll b, ll n){
  ll ret = 1;
  while(b){
    if(b&1) ret = mul(ret, a, n);
    a = mul(a, a, n);
    b >>= 1;}
  return ret;}