#include "iostream"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;
int main() {
    vector<string>  A;
    string  s;
    int r1 = 0;
    int r2 = 0;
    map<string, int> D{
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}
    };
    while (getline(cin, s)) {
        A.push_back(s);
        vector<pair<int, string>> a;
        int i = -1;
        char L, R;
        while (++i < s.length()) {
            if (isdigit(s[i])) {
                R = s[i];
            }
        }
        i = s.length();
        while (--i > -1) {
            if (isdigit(s[i])) {
                L = s[i];
            }
        }
        string ss = "";
        ss += L;
        ss += R;
        r1 += stoi(ss);
        for (auto d: D) {
            int l = s.find(d.first), r = s.rfind(d.first);
            if (l != -1)
                a.push_back({l, d.first});
            if (r != -1)
                a.push_back({r, d.first});
        }
        sort(a.begin(), a.end(), [](auto x, auto y){
            return x.first < y.first;
        });
        string ll = to_string(D[a[0].second]);
        string rr = to_string(D[a.back().second]);
        ss = "";
        ss += ll;
        ss += rr;
        r2 += stoi(ss);
    }
    cout << "part 1: " << r1 << endl;
    cout << "part 2: " << r2 << endl;
}

