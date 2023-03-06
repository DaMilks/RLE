#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int res = 0;
    int resM = 0;
    int resS = 0;
    int n, m, k, sizeM = 0, sizeS = 0;
    string mn;
    string ms;
    cin >> n >> m >> k;
    cin >> mn >> ms;
    stringstream str(mn);
    stringstream str1(ms);

    char bm, bs;
    int am, as;
    str >> bm >> am;
    str1 >> bs >> as;
    int a = 0;
    while (str && str1)
    {
        if (bm == bs)
        {
            a = 0;
        }
        else a = 1;
            if (am < as) {
                res += am*a;
                as -= am;
                str >> bm >> am;
            }
            else if (am == as) {
                res += am*a;
                as -= am;
                str >> bm >> am;
                str1 >> bs >> as;
            }
            else if (am > as) {
                res += as*a;
                am -= as;
                str1 >> bs >> as;
            }
        }

    if (res < k) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}