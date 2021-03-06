#include <iostream>
#include <vector>

using namespace std;

/*
Returns true if n is a palindromic number, false otherwise
*/
bool isPalindromic(int n) {
    vector<int> digits;
    //creates a vector of all the digits of n
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    //returns false if the nth digit doesn't match the (end-n+1)th digit
    for (int i = 0; i < digits.size()/2; i++) {
       if (digits[i] != digits[digits.size() - 1 - i])
           return false;
    }
    return true;
}

/*
A struct that can be constructed with two positive integers, a and b. Each time
the method getNext() is called, it returns the next highest possible product 
of integers less than or equal to the starting integers a and b. For example,
if it is constructed with integers 10 and 9, the first time getNext() is called
it will return 90 (10*9), the next time it is called, it will return 81 (9*9) 
*/
struct ProductGeneratorHighToLow {
    int a,b;
    vector< vector<int> > poss;

    ProductGeneratorHighToLow(int a, int b) : a(a),b(b) {
        int high = max(a,b);
        int low = min(a,b);
        vector<int> arr {high,low};
        poss.push_back(arr);
    }

    int getNext() {


        while (poss.back()[1] < poss.back()[0] - 1) {
            vector<int> arr {poss.back()[0]-1,poss.back()[1]};
            poss.push_back(arr);
        }

        int max = -1;
        vector<int> max_indices;
        for (int i = 0; i < poss.size(); i++) {
            int prod = poss[i][0]*poss[i][1];
            if (prod > max) {
                max = prod;
                max_indices = {i};
            } else if (prod == max ) {
                max_indices.push_back(i);
            }

        }

        for (int i: max_indices) {
            poss[i] = vector<int> {poss[i][0],poss[i][1]-1};
        }



        return max;
    }
};

int main() {

    auto gen = ProductGeneratorHighToLow(999,999);

    while (true) {
        int next_highest = gen.getNext();
        if (isPalindromic(next_highest)){
	    cout << "Highest Palindromic: " << next_highest << endl;
	    break;
        }
    }

    return 0;
}
