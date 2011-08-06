#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
    int cols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(cols)/sizeof(int);
    sort(cols, cols+size);
    do {
        set<int> tmpset1;
        set<int> tmpset2;
        for(int i = 0; i < size; ++i) {
            tmpset1.insert(cols[i]+i);
            tmpset2.insert(cols[i]-i);
        }
        if (tmpset1.size() == size && tmpset2.size() == size) {
            for(int j = 0; j < size; ++j) {
                cout << endl;
                for(int k = 0; k < size; ++k)
                    if (k == cols[j])
                        cout << "Q";
                    else
                        cout << "+";
            }
            cout << endl;
        }
    } while (next_permutation(cols, cols+size));
}
