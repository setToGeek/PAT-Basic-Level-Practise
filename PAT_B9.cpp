// 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
//
// 输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
//
// 输出格式：每个测试用例的输出占一行，输出倒序后的句子。

#include <iostream>
using namespace std;

typedef char WORD[80];
 int main(){
        WORD Word[80];
        int Tag = 0;
        int Ptr = 0;
        do{
                cin >> Word[Ptr++];
        }
        while(cin.get() != '\n');
        for(int i = Ptr - 1; i > -1; i--){
                if(Tag)
                        cout << " ";
                cout << Word[i];
                Tag = 1;
        }
}
