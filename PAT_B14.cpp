#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define min(a, b) (a > b ? b : a)
typedef char CODE[60];
enum DAY {MON, TUE, WED, THU, FRI, SAT, SUN};

void SwitchToDay(char ch, DAY &day){
        day = (DAY)(ch - 65);
}
int main(){
        DAY Day;
        int Len, Ptr = 0, Hour, Minute;
        CODE Sentence[4];
        for(int i = 0; i < 4; i++){
                cin >> Sentence[i];
        }
        Len = min(strlen(Sentence[0]), strlen(Sentence[1]));
        while(Ptr != Len){
                char Ch;
                if(Sentence[0][Ptr] == Sentence[1][Ptr]){
                        Ch = Sentence[0][Ptr];
                        cout << Ch << endl;
                        SwitchToDay(Ch, Day);
                        Ptr++;
                        break;
                }
                Ptr++;
        }
        while(Ptr != Len){
                char Ch;
                if(Sentence[0][Ptr] == Sentence[1][Ptr]){
                        Ch = Sentence[0][Ptr];
                        cout << Ch << endl;
                        if(Ch >= 'A')
                                Hour = Ch - 55;
                        else
                                Hour = Ch - 48;
                        break;
                }
                Ptr++;
        }
        Ptr = 0;
        Len = min(strlen(Sentence[2]), strlen(Sentence[3]));
        while(Ptr != Len){
                if(Sentence[2][Ptr] == Sentence[3][Ptr]){
                        Minute = Ptr;
                        break;
                }
                Ptr++;
        }
        cout << Day << " " << Hour << ":" << setfill('0') << setw(2) << Minute;
        return 0;
}
