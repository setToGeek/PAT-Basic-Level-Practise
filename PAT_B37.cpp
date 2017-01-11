#include <iostream>

using namespace std;

struct Currency{
    int Galleon, Sickle, Knut;

    friend istream& operator>>(istream& i, Currency &c){
        char ch;
        i >> c.Galleon >> ch >> c.Sickle >> ch >> c.Knut;
        return i;
    }
    friend ostream& operator<<(ostream& o, Currency& c){
        o << c.Galleon << '.' << c.Sickle << '.' << c.Knut;
        return o;
    }
};

int main(int argc, char const *argv[]) {
    Currency actually_pay, payable_price, c;
    cin >> payable_price >> actually_pay;

    int a_p = (actually_pay.Galleon * 17 + actually_pay.Sickle) * 29 + actually_pay.Knut;
    int p_p = (payable_price.Galleon * 17 + payable_price.Sickle) * 29 + payable_price.Knut;
    int change = a_p - p_p;
    int signal = 0;
    if(change < 0){
        signal = 1;
        change *= -1;
    }
    c.Knut = change % 29;
    change /= 29;
    c.Sickle = change % 17;
    change /= 17;
    c.Galleon = change;
    if(signal == 1)
        cout << '-';
    cout << c;

    return 0;
}
