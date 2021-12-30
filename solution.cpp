#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

namespace detail {

const vector<string> tableWithData() {
    ifstream myReadFile("inputData.txt");
    string mytext;
    vector<string> tableOfStrings;

    while (getline (myReadFile, mytext))
    {
        tableOfStrings.push_back(mytext);
    }

    myReadFile.close();

    return tableOfStrings;
}


int howMany(const vector<string> &tableOfStrings)
{
    int howManyValue = 0;
    for ( auto it = tableOfStrings.begin(); it != tableOfStrings.end(); it++)
    {
        int previous = stoi(*it);
        if (previous == 2682) {
            break;
        }
        auto nextValue = next(it, 1);

        cout << "Next Value: " << *nextValue;
        int actual = stoi(*(nextValue));

        if (previous < actual )
        {
            cout << "Previous: " << previous << ", " << "Actual: " << actual << endl;
            howManyValue++;
        }
    }
    return howManyValue;
}

} // detail



int main()
{

    const auto tableOfStrings = detail::tableWithData();
    int result = detail::howMany(tableOfStrings);
    cout << "The answer is: " << result << endl;

}
