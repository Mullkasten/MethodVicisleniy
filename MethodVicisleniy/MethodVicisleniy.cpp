#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
void func() {
    float x = 4, y=4, alf=1, xt = 0, yt = 0,eps=0.0001,k=0,f=0,ft=0;
    do {
        f = 3*x - 1.2*y + pow(M_E, 0.02 * x * x + 0.13 * y * y);
        xt = x - alf * (0.04 * x * pow(M_E, 0.02 * x * x + 0.13 * y * y) + 3);
        yt = y - alf * (0.26 * y * pow(M_E, 0.02 * x * x + 0.13 * y * y) - 1.2);
        ft = 3 * xt - 1.2 * yt + pow(M_E, 0.02 * xt * xt + 0.13 * yt * yt);
        k++;
        while (f < ft) {
            alf /= 2;
            xt = x - alf * (0.04 * x * pow(M_E, 0.02 * x * x + 0.13 * y * y) + 3);
            yt = y - alf * (0.26 * y * pow(M_E, 0.02 * x * x + 0.13 * y * y) - 1.2);
            ft = 3 * xt - 1.2 * yt + pow(M_E, 0.02 * xt * xt + 0.13 * yt * yt);
        }
        x = xt;
        y = yt;
        cout << "x = " << x << "; y = " << y << "\n";
        cout << "f = " << f << "; f'x = " << (0.04 * x * pow(M_E, 0.02 * x * x + 0.13 * y * y) + 3) << "; f'y = " << (0.26 * y * pow(M_E, 0.02 * x * x + 0.13 * y * y) - 1.2) << "\n";
        cout << "alfa = " << alf << "\n";
    } while (not(((0.04 * x * pow(M_E, 0.02 * x * x + 0.13 * y * y) + 3) < (eps / 2))&&(((0.26 * y * pow(M_E, 0.02 * x * x + 0.13 * y * y) - 1.2) < (eps / 2)))));

    cout << "k = " << k<< "\n";
    cout << "x = " << x << "; y = " << y << "\n";
}



int main()
{
    func();
    std::cout << "The End!\n";
}

