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

bool checkIfException(int value)
{
    if (value == 2682) {
        return true;
    }
    return false;
}


int howMany(const vector<string> &tableOfStrings)
{
    int howManyValue = 0;
    for ( auto it = tableOfStrings.begin(); it != tableOfStrings.end(); it++)
    {
        // First result iterators
        int first = stoi(*it);
        if (checkIfException(first))
            break;

        auto nextValue = next(it, 1);

        int second = stoi(*(nextValue));
        if (checkIfException(second))
            break;
        auto thirdValue = next(nextValue, 1);

        int third = stoi(*(thirdValue));
        if (checkIfException(third))
            break;

        // Second result iterators
        auto secondResultFirstIterator = next(it, 1);
        int secondResultFirst = stoi(*(secondResultFirstIterator));
        if (checkIfException(secondResultFirst))
            break;

        auto secondResultSecondIterator = next(secondResultFirstIterator, 1);
        int secondResultSecond = stoi(*(secondResultSecondIterator));
        if (checkIfException(secondResultSecond))
            break;

        auto secondResultThirdIterator = next(secondResultSecondIterator, 1);
        int secondResultThird = stoi(*(secondResultThirdIterator));
        if (checkIfException(secondResultThird))
            break;

        // Sum of the values
        int previousResult = first + second + third;

        int actualResult = secondResultFirst + secondResultSecond + secondResultThird;

        // Equal the values
        if (previousResult < actualResult )
        {
            // Count the result
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
