#include <iostream>

using namespace std;

class Robotpart{

public:

    string get_name();
    int get_partNum();
    double get_weight();
    double get_price();
    string get_descript();
    void get_image();


protected:
    string name;
    int partNum;
    double weight;
    double price;
    string descript;
    Renderedimage image;

};
