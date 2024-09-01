#include<bits/stdc++.h>

using namespace std;


//debug template ust to keep track of the variables

/*debug start*/
 void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 /*debug end*/



int power(int a, int b, int p){
    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%p;
        }
        a = (a*a)%p;
        b = b>>1;
    }
    return res;
}

//precomputation of gamma^i mod p for i = 1 to q-1
void precomp(map<int, int> &T, int p, int q, int gamma){
    int m = ceil(sqrt(q));
    int beta = 1;
    for(int i=0; i<m; i++){
        T[beta] = i;
        beta = (beta*gamma)%p;
    }
}


int babyStepGiantStep(int p, int q, int gamma, int alpha){
    // map<int, int> T;
    map<int, int> T;
    for(int i=1; i<=p-1; i++)
        T[i] = -1;
    precomp(T, p, q, gamma);
    debug(T);
    int m = ceil(sqrt(q));
    int gamma_inv = power(gamma, p-2, p);
    int gamma_m_inv = power(gamma_inv, m, p);
    int beta = alpha,  j = 0, i = T[alpha];
    while(i==-1){
        beta = (beta*gamma_m_inv)%p;
        j++;
        i = T[beta];
    }
    return i + j*m;
}

int main(){
    //given p, q, gamma and alpha
    //ie order of gamma in mod p is q
    int p, q, gamma, alpha;
    //to find x in alpha = gamma^x mod p
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter q: ";
    cin >> q;
    cout << "Enter gamma: ";
    cin >> gamma;
    cout << "Enter alpha: ";
    cin >> alpha;

    int x = babyStepGiantStep(p, q, gamma, alpha);
    cout<<"Discrete log, x = "<<x<<endl;
}