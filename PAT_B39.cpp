#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    string given_beads, wanted_beads;
    cin >> given_beads >> wanted_beads;
    // int g_size = given_beads.size();
    // int w_size = wanted_beads.size();

    sort(given_beads.begin(), given_beads.end());
    sort(wanted_beads.begin(), wanted_beads.end());
    // cout << given_beads <<endl;
    // cout << wanted_beads << endl;

    int p_givenbeads = 0, p_wantedbeads = 0;
    int less = 0, more = 0;
    int g_len = given_beads.size();
    int w_len = wanted_beads.size();
    while(p_givenbeads < g_len && p_wantedbeads < w_len){
        if(wanted_beads[p_wantedbeads] < given_beads[p_givenbeads]){
            // cout << wanted_beads[p_wantedbeads] << ' ' << given_beads[p_givenbeads] <<endl;
            ++less;
            // cout << less << endl;
            ++p_wantedbeads;
            // cout << p_wantedbeads <<endl;
        }
        else if(wanted_beads[p_wantedbeads] == given_beads[p_givenbeads]){
            // cout << wanted_beads[p_wantedbeads] << ' ' << given_beads[p_givenbeads] <<endl;
            ++p_wantedbeads;
            ++p_givenbeads;
            // cout << p_wantedbeads << endl;
            // cout << p_givenbeads << endl;
        }
        else{
            // cout << wanted_beads[p_wantedbeads] << ' ' << given_beads[p_givenbeads] <<endl;
            ++more;
            ++p_givenbeads;
            // cout << more <<endl;
            // cout << p_givenbeads << endl;
        }
    }
    if(p_givenbeads == g_len){
        less += w_len - p_wantedbeads;
    }
    if(p_wantedbeads == w_len){
        more += g_len - p_givenbeads;
    }
    if(less == 0){
        cout << "Yes " << more;
    }
    else{
        cout << "No " << less;
    }

    return 0;
}
