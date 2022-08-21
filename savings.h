#ifndef SAVINGS_H_
#define SAVINGS_H_


class savings {

public:
	savings(double initialInvestment, double monthDeposit, double rate, int years);
	virtual ~savings();
	void reportNoMonthlyDeposits();
	void reportWithMonthlyDeposits();
//private declarations to abide by Airgead Banking Standards
private:
	double initialDeposit;
	double monthlyDeposit;
	double interestRate;
	int numYears;
};

#endif
