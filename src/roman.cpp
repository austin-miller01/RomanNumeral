/**
 * @brief Roman Class implementation.
 */

#include "roman.hpp"

/* Please add all Roman member definition and two non-member functions in this .cpp file */
std::string convertIntToRoman(int num);
int convertRomanToInt(std::string str);

//initializes romanStr to empty string
Roman::Roman(){
    this->romanStr = "";

}

//initializes romanStr to str
Roman::Roman(std::string str){
    this->romanStr = str;
}

//intializes romanStr by converting num to string
Roman::Roman(int num){
    std::string roman = convertIntToRoman(num);
    this->romanStr = roman;
}

//destrucst the roman object
Roman::~Roman(){
}

//uses inputed string to change objects roman
void Roman::SetRoman(std::string str){
    this->romanStr = str;
}

//converts num to roman and sets objects romanStr to new string
void Roman::SetRoman(int num){
    std::string roman = convertIntToRoman(num);
    this->romanStr = roman;
}

//returns objects romanStr
std::string Roman::GetRoman() const{
    return this->romanStr;
}

//converts objects roman to int then returns that int
int Roman::GetInt() const{
    int num = convertRomanToInt(this->romanStr);
    return num;
}

//adds object roman and parameter roman then updates objects roman
void Roman::IncreaseWith(const Roman &r){

    //stores objects and parameters integer values
    int objNum = this->GetInt();
    int paraNum = r.GetInt();

    //adds the two values
    int total = objNum + paraNum;

    //converts to string then updates objects romanStr
    std::string str = convertIntToRoman(total);

    this->romanStr = str;
}

//converts integer to roman numeral
std::string convertIntToRoman(int num){
        
        //return string
        std::string ret = "";
        //useful values
        int numDigitsInPlace,check;

        //all base roman numeral values and their coordinating values
        std::string all_roman_vals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int coordinating_nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        //loops through the base roman vals
        //if the current num can be deduced by coordinating_num, it adds the base
        //roman value to the return string, does this for every value
        for(int i = 0; i < 13; i++){

            numDigitsInPlace = 0;
            check = 0;

            while(check + coordinating_nums[i] <= num){
                numDigitsInPlace++;
                check+=coordinating_nums[i];
            }

            for(int j = 0; j < numDigitsInPlace; j++){
                ret += all_roman_vals[i];
                num -= coordinating_nums[i];
            }
        }

        return ret;

}

int convertRomanToInt(std::string str){

    //all base roman numeral values and their coordinating values
    std::string all_roman_vals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int coordinating_nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    //useful check values and return value
    int ret = 0, prev = 0, current = 0, len = str.length();
    std::string temp = "";

    //loops through the string, when it finds a matching value in roman base
    //it then adds that value to the return
    //uses the previous value to determine if it is "IX" etc
    //if previous is less than the current value then we substract 2*prev from current
    //and then add that current to the return value, this was the most
    //efficient way I could think of doing it
    for(int i = 0; i < len; i++){
        temp = str[i];

        for(int j = 0; j < 13; j++){
            if(temp == all_roman_vals[j])current = coordinating_nums[j];
        }
        if(prev < current)ret+= (current - (2 * prev));
        else ret += current;

        prev = current;
    }

        return ret;
    }