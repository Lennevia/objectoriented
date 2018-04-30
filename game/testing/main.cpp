#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void){

    char num[2];
    std::cout << "Enter 1, 2, or 3" << std::endl;

  //  std::cin.get(num);
    fgets(num, 3, stdin);

    std::cout << "the number you put in was: " << num;

    return 0;

}


//// istream::get example
//#include <iostream>     // std::cin, std::cout
//#include <fstream>      // std::ifstream
//
//int main () {
//    char str[256];
//
//    std::cout << "Enter the name of an existing text file: ";
//    std::cin.get (str,256);    // get c-string
//
//    std::ifstream is(str);     // open file
//
//    char c;
//    while (is.get(c))          // loop getting single characters
//        std::cout << c;
//
//    is.close();                // close file
//
//    return 0;
//}
