#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class dir;
class node;


typedef unsigned long long ull;


class node
{
public:
    dir* parent;
    std::string name;
    virtual unsigned int size() = 0;
    node(dir* parent = nullptr, std::string name = "") : parent(parent), name(name) {};
};

class file : public node
{
public:
    unsigned int _size = 0;
    inline unsigned int size() override { return _size; }
    file(dir* parent = nullptr, std::string name = "", unsigned int _size = 0) : node(parent, name), _size(_size) {};
};

class dir : public node
{
public:
    std::vector<node*> children = std::vector<node*>();
    dir(dir* parent = nullptr, std::string name = "") : node(parent, name) {};
    ull ForEach(bool(*DF)(dir*) = nullptr, bool(*FF)(file*) = nullptr)
    {
        for (ull i = 0; i < children.size(); i++)
        {
            dir* d = dynamic_cast<dir*>(children[i]);
            file* f = dynamic_cast<file*>(children[i]);
            if (DF != nullptr && d != nullptr && !DF(d)) return i;
            else if (FF != nullptr && f != nullptr && !FF(f)) return i;
            else throw std::exception();
        }
    }
    unsigned int size() override 
    {
        unsigned int res = 0;
        for (ull i = 0; i < children.size(); i++) res += children[i]->size();
        return res;
    }
    void addChild(node* node) { children.push_back(node); }
    void removeChild(ull index) { children.erase(children.begin() + index); }
    node* operator[](ull index) { return children[index]; }
    ull find(std::string name) 
    {
        for (ull i = 0; i < children.size(); i++) if (children[i]->name == name) return i;
        return -1;
    }
    /*void operator delete(void* v)
    {
        static_cast<dir*>(v)->children.~vector();
        delete[] v;
    }*/
};

unsigned int a1(dir* directory) //unefficient
{
    unsigned int res = 0;
    {
        unsigned int t = directory->size();
        if (t <= 100000) res += t;
    }
    for (ull i = 0; i < directory->children.size(); i++)
    {
        dir* d = dynamic_cast<dir*>(directory->children[i]);
        if (d != nullptr) res += a1(d);
    }
    return res;
}

unsigned int a2(dir* directory, dir* min = nullptr, unsigned int minS = ULONG_MAX)
{
    

}

int main()
{
    std::ifstream input("input.txt");
    if (input)
    {
        ull ans1 = 0, ans2 = 0;
        dir* root = new dir(nullptr, "/"), * cd = root;
        std::string crnString;
        while (std::getline(input, crnString))
        {
            if (crnString[0] == '$')
            {
                std::string cmd = crnString.substr(2, 2);
                if (cmd == "cd")
                {
                    std::string arg = crnString.substr(5);
                    if (arg == "..") cd = cd->parent;
                    else if (arg == "/") cd = root;
                    else cd = dynamic_cast<dir*>(cd->children[cd->find(arg)]);
                }
                else if (cmd == "ls") {}
                else throw std::exception();
            }
            else if (crnString.substr(0, 3) == "dir") cd->addChild(new dir(cd, crnString.substr(4)));
            else
            {
                ull s1 = crnString.find(' ');
                cd->addChild(new file(cd, crnString.substr(s1 + 1), std::stoul(crnString.substr(0, s1))));
            }
        }
        
        ans1 = a1(root);
        ans2 = a2(root);

        std::cout << "Part One: " << ans1 << std::endl
                  << "Part Two: " << ans2 << std::endl;
        
        //root->operator delete(root);
    }
    if (input.is_open()) input.close();
    std::cout << std::endl;
    system("pause");
    return 0;
}