/*  Given the total amount of money collected for a given month,
 	this program calculates the taxes owed to the state and county.
*/
#include <iostream>
#include <iomanip>
#include <string>
//#define DEBUG 1
using namespace std;

int main()
{	
	const float STATE = 0.065;        // state tax rate 
	const float COUNTY = 0.0275;      // county tax rate 
	
	string month;                     // Month for which taxes should be calculated
	int year                          // Year in which the given month resides	
	float totalCollected;             // Total amount of DOLLARS collected for the given month
		
	cout << "Enter the month for which taxes should be calculated (SPELL IT OUT): ";
	cin >> month;
	
	cout << "\nEnter the year (YYYY or YY): ";
	cin >> year;
	
	cout << "\nEnter the total (DOLLARS AND CENTS) collected in " << month << " " << year << ": $";
	cin >> totalCollected; cout << endl;
	
	float sales = totalCollected / ((STATE + COUNTY) + 1);
	
	long stateTaxINT = sales * 100 * (STATE);                  // convert sales tax to cents in order to truncate extra decimal places and properly calculate taxes
	long countyTaxINT = sales * 100 * (COUNTY);		

	float stateTax = (float)stateTaxINT / 100;                // convert back to dollars, typecast TaxINT to float for final calculation
	float countyTax = (float)countyTaxINT / 100;
	
	float totalTax = countyTax + stateTax;                    // Total sales tax paid by customers

	cout << setprecision(2) << fixed;                         // Force output of two decimal places
	cout << month << " " << year << "\n-----------------" << endl;
	cout << "Total Collected:\t$ " << totalCollected << endl;
	cout << "Sales:\t\t\t$ " << sales << endl;
	cout << "County Sales Tax:\t$ " << countyTax << endl;
	cout << "State Sales Tax:\t$ " << stateTax << endl;
	cout << "Total Sales Tax:\t$ " << totalTax << "\n" << endl;
		
	return 0;	
}
