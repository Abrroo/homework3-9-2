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
		denominator_ = denominator;

	}
	int multiplyFirstCross(Fraction other) { return numerator_ * other.denominator_; }
	int multiplySecondCross(Fraction other) { return other.numerator_ * denominator_; }

	Fraction operator+(Fraction other) 
	{ 
		return Fraction(multiplyFirstCross(other) + multiplySecondCross(other), denominator_ * other.denominator_); 
	}
	Fraction operator-(Fraction other) 
	{ 
		return Fraction(multiplyFirstCross(other) - multiplySecondCross(other), denominator_ * other.denominator_); 
	}
	Fraction operator*(Fraction other) 
	{
		std::cout << numerator_ << "/" << denominator_ << " * " << other.numerator_ << "/" << other.denominator_ << " = ";
		int divisor = std::gcd(numerator_ * other.numerator_, denominator_ * other.denominator_);
		return Fraction((numerator_ * other.numerator_)/divisor, (denominator_ * other.denominator_)/divisor); 
	}
	Fraction operator/(Fraction other)
	{
		int divisor = std::gcd(numerator_ * other.denominator_, denominator_ * other.numerator_);
		return Fraction((numerator_ * other.denominator_) / divisor, (denominator_ * other.numerator_) / divisor);
	}

	Fraction operator-() { return Fraction(numerator_ * -1, denominator_);}
	Fraction operator++() { std::cout << "++"; return Fraction(numerator_ + denominator_, denominator_); }
	Fraction operator++(int) { std::cout << "++"; return Fraction(numerator_ + denominator_, denominator_); }
	Fraction operator--() { std::cout << "--"; return Fraction(--numerator_, --denominator_); }
	Fraction operator--(int) { std::cout << "--"; return Fraction(numerator_--, denominator_--); }

	void printFraction()
	{
		std::cout << numerator_ << "/" << denominator_ << std::endl;
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
	mult_f1_f2.printFraction();
	
	/*Fraction div_f1_f2 = -f1 / f2;
	div_f1_f2.printFraction();

	Fraction mult_f1_f2_v1 = ++f1 * f2;
	mult_f1_f2.printFraction();

	Fraction mult_f1_f2_v2 = f1++ * f2;
	mult_f1_f2.printFraction();*/
	

	return 0;
}