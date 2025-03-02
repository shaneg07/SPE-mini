#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

int fact(int x){

    int i = 1, n = 1;

    while(i <= x) {
        n *= i;
        i++;  
    }
     
    return n;
}

int main() {

    while(true){
        double ans;
        double x, y;
        int choice;
        cout << "\n-----------------MENU----------------\n";
        cout << "1. Square Root\n";
        cout << "2. Factorial\n";
        cout << "3. Log Base 2\n";
        cout << "4. Power\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
   

        switch (choice) {
            case 1:
                cout << "Enter number: ";
                cin >> x;
                ans = sqrt(x);
                cout << "Result: " << ans << endl;
                break;
        
            case 2:
                cout << "Enter number: ";
                cin >> x;
                ans = fact(x);
                cout << "Result: " << ans << endl;
                break;
        
            case 3:
                cout << "Enter number: ";
                cin >> x;
                ans = log2(x);
                cout << "Result: " << ans << endl;
                break;
        
            case 4:
                cout << "Enter number: ";
                cin >> x;
                cout << "Enter power: ";
                cin >> y;
                ans = pow(x, y);
                cout << "Result: " << ans << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
            }
    }

    return 0;
}