#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template<typename Collection>
struct PersistenceManager {
    static void save(const Collection &c, const std::string& filename) {
       std::ofstream ofs(filename.c_str());
       for(auto e : c.entries) {
           ofs << e << std::endl;
       }
    }
};

struct Journal 
{
    std::string title;
    std::vector<std::string> entries;

    explicit Journal(const std::string& title) : title(title) {}

    void add(std::string entry) { entries.push_back(entry);}
};

int main()
{
    std::string title = "c++ journal";

    Journal j = Journal(title);
    j.add("Polymorphism");
    j.add("Inheritance");
    j.add("Generics");
    j.add("End");

    PersistenceManager<Journal>().save(j, "c++-journal.txt");

    return 0;
}

