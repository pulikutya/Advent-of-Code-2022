#include <iostream>
#include <fstream>
#include <string>

inline char getPriority(char v)
{
    if (v >= 'a' && v <= 'z') return  v - 'a' + 1;
    else if (v >= 'A' && v <= 'Z') return v - 'A' + 27;
}

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        std::string crnString;
        int ans1 = 0, ans2 = 0;
        std::string g3[3] = { std::string(), std::string(), std::string() };
        unsigned char gi = 0;
        while (std::getline(input, crnString))
        {
            g3[gi] = crnString;
            std::string s1 = crnString.substr(0, crnString.length() / 2), s2 = crnString.substr(crnString.length() / 2);
            for (unsigned long long int i = 0; i < s1.length(); i++)
            {
                if (s2.find(s1[i]) != std::string::npos) 
                { 
                    ans1 += (int)getPriority(s1[i]); break;
                }
            }

            if (gi == 2)
            {
                gi = 0;
                for (unsigned long long int i = 0; i < g3[0].length(); i++)
                {
                    if (g3[1].find(g3[0][i]) != std::string::npos && g3[2].find(g3[0][i]) != std::string::npos)
                    { 
                        ans2 += (int)getPriority(g3[0][i]); break;
                    }
                }
            }
            else gi++;
        }

        std::cout << "Part One: " << ans1 << std::endl;
        std::cout << "Part Two: " << ans2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}