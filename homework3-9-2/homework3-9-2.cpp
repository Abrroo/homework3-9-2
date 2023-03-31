#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_= denominator;

	}
	
	int multiplyFirstCross(Fraction other) { return numerator_ * other.denominator_; }
	int multiplySecondCross(Fraction other) { return other.numerator_ * denominator_; }

	Fraction operator+(Fraction other) 
	{ 
		std::string operation = " + ";
		int result_num = multiplyFirstCross(other) + multiplySecondCross(other);
		int result_den = denominator_ * other.denominator_;
		printOperation(operation, numerator_, denominator_, other.numerator_, other.denominator_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator-(Fraction other) 
	{ 
		std::string operation = " - ";
		int result_num = multiplyFirstCross(other) - multiplySecondCross(other);
		int result_den = denominator_ * other.denominator_;
		printOperation(operation, numerator_, denominator_, other.numerator_, other.denominator_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator*(Fraction other) 
	{
		int divisor = std::gcd(numerator_ * other.numerator_, denominator_ * other.denominator_);
		int result_num = (numerator_ * other.numerator_) / divisor;
		int result_den = (denominator_ * other.denominator_) / divisor;
		std::string operation = " * ";
		printOperation(operation, numerator_, denominator_, other.numerator_, other.denominator_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator/(Fraction other)
	{
		int divisor = std::gcd(numerator_ * other.denominator_, denominator_ * other.numerator_);
		int result_num = (numerator_ * other.denominator_) / divisor;
		int result_den = (denominator_ * other.numerator_) / divisor;
		std::string operation = " / ";
		printOperation(operation, numerator_, denominator_, other.numerator_, other.denominator_, result_num, result_den);
		return Fraction(result_num, result_den);
	}

	Fraction operator-() { return Fraction(numerator_ * -1, denominator_);}
	Fraction operator++() 
	{ 
		return Fraction(numerator_ + denominator_, denominator_); 
	}
	Fraction operator++(int) 
	{ 
		numerator_ = numerator_ + denominator_;
		return Fraction(numerator_ - denominator_, denominator_); 
	}
	Fraction operator--() 
	{ 
		return Fraction(numerator_ - denominator_, denominator_);
	}
	Fraction operator--(int) 
	{ 
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_ + denominator_, denominator_);
	}

	void printFraction(int numerator_, int denominator_)
	{
		std::cout << numerator_ << "/" << denominator_;
	}
	void printOperation(std::string operation, int num1, int den1, int num2, int den2, int res_num, int res_den)
	{
		printFraction(num1, den1);
		std::cout << operation;
		printFraction(num2, den2);
		std::cout << " = ";
		printFraction(res_num, res_den);
		std::cout << std::endl;

	}
};

int main()
{
	
	setlocale(LC_ALL, "Russian");

	int num1, num2, den1, den2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> den1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> den2;
	std::cout << std::endl;

	Fraction f1(num1, den1);
	Fraction f2(num2, den2);
	
	


	/*Fraction summ_f1_f2 = f1 + f2;
	summ_f1_f2.printFraction();

	Fraction sub_f1_f2 = f1 - f2;
	sub_f1_f2.printFraction();*/

	Fraction mult_f1_f2 = ++f1 * f2;
	
	/*Fraction div_f1_f2 = -f1 / f2;
	div_f1_f2.printFraction();

	Fraction mult_f1_f2_v1 = ++f1 * f2;
	mult_f1_f2.printFraction();

	Fraction mult_f1_f2_v2 = f1++ * f2;
	mult_f1_f2.printFraction();*/
	

	return 0;
}