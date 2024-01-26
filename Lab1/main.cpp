/*
//  main.cpp
//  Lab1
//
//  Created by Patricia Antlitz on 1/30/23.
 
 Lab01 COMP2010 - Computing 3
 
 Group members:
 
 Yan Ngo
 Patricia Antlitz
 Guarav Bhatnagar
 Khoa Bui
 
 Please refer to the README file
 
 The purpose of this program is to create a simple loan calculator.
 The user will be allow to enter a number to be used as the interest rate, the total amount of the loan, and in how many
 months the month will be paid. The program will calculate the rate for the total loan with interest, and the total for the
 monthly payment. It uses the provided "discount installment loan" format explained in the instructions.
 
 source for EMI:
 https://www.wikihow.com/Calculate-an-Installment-Loan-Payment#:~:text=The%20equation%20to%20find%20the,)%5En%2D1).
 
 Instruction:
 
 Write a program that will take three inputs: the amount the consumer needs to receive, the interest rate,
 and the duration of the loan in months. The program should then calculate the face value required in
 order for the consumer to receive the amount needed. It should also calculate the monthly payment.
 
 Your program should generate output similar to the following:
 Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to
 quit): 15
 Please enter the amount you would like to receive: 1000
 Please enter loan period in months: 12
 The total amount of your loan (including interest at 15% per annum) is $1176.47.
 Your monthly payment for 12 months will be $98.04.
 Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to
 quit): 0
 Exit code: 0 (normal program termination
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, const char* argv[])
{
    //these two declarations will fix the decimal point to two - to be used by the double variables (output)
    cout.setf(ios::fixed);
    cout.precision(2);
    
    double loanAmount;
    double totalAmount;
    double monthlyPayment;
    double rate;
    double time;
    int interestRate;
    int months;
    //loop variable
    int i = 0;
    
    //should continue to loop until the user quits
    while(i >= 0)
    {
        //will get an interest rate for the calculation
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit)" << endl;
        cin >> interestRate;
        
        //quit the program by entering 0
        if (interestRate == 0)
        {
            exit(0);
        }
        //get the total amount the user would like to loan
        cout << "Please enter the amount you would like to receive: " << endl;
        cin >> loanAmount;
        //how many payments?
        cout << "Please enter loan period in months: " << endl;
        cin >> months;
        
        //loan algorithm
        //in order to get the results from the lab instructions, we came up with the following calculation:
        //We have a calculation for EMI loan down below commented out, which is most likely what we would have done if the examples were not give.
        rate = 1 - (static_cast<double>(interestRate) / 100);
        totalAmount = (loanAmount / rate) * (static_cast<double>(months) / 12);
        monthlyPayment = totalAmount / months;

        //This would be the correct calculation to get an accurate EMI loan values:
//        rate = static_cast<double>(interestRate) / (12 * 100);
//        time = months * 12;
//        totalAmount = (loanAmount * rate * pow(1 + rate, months)) / (pow(1+ rate, months) - 1);
//        totalAmount *= months;
//        monthlyPayment = totalAmount / months;
        
        cout << "The total amount of your loan (including interest at " << interestRate << "% per annum) is $" << totalAmount << endl;
        cout << "Your monthly payment for " << months << " months will be " << monthlyPayment << endl << endl;
    }
    
    return 0;
}
