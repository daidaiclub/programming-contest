const int MXN = 1e7 + 5;
struct Manacher { // 0-base 每個點為中心的最長回文長度
  char str[MXN]; int p[MXN], len = 0;
  void init(string s) { // O(n)
    MEM(p, 0); str[len++] = '$', str[len++] = '#';
    for(int i = 0; i < s.size(); ++i)
      str[len++] = s[i], str[len++] = '#';
    str[len] = '*';
    int mx = 0, id = 0;
    for(int i = 1; i < len; ++i) {
      p[i] = mx > i ? min(p[(id<<1) - i], mx - i) : 1;
      while(str[i + p[i]] == str[i - p[i]]) p[i]++;
      if(i + p[i] > mx)
        mx = i + p[i], id = i;
    } } // bt=1: middle between mid, mid+1
  int query(int mid, bool bt = 0){
    return p[mid * 2 + 2 + bt] - 1; } };
