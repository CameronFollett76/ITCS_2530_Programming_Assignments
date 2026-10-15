#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Declaring the Variables.
	string favoriteTheme;
	int setsOwned;
	double hoursPerWeek;
	double hoursPerYear;

	// Prompt the user for their favorite LEGO theme or building style.
	cout << "Welcome to the LEGO Builder Profile!" << endl;
	cout << "What is your favorite LEGO theme or building style? (e.g., Star Wars, City, Custom Creations, etc.)" << endl;
	getline(cin, favoriteTheme);

	// Prompt the user for the number of LEGO sets they currently own.
	cout << "How many LEGO sets do you currently own?" << endl;
	cin >> setsOwned;

	// Prompt the user for the average number of hours they spend building LEGO sets per week.
	cout << "On average, how many hours a week do you spend building LEGO sets?" << endl;
	cin >> hoursPerWeek;

	// Calculate the total number of hours spent building LEGO sets per year.
	hoursPerYear = hoursPerWeek * 52;

	cout << "Your favorite theme/building style is " << favoriteTheme << " and you own " << setsOwned << " LEGO sets." << " You also spend an average of " << hoursPerWeek << " hours per week building LEGO sets" << " and spend a total of " << hoursPerYear << " hours per year building LEGO sets." << endl;
}