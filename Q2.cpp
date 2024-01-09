/*
Name:Muhammad Abdullah Ghani
Roll No:22I-2683
*/
#include<iostream>
#include<string>
using namespace std;

class CSR {
private:
	int csrID;
	char* csrName;
	int hours;
	int complaintsResolved;
	float payrate;
	float wage;
	static int totalComplaintsResolved;
public:
	CSR() {
		csrID = 0;
		csrName = nullptr;
		hours = 0;
		complaintsResolved = 0;
		payrate = 0;
		wage = 0.0;
		
	}
	CSR(int id, int h, const char * name, int complaint,float wages, float pay) {
		wage = wages;
		payrate = pay;
		complaintsResolved = complaint;
		csrID = id;
		hours = h;
		complaintsResolved = complaint;

		int c = 0;
		for (; name[c] != '\0';) {
			c++;
		}
		csrName = new char[c];
		for (int i = 0; i < c; i++) {
			csrName[i] = name[i];

		}

		csrName[c] = '\0';
		
		
	}
	
	int getCSRID() {
		return csrID;
	}
	char* getName() {
		return csrName;
	}
		
	int getHours() {
		return hours;
	}
	int getComplaintsResolved() {
		return complaintsResolved;
	}
	float getPayrate() {
		//calcPayrate();
		return payrate;
	}
	float getWage() {
		return wage;
	}
	void setCSRID(int ID) {
		csrID = ID;
	}
	void setName(char* n) {
		int c = 0;
		while (*n != '\0') {
			c++;
		}
		csrName = new char[c + 1];
		for (int i = 0; i < c; i++) {
			csrName[i] = n[i];
		}
	
	}
	void setHours(int hours) {
		this->hours = hours;
	}
	void setComplaintsResolved(int cpsResolved) {
		complaintsResolved = cpsResolved;
	}
	static void setTotalCpsResolved(int totalCpsResolved) {
		totalComplaintsResolved = totalCpsResolved;
	}
	float calcWage() {
			wage = hours * payrate;
			return wage;
	}
	void calcPayrate() {
		payrate = 50 * (complaintsResolved / totalComplaintsResolved);
	}
	static int getTotalCpsResolved() {
		return totalComplaintsResolved;
	}

};
int  CSR::totalComplaintsResolved = 0;
CSR getCSR_at(CSR employees[7], int index) {
	return employees[index];
}
float calcAllEmployeeWages(CSR employees[7]) {
	CSR obj;
	float sum=0;
	for (int i = 0; i < 7; i++) {
		sum+= employees[i].calcWage();
	}
	return sum;
	
}
void SortByHours(CSR employees[7]) {
	CSR temp;
	for (int j = 0; j < 7;j++) {
		for (int i = 0; i < 6 - i; i++) {
			if (employees[j].getHours() < employees[j + 1].getHours())
				temp = employees[i];
			employees[i] = employees[i + 1];
			employees[i + 1] = temp;
		}
	}
}
void SortByComplaintsRes(CSR employees[7]) {
		CSR temp;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6 - i; j++) {
				if (employees[j].getComplaintsResolved() < employees[j + 1].getComplaintsResolved()) {
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
}
void SortByWages(CSR employees[7]) {
	CSR temp;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6 - i; j++) {
			if (employees[j].getWage() < employees[j + 1].getWage()) {
				temp = employees[j];
				employees[j] = employees[j + 1];
				employees[j + 1] = temp;
			}
		}
	}
}
int main() {
	CSR employees[7];
	employees[0] = CSR(1, 40, "Abdullah", 2,200,2000);
	employees[1] = CSR(2, 35, "Ghani", 3,300,8000);
	employees[2] = CSR(4, 45, "Hassan", 4,400,1500);
	employees[3] = CSR(5, 30, "Ali", 6,500,500);
	employees[4] = CSR(5, 50, "yasir", 2,600,9000);
	employees[5] = CSR(5, 35, "Ibrahim", 8,700,1000);
	employees[6] = CSR(5, 40, "Khan", 1,800,1000);
	CSR obj;
	
	for (int i = 0; i < 7; i++) {
		CSR::setTotalCpsResolved(CSR::getTotalCpsResolved() + employees[i].getComplaintsResolved());
	}
	cout << "Total complaints " << obj.getTotalCpsResolved() << endl;
	cout << "\nWages " << endl;
	cout<<calcAllEmployeeWages(employees);
		
	cout << "\nEmployee info before sorting " << endl;
	for (int i = 0; i < 7; i++) {
		cout << "ID " << employees[i].getCSRID() << endl;
		cout << "Name " << employees[i].getName()<<endl;
		cout << "Hours " << employees[i].getHours()<<endl;
		cout << "Complaints Resolved " << employees[i].getComplaintsResolved()<<endl;
		cout<< "Wages " << employees[i].getWage() << endl;
	}
	SortByComplaintsRes(employees);
	cout << "\nEmployee info After sorting by Complaints" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "ID " << employees[i].getCSRID() << endl;
		cout << "Name " << employees[i].getName() << endl;
		cout << "Hours " << employees[i].getHours() << endl;
		cout << "Complaints Resolved " << employees[i].getComplaintsResolved() << endl;
		cout << "Wages " << employees[i].getWage() << endl;
	}
	SortByWages(employees);
	cout << "\nEmployee info After sorting by Wages" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "ID " << employees[i].getCSRID() << endl;
		cout << "Name " << employees[i].getName() << endl;
		cout << "Hours " << employees[i].getHours() << endl;
		cout << "Complaints Resolved " << employees[i].getComplaintsResolved() << endl;
		cout << "Wages " << employees[i].getWage() << endl;
	}
	SortByHours(employees);
	cout << "\nEmployee info After sorting by hours" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "ID " << employees[i].getCSRID() << endl;
		cout << "Name " << employees[i].getName() << endl;
		cout << "Hours " << employees[i].getHours() << endl;
		cout << "Complaints Resolved " << employees[i].getComplaintsResolved() << endl;
		cout << "Wages " << employees[i].getWage() << endl;
	}




	return 0;
}