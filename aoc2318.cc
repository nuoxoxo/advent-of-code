#include "iostream"
#include "vector"
#include "sstream"
#include "string" // stoi
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using ll = long long;

void DBG ( vector<string> & );
ll Shoelace (vector<string> &, bool);

int main ()
{
    vector<string> A;
    string s;
    while (getline(cin, s))
        A.push_back(s);
    DBG(A);

    ll p1 = Shoelace (A, false);
    cout << "Part 1: " << p1 << endl;

    ll p2 = Shoelace (A, true);
    cout << "Part 2: " << p2 << endl;

}

ll Shoelace (vector<string> & A, bool part2 )
{
    ll res = 0;
    vector<char> DIR{'R', 'D', 'L', 'U'};
    vl curr{0, 0};
    ll peri = 0;
    vvl D{ curr };
    for (string & s : A)
    {
        string line, d;
        // unsigned long long n;
        long long n;
        ll r = curr[0];
        ll c = curr[1];
        stringstream ss(s);
        ss >> d >> n >> line;
        if ( part2 )
        {
            d = "";
            d += line[line.size() - 2];
            d = DIR[stoi(d)];
            n = stoll(line.substr(2,5), nullptr, 16);
            // cout << d << " <- d, n -> " << n << endl;
            // cout << line.substr(2,5) << ' ' << stoll(line.substr(2,5), nullptr, 16) << endl;
        }
        if (d == "R")
            c += n;
        if (d == "D")
            r += n;
        if (d == "L")
            c -= n;
        if (d == "U")
            r -= n;
        curr = {r, c};
        peri += n;
        D.push_back( curr );
    }
    ll up = 0;
    ll down = 0;
    int i = -1;
    vl next;
    while (++i < D.size() - 1)
    {
        curr = D[i];
        next = D[i+1];
        up += curr[0] * next[1];
        down += curr[1] * next[0];
    }
    up += D[D.size() - 1][0] * D[0][1];
    down+=D[D.size() - 1][1] * D[0][0];
    ll area = abs(up - down) / 2;
    ll pick = area - peri/2 + 1;
    res = peri + pick;
    return res;
}

void DBG( vector<string> & A) { for ( string & s: A) { cout << s << '\n'; }}
void print(int total,...) {
    va_list args;
    int n, i = total;
    va_start( args, total );
    while (--i > -1) { n = va_arg(args, int); cout << n << ' '; }
    va_end( args );
    cout << '\n';
}

