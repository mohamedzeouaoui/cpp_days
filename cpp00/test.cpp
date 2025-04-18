#include <iostream>
#include <string> 


class Test {
    private:
        std::string PTRname;
    public:
        Test(std::string name) {
            PTRname = name;
        }
        
        void setName(std::string name);
        
        std::string getName() {
            return this->PTRname;
        }
};

int main() {
    Test test("test");

    test.setName("simo");
    std::cout << "name: " << test.getName() << std::endl;
    return 0;
}


void Test::setName(std::string name) {
    this->PTRname = name;
}