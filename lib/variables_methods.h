#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Container{
public:
    Container()=default;
    void menu() const;
    void save_to_file(std::string message, std::string path) const;
    void main_app() const;
    std::string rle_algorithm(std::string message) const;
    std::string switch_to_uppercase(std::string message)const;
    std::string delete_spaces(std::string message)const;






};