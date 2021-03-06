#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 50;
int n, m, id[N][N], a, b, u, v;
vi g[N];
db w[N], t, tt;

namespace GaussDB{
	static const int N=510;
	double mat[N][N];//增广矩阵
	double x[N];//解集
	bool free_x[N];//标记是否是不确定的变元
	const double eps = 1e-10;
	int Gauss(int equ, int var){
		int k;
		int max_r, col;
		int free_index, free_num;
		memset(free_x, 1, sizeof(free_x));
		memset(x, 0, sizeof(x));
		for(k=col=0; k<equ&&col<var; ++k, ++col){
			max_r=k;
			rep(i, k+1, equ)
				if(fabs(mat[i][col])-mat[max_r][col]>eps) max_r=i;
			if(max_r!=k)
				rep(j, k, var+1)swap(mat[max_r][j], mat[k][j]);
			if(fabs(mat[k][col]<eps)){--k;continue;}
			rep(i, k+1, equ){
				if(fabs(mat[i][col])<=eps) continue;
				double tmp=mat[i][col]/mat[k][col];
				rep(j, col, var+1)
					mat[i][j]-=mat[k][j]*tmp;
			}

		}
		rep(i, k, equ)
			if(fabs(mat[i][var]>eps)) return 0;//无解
		if(k<var){
			for(int i=k-1; i>=0; --i){
				free_num=0;
				rep(j, 0, var){
					if(fabs(mat[i][j])>eps&&free_x[j]){
						free_num+=1;
						free_index=j;
					}
				}
				if(free_num>1) continue;
				double tmp=mat[i][var];
				rep(j, 0, var){
					if(j!=free_index&&fabs(mat[i][j])>eps)
						tmp-=mat[i][j]*x[j];
				}
				free_x[free_index]=0;
				x[free_index]=tmp/mat[i][free_index];
			}
			return var-k;//自由变元个数
		}
		for(int i=var-1; i>=0; --i){
			double tmp=mat[i][var];
			rep(j, i+1, var){
				if(fabs(mat[i][j])>eps)
					tmp-=x[j]*mat[i][j];
			}
			x[i]=tmp/mat[i][i];
		}
		return 1;
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(6);
	cin >> n >> m >> a >> b;
	rep(i, 0, m) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i, 1, n+1) cin >> w[i], g[i].pb(i);
	rep(i, 1, n+1) rep(j, 1, n+1) id[i][j] = (i - 1) * n + j - 1;
	GaussDB :: mat[id[a][b]][n * n] = 1;
	rep(i, 1, n+1) rep(j, 1, n+1) {
		int p = id[i][j];
		GaussDB :: mat[p][p] += 1;
		if (i != j) {
			rep(k, 0, sz(g[i])) {
				u = g[i][k]; if (u == i) t = w[i]; else t = (1 - w[i]) / (sz(g[i]) - 1);  
				rep(l, 0, sz(g[j])) {
					v = g[j][l]; if (v == j) tt = t * w[j]; else tt = (1 - w[j]) / (sz(g[j]) - 1) * t; 	
					GaussDB :: mat[id[u][v]][id[i][j]] -= tt; 
				}
			}
		}
	}
	GaussDB :: Gauss(n * n, n * n);
	rep(i, 1, n+1) cout << GaussDB :: x[id[i][i]] << " "; 
	return 0;
}

