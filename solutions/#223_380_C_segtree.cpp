#include "bits/stdc++.h"
using  namespace  std;
typedef  long long ll;
#define all(x) x.begin(), x.end()
 
struct  item{
        int bad_open, bad_closed;
        //bad open ::= .. ()() .. ((((
        //bad closed ::= )))) ... ()() ..
};

struct segtree{
        int sz;
        vector<item> values;
        void init(int n){
                sz = 1;
                while (sz < n) sz *= 2;
                values.resize(2 * sz, NEUTRAL_ELEMENT);
        }
        item NEUTRAL_ELEMENT = {0, 0};
        item merge(item a, item b){
                int cancel = min(a.bad_open, b.bad_closed);
                return {b.bad_open + a.bad_open - cancel,
                        a.bad_closed + b.bad_closed - cancel};
        }
        item single(int v){
                //0 for (
                //1 for )
                return {!v, v};
        }
        void build(vector<int> &a, int x, int lx, int rx){
                if(rx - lx == 1){
                        if(lx < (int) a.size()){
                                values[x] = single(a[lx]);
                        }
                        return;
                }
                int m = (lx + rx) / 2;
                build(a, 2 * x + 1, lx, m);
                build(a, 2 * x + 2, m, rx);
                values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
        }
        void build(vector<int> &a){
                build(a, 0, 0, sz);
        }
        item calc(int l, int r, int x, int lx, int rx){
                if(l >= rx || lx >= r) return NEUTRAL_ELEMENT;
                if(lx >= l && rx <= r) return values[x];
                
                int m = (lx + rx) / 2;
                item s1 = calc(l, r, 2 * x + 1, lx, m);
                item s2 = calc(l, r, 2 * x + 2, m, rx);
                return merge(s1, s2);
        }
        item calc(int l, int r){
                return calc(l, r, 0, 0, sz);
        }
};
 
void solve(){
        string s; cin>>s;
        int n = s.length();
        vector<int> v(n);
        for(int i = 0; i < n; i++){
                v[i] = s[i] == ')';
        }
        segtree st;
        st.init(n);
        st.build(v);
        
        int m; cin>>m;
        while(m--){
                int L, R;
                cin>>L>>R;
                
                item seg = st.calc(L - 1, R);
                cout<<R - L + 1 - seg.bad_closed - seg.bad_open<<"\n";
        }
}
int main(){
        cin.tie(0);
        cin.sync_with_stdio(0);
        
        int t=1;
        while(t--){
                solve();
        }
}