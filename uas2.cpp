#include <iostream>
#include <algorithm>

using namespace std;

// Function prototypes
double mean(int numbers[], int numElements);
int median(int numbers[], int numElements);

int main()
{
    // Array to store the integers
    int numbers[100];

    // Variables to store the number of elements and the input
    int numElements = 0;
    int input;

    // Prompt the user to enter a list of integers
    cout << "Enter a list of integers (enter a negative number to stop):" << endl;
    cin >> input;
    while (input >= 0)
    {
        numbers[numElements] = input;
        numElements++;
        cin >> input;
    }

    // Sort the array
    sort(numbers, numbers + numElements);

    // Calculate and display the mean and median
    cout << "The mean is: " << mean(numbers, numElements) << endl;
    cout << "The median is: " << median(numbers, numElements) << endl;

    return 0;
}

// Function to calculate the mean of an array of integers
double mean(int numbers[], int numElements)
{
    int sum = 0;
    for (int i = 0; i < numElements; i++)
    {
        sum += numbers[i];
    }
    return (double)sum / numElements;
}

// Function to calculate the median of an array of integers
int median(int numbers[], int numElements)
{
    if (numElements % 2 == 0)
    {
        // If the number of elements is even, return the average of the two middle numbers
        int middle1 = numbers[numElements / 2 - 1];
        int middle2 = numbers[numElements / 2];
        return (middle1 + middle2) / 2;
    }
    else
    {
        // If the number of elements is odd, return the middle number
        return numbers[numElements / 2];
    }
}
