#include <bits/stdc++.h>

using namespace std;

inline int pos(int i, int j) {
    return i * 5 + j;
}

inline int isSet(int x, int pos) {
    return (x >> pos) & 1;
}

int isInside(int x, int y) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        return 0;
    }
    return 1;
}

void print(int mask) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (isSet(mask, pos(i, j))) {
                cout << '#';
            } else {
                cout <<'.';
            }
        }
        cout << '\n';
    }
    cout <<"---------------------\n";
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    int mask = 0;
    int new_mask = 0;
    long long rating = 0;
    bool found = 0;
    unordered_set<int> cache;
    char val;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5;  ++j) {
            in >> val;
            mask |= (val == '#') << pos(i, j);
        }
    }
    print(mask);
    cache.insert(mask);
    new_mask = mask;
    for (int minute = 1; minute <= 1000 && !found; ++minute) {
        for (int i = 0; i < 5 && !found; ++i) {
            for (int j = 0; j < 5 && !found; ++j) {

                int no_adjacent_bugs = 0;
                if (isInside(i - 1, j)) {
                    if (isSet(mask, pos(i - 1, j))) {
                        ++no_adjacent_bugs;
                    }
                }

                if (isInside(i + 1, j)) {
                    if (isSet(mask, pos(i + 1, j))) {
                        ++no_adjacent_bugs;
                    }
                }

                if (isInside(i, j - 1)) {
                    if (isSet(mask, pos(i, j - 1))) {
                        ++no_adjacent_bugs;
                    }
                }

                if (isInside(i, j + 1)) {
                    if (isSet(mask, pos(i, j + 1))) {
                        ++no_adjacent_bugs;
                    }
                }

                if (isSet(mask, pos(i, j))) {
                    if (no_adjacent_bugs != 1) {
                        new_mask &= ~(1 << pos(i, j));
                    }
                } else {
                    if (no_adjacent_bugs == 1 || no_adjacent_bugs == 2) {
                        new_mask |= (1 << pos(i, j));
                    }
                }
               // cout << no_adjacent_bugs;
            }
           // cout << '\n';
        }
        mask = new_mask;
        print(new_mask);
        if (cache.find(mask) != cache.end()) {
            print(mask);
            found = 1;
        }
        cache.insert(mask);
    }
    for (int i = 0; i < 25; ++i) {
        rating += (1 << i) * isSet(mask, pos(i / 5, i % 5));
    }
    out << found << ' ' << rating;
    return 0;
}
