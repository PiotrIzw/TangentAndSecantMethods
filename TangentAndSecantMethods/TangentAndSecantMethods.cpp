#include <iostream>
using namespace std;


class Tangent {
public:
	double calculateTangentValue(double x, double accuracy);
};

class Secant {
public:
	double calculateSecantValue(double x0, double x1, double accuracy);
};



static double functionToCalculate(double x)
{
	return cos(x);
}


static double derivativeOfFunction(double x)
{
	return -sin(x);
}


double Tangent::calculateTangentValue(double x, double accuracy)
{
	int i = 0;
	double h = functionToCalculate(x) / derivativeOfFunction(x);
	while (fabs(h) >= accuracy)
	{
		i++;
		h = functionToCalculate(x) / derivativeOfFunction(x);


		x = x - h;
		cout << "Znaleziony punkt: " << x << endl;
	}

	cout << "Szukane rozwiazanie to: " << x << endl;
	cout << "Liczba iteracji: " << i << endl;
	return x;
}


double Secant::calculateSecantValue(double x0, double x1, double accuracy)
{
	double x2 = 0;
	int i = 0;
	while (fabs(x1 - x0) >= accuracy)
	{
		x2 = (functionToCalculate(x1) * x0 - functionToCalculate(x0) * x1) / (functionToCalculate(x1) - functionToCalculate(x0));
		x0 = x1;
		x1 = x2;

		i++;
		cout << "Znaleziony punkt: " << x2 << endl;
	}
	cout << "Szukane rozwiazanie to: " << x2 << endl;
	cout << "Liczba iteracji: " << i << endl;
	return x2;
}


int main()
{
	cout << "Rownanie: cos(x)" << endl;
	cout << "Metoda stycznych: " << endl;
	Tangent tangent;
	double x0;
	cout << "x0 = ";
	cin >> x0;

	cout << "Dokladnosc = ";
	double accuracy;
	cin >> accuracy;
	
	cout << endl << "Rozwiaznie: " << endl;
	double result = tangent.calculateTangentValue(x0, accuracy);
	result;
	cout << "Wartosc w funkcji w rozwiazaniu: " << functionToCalculate(result) << endl;
	cout << endl;

	cout << "Metoda siecznych: " << endl;

	Secant secant;
	float x1, x2;

	cout << "x1 = ";
	cin >> x1;

	cout << "x2 = ";
	cin >> x2;

	cout << "Dokladnosc = ";
	cin >> accuracy;

	cout << endl << "Rozwiaznie: " << endl;
	result = secant.calculateSecantValue(x1, x2, accuracy);
	result;
	cout << "Wartosc w funkcji w rozwiazaniu: " << functionToCalculate(result) << endl;
	cout << endl;
	return 0;
}