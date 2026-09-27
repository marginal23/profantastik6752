/*******************************
* Автор: Сатин В.Р.            *
* Вариант: 10                  *
* Название: Линейные алгоритмы *
*******************************/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const double pi = 3.14;
    double v, r, t, phi, gamma, omega, radians, l;
    double vApprox;

    cout << "r=";
    cin >> r;

    cout << "l=";
    cin >> l;

    cout << "t=";
    cin >> t;

    cout << "phi=";
    cin >> phi;

    // Converting centimeters to meters
    r = r / 100.0;
    l = l / 100.0;

    // C++ works with radians, but we have degrees.
    radians = phi * pi / 180.0;

    // Let us find gamma
    gamma = asin((r * sin(radians)) / l);

    // Precise formula
    v = -(r * radians / t) * (sin(radians + gamma) / cos(gamma));

    // Approximate formula
    vApprox = -(r * radians / t) * (sin(radians) + (r * sin(radians) * cos(radians)) / l);

    // Acceleration
    omega = -(r * radians * radians / (t * t)) * (cos(radians) + (r * cos(2.0 * radians)) / l);

    // Outputting the answer
    cout << "gamma = " << gamma << '\n'
         << "Exact velocity = " << v << '\n'
         << "Approximate velocity = " << vApprox << '\n'
         << "Acceleration = " << omega << '\n';

    return 0;
}
