#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        int sum1 = 0, sum2 = 0;
        std::vector<std::stack<char>&> stacks;
        while (std::getline(input, crnString) && !crnString.empty())
        {
            
        }

        while (std::getline(input, crnString))
        {
            
            
        }

        std::cout << "Part One: " << sum1 << std::endl;
        std::cout << "Part Two: " << sum2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}