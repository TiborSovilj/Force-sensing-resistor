#include "mbed.h"
#include "ForceResistor.h"




ForceResistor force(p20);




int main()
{
    while (1) {
        
        double a;
        a = force.getMass();
        force.displayMass();
    }
}
