#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxDate = 20140906;
const int minDate = 18140906;

int main(){
    int n, max = 20140906, min = 18140906, validNums = 0;
    char *oldest = NULL, *youngest = NULL;
    cin >> n;
    while(n--){
        int ptr = 0;
        char *name = new char[6];
        char ch, birthday[9];
        cin >> name;
        while((ch = cin.get()) != '\n'){
            if(ch >= '0' && ch <= '9')
                birthday[ptr++] = ch;
        }
        birthday[ptr] = '\n';
        int date = atoi(birthday);
        if(date >= minDate && date <= maxDate){
            validNums++;
            if(date < max){
                char *tmp = new char[6];
                delete []oldest;
                strcpy(tmp, name);
                max = date;
                oldest = tmp;
            }
            if(date > min){
                char *tmp = new char[6];
                delete []youngest;
                strcpy(tmp, name);
                min = date;
                youngest = tmp;
            }
            cout << validNums << " ";
        }
        delete []name;
        cout << oldest << " " << youngest << " ";
    }
    cout << validNums << " " << oldest << " " << youngest;
    delete oldest;
    delete youngest;
    return 0;
}
