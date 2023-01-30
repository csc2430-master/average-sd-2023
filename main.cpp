#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

int main() {
    string filename;
    cout << "Filename: ";
    cin >> filename;
    ifstream file(filename);
    if (file.fail()){
        cerr << "Unable to open" << endl;
        return 1;
    }
    int n;
    file >> n;
    int* array = new int[n];
    // ASSUME THE FILE HAS n NUMBERS... SHOULD CHECK LATER
    for (int i = 0; i < n; ++i) {
        file >> array[i];
    }
    file.close();
    // Calculate Average
    float average = 0;
    for (int i = 0; i < n; ++i) {
        average += array[i];
    }
    average /= n;

    // Calculate Standard Deviation
    float stdev = 0;
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(array[i] - average, 2);
    }
    stdev = sqrt(sum / n);

    cout << "The average is: " << average << endl;
    cout << "The standard deviation is: " << stdev << endl;

    delete[] array;


    return 0;
}



