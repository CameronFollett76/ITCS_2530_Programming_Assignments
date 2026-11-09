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
	char addAnother;
	string setName;
	int setNumber;
	double setPrice;
	int totalSetsEntered = 0;
	double totalCollectionValue = 0.0;
	double averageSetPrice = 0.0;

	// Prompt the user for their favorite LEGO theme or building style.
	cout << "Welcome to the LEGO Builder Profile!" << endl;
	cout << "What is your favorite LEGO theme or building style? (e.g., Star Wars, City, Custom Creations, etc.)" << endl;
	getline(cin, favoriteTheme);

	// Input validation for favorite LEGO theme
	while (favoriteTheme.empty())
	{
		cout << "Please enter a LEGO theme or building style." << endl;
		getline(cin, favoriteTheme);
	}

	// Prompt the user for the number of LEGO sets they currently own.
	cout << "How many LEGO sets do you currently own?" << endl;
	cin >> setsOwned;

	// Input validation for the number of LEGO sets owned
	while (cin.fail() || setsOwned < 0)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
		}

		cout << "Please enter a valid number of LEGO sets (0 or more)." << endl;
		cin >> setsOwned;
	}

	// Prompt the user for the average number of hours they spend building LEGO sets per week.
	cout << "On average, how many hours a week do you spend building LEGO sets?" << endl;
	cin >> hoursPerWeek;

	// Validate input for Hours Per Week
	while (cin.fail() || hoursPerWeek < 0)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
		}

		cout << "Please enter a valid number of Hours (0 or more)." << endl;
		cin >> hoursPerWeek;
	}

	// Clear the input buffer before using getline for setName
	cin.ignore(200, '\n');

	// Loop to allow the user to enter multiple LEGO sets
	do
	{
		cout << "Enter the name of a LEGO set you own: ";
		getline(cin, setName);

		cout << "Enter the set number for " << setName << ": ";
		cin >> setNumber;

		// Input validation for LEGO set number (must be greater than 0)
		while (cin.fail() || setNumber <= 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid LEGO set number (greater than 0): ";
			cin >> setNumber;
		}

		cout << "Enter the price of " << setName << ": $";
		cin >> setPrice;

		// Input validation for LEGO set price (must be 0 or more)
		while (cin.fail() || setPrice < 0)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
			}

			cout << "Please enter a valid price (0 or more): $";
			cin >> setPrice;
		}

		totalSetsEntered++;
		totalCollectionValue = totalCollectionValue + setPrice;

		// Display the information for the LEGO set just entered.
		cout << endl;
		cout << "LEGO Set Added!" << endl;
		cout << "Set Name: " << setName << endl;
		cout << "Set Number: " << setNumber << endl;
		cout << fixed << setprecision(2);
		cout << "Set Price : $" << setPrice << endl;

		// Ask the user if they want to add another LEGO set
		cout << endl;
		cout << "Do you want to add another LEGO set? (Y/N): ";
		cin >> addAnother;
		cin.ignore(200, '\n'); // Clear the input buffer before the next iteration
	} while (addAnother == 'Y' || addAnother == 'y');

	// Calculate the average price of the LEGO sets entered.
	if (totalSetsEntered > 0)
	{
		averageSetPrice = totalCollectionValue / totalSetsEntered;
	}
	
	cout << endl;
	cout << "====== LEGO COLLECTION STATISTICS ======" << endl;

	for (int statistic = 1; statistic <= 3; statistic++)
	{
		// Display the statistics
		if (statistic == 1)
		{
			cout << "Total Sets Entered: " << totalSetsEntered << endl;
		}
		else if (statistic == 2)
		{
			cout << "Total Collection Value: $" << totalCollectionValue << endl;
		}
		else if (statistic == 3)
		{
			cout << "Average Price Per Set: $" << averageSetPrice << endl;
		}
	}
	
	// Display the LEGO collection summary.
	cout << endl;
	cout << "========================================" << endl;
	cout << "          COLLECTION SUMMARY" << endl;
	cout << "========================================" << endl;
	cout << "Total Sets Entered: " << totalSetsEntered << endl;
	cout << "Total Collection Value: $" << totalCollectionValue << endl;
	cout << "========================================" << endl;

	// Calculate the total number of hours spent building LEGO sets per year.
	hoursPerYear = hoursPerWeek * 52;

	//Output to a text file
	ofstream reportFile("report.txt");

	// Display the title for the report
	cout << "==================================================" << endl;
	cout << "             MY LEGO HOBBY PROFILE" << endl;
	cout << "==================================================" << endl;

	reportFile << "==================================================" << endl;
	reportFile << "             MY LEGO HOBBY PROFILE" << endl;
	reportFile << "==================================================" << endl;

	// Display Column Headers
	cout << endl;
	cout << left << setw(40) << "Information" << right << setw(15) << "Your Answers" << endl;
	cout << "-------------------------------------------------------" << endl;

	reportFile << endl;
	reportFile << left << setw(40) << "Information" << right << setw(15) << "Your Answers" << endl;
	reportFile << "-------------------------------------------------------" << endl;

	// Format the output to display two decimal places
	cout << fixed << setprecision(2);
	reportFile << fixed << setprecision(2);

	// Display the LEGO Hobby Profile information
	cout << left << setw(40) << "Favorite LEGO Theme/Building Style" << right << setw(15) << favoriteTheme << endl;
	reportFile << left << setw(40) << "Favorite LEGO Theme/Building Style" << right << setw(15) << favoriteTheme << endl;

	cout << left << setw(40) << "Number of LEGO Sets Owned" << right << setw(15) << setsOwned << endl;
	reportFile << left << setw(40) << "Number of LEGO Sets Owned" << right << setw(15) << setsOwned << endl;

	cout << left << setw(40) << "Average Hours Spent Building per Week" << right << setw(15) << hoursPerWeek << endl;
	reportFile << left << setw(40) << "Average Hours Spent Building per Week" << right << setw(15) << hoursPerWeek << endl;

	cout << left << setw(40) << "Total Hours Spent Building per Year" << right << setw(15) << hoursPerYear << endl;
	reportFile << left << setw(40) << "Total Hours Spent Building per Year" << right << setw(15) << hoursPerYear << endl;

	cout << left << setw(40) << "Total LEGO Sets Entered" << right << setw(15) << totalSetsEntered << endl;
	reportFile << left << setw(40) << "Total LEGO Sets Entered" << right << setw(15) << totalSetsEntered << endl;

	cout << left << setw(40) << "Total Collection Value" << right << setw(15) << totalCollectionValue << endl;
	reportFile << left << setw(40) << "Total Collection Value" << right << setw(15) << totalCollectionValue << endl;

	cout << left << setw(40) << "Average Price Per Set" << right << setw(15) << averageSetPrice << endl;
	reportFile << left << setw(40) << "Average Price Per Set" << right << setw(15) << averageSetPrice << endl;

	cout << "-------------------------------------------------------" << endl;
	reportFile << "-------------------------------------------------------" << endl;

	// Close the report file
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