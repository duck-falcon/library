// ライブラリテスト実行用　好きに上書きしてok

#include <bits/stdc++.h>
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()

  // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vl  = vector<ll>;

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

template<typename T> void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) { cout << v << ","; }
  cout << "]" << endl;
}

template<>
void pv(vector<P> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << "<" << v.fi << ","<< v.se << ">" << ",";
  }
  cout << "]" << endl;
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}

// bfs

// 行、列
int rows,columns;
// 長方形グリッド
vvi maze;
// 既に到達した点
vvi seen;
// ある地点からの最短距離
vvi d;
// start goal
int sx,sy,gx,gy;

// 4方向
vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
// 8方向
// vi dx = {1,1,0,-1,-1,-1,0,1}, dy = {0,1,1,1,0,-1,-1,-1};

// seen を d が -1 か否かで代用できるため、これを使うメリットがない気もするが残しておく
void bfs(int x, int y) {
  int n = dx.size();
  seen.at(x).at(y) = 0;
  queue<P> que;
  que.push(P(x,y));

  while(que.size()) {
    P p = que.front();que.pop();
    rep(i,n) {
      int nx = p.fi + dx.at(i), ny = p.se + dy.at(i);
      if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny) and !seen.at(nx).at(ny)) {
        que.push(P(nx,ny));
        seen.at(nx).at(ny) = 1;
      }
    }
  }
}

void bfsLength(int x, int y) {
  int n = dx.size();
  queue<P> que;
  que.push(P(x,y));
  d.at(x).at(y) = 0;

  while(que.size()) {
    P p = que.front();que.pop();
    rep(i,n) {
      int nx = p.fi + dx.at(i), ny = p.se + dy.at(i);
      if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny) and d.at(nx).at(ny) == -1) {
        que.push(P(nx,ny));
        d.at(nx).at(ny) = d.at(p.fi).at(p.se) + 1;
      }
    }
  }
}

// 入力整形例
int main() {
  // h w のこと
  cin >> columns >> rows;
  maze = vvi(columns,vi(rows,0));
  seen = vvi(columns,vi(rows,0));
  rep(i, columns) {
    string s; cin >> s;
    rep(j, rows) {
      if(s.at(j)=='.') maze.at(i).at(j) = 1;
      else if (s.at(j)=='#') maze.at(i).at(j) = 0;
  //    else if (s.at(j) == 's') {sx = i; sy = j;maze.at(i).at(j)=1;}
  //    else if (s.at(j) == 'g') {gx = i, gy = j;maze.at(i).at(j)=1;}
    }
  }

  //ある地点からの最短距離を全部求める
  /*d = vvi(columns,vi(rows,-1));
  bfsLength(sx,sy);*/



  return 0;
}
