#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int flag_;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_= denominator;
		flag_ = 0;

	}

	int multiplyFirstCross(Fraction other) { return numerator_ * other.denominator_; }
	int multiplySecondCross(Fraction other) { return other.numerator_ * denominator_; }

	Fraction operator+(Fraction other) 
	{ 
		std::string operation = " + ";
		int result_num = multiplyFirstCross(other) + multiplySecondCross(other);
		int result_den = denominator_ * other.denominator_;
		printOperation(operation, numerator_, denominator_, flag_, other.numerator_, other.denominator_, other.flag_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator-(Fraction other) 
	{ 
		std::string operation = " - ";
		int result_num = multiplyFirstCross(other) - multiplySecondCross(other);
		int result_den = denominator_ * other.denominator_;
		printOperation(operation, numerator_, denominator_, flag_, other.numerator_, other.denominator_, other.flag_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator*(Fraction other) 
	{
		int divisor = std::gcd(numerator_ * other.numerator_, denominator_ * other.denominator_);
		int result_num = (numerator_ * other.numerator_) / divisor;
		int result_den = (denominator_ * other.denominator_) / divisor;
		std::string operation = " * ";
		printOperation(operation, numerator_, denominator_, flag_, other.numerator_, other.denominator_, other.flag_, result_num, result_den);
		return Fraction(result_num, result_den); 
	}
	Fraction operator/(Fraction other)
	{
		int divisor = std::gcd(numerator_ * other.denominator_, denominator_ * other.numerator_);
		int result_num = (numerator_ * other.denominator_) / divisor;
		int result_den = (denominator_ * other.numerator_) / divisor;
		std::string operation = " / ";
		printOperation(operation, numerator_, denominator_, flag_, other.numerator_, other.denominator_, other.flag_, result_num, result_den);
		return Fraction(result_num, result_den);
	}

	Fraction operator-() { return Fraction(numerator_ * -1, denominator_);}
	Fraction& operator++() //post
	{ 
		flag_ = 2;
		numerator_ = numerator_ + denominator_;
		return *this; 
	}
	Fraction operator++(int) //pre
	{ 
		flag_ = 1;
		Fraction temp = *this;
		numerator_ = numerator_ + denominator_;
		return temp; 
	}
	Fraction& operator--() //post
	{ 
		flag_ = 4;
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction operator--(int) //pre
	{ 
		flag_ = 3;
		Fraction temp = *this;
		numerator_ = numerator_ - denominator_;
		return temp;
	}

	void printFraction(int numerator_, int denominator_)
	{
		std::cout << numerator_ << "/" << denominator_;
	}

	void printFraction()
	{
		std::cout << numerator_ << "/" << denominator_;
	}

	void wipe()
	{
		this->flag_ = 0;
	}

	void printOperation(std::string operation, int num1, int den1, int flag1, int num2, int den2, int flag2, int res_num, int res_den)
	{
		if (flag1 == 2) { std::cout << "++"; }
		if (flag1 == 4) { std::cout << "--"; }
		printFraction(num1, den1);
		if (flag1 == 1) { std::cout << "++"; }
		if (flag1 == 3) { std::cout << "--"; }
		std::cout << operation;
		if (flag2 == 2) { std::cout << "++"; }
		if (flag2 == 4) { std::cout << "--"; }
		printFraction(num2, den2);
		if (flag2 == 1) { std::cout << "++"; }
		if (flag2 == 3) { std::cout << "--"; }
		std::cout << " = ";
		printFraction(res_num, res_den);
		std::cout << std::endl;
		//flag1 = 0;
		//flag2 = 0;

	}
};

void printData(Fraction f1, Fraction f2)
{
	std::cout << "Значение дроби 1: ";
	f1.printFraction();
	std::cout << std::endl;
	std::cout << "Значение дроби 2: ";
	f2.printFraction();
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	
	setlocale(LC_ALL, "Russian");
	
	int num1, num2, den1, den2;

	//std::cout << "Введите числитель дроби 1: ";
	//std::cin >> num1;
	//std::cout << "Введите знаменатель дроби 1: ";
	//std::cin >> den1;
	//std::cout << "Введите числитель дроби 2: ";
	//std::cin >> num2;
	//std::cout << "Введите знаменатель дроби 2: ";
	//std::cin >> den2;
	//std::cout << std::endl;

	//Fraction f1(num1, den1);
	//Fraction f2(num2, den2);
	
	Fraction f1(3, 4);
	Fraction f2(3, 4);

	//Fraction summ_f1_f2 = f1 + f2;
	//Fraction sub_f1_f2 = f1 - f2;
	Fraction mult_f1_f2 = f1++ * ++f2;
	printData(f1, f2);
	f1.wipe();
	f2.wipe();
	Fraction div_f1_f2 = f1 / f2++;
	printData(f1, f2);
	//Fraction mult_f1_f2_v1 = ++f1 * f2;
	//Fraction mult_f1_f2_v2 = f1++ * f2;
	

	return 0;
}