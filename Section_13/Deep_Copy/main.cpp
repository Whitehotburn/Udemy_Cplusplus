#include <iostream>

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data;}

    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source)
    : Deep {*source.data} {
        std::cout << "Copy constructor - shallow copy" << std::endl;
    }

Deep::~Deep() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}

void display_deep(Deep s) {
    std::cout << s.get_data_value() << std::endl;
}

int main() {
    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};
    obj2.set_data_value(1000);

    return 0;
}