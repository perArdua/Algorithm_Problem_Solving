#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

struct Point{
    int x, y;
    Point(){}
    Point(int _x, int _y) : x{_x}, y{_y} {}
    bool operator< (const Point& u) const{
        if(y == u.y){
            return x < u.x;
        }else{
            return y < u.y;
        }
    }
};

bool comparator(const Point& u, const Point& v){
    return u.x < v.x;
}

int dist(const Point& u, const Point& v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

int main(){
    FAST;
    int n;
    cin >> n;
    vector<Point> points(n);
    rep(i, 0, n){
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), comparator);
    set<Point> candidates = {points[0], points[1]};
    int ans = dist(points[0], points[1]);
    int start = 0;
    rep(i, 2, n){
        Point current = points[i];
        while(start < i){
            auto p = points[start];
            int delta_x = current.x - p.x;
            if(delta_x * delta_x > ans){
                candidates.erase(p);
                ++start;
            }else{
                break;
            }
        }

        int d = (int)sqrt((double)ans) + 1;
        auto lower = candidates.lower_bound(Point(-10000, current.y - d));
        auto upper = candidates.upper_bound(Point(10000, current.y + d));
        for (auto it = lower; it != upper; it++) {
            int d = dist(current, *it);
            if (d < ans) {
                ans = d;
            }
        }
        candidates.insert(current);
    }
    cout << ans << endl;
    return 0;
}
