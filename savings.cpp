#include <iomanip>
#include <iostream>
#include "savings.h"

using namespace std;


//Constructor

//Set values for each variable
savings::savings(double initialInvestment, double monthDeposit, double rate, int years) {
	this->initialDeposit = initialInvestment;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = rate;
	this->numYears = years;

}


//Destructor
savings::~savings() {
}


//Prints report without monthly deposits
void savings::reportNoMonthlyDeposits() {

	//Print Table
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	//Calculate interest for number of years given
	int currentyear = 1;
	double yearendBalance = this->initialDeposit;

	while (currentyear <= this->numYears) {

		//Calculate interest
		double interestearned = yearendBalance * this->interestRate / 100;
		yearendBalance += interestearned;

		//Print results for each year given
		cout << right << setw(10) << currentyear << fixed << setprecision(2) << setw(20) << yearendBalance << setw(35) << interestearned << endl;
		currentyear++;
	}

}


//Prints report considering monthly deposit

void savings::reportWithMonthlyDeposits() {

	//Print Table
	cout << " Balance and Interest with additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	//Iterate for given years and calculate interest earned

	int currentyear = 1;
	double yearendBalance = this->initialDeposit;

	while (currentyear <= this->numYears) {

		//calulate interest monthly and find compoud interest
		int month = 1;
		double interestearned = 0.0;
		double monthendbalance = yearendBalance;

		while (month <= 12) {

			//Add monthly deposit
			monthendbalance += this->monthlyDeposit;

			//Calculate monthly interest, interest rate is for annual. so divide the rate by 12
			double monthlyinterest = monthendbalance * this->interestRate / (100 * 12);

			//Add the monthly interest to yearly interest earned
			interestearned += monthlyinterest;

			// add the interest to monthend balance
			monthendbalance += monthlyinterest;

			//Increase the month by 1
			month++;

		}


		yearendBalance = monthendbalance;

		//Print the results
		cout << right << setw(10) << currentyear << fixed << setprecision(2) << setw(20) << yearendBalance << setw(35) << interestearned << endl;

		//Increase the year count by one
		currentyear++;

	}

}