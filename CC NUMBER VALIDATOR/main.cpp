#include<iostream>
#include<stdio.h>
#include<string>

bool isNumber(const std::string& s){
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) < '0' || s.at(i) > '9')
            return false;
    }
    return true;
}

int32_t main(){
    std::string ccNo;
    std::cout << "This program uses the luhn Algorithm to validate a CC number." << std::endl;
    std::cout << "You can enter 'exit' anytime to quit" << std::endl;

    while(1) {
        std::cout << "Please enter a CC number to validate" << std::endl;
        std::cin >> ccNo;

        if(ccNo == "exit")
            break;
        else if(!isNumber(ccNo)){
            std::cout << "Bad Input" << std::endl;
            continue;
        }

        int len = ccNo.size();
        int doubleEvenSum = 0;

        for(int i = len - 2; i >= 0; i -= 2){
            int dbl = ((ccNo[i] - 48) * 2);
            if(dbl > 9){
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        for(int i = len - 1; i >= 0; i -= 2){
            doubleEvenSum += (ccNo[i] - 48);
        }

        std::cout << (doubleEvenSum % 10 == 0 ? "Valid" : "Invalid") << std::endl;
        continue;
    }

}
