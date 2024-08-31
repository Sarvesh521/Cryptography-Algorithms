#include<bits/stdc++.h>

#define int long long

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

vector<array<int, 2>> getFactors(int n){
    vector<array<int, 2>> factors(1);
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            int count = 0;
            while(n%i == 0){
                count++;
                n = n/i;
            }
            factors.push_back({i, count});
        }
    }
    if(n > 1){
        factors.push_back({n, 1});
    }
    return factors;
}

int getGenerator(int p, vector<array<int, 2>> &factors, int r){
    vector<int> gamma;
    int gammaf = 1;
    for(int i=1; i<r; i++){
        int beta, alpha;
        do{
            alpha = rand()%(p-1) + 1;
            beta = power(alpha, (p-1)/factors[i][0], p);
        }while(beta == 1);
        int d = pow(factors[i][0], factors[i][1]);
        debug(alpha, beta);      
        gamma.push_back(power(alpha, (p-1)/d, p));
        gammaf = (gammaf*gamma.back())%p;
    }   
    debug(gamma);
    return gammaf;    
}

int32_t main(){
    int p;
    cout<<"Enter an odd prime: ";
    cin>>p;
    //get factors of p-1;
    vector<array<int, 2>> fac =  getFactors(p-1);
    debug(fac);
    int r = fac.size();
    int g = getGenerator(p, fac, r);
    cout << g << endl;
}