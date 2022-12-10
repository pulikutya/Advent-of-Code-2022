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
        std::string ans1, ans2;
        std::vector<std::stack<char>> stacks1;
        std::vector<std::stack<char>> stacks2;
        {
            std::vector<std::string> headerLines({ "" });
            while (std::getline(input, headerLines.back()) && !(headerLines.back().empty()))
            {
                headerLines.push_back("");
            }
            headerLines.erase(headerLines.end()-2, headerLines.end());

            for (unsigned long long i = (headerLines.size())-1; i != ULLONG_MAX; i--)
            {
                for (unsigned long long j = 1, s = 0; j < headerLines[i].size(); j += 4, s++)
                {
                    if (headerLines[i][j] == ' ') continue;
                    if (s >= stacks1.size()) stacks1.push_back(std::stack<char>());
                    if (s >= stacks2.size()) stacks2.push_back(std::stack<char>());
                    stacks1[s].push(headerLines[i][j]);
                    stacks2[s].push(headerLines[i][j]);
                }
            }
        }
        

        std::string crnString;
        while (std::getline(input, crnString))
        {
            unsigned long long
                f = crnString.find('f', 5),
                t = crnString.find('t', f + 5);

            int
                count = std::stoi(crnString.substr(5, f - 2)),
                from = std::stoi(crnString.substr(f + 5, t - 2)),
                to = std::stoi(crnString.substr(t + 3));

            count; from--; to--;

            std::stack<char> temp;

            for (int i = 0; i < count; i++)
            {
                stacks1[to].push(stacks1[from].top());
                stacks1[from].pop();

                temp.push(stacks2[from].top());
                stacks2[from].pop();
            }
            for (int i = 0; i < count; i++)
            {
                stacks2[to].push(temp.top());
                temp.pop();
            }

        }

        for (unsigned long long i = 0; i < stacks1.size(); i++)
        {
            ans1 += stacks1[i].top();
            ans2 += stacks2[i].top();
        }

        std::cout << "Part One: " << ans1 << std::endl;
        std::cout << "Part Two: " << ans2 << std::endl;
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}