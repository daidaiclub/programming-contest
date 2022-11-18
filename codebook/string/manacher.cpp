const int MXN = 1e7 + 5;
struct Manacher{ // 0-base 每個點為中心的最長回文長度
  string st; int p[MXN * 2];
  void init(string s){ // O(n)
    MEM(p, 0); st.clear();
    st.push_back('$'); st.push_back('#');
    for(int i = 0; i < s.size(); ++i)
      st.push_back(s[i]), st.push_back('#');
    st.push_back('*');
    int mx = 0, id = 0;
    for(int i = 1; i < st.size(); ++i){
      p[i] = mx>i ? min(p[(id << 1) - i], mx - i) : 1;
      while(st[i + p[i]] == st[i - p[i]]) p[i]++;
      if(i + p[i] > mx) mx = i + p[i], id = i; } }
  // bt=1: middle between mid, mid+1
  int query(int mid, bool bt = 0) {
    return p[mid * 2 + 2 + bt] - 1; } };
