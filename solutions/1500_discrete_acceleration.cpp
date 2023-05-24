#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    cout << setprecision(15); 
    cout << fixed;
    while (tt--) {
        int n, l;
        cin >> n >> l;
        double flag;
        list<double> flags;
        for (int i=0;i<n;i++) {
            cin >> flag;
            flags.push_back(flag);
        }
        double car1x=0, car2x=l, t1=0, t2=0;
        double speed1=1, speed2=1;
        double ans=0;
        while (!flags.empty()) {
            t1 = (flags.front() - car1x ) / speed1;
            t2 = ( car2x - flags.back() ) / speed2;
            if (t2 > t1) {
                ans+=t1;
                car1x = flags.front();
                flags.pop_front();
                speed1 += 1;
                car2x -= speed2 * t1;
            } else if (t2 < t1){
                ans+=t2;
                car2x = flags.back();
                flags.pop_back();
                speed2 += 1;
                car1x += speed1 * t2;
            } else {
                ans+=t1;
                car2x = flags.back();
                car1x = flags.front();
                speed1+=1;
                speed2+=1;
                flags.pop_back();
                if (!flags.empty()) {
                    flags.pop_front();
                }
            }
        }
        ans += (car2x - car1x) / (speed1+speed2);
        cout << ans << endl;
    }
    return 0;
}