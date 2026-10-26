#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	// Declaring the Variables.
	string favoriteTheme;
	int setsOwned;
	double hoursPerWeek;
	double hoursPerYear;
	int menuChoice;

	// Prompt the user for their favorite LEGO theme or building style.
	cout << "Welcome to the LEGO Builder Profile!" << endl;
	cout << "What is your favorite LEGO theme or building style? (e.g., Star Wars, City, Custom Creations, etc.)" << endl;
	getline(cin, favoriteTheme);

	// Prompt the user for the number of LEGO sets they currently own.
	cout << "How many LEGO sets do you currently own?" << endl;
	cin >> setsOwned;

	// Validate input for Sets Owned
	if (setsOwned < 0)
	{
		cout << "Please enter a valid number of LEGO sets (0 or more)." << endl;
		cin >> setsOwned;
	}
	// Prompt the user for the average number of hours they spend building LEGO sets per week.
	cout << "On average, how many hours a week do you spend building LEGO sets?" << endl;
	cin >> hoursPerWeek;

	// Validate input for Hours Per Week
	if (hoursPerWeek < 0)
	{
		cout << "Please enter a valid number of Hours (0 or more)." << endl;
		cin >> hoursPerWeek;
	}

	// Calculate the total number of hours spent building LEGO sets per year.
	hoursPerYear = hoursPerWeek * 52;

	//Output to a text file
	ofstream reportFile("report.txt");

	// Display the title for the report
	reportFile << "==================================================" << endl;
	reportFile << "             MY LEGO HOBBY PROFILE" << endl;
	reportFile << "==================================================" << endl;

	// Display Column Headers
	reportFile << endl;
	reportFile << left << setw(40) << "Information" << right << setw(15) << "Your Answers" << endl;

	reportFile << "-------------------------------------------------------" << endl;

	//Display the LEGO Hobby Profile information
	reportFile << left << setw(40) << "Favorite LEGO Theme/Building Style" << right << setw(15) << favoriteTheme << endl;

	reportFile << left << setw(40) << "Number of LEGO Sets Owned" << right << setw(15) << setsOwned << endl;

	//Format the output to display two decimal places
	reportFile << fixed << setprecision(2);

	reportFile << left << setw(40) << "Average Hours Spent Building per Week" << right << setw(15) << hoursPerWeek << endl;

	reportFile << left << setw(40) << "Total Hours Spent Building per Year" << right << setw(15) << hoursPerYear << endl;

	reportFile << "-------------------------------------------------------" << endl;

	// Close the report file.
	reportFile.close();

	// Display the user options table
	cout << "==== LEGO Hobby Menu ====" << endl;
	cout << "1. Where to find Your LEGO Hobby Profile" << endl;
	cout << "2. What your building habits are!" << endl;
	cout << "3. Thank you for using the LEGO Builder Profile!" << endl;
	cout << "Please enter your choice (1, 2, or 3): ";
	cin >> menuChoice;

	// Switch statement to handle menu choices
	switch (menuChoice)
	{
	case 1:
		cout << "Your LEGO Profile has been saved to report.txt" << endl;
		break;

	case 2:
		if (hoursPerWeek >= 5 && setsOwned >= 10)
		{
			cout << "You are a dedicated LEGO builder!" << endl;
		}
		else
		{
			cout << "You are a casual LEGO builder!" << endl;
		}

		if (hoursPerYear >= 260 && hoursPerWeek >= 5)
		{
			cout << "You spent a lot of time throughout the year building LEGO sets!" << endl;
		}
		else
		{
			cout << "You have plenty of room and time to grow your building time!" << endl;
		}
		break;

	case 3:
		cout << "Thank you for using the LEGO Builder Profile!" << endl;
		break;

	default:
		cout << "Invalid choice. Please select 1, 2, or 3." << endl;
	}

	return 0;
}