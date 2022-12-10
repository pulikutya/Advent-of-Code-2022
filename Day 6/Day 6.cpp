#include <iostream>
#include <fstream>


int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        unsigned long long int ans1 = 0, ans2 = 0;
        bool found1 = false, found2 = false;
        char buffer1[4], buffer2[14], tempBuffer;
        while (!input.eof() && (!found1 || !found2))
        {
            input >> tempBuffer;
            if (!found1) 
            {
                buffer1[ans1 % 4] = tempBuffer;
                for (unsigned char i = 0; i < 4; i++)
                {
                    for (unsigned char j = i + 1; j < 4; j++) if (buffer1[i] == buffer1[j]) goto N_FOUND1;
                }
                found1 = true;
            N_FOUND1:
                ans1++;
            }

            if (!found2)
            {
                buffer2[ans2 % 14] = tempBuffer;
                for (unsigned char i = 0; i < 14; i++)
                {
                    for (unsigned char j = i + 1; j < 14; j++) if (buffer2[i] == buffer2[j]) goto N_FOUND2;
                }
                found2 = true;
            N_FOUND2: 
                ans2++;
            }
        }

        std::cout << "Part One: " << ans1 << std::endl
                  << "Part Two: " << ans2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}