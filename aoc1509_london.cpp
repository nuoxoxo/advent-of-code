/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

std::vector< int >  all_dist(
        std::vector< std::vector< std::string > > routes,
        std::map< std::pair< std::string, std::string >, int > intervals );
void    show_map( std::map< std::pair< std::string, std::string >, int > i );
void    show_routes( std::vector< std::vector< std::string > > routes );
void    show_places( std::vector< std::string > places );
void    show_int_vect( std::vector< int > v);

//  DRIVE

int     main(void)
{
        std::map< std::pair< std::string, std::string >, int > intervals;
        std::vector< std::vector< std::string > > routes;
        std::vector< std::string > places;
        std::vector< int > distances;
        std::string s;
        int max, min;
        
        while (std::getline(std::cin, s))
        {
            std::pair< std::pair< std::string, std::string >, int > city_dist;
            std::pair< std::string, std::string > city_pair;
            std::stringstream ss(s);
            std::string temp, from, to;
            int         dist;

            ss >> from;
            if (std::find(places.begin(), places.end(), from) == places.end())
                places.push_back(from);
            ss >> temp >> to;
            if (std::find(places.begin(), places.end(), to) == places.end())
                places.push_back(to);
            ss >> temp >> dist;
            city_pair = std::make_pair(from, to);
            city_dist = std::make_pair(city_pair, dist);
            intervals.insert ( city_dist );
            city_pair = std::make_pair(to, from);
            city_dist = std::make_pair(city_pair, dist);
            intervals.insert ( city_dist );
        }
        show_places( places ); // test
        show_map( intervals ); // test
        std::sort( places.begin(), places.end() );
        while ( std::next_permutation( places.begin(), places.end() ) )
            routes.push_back( places );
        show_routes( routes ); // test
        distances = all_dist( routes, intervals );
        show_int_vect( distances ); // test
        min = *std::min_element( distances.begin(), distances.end() );
        max = *std::max_element( distances.begin(), distances.end() );
        std::cout << "Star 1 : " << max << std::endl;
        std::cout << "Star 2 : " << min << std::endl;

        return (0);
}

//

std::vector< int >  all_dist(
        std::vector< std::vector< std::string > > routes,
        std::map< std::pair< std::string, std::string >, int > intervals)
{
        std::vector< int >  distances;
        int                 total, i, j;

        i = -1;
        while (++i < (int) routes.size())
        {
            total = 0;
            j = -1;
            while (++j < (int) routes[i].size() - 1)
            {
                std::pair<std::string, std::string> p;
                p = std::make_pair(routes[i][j], routes[i][j + 1]);
                total += intervals[p];
            }
            distances.push_back(total);
        }

        return (distances);
}

//  debugger

void    show_int_vect( std::vector<int> v)
{
        std::cout << "---- Showing all " << v.size() << " distances ----" << std::endl;
        for (int i = 0; i < (int) v.size(); i++)
            std::cout << v[i] << " ";
        std::cout << std::endl;
        std::cout << "---- End showing ----\n" << std::endl;
}

void    show_routes( std::vector< std::vector<std::string> > r )
{
        int     i, j;

        std::cout << "---- Showing all " << r.size() << " possible routes ----" << std::endl;
        i = -1;
        while (++i < (int) r.size())
        {
            j = -1;
            while (++j < (int) r[i].size()) std::cout << r[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << "---- End showing ----\n" << std::endl;
}

void    show_map( std::map<std::pair<std::string, std::string>, int> intervals )
{
        std::map<std::pair<std::string, std::string>, int>::iterator it;

        std::cout << "---- Showing all " << intervals.size() << " city-pairs ----" << std::endl;
        for (it = intervals.begin(); it != intervals.end(); it++)
            std::cout << it->first.first << " " << it->first.second << " " << it->second << std::endl;
        std::cout << "---- End showing ----\n" << std::endl;
}

void    show_places( std::vector<std::string> places )
{
        int     i = -1;

        std::cout << "---- Showing all " << places.size() << " locations ----" << std::endl;
        while (++i < (int) places.size())
            std::cout << places[i] << std::endl;
        std::cout << "---- End showing ----\n" << std::endl;
}
