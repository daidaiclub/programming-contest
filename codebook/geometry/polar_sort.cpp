sort(pl.begin(), pl.end(), [&](Pt a, Pt b){
  // a = a - o, b = b - o;
  if(a.qua() == b.qua()) return (a ^ b) > 0;
  return a.qua() < b.qua();
}); // degree 0 to 359
sort(pl.begin(), pl.end(), [&](Pt a, Pt b){
  return (a - pt[i]).angle() < (b - pt[i]).angle();
}); // degree -180 to 180, slower
