#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// creating a class to store and manage data related to local economy
class LocalEconomy {
	private:
		// class fields
		string name;
		double population;
		double medianIncome;
		int GDP;
		string region;
		string country;

	public:
		// constructor to initialize fields
		void LocalEconomy(string n, double po, double med, int g, string r, string c) {
			name = n;
			population = po;
			medianIncome = med;
			GDP = g;
			region = r;
			country = c;
		}

		// getter methods for private fields
		string getName() {
			return name;
		}
		double getPopulation() {
			return population;
		}
		double getMedianIncome() {
			return medianIncome;
		}
		int getGDP() {
			return GDP;
		}
		string getRegion() {
			return region;
		}
		string getCountry() {
			return country;
		}

		// method to print the data in a readable format
		void printData() {
			cout << "Name: " << getName() << endl;
			cout << "Population: " << getPopulation() << endl;
			cout << "Median Income: " << getMedianIncome() << endl;
			cout << "GDP: " << getGDP() << endl;
			cout << "Region: " << getRegion() << endl;
			cout << "Country: " << getCountry() << endl;
		}

		// method to read data from a text file into the class fields
		void loadData(string fileName) {
			ifstream inFile;
			inFile.open(fileName.c_str());

			if(inFile.is_open()) {
				// read data into fields
				string line;
				while (getline(inFile, line)) {
					string value;
					int count = 0;
					istringstream ss(line);

					while (getline(ss, value, ',')) {
						switch (count) {
							case 0:
								name = value;
								break;
							case 1:
								population = stod(value);
								break;
							case 2:
								medianIncome = stod(value);
								break;
							case 3:
								GDP = stoi(value);
								break;
							case 4:
								region = value;
								break;
							case 5:
								country = value;
								break;
						}
						count++;
					}
				}

				// close the file
				inFile.close();
			} else {
				// throw exception if file does not exist
				throw "File not found!";
			}
		}

		// method to update a single field
		void updateField(string fieldName, string newValue) {
			if (fieldName == "name") {
				name = newValue;
			}
			else if (fieldName == "population") {
				population = stod(newValue);
			}
			else if (fieldName == "medianIncome") {
				medianIncome = stod(newValue);
			}
			else if (fieldName == "GDP") {
				GDP = stoi(newValue);
			}
			else if (fieldName == "region") {
				region = newValue;
			}
			else if (fieldName == "country") {
				country = newValue;
			}
			else {
				// throw exception if invalid field name
				throw "Invalid field name!";
			}
		}

		// method to write data to a text file
		void writeData(string fileName) {
			// open file and append data
			ofstream outFile;
			outFile.open(fileName.c_str(), ofstream::app);
			
			if (outFile.is_open()) {
				outFile << getName() << "," << getPopulation() << "," << getMedianIncome() << "," <<
					getGDP() << "," << getRegion() << "," << getCountry() << endl;
			}

			// close the file
			outFile.close();
		}

};

int main() {
	// create a new instance of the LocalEconomy class
	LocalEconomy economy;
	
	// load data from file
	economy.loadData("LocalEconomy.txt");
	
	// print data
	economy.printData();
	
	// update field
	economy.updateField("GDP", "50000");
	
	// print updated data
	cout << endl << "Updated data:" << endl;
	economy.printData();
	
	// write data to file
	economy.writeData("LocalEconomy.txt");
	
	return 0;
}