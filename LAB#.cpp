/*************************
* Автор: Сатин В.Р.      *
* Дата: 21.09.26         *
* Название: Вариант 10   *
*************************/


#include <cmath> 
#include <iomanip> 
#include <iostream>
int main() {

	// Declared variables
	double v, r, t, phi, gamma, omega, radians, l;
	double v_approx;
	const double pi = 3.14;

	// The user enters the values of the variables.
	std::cout << "r=";
	std::cin >> r;
	
	std::cout << "l=";
	std::cin >> l;
	
	std::cout << "t=";
	std::cin >> t;
	
	std::cout << "phi=";
	std::cin >> phi;
	

	// Converting centimeters to meters
	r = r / 100;
	l = l / 100;

	// C++ works with radians, but we have degrees.
	radians = phi * pi / 180;

	// Let us find gamma 
	gamma = std::asin((r * std::sin(radians)) / l);

	// Precise formula
	v = -(r * radians / t) *
		(std::sin(radians + gamma) / std::cos(gamma));

	// Approximate formula
	v_approx = -(r * radians / t) *
		(std::sin(radians) +
			(r * std::sin(radians) * std::cos(radians)) / l);

	// Acceleration
	omega = -(r * radians * radians / (t * t)) *
		(std::cos(radians) +
			(r * std::cos(2 * radians)) / l);
	
	// Outputting the answer
	std::cout << "gamma = " << gamma << std::endl;
	std::cout << "Exact velocity = " << v << std::endl;
	std::cout << "Approximate velocity = "<< v_approx << std::endl;
	std::cout << "Acceleration = "<< omega << std::endl;
	return 0;
}