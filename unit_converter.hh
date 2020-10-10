#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class conversion {
public:
    conversion(string unit1, string unit2, double conversionFactor) 
        : unit1(unit1), unit2(unit2), conversionFactor(conversionFactor) {};

    string getUnit1() {
        return this->unit1;
    }
    string getUnit2() {
        return this->unit2;
    }
    double getConversionFactor() {
        return this->conversionFactor; 
    }

private:
    string unit1;
    string unit2;
    double conversionFactor;
};

class unitConverter {
public:
    unitConverter() {};

    void addConversion(string identifier, string unit1, string unit2, double conversionFactor) {
        conversion* temp = new conversion(unit1, unit2, conversionFactor);
        factors.push_back(temp);
        factorNames.push_back(identifier);
    };

    void converter() {
        int temp;
        int temp2;
        double units;
        for (int i = 0; i <= (factorNames.size() - 1); i++) {
            cout << (i + 1) << ". " << factorNames[i] << endl;
        }
        cout << "Which one?" << endl;
        cin >> temp;
        cout << "Normal (1) or reverse (2)?" << endl;
        cin >> temp2;
        if (temp2 == 1) {
            cout << "How many " << factors[temp - 1]->getUnit1() << "?" << endl;
            cin >> units;
            cout << units << " " << factors[temp - 1]->getUnit1() << " is " 
                << convert((temp - 1), units) << " " << factors[temp - 1]->getUnit2() << "." << endl;
        } else if (temp2 == 2) {
            cout << "How many " << factors[temp - 1]->getUnit2() << "?" << endl;
            cin >> units;
            cout << units << " " << factors[temp - 1]->getUnit2() << " is " 
                << reverseConvert((temp - 1), units) << " " << factors[temp - 1]->getUnit1() << "." << endl;
        } else {
            return;
        }
    };

    double reverseConvert(int factor, double numberOfUnits) {
        return (factors[factor]->getConversionFactor() * numberOfUnits);
    };

    double convert(int factor, double numberOfUnits) {
        return (numberOfUnits / factors[factor]->getConversionFactor());
    };

private:
    vector<conversion*> factors;
    vector<string> factorNames;
};

