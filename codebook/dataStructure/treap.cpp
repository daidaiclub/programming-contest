struct Treap{
  Treap *l, *r;
  int pri, sz, rev;
  ll val, sum;
  Treap(int _val): l(nullptr), r(nullptr),
    pri(rand()), sz(1), rev(0),
    val(_val), sum(_val){} };

ll gsz(Treap *x){ return x ? x->sz : 0; }
ll gsum(Treap *x){ return x ? x->sum : 0; }

Treap* pull(Treap *x){
  x->sz = gsz(x->l) + gsz(x->r) + 1;
  x->sum = x->val + gsum(x->l) + gsum(x->r);
  return x; }
void push(Treap *x){
  if(x->rev){
    swap(x->l, x->r);
    if(x->l) x->l->rev ^= 1;
    if(x->r) x->r->rev ^= 1;
    x->rev = 0; } }

Treap* merge(Treap* a, Treap* b){
  if(!a || !b) return a ? a : b;
  push(a), push(b);
  if(a->pri > b->pri){
    a->r = merge(a->r, b);
    return pull(a); }
  else{
    b->l = merge(a, b->l);
    return pull(b); } }

void split(Treap *x, int k, Treap *&a, Treap *&b){
  if(!x) a = b = nullptr;
  else{
    push(x);
    if(x->val <= k) a = x, split(x->r, k, a->r, b);
    else            b = x, split(x->l, k, a, b->l);
    pull(x); } }

void kth(Treap *x, int k, Treap *&a, Treap *&b){
  if(!x) a = b = nullptr;
  else{
    push(x);
    if(gsz(x->l) < k)
         a = x, kth(x->r, k - gsz(x->l) - 1, a->r, b);
    else b = x, kth(x->l, k, a, b->l);
    pull(x); } }