#include "mbed.h"
#include <vector>

class ForceResistor{
private:
    double finalMass;
    vector<double> discreteArray;
    Timer timer;
    AnalogIn analog;

public:
    ForceResistor(PinName pin);
    double getMass();
    void displayMass();
};