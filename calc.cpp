#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
void fact(double *x){

    int i =  (int) *x;

    i++;

    *x = -69;
    
}

int main() {


    bool e = true;

    while(true){
        std::string ch, i;
        double ans = 0, inp1, inp2;
        std::cout << "Enter  number or Q to quit\n";
        std::cin >> ch;
        std::transform(ch.begin(), ch.end(), ch.begin(),
        [](unsigned char c){ return std::tolower(c); });
        if(ch == "q"){
            std::cout << "Exiting!\n";
            return 0;
        }
        std::cout << " ● sq- √x\n ● fc- x!\n ● ln- ln(x)\n ● pw- x^b\n";
        std::cin >>i;
       
       
        ans = std::stoi(ch);
        if(i == "sq"){
            ans = pow(ans, 2);
        }
        else if(i == "ln"){
            ans = log(ans);
        }
        else if(i == "fc"){
            fact(&ans);
        }
        else if(i == "pw"){
            
        }

        std::cout << ans << '\n';
        

      
    }

    return 0;
}