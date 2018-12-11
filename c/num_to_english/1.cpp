#include<stdio.h>
#include<string.h>
#include<string>

/* For now, lets take only 3 digit numbers (at max) */

const char *convert_num_to_dictionary(int n) {
    switch(n) {

        case 1:     return "one ";
                    break;
        case 2:     return "two ";
                    break;
        case 3:     return "three ";
                    break;
        case 4:     return "four ";
                    break;
        case 5:     return "five ";
                    break;
        case 6:     return "six ";
                    break;
        case 7:     return "seven ";
                    break;
        case 8:     return "eight ";
                    break;
        case 11:     return "eleven ";
                    break;
        case 12:     return "twelve ";
                    break;
        case 13:     return "thirteen ";
                    break;
        case 14:     return "fourteen ";
                    break;
        case 15:     return "fifteen ";
                    break;
        case 16:     return "sixteen ";
                    break;
        case 17:     return "seventeen ";
                    break;
        case 18:     return "eighteen ";
                    break;
        case 19:     return "nineteen ";
                    break;
        case 20:     return "twenty ";
                    break;
        case 30:     return "thirty ";
                    break;
        case 40:     return "fourty ";
                    break;
        case 50:     return "fifty ";
                    break;
        case 60:     return "sixty ";
                    break;
        case 70:     return "seventy ";
                    break;
        case 80:     return "eighty ";
                    break;
        case 90:     return "ninety ";
                    break;
        default:   
                return ""; 
                break;
    }
}
const char *convert_num_to_dictionary2(int n, int r) {

    if (r == 0) {
        return "";
    }

    switch(n) {
        case 100: return "hundred ";
                    break;
        case 1000: return "thousand ";
                    break;
        case 1000000: return "million ";
                    break;
        default:
                return "";
                break;
    }
}

std::string temp_output;
std::string small_num_to_string(int n) {

    int carry = 1;
    temp_output = "";
printf("small: %d\n", n);
    while (n > 0 ) {
        int rem = n % 10;
//printf("---%d, r:%d, c:%d, n:%d\n", rem*carry, rem, carry, n);
        if (rem * carry <= 99 ) {
            temp_output = convert_num_to_dictionary(rem*carry) + temp_output;
        } else {
            temp_output = convert_num_to_dictionary2(carry, rem) + temp_output;
            temp_output = convert_num_to_dictionary(rem) + temp_output;
        }
        n = n/10;
        carry = carry * 10;
    }
    return temp_output;
}
void num_to_string(int n) {

    std::string output;
    int carry = 1;

    while (n > 0 ) {
        int rem = n % 1000;
        int ahead = n / 1000;
        output = small_num_to_string(rem) + output;
        output = convert_num_to_dictionary2(carry, ahead) + output;
        n = n/1000;
        carry = carry * 1000;
    }
    printf("%s\n", output.c_str());
}



main() {

    int n;
    scanf("%d", &n);

    num_to_string(n);

}
