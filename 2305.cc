#include "iostream"
#include "algorithm"
#include "sstream"
#include "vector"
#include "map"
using namespace std;
#define ull unsigned long long
#define ll long long

int main() {
    ull r1 = 0;
    ull r2 = 0;

    // Parsing

    vector<ull> seeds;
    string line;
    vector<vector<ull>> submap;
    vector<vector<vector<ull>>> maps;
    while (getline(cin, line))
    {
        string w;
        if (line.find("seeds") != string::npos)
        {
            line = line.substr(6); // substr from index 6 where ':' is 
            stringstream ss(line);
            ull num;
            while (ss >> num)
                seeds.push_back(num);
        }
        else if (line.empty() && ! submap.empty())
        {
            maps.push_back(submap);
            submap.clear();
        }
        else if (line != "" && line.find("map") == string::npos)
        {
            vector<ull> temp;
            stringstream ss(line);
            ull num;
            while (ss >> num)
                temp.push_back(num);
            reverse(temp.begin(), temp.end());
            submap.push_back(temp);
        }
    }
    maps.push_back(submap); // get the last lingering section/submap

    // Debugger

    /*
    // - DBG: maps
    for (vector<vector<ull>> a: maps){
        cout << "[\n";
        for (vector<ull> & b: a){
            cout << "\t[";
            for (ull & c: b) cout << c << "  ";
            cout << "]\n";
        }
        cout << "]\n";
    }
    // - DBG: seeds
    for (ull s: seeds) cout << "(seed): " << s << endl;
    */

    // Part 1

    vector<ull> seeds_copy(seeds); // For Part 2

    int i = -1;
    while (++i < (int) seeds.size())
    {
        // 👆 we can reverse the order of these 2
        // 👇 looplevels and result will not change
        for (vector<vector<ull>> & submaps: maps)
        {
            for (vector<ull> & submap: submaps)
            {
                ull length, begin, end, dest, dist;
                length = submap[0];
                begin = submap[1];
                end = submap[2];
                if (begin <= seeds[i] && seeds[i] < begin + length)
                {
                    // eg. 79 is in the range of [50, 50 + 48)
                    // how far we're from start now : 79 - 50 = 29
                    // we should go as far from end : 52 + 29 = 81 <- sample
                    dist = seeds[i] - begin;
                    dest = end + dist;
                    seeds[i] = dest;
                    break ;
                }
            }
        }
    }

    r1 = *min_element(seeds.begin(), seeds.end());
    //cout << "part 1: " << r1 << endl; exit(0);

    // Part 2

    vector<vector<ull>> seeds_2;
    i = 0;
    while (i < seeds_copy.size())
    {
        seeds_2.push_back(vector<ull>{
            seeds_copy[i],
            seeds_copy[i] + seeds_copy[i + 1]
        });
        i += 2;
    }

    for (vector<vector<ull>> & submaps: maps)
    {
        // &s can be a pair<ull> but is a 2-elem vector here for simplicity 

        vector<vector<ull>> update;
        while ( ! seeds_2.empty())
        {
            vector<ull> bounds = seeds_2.back();//[ (int) seeds_2.size() - 1];
            seeds_2.pop_back();
            ull length, begin, end;
            ull left_bound = bounds[0];
            ull right_bound = bounds[1];
            int segment_is_workable = 0;
            for (vector<ull> & submap: submaps)
            {
                length = submap[0];
                begin = submap[1];
                end = submap[2];

                // since the axis grows rightward the real left bound
                // is the right-most one of the 2 left limits
                ull real_left_bound = max( begin, left_bound );

                // the real right bound is the nearest one 
                ull real_right_bound = min( begin + length, right_bound );

                if (!(real_left_bound < real_right_bound))
                    continue ; // segment exists iff its left > right
                ull left_dist = real_left_bound - begin; // offsets like in p1
                ull right_dist = real_right_bound - begin;
                update.push_back({
                    end + left_dist,
                    end + right_dist
                });

                // consider scenario where the real bounds
                // are within the seed's original range
                // in this case we should add the 2 missed-out 
                // segments to the 
                // segment 1) from seed's range's to real left bound
                if (left_bound < real_left_bound)
                    seeds_2.push_back(vector<ull>{
                        left_bound,
                        real_left_bound
                    });
                // segment 2) from seed's range's end to the real right bound
                if (real_right_bound < right_bound)
                    seeds_2.push_back(vector<ull>{
                        real_right_bound,
                        right_bound
                    });
                segment_is_workable = 1;
                // break ;
            }
            if ( ! segment_is_workable)
                update.push_back({left_bound, right_bound});
        }
        seeds_2 = update;
    }
    sort(seeds_2.begin(), seeds_2.end());
    r2 = seeds_2[0][0];
    cout << "part 1: " << r1 << endl;
    cout << "part 2: " << r2 << endl;
}

