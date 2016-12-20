#include <iostream>
using namespace std;

struct Question{
    int total, correct, score;
    char answer[5];
    friend istream& operator>>(istream &i, Question q);
};

friend istream& operator>>(istream &i, Question q){
    i >> q.score >> q.total >> q.correct;
    for (size_t i = 0; i < q.correct; i++) {
        i >> q.answer[i];
    }
}
