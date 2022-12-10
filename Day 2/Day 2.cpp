#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        int ans1 = 0, ans2 = 0;
        while (std::getline(input, crnString))
        {
            int p1 = crnString[0] - 'A' + 1;
            int p2 = crnString[2] - 'X' + 1;
            ans1 += p2 + (p1 == p2 ? 3 : (p1 % 3 + 1 == p2? 6 : 0));
            ans2 += (p2 - 1) * 3 + (p2 + p1 % 3) + 1;
        }

        std::cout << "Part One: " << ans1 << std::endl;
        std::cout << "Part Two: " << ans2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}
