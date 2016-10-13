
class Battery : Robotpart{
public:
    Battery(){}
    double get_energy(){return energy;}
    double get_maxpower(){return maxPow;}

private:
    double energy;
    double maxPow;
};
