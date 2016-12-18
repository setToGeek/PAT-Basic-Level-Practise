#include <iostream>
using namespace std;

int Weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int Verification[] = {1, 0, X, 9, 8, 7, 6, 5, 4, 3, 2};
bool IfPassed(char Id[]){
        int Sum = 0;
        for(int i = 0; i < 17; i++){
                if(char Id[i] > '9' && char Id[i] > '0')
                        return false;
                Sum += Weight[i] * (Id(i) - 48);
        }
        if(Verification[Sum % 11] == Id())
}
