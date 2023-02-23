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
    
    cin >> mn >> ms;
    for (int i = 0; i < mn.length(); i++)
        if (!isdigit(mn[i]))
            sizeM++;
    for (int i = 0; i < ms.length(); i++)
        if (!isdigit(ms[i]))
            sizeS++;
    int* am = new int[sizeM];
    int* as = new int[sizeS];
    char* bm = new char[sizeM];
    char* bs = new char[sizeS];
    stringstream str(mn);
    for (int i = 0; i < sizeM; i++)
        str >> bm[i] >> am[i];
    str = stringstream(ms);
    for (int i = 0; i < sizeS; i++)
        str >> bs[i] >> as[i];
    int tmp;
    while (resS < sizeS && resM < sizeM) 
    {
        if (bm[resM] == bs[resS]) {
            tmp = am[resM];
            am[resM] -= as[resS];
            as[resS] -= tmp;
            if (am[resM] <= 0) {
                resM++;
            }
            if (as[resS] <= 0) {
                resS++;
            }
        }
        else {
            if (am[resM] < as[resS]) {
                res += am[resM];
                as[resS] -= am[resM];
                resM++;
            }
            if (am[resM] == as[resS]) {
                res += am[resM];
                resS++;
                resM++;
            }
            else {
                res += as[resS];
                am[resM] -= as[resS];
                resS++;
            }
        }
    }
    if (res < k) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    delete[] bm;
    delete[] bs;
    delete[] as;
    delete[] am;
    return 0;
}