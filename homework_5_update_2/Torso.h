class Torso : Robotpart{
public:
    Torso(){}
private:
    int batterySlots;
    Head head;
    vector<Arm> arms;
    Motor motor;
    vector<Battery> batteries;
};
