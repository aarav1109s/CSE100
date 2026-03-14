#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<list<int>> table(m);

    char cmd;
    while (cin >> cmd) {
        if (cmd == 'e') {
            break;
        }
        if (cmd == 'o') {
            for (int i = 0; i < m; i++) {
                cout << i << ":";
                for (int key : table[i]) {
                    cout << key << "->";
                }
                cout << ";\n";
            }
            continue;
        }
        int key;
        cin >> key;
        int idx = key % m;

        if (cmd == 'i') {
            table[idx].push_front(key);
        } else if (cmd == 's') {
            int j = 0;
            bool found = false;
            for (auto it = table[idx].begin(); it != table[idx].end(); ++it, ++j) {
                if (*it == key) {
                    cout << key << ":FOUND_AT" << idx << "," << j << ";\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << key << ":NOT_FOUND;\n";
            }
        } else if (cmd == 'd') {
            bool deleted = false;
            for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
                if (*it == key) {
                    table[idx].erase(it);
                    cout << key << ":DELETED;\n";
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << key << ":DELETE_FAILED;\n";
            }
        }
    }
    return 0;
}
