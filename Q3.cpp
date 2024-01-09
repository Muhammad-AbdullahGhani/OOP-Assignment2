/*
Name:Muhammad Abdullah Ghani
Roll No:22I-2683
*/
#include<iostream>
#include<string>
using namespace std;
class Integer {
private:
	int integer;
public:
	Integer() {
		integer = 0;
	}
	Integer(int num) {
		integer = num;
	}
	Integer(string number) {
		 int result = 0;
		int sign = 1;
		int i = 0;
		if (number[0] == '-') {
			sign = -1;
			i = 1;
		}
		else {
			i = 0;
		}
		for (; i < number.size();i++) {
			if (isdigit(number[i])) {
				result = result * 10 + (number[i] - '0');
			}
		}
		integer = result;
	
	}
	void set(int integer) {
		this->integer = integer;
	}
	int get()const {
		return integer;
	}
	int bitCount() {
		int c=0,bit = integer;
		for (int i = bit; bit != 0; ) {
			c -=-(bit & 1);
			bit >>= 1;
		}
		return c;
	}
	int compareTo(Integer i) {
		if (integer == i.get()) {
			return 1;
		}
	}
	double doubleValue() {
		return static_cast<double>(integer);
	}
	float floatValue() {
		return static_cast<float>(integer);
	}
	Integer plus(const Integer i) {
		
		return Integer( integer + i.integer);
	 
	}
	Integer minus(const Integer i) {
		return Integer(integer - i.integer);
	}
	Integer multiple(const Integer i) {
		return Integer(integer * i.integer);
	}
	Integer divide(const Integer i) {
		return Integer(integer / i.integer);
	}
	static int numberOfLeadingZeros(int i) {
		int size,c=0;
		size = 4;
		for (int j = size * 8 ; j > 0; j--) {
			if ((i & (1 << j)) == 0) {
				c-=-1;
			}
			else {
				break;
			}
			
		}
		return c;
	}

	static int numberOfTrailingZeros(int i) {
		int size = 4, c = 0;
		int count = 0;
		for (int j = size * 8; j > 0; j--)
		 if((i & 1) == 0) {
			 count-=-1;
			i >>= 1;
		}
		return count;
	}
	static string toBinaryString(int i) {
		char bin;
		string binarystring = "";
		for (; i > 0;) {
			bin = '0' + (i % 2);
			binarystring =binarystring +bin;
			i =i/2;
		}
		string result;
		result = binarystring;
		return result;

	}

};
int main() {
	Integer num(4);
	Integer str("3");
	cout << "Bit count " << num.bitCount()<<endl;
	Integer number(4);
	cout << "Comparison " << num.compareTo(number);
	Integer s;
	s= num.plus(str);
	cout << "Sum is" << s.get()<<endl;
	Integer difference;
	difference= num.minus(number);
	cout << "difference is" << difference.get()<<endl;
	Integer multi;
	multi= num.multiple(number);
	cout << "Multiplication is" << multi.get()<<endl;

	Integer division;
		division= num.divide(number);
		cout << "Division is" << division.get()<<endl;
		Integer obj(10);
		cout << "\nLeading zeroes "<<obj.numberOfLeadingZeros(obj.get()) << endl;
		cout << "\nTrailing zeroes " << obj.numberOfTrailingZeros(obj.get()) << endl;
		cout << "Binary conversion is " << obj.toBinaryString(obj.get());
	return 0;
}
