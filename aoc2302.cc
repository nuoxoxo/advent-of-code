#include "iostream"
#include "sstream"
#include "vector"
#include "map"
using namespace std;

int main() {
    int r1 = 0;
    int r2 = 0;
    string s;
    map<string, int> D{
        {"red", 12}, {"green", 13}, {"blue", 14}
    };
    while (getline(cin, s)) {
        stringstream ss(s);
        string w;
        vector<string> a;
        while (ss >> w) {
            a.push_back(w);
        }
        int idx = stoi(a[1]);
        bool ok = true;
        int i = 2;
        int R = 0, G = 0, B = 0;
        while (i < a.size()) {
            string key = a[i + 1];
            if (key.back() == ';' || key.back() == ',')
                key.pop_back();
            int val = stoi(a[i]);
            cout << key << ' ' << val << ' ';
            if (D[key] < val)
                ok = false;
            if (key == "red")
                R = max(R, val);
            if (key == "green")
                G = max(G, val);
            if (key == "blue")
                B = max(B, val);
            i += 2;
        }
        cout << endl;
        if (ok)
            r1 += idx;
        r2 += R*G*B;
    }
    cout << "part 1: " << r1 << endl;
    cout << "part 2: " << r2 << endl;
}

