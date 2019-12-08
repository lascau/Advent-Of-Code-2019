#include <bits/stdc++.h>
 
using namespace std;
 
const int wide = 25;
const int tall = 6;
 
int main() {
    string in;
    cin >> in;
    string res(wide * tall, '2');
    for (int pos = 0; pos < wide * tall; ++pos) {
        int cur_layer = 0;
        while (1)
        {
            if (in[cur_layer * wide * tall + pos] != '2')
            {
                res[pos] = in[cur_layer * wide * tall + pos];
                break;
            }
            ++cur_layer;
        }
    }
 
    for (int i = 0; i < res.size(); ++i) {
        if (i % 25 == 0)
            cout << '\n';
        if (res[i] == '1'){
            cout << "# ";
        } else {
            cout << ". ";
        }
    }
    return 0;
}