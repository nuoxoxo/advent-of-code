#include "iostream"
#include "queue"
//#include "utility"
#include "vector"
#include "sstream"
#include "cassert"
#include "set"//map"
#include "cstdarg"//"initializer_list"
using namespace std;
//using pii = pair<int, int>;
//using ppii = pair<pii, pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void DBG(vvi&);
void print(int,...);

int DIJK (vvi &, bool);

int main ()
{
    vector<vector<int>> A;
    string s;
    char chr;
    while (cin >> s)
    {
        stringstream ss(s);
        vector<int> temp;
        while (ss >> chr) temp.push_back(chr - '0');
        A.push_back(temp);
    }

    //DBG(A);

    int p1 = DIJK (A, false);
    cout << "Part 1: " << p1 << endl;

    int p2 = DIJK (A, true);
    cout << "Part 2: " << p2 << endl;

    assert(p1 == 102 || p1 == 1246 || p1 == 59);
    assert(p2 == 94 || p2 == 1389 || p2 == 71);

}

int DIJK (vector<vector<int>> & A, bool p2)
{
    auto cmp = [](const vi & L, const vi & R) {
        return L[0] > R[0];
    };
    //priority_queue<vector<int>> Q;
    vector<int>::iterator it;
    int R = A.size(), C = A[0].size();
    int r = 0, c = 0, dr = 0, dc = 0, loss = A[0][0], step = 0;
    int newloss, newr, newc, rr, cc, i;
    vi DR{1,0,-1, 0};
    vi DC{0,1, 0,-1};
    vi east{0,step,0,0,0,1};
    vi south{0,step,0,0,1,0};
    priority_queue< vi, vvi, decltype( cmp ) > Q( cmp);
    Q.push( east );
    Q.push( south );
    set<vi> seen{ {0,0,0,0,0} };
    while ( ! Q.empty())
    {
        vi temp = Q.top() ;
        loss = temp[0],
        step = temp[1],
        r = temp[2],
        c = temp[3],
        dr = temp[4],
        dc = temp[5];
        Q.pop();
        if (r > R - 1 || r < 0 || c < 0 || c > C - 1)
            continue ;
        if (r == R - 1 && c == C - 1 && step > (p2 ? 3 : -1)) // PART 2
            break ;
        if (seen.find( { step, r, c, dr, dc } ) != seen.end())
            continue ;
        seen.insert({step, r, c, dr, dc } );
        if (step > (p2 ? 9 : 2)) // PART 2
        {
            step = 1;
            i = -1;
            while (++i < 4)
            {
                //print(7, loss, step, r, c, dr, dc, i);
                rr = DR[i], cc = DC[i];
                if ( rr == dr && cc == dc || rr == -dr && cc == -dc )
                    continue ;
                newr = r + rr, newc = c + cc;
                if ( ! (newr > R - 1 || newr < 0 || newc < 0 || newc > C - 1) )
                {
                    newloss = loss + A[newr][newc];
                    Q.push( { newloss, step, newr, newc, rr, cc } );
                }
            }
            continue ;
        }
        // cont. curr dir
        newr = r + dr, newc = c + dc;
        if ( ! (newr > R - 1 || newr < 0 || newc < 0 || newc > C - 1) )
        {
            newloss = loss + A[newr][newc];
            Q.push( { newloss, step + 1, newr, newc, dr, dc } );
        }
        // move sideways
        if (step > (p2 ? 3 : -1)) // PART 2
        {
            step = 1;
            i = -1;
            while (++i < 4)
            {
                rr = DR[i], cc = DC[i];
                if (rr == dr && cc == dc || rr == -dr && cc == -dc)
                    continue ;
                newr = r + rr, newc = c + cc;
                if ( ! (newr > R - 1 || newr < 0 || newc < 0 || newc > C - 1) )
                {
                    newloss = loss + A[newr][newc];
                    Q.push( { newloss, step, newr, newc, rr, cc } );
                }
            }
        }
    }
    return loss;
}

void DBG( vvi & A) { for ( vi & a: A) { for (int n: a) cout << n << ' '; cout << '\n'; }}
void print(int total,...) {
    va_list args;
    int n, i = total;
    va_start( args, total );
    while (--i > -1) { n = va_arg(args, int); cout << n << ' '; }
    va_end( args );
    cout << '\n';
}

