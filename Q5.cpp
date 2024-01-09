/*
Name:Muhammad Abdullah Ghani
Roll No:22I-2683
*/
#include<iostream>
using namespace std;
class fruitsalad{
private:
	string fruit[10];
	int servings;
	static int c;
public:
	fruitsalad() {
		servings = 0;
		fruit[10] ;
	}
	fruitsalad(string ingredients[], int numservings) {
		servings = numservings;
		for (int i = 0; i < 10; i++) {
			fruit[i] = ingredients[i];
		}
	}
	void setfruits(string fruits) {
		int i = 0;
		for (; i < 10;) {
			fruit[i] = fruits[i];
			i++;
		}
	}
	string getfruits(int i) {
		return fruit[i];
	}

	void setservings(int serving) {
		servings = serving;
		}
	int getservings(){
		return servings;
	}
	void addfruit(string fruitarg) {
		for (int i = 0; i < 10; i++) {
			if (fruit[i] == "") {
				fruit[i] = fruitarg;
				cout << "Fruit added" << endl;
				return;
			}
			else {
				cout << "Cant add fruit"<<endl;
			}
			
		}
	}
	void removefruit(string fruitarg) {
		for (int i = 0; i < 10; i++) {
			if (fruit[i] == fruitarg) {
				fruit[i] = "";
				cout << "Fruit removed" << endl;
				return;
			}
			else {
				cout << "Cant find the fruit" << endl;
			}
			
		}
	}
	void resetserving() {
		servings = 4;
	}
	string serve() {
	
		++c;
		if (servings<= 4) {
			return "enjoy";
		}
		else {
			return "sorry";
		}
	}



};
int fruitsalad::c = 0;
	int main() {

	
		string ingredients[]= { "Orange", "Mango", "orange", "strawberry", "melon", "cherry", "grape", "pineapple", "","Apple"};
		int numservings = 3;
		fruitsalad s(ingredients, numservings);
		s.addfruit("grapefruit");
		s.removefruit("strawberry");
		s.setservings(4);
		cout << "Servings" << s.getservings()<<endl;
		cout << "Serveing " << s.serve() << endl;
		
		return 0;
	}
