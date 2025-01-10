#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	
	ScalarConverter::convert(argv[1]);
	
	return (0);
}

// floatは2^31(≈2.1474836e9)付近から誤差が出るので、それを考慮すること。

//#include "ScalarConverter.hpp"
//#include <iostream>

//int main(int ac, char **av){
//    // ScalarConverter a;
//    for(int i = 1; i < ac; i++){
//        std::string s(av[i]);
//        ScalarConverter::convert(s);
//    }
//    std::cout <<"-------------------------" <<std::endl;
//    std::cout <<"test case zone" <<std::endl;
//    std::string r[] = {
//        "-2147483649",
//        "-2147483648",
//        "-10",
//        "0",
//        "10",
//        "50",
//        "2147483647",
//        "2147483648",
//        "-2147483649.0f",
//        "-2147483648.0f",
//        "-10.0f",
//        "0.0f",
//        "10.0f",
//        "50.0f",
//        "2147483647.0f",
//        "2147483648.0f",
//        "-2147483649.0",
//        "-2147483648.0",
//        "-10.0",
//        "0.0",
//        "10.0",
//        "50.0",
//        "2147483647.0",
//        "2147483648.0",
//        "-1.1",
//        "0.001",
//        "1.1",
//        "nan",
//        "nanf",
//        "-inf",
//        "+inf",
//        "-inff",
//        "+inff",
//        "500f78",
//        "500f",
//        "123.45.5",
//        "123.45.5f",
//        "123.45f78",
//        "123.45f78f",
//        "OWARI"
//    };
//    for(int i = 0; r[i] != "OWARI"; i++){
//        std::cout <<"-------------------------" <<std::endl;
//        std::cout <<"|" <<r[i] <<"|" <<std::endl;
//        ScalarConverter::convert(r[i]);
//    }
//    std::cout <<"-------------------------" <<std::endl;
//}