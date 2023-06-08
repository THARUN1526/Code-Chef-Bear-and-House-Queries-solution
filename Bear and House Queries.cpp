#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define pyes cout << "YES" << '\n'
#define pno cout << "NO" << '\n'
#define ff first
#define ss second
#define int long long
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int MAXN = 2e5 + 20;
const int LMAXN = 9223372036854775807;  // the max value of long long int
long long MOD = 1e9 + 7;
// ll a[MAXN], pre[MAXN];
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define m_p make_pair
#define vi vector<int>

#define lp(i, a, b) for (int i = a; i < b; i++)
#define fastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (auto &x : a) out << x << ' '; return out;};
void print(int a) {
  cout << a << '\n';
}
void print(vector<int> &a) {
  for(auto it : a) {
    cout << it << ' ';
  }
  cout << '\n';
}
void print(vector<vi> &a) {
  for(auto it : a) {
    for(auto e : it) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}

template <typename T>
void print1dvector(vector<T> V) {
  for (auto it : V) {
    cout << it << ' ';
  }
  cout << '\n';
}

template <typename T>
void print2dvector(vector<vector<T>> V) {
  for (auto it : V) {
    for (auto itr : it) {
      cout << itr << ' ';
    }
    cout << '\n';
  }
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <std::size_t MAXN>  // change the value of bitest to any size (say nax)
                             // that you need to assign
                             bool operator<(const std::bitset<MAXN>& x,
                                            const std::bitset<MAXN>& y) {
  for (int i = MAXN - 1; i >= 0; i--) {
    if (x[i] ^ y[i]) return y[i];
  }
  return false;
}

void makeUniq(vector<int>& vec) {
  sort(all(vec));
  vec.resize(unique(all(vec)) - vec.begin());
}

int binaryStrToDecimal(string b) { return stol(b, nullptr, 2); }

int nxt() {
  int x;
  cin >> x;
  return x;
}

int Sqrt(int n) {
  int l = 1, r = n, ans = n;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (mid > n / mid)
      r = mid - 1;
    else {
      ans = mid;
      l = mid + 1;
    }
  }
  return ans;
}

bool isPerfectSquare(int n) {
  int x = Sqrt(n);
  return x * x == n;
}

ll accurateFloor(ll a, ll b) {  // gives the accurate floor for -ve/+ve
  ll val = a / b;
  while (val * b > a) val--;
  return val;
}

ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

bool isPowerOf2(ll n) { return (ceil(log2(n)) == floor(log2(n))); }
/*
 unsigned int hibit(unsigned int x) { // return the position of highest set
 bit
  if(x == 0) {
    return 0;
  } else {
    return (32 - (__builtin_clz(x | 1)));
  }
}
*/
ll fastpow(ll b, ll p) {
  if (!p) return 1;
  ll ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
int powermodulo(int a, int p, int m) {
  int ans = 1;
  a = a % m;
  while (p > 0) {
    if (p & 1) ans *= a;
    ans = ans % m;
    a = (a * a) % m;
    p = p >> 1;
  }
  return ans;
}
int inverse(int a, int p = MOD) { return (powermodulo(a, p - 2, p)) % p; }
struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  // get representive component (uses path compression)
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
const int factnax=2e5 + 20;
vector<int> fact;
void pre_calc_fact() {
  fact = vector<int>(factnax);
  fact[0] = 1;
  for (int i = 1; i < factnax; i++) {
    fact[i] = ((fact[i - 1] % MOD) * i) % MOD;
  }
}

int nCr(int n, int r) {
  if(r > n) return 0;
  return ((fact[n] % MOD * inverse(fact[r]) % MOD) % MOD *
          inverse(fact[n - r]) % MOD);
}

int mod_add(int a, int b) {
    return (a+b)%MOD;
}
int mod_sub(int a, int b) {
    return (a-b+MOD)%MOD;
}
int mod_mult(int a, int b) {
    return (a*b)%MOD;
}
int mod_div(int a, int b) {
    return (mod_mult(a , inverse(b)));
}
vector<int> bstov(string s){
    int  n = s.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        ans[i] = s[i] - 'a';
    }
    return ans;
}

struct fTree {
  vector<int> bit;  // binary indexed tree
  int n;

  fTree(int n) {
    this->n = n + 1;
    bit.assign(n + 1, 0);
  }

  fTree(vector<int> a) : fTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }

  int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
  }
  void setX(int indx, int x) { add(indx, x - sum(indx, indx)); }
};

int ask(int a, int b) {
    cout << "? " << a << " "  << b << endl;
    string s;
    cin >> s;
    if(s[0] == 'Y') return 1;
    else return 0;
}

void give(int ans) {
    cout << "! " << ans << endl;
}

void solve() {
    int th = -1, sw = -1, tw = -1;

    int l = 0, r = 1000;


    function<bool(int)> cond1 = [&] (int m) {
        return (ask(0,m));
    };
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(cond1(m)) l = m + 1;
        else {
            r = m - 1;
        }
    }
    th = r;
    l = 0, r = 1000;
    function<bool(int)> cond2 = [&](int m) {
        return ask(m, 0);
    };
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(cond2(m)) l = m + 1;
        else {
            r = m - 1;
        }
    }
    sw = r;
    l = 0, r = 1000;
    function<bool(int)> cond3 = [&](int m) {
        return ask(m,  2*sw);
    };
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(cond3(m)) l = m + 1;
        else {
            r = m - 1;
        }
    }
    tw = r;

    give((th-2*sw)*tw + 4*sw*sw);
}

signed main() {
  fastIO();
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
