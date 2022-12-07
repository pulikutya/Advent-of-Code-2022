#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        int sum1 = 0, sum2 = 0;
        while (std::getline(input, crnString))
        {
            int p1 = crnString[0] - 'A' + 1;
            int p2 = crnString[2] - 'X' + 1;
            sum1 += p2 + (p1 == p2 ? 3 : (p1 % 3 + 1 == p2? 6 : 0));
            sum2 += (p2 - 1) * 3 + (((p2-2) + (p1-1)) % 3) + 1;
#error incomplete
        }

        std::cout << "Part One: " << sum1 << std::endl;
        std::cout << "Part Two: " << sum2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}
