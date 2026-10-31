#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isInteger(string input){
  int start = 0;

  if(input[0] == '-' || input[0] == '+')
      start = 1;

  if(start == input.length())
      return false;

  for(int i = start; i < input.length(); i++)
  {
      if(!isdigit(input[i]))
          return false;
  }

  return true;
}
int main() {
  int n, ITEM;
  cout << "Enter size of array: ";
  cin >> n;

  // Extra space for insertion
  int *arr = new int[n + 1];

  cout << "Enter sorted array elements:\n";
  for(int i = 0; i < n; i++) cin >> arr[i];

  string input;
  cout << "Enter ITEM to search: ";
  cin >> input;

  if(!isInteger(input)) {
      cout << "Invalid input! ITEM must be an integer.";
      delete[] arr;
      return 0;
  }

  ITEM = stoi(input);

  // Binary Search
  int low = 0, high = n - 1, pos = -1;

  while(low <= high) {
    int mid = low + (high - low) / 2;

    if(arr[mid] == ITEM) {
      pos = mid;
      break;
    }
    else if(arr[mid] < ITEM) low = mid + 1;
    else high = mid - 1;
  }

  // ITEM found -> delete it
  if(pos != -1) {
    for(int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];

    n--;

    cout << "ITEM found and deleted.\n";
  }

  // ITEM not found -> insert at 'low'
  else {
    pos = low;

    // Shift elements to the right
    for(int i = n; i > pos; i--) arr[i] = arr[i - 1];

    arr[pos] = ITEM;
    n++;

    cout << "ITEM not found, so it was inserted.\n";
  }

  cout << "Final array:\n";
  for(int i = 0; i < n; i++) cout << arr[i] << " ";

  delete[] arr;

  return 0;
}