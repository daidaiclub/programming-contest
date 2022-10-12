while(l < r){ // first l of check(l) == true
  ll m = (l + r) >> 1;
  if(!check(m)) l = m + 1; else r = m; }
while(l < r){ // last l of check(l) == false
  ll m = (l + r + 1) >> 1;
  if(!check(m)) l = m;     else r = m - 1; }
while(l < r){
  ll ml = l + (r - l) / 3, mr = r + (r - l) / 3;
  if(check(ml)>check(mr)) l = ml + 1; else r = mr - 1;}
