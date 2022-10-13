int lis(vector<ll> &v){ // O(nlgn)
  vector<ll> p;
  for(int i = 0; i < v.size(); ++i)
    if(p.empty() || p.back() < v[i]) p.PB(v[i]);
    else *lower_bound(p.begin(), p.end(), v[i]) = v[i];
  return p.size(); }

int lcs(string s, string t){ // O(nlgn)
  map<char, vector<int> > mp;
  for(int i = 0; i < s.size(); ++i) mp[s[i]].PB(i);
  vector<int> p;
  for(int i = 0; i < t.size(); ++i){
    auto &v = mp[t[i]];
    for(int j = v.size() - 1; j >= 0; --j)
      if(p.empty() || p.back() < v[j]) p.PB(v[j]);
      else *lower_bound(p.begin(),p.end(), v[j])=v[j];}
  return p.size(); }
