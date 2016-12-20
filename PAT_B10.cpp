// 设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
//
// 输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//
// 输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

#include <iostream>
using namespace std;

#define MAXSIZE 10000
int main(){
        int Nums = 0;
        int Tag = 0;
        int Poly[MAXSIZE];
        do{
                cin >> Poly[Nums++];
        }
        while(cin.get() != '\n');
        if(Nums == 2 && Poly[1] == 0)
        for(int i = 0; i < Nums; i++){
                if(i % 2 == 0)
                        Poly[i] *= Poly[i + 1];
                else
                        Poly[i]--;
        }
        for(int i = 0; i < Nums - 2; i++){
                if(Tag)
                        cout << " ";
                cout << Poly[i];
                Tag = 1;
        }
        if(Poly[Nums - 1] != -1)
                cout << " " << Poly[Nums - 2] << " " << Poly[Nums - 1];
        if(Nums == 2 && Poly[Nums - 1] == -1)
                cout << "0 0";
        return 0;
}
