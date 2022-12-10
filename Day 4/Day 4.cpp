#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        int sum1 = 0, sum2 = 0;
        int iv[2][2];

        while (std::getline(input, crnString))
        {
            unsigned long long
                i1 = crnString.find('-'),
                s = crnString.find(',', i1),
                i2 = crnString.find('-', s);
            iv[0][0] = std::stoi(crnString.substr(0, i1));
            iv[0][1] = std::stoi(crnString.substr(i1 + 1, s - i1 - 1));
            iv[1][0] = std::stoi(crnString.substr(s + 1, i2 - s - 1));
            iv[1][1] = std::stoi(crnString.substr(i2 + 1));

            if ((iv[0][0] <= iv[1][0] && iv[0][1] >= iv[1][1]) || (iv[0][0] >= iv[1][0] && iv[0][1] <= iv [1][1]))            
            {
                sum1++;
                sum2++;
            }
            else if ((iv[0][0] <= iv[1][0] && iv[0][1] >= iv[1][0]) || (iv[0][0] <= iv[1][1] && iv[0][1] >= iv[1][1])) 
            {
                sum2++;
            }
        }

        std::cout << "Part One: " << sum1 << std::endl;
        std::cout << "Part Two: " << sum2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}