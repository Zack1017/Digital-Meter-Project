# Part 3 - Ammeter

## Background 

### Measuring the Electrical Current

The simplest method for measuring the current is using Ohm’s law. This law states the electrical current in a path is directly proportional to the voltage divided by the resistance in that path.

Another technique for measuring the current is using the hall-effect principle. The passing of the electrical current creates a magnetic field and consequently the hall voltage. By measuring the hall voltage, you can calculate the magnetic field intensity and therefore the passing electrical current.

## Building in Hardware 

We use the AC712 sensor for making the ammeter. It is available as a module in various ranges. In this project, we are using the 5A range of this module.

![ImageAC71](/assets/images/multimeter-ac712.jpg)

This sensor uses the hall effect to measure the current. Then it outputs a voltage proportional to the measured current, namely 185 millivolts for each amp of current.

![ImagePin](/assets/images/pinout.jpg)

## Circuit

![Circuit](/assets/images/p3_circuit.png)