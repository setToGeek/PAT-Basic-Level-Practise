#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
    int id[10000] = {0};
    int visited[10000] = {0};
    int ifPrime[10001];
    for (int i = 2; i < 10001; i++) {
        if(i == 2){
            ifPrime[i] = 1;
            continue;
        }
        int j = 2;
        for(; j < sqrt(i); j++){
            if(ifPrime[j] == 1 && i % j == 0){
                ifPrime[i] = 0;
                break;
            }
        }
        if(j > sqrt(i))
            ifPrime[i] = 1;
    }
    int n, rank = 1;
    cin >>n;
    while(n--){
        int tmp;
        cin >> tmp;
        id[tmp] = rank;
        rank++;
    }
    cin >> n;
    while(n--){
        int inquiry;
        cin >> inquiry;
        if(id[inquiry] == 0){
            cout << setw(4) << setfill('0') << inquiry << ": Are you kidding?";
        } else if(visited[inquiry] == 1){
            cout << setw(4) << setfill('0') << inquiry << ": Checked";
        } else if (id[inquiry] == 1) {
            cout << setw(4) << setfill('0') << inquiry << ": Mystery Award";
        } else if (ifPrime[id[inquiry]]) {
            cout << setw(4) << setfill('0') << inquiry << ": Minion";
        } else {
            cout << setw(4) << setfill('0') << inquiry << ": Chocolate";
        }
        visited[inquiry] = 1;
        cout << endl;
    }
    return 0;
}
