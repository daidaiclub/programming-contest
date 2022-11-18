struct Matrix{
  ll v[MXN][MXN]; int n;
  void init(int n): n(n){ MEM(v, 0); }
  Matrix operator*(const Matrix &rhs){
    Matrix z; z.init(n);
    for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) 
      (z.v[i][j] += v[i][k] * rhs.v[k][j] % MOD) %= MOD;
    return z;
  }
};

Matrix operator^(Matrix m, ll a){
  Matrix ret; ret.init(m.n);
  for(int i = 0; i < m.n; ++i) ret.v[i][i] = 1;
  while(a){
    if(a & 1) ret = (ret * m);
    m = m * m;
    a >>= 1;
  }
  return ret;
}