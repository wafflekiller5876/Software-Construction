//Project 1
//Simple debt and interest program
//Calvin Hirschler
//clh0118
//project1_Hirschler_clh0118.cpp
//g++ project1_Hirschler_clh0118.cpp -0 a.out
//./a.out
#include <iostream>
#include <fstream>
#include <iomanip>
using std::cout; using std::endl;
using std::cin;
using std::ifstream;

int main() { 
	
	//variables
	double loanAmount = 0;
	double interest = 0;
	int monthlyPayments = 0;
	int numOfMonths = 0;
	double payment = 0;
	double interestPayment = 0;
	double principal = 0;
	double totalInterest = 0;
	//getting input
	cout << "Enter the loan amount" << endl;
	cin >> loanAmount;
	cout << "Enter the interest rate" << endl;
	cin >> interest;
	cout << "Enter the monthly payments" << endl;
	cin >> monthlyPayments;
	
	interest = interest/1200;
	//checking input
	if (loanAmount < 0 || monthlyPayments < 0 || interest < 0){
		cout << "number entered is negative" << endl;
		return 0;
	}
	if (loanAmount * interest >= monthlyPayments){
		cout << "you must input a greater monthly payment... you will not pay off your debt" << endl;
		return 0;
	}
	//display input to user
	cout << "Loan Amount: " << loanAmount << endl;
	cout << "Interest Rate: " << interest << endl;
	cout << "Monthly Payments: " << monthlyPayments << endl;
	//starting output
	cout << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal" << endl;
	//while loop
	while (loanAmount + loanAmount * interest - monthlyPayments > 0) {
		//first month
		if (numOfMonths == 0) {
			std::cout << std::fixed << std::setprecision(2) <<
			"0\t$" << loanAmount << "\tN/A\t\tN/A\tN/A\t\tN/A" << endl;
			//setting variables
			interestPayment = loanAmount * interest;
			principal = monthlyPayments - interestPayment;
			numOfMonths++;
			loanAmount = (loanAmount + loanAmount * interest) - monthlyPayments;
			totalInterest = totalInterest + interestPayment;
		}
		//output
		cout << numOfMonths << "\t$";
		std::cout << std::fixed << std::setprecision(2) <<
		loanAmount<< "\t\t$" << monthlyPayments << "\t\t" << interest * 100 << "\t$" <<
		interestPayment << "\t\t$" << principal << "\t" << endl;
		//setting variables
		interestPayment = loanAmount * interest;
		principal = monthlyPayments - interestPayment;
		numOfMonths++;
		loanAmount = (loanAmount + loanAmount * interest) - monthlyPayments;
		totalInterest = totalInterest + interestPayment;
		//incase something bad happens
		if (numOfMonths > 1000)
			break;
	}

	cout << numOfMonths << "\t$";
	std::cout << std::fixed << std::setprecision(2) <<
	loanAmount<< "\t\t$" << monthlyPayments << "\t\t" << interest * 100 << "\t$" <<
	interestPayment << "\t\t$" << principal << "\t" << endl;

	cout << numOfMonths + 1 << "\t";
	std::cout << std::fixed << std::setprecision(2) <<
	"$0.00\t\t" << loanAmount + loanAmount * interest << "\t\t" << interest * 100 << "\t$" <<
	loanAmount * interest << "\t\t$" << principal << "\t" << endl;
	
	totalInterest = totalInterest + loanAmount * interest;
	//cout at the end
	cout << "It takes " << numOfMonths + 1 << " months to pay off the loan." << endl;
	std::cout << std::fixed << std::setprecision(2) <<
	"Total interest paid is :$" << totalInterest << endl;	
	
}



