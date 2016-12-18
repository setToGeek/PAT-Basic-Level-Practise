#include <iostream>
using namespace std;
#define MAXSIZE 100

void TurnIntoPinyin(int N){
        switch(N){
                case 1: cout << "yi";   break;
                case 2: cout << "er";   break;
                case 3: cout << "san";  break;
                case 4: cout << "si";   break;
                case 5: cout << "wu";   break;
                case 6: cout << "liu";  break;
                case 7: cout << "qi";   break;
                case 8: cout << "ba";   break;
                case 9: cout << "jiu";  break;
                case 0: cout << "ling"; break;
        }
}
int main(){
        char cBigN[MAXSIZE];
        int BigN[3], Sum = 0;
        cin >> cBigN;
        int Ptr = 0;
        while(cBigN[Ptr] != '\0'){
                Sum += cBigN[Ptr] - 48;
                Ptr++;
        }
        if(Ptr > 100){
                cerr << "输入整数过大";
                return -1;
        }
        Ptr = 0;
        while(Sum != 0){
                BigN[Ptr] = Sum % 10;
                Sum /= 10;
                Ptr++;
        }
        TurnIntoPinyin(BigN[Ptr - 1]);
        for(int i = Ptr - 2; i >= 0; i--){
                cout << " ";
                TurnIntoPinyin(BigN[i]);
        }
        return 0;
}
