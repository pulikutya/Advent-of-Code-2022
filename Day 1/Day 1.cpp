#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        unsigned int crnSum = 0;
        unsigned int first3max[3] { 0, 0, 0 };
        while (std::getline(input, crnString))
        {
            if (crnString.empty())
            {
                if (crnSum > first3max[0]) first3max[0] = crnSum;
                if (first3max[1] < first3max[0]) std::swap(first3max[1], first3max[0]);
                if (first3max[2] < first3max[1]) std::swap(first3max[2], first3max[1]);
                crnSum = 0;
            }
            else crnSum += std::stoi(crnString);
        }

        std::cout << "Part One: " << first3max[2] << std::endl;
        std::cout << "Part Two: " << first3max[0] + first3max[1] + first3max[2] << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}
