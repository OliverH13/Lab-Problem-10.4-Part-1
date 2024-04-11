
#include <iostream>

using namespace std;

int credit_card_check(int value);

int main() {
    int input;

    while (true) {
        cout << "Enter 8-digit card # or Q to quit: ";
        cin >> input;

        bool Q = false;
        if (input == false) break;

        if (credit_card_check(input) == true)
            cout << "Card is valid." << endl << endl;
        else
            cout << "Card is not valid." << endl << endl;
    }
}

int credit_card_check(int value) {
    int even_digits = value;
    int odd_digits;
    int first_sum = 0;
    int second_sum = 0;
    int third_sum;

    do {
        odd_digits = even_digits % 10;
        even_digits = even_digits / 100;
        first_sum += odd_digits;
    } while (even_digits > 0);

    int digi_one;
    int digi_two;
    even_digits = value;

    do {
        even_digits = even_digits / 10;
        odd_digits = even_digits % 10;
        odd_digits *= 2;
       
        if (odd_digits >= 10) {
            digi_one = odd_digits % 10;
            digi_two = odd_digits / 10;
            second_sum = second_sum + digi_one + digi_two;
        }
        else {
            second_sum += odd_digits;
        }
        even_digits /= 10;

    } while (even_digits > 0);

    third_sum = first_sum + second_sum;

    if (third_sum % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}