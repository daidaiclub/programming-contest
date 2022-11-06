const ld EPS = 1e-8;
const ld PI = acos(-1);
int dcmp(ld x){ // float x (<, ==, >) y -> (-1, 0, 1)
  if(abs(x) < EPS) return 0;
  else return x < 0 ? -1 : 1;
}
struct Pt{
  ld x, y; // 改三維記得其他函式都要改
  Pt(ld _x = 0, ld _y = 0): x(_x), y(_y){}
  Pt operator+(const Pt &a) const{
    return Pt(x + a.x, y + a.y); }
  Pt operator-(const Pt &a) const{
    return Pt(x - a.x, y - a.y); }
  Pt operator*(const ld &a) const{
    return Pt(x * a, y * a); }
  Pt operator/(const ld &a) const{
    return Pt(x / a, y / a); }
  ld operator*(const Pt &a) const{ // dot product
    return x * a.x + y * a.y; }
  ld operator^(const Pt &a) const{ // cross product
    return x *a.y - y * a.x; }
  bool operator<(const Pt &a) const{
    return x < a.x || (x == a.x && y < a.y); }
    // return dcmp(x-a.x) < 0 ||
    //   (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
  bool operator==(const Pt &a) const{
    return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0; }
  int qua() { // 在哪個象限(軸上點歸類到逆時針的象限)
    if(x > 0 && y >= 0) return 1;
    if(x <= 0 && y > 0) return 2;
    if(x < 0 && y <= 0) return 3;
    if(x >= 0 && y < 0) return 4; }
  ld angle() const{ // -pi ~ pi
    if(dcmp(x) == 0 && dcmp(y) == 0) return 0;
    return atan2(y, x); } };
ld norm2(const Pt &a){
  return a * a; }
ld norm(const Pt &a){ // norm(a - b) = dis of a, b
  return sqrt(norm2(a)); }
Pt perp(const Pt &a){ // 垂直向量(順時針旋轉90度)
  return Pt(-a.y, a.x); }
Pt rotate(const Pt &a, ld ang){
  return Pt(a.x * cos(ang) - a.y * sin(ang),
            a.x * sin(ang) + a.y * cos(ang)); }
struct Line{
  Pt s, e, v; // start, end, end - start
  ld ang; // angle of v
  Line(Pt _s = Pt(0, 0), Pt _e = Pt(0, 0)):
    s(_s), e(_e) { v = e - s; ang = atan2(v.y, v.x); }
  bool operator<(const Line &L) const{ // sort by angle
    return ang < L.ang; } };
struct Circle{
  Pt o; ld r;
  Circle(Pt _o = Pt(0, 0), ld _r = 0): o(_o), r(_r){}
  bool inside(const Pt &a) const {
    return norm2(a - o) <= r * r; } };
