#include <iostream>
#include "savings.h"

using namespace std;

int main() {
	while (1) {
		//Required Display
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;\
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		cout << endl;

		//Declare variabes for input
		double initialInvestment;
		double monthlydeposit;
		double interestrate;
		int years;
		string choice;

		//Required dislpay with input
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: $";
		cin >> initialInvestment;
		cout << "Monthly Deposit: $";
		cin >> monthlydeposit;
		cout << "Annual Interest: %";
		cin >> interestrate;
		cout << "Number of years: ";
		cin >> years;

		//Create savings object using the given inputs
		savings mysavings = savings(initialInvestment, monthlydeposit, interestrate, years);
		cout << endl;

		//Invoke the report methods
		mysavings.reportNoMonthlyDeposits();
		cout << endl;

		//call monthly deposit report, if it has monthly deposit at least $1
		if (monthlydeposit > 0) {
			mysavings.reportWithMonthlyDeposits();
		}


		//Get input on choice decision
		cout << endl << "Do you want to try another? (y/n): ";
		cin >> choice;

		//Anything other than y, end program.
		if (choice != "y") {
			break;
		}
		cout << endl;
	}
	return 0;

}