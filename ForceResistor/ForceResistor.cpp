#include "mbed.h"
#include "ForceResistor.h"
#include <vector>

Serial pc(USBTX, USBRX);

ForceResistor::ForceResistor(PinName pin) : analog(pin){
}

double ForceResistor::getMass(){

    double forceValue, voltage, fsrResistance, fsrConductance, fsrForce, mass;

    // timer
    timer.start();
    while (timer.read_ms() < 1000){
        forceValue = analog.read();
        voltage = forceValue*3.3;
        fsrResistance = 3.3 - voltage;
        fsrResistance = fsrResistance * 10000;
        fsrResistance = fsrResistance / voltage;
        fsrConductance = 1000000;
        fsrConductance = fsrConductance / fsrResistance;
        fsrForce = fsrConductance / 80;
        mass = fsrForce * 1000 / 9.81;
    
        discreteArray.push_back(mass);
        wait_ms(100);
    }

    timer.stop();
    timer.reset();

    double sum = 0;
    for (int i = 0; i < discreteArray.size(); ++i){
        sum = sum + discreteArray[i];
    }
    finalMass = sum/discreteArray.size();
    
    discreteArray.clear();
    return finalMass;
}

void ForceResistor::displayMass(){
    pc.printf("masa(gram):\t%f    \r", finalMass);
}