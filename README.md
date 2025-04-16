# Digital-Meter-Project
EE120 Final Project 

# Part 0A: Setting Up the Project
[Click Here](https://github.com/SDSMT-EE120/Digital-Meter-Project/tree/main/Part0-Setup) 

How to setup and program the ESP32. 

# Part 0B: Smart Weather Dashboard 
[Click Here](https://github.com/SDSMT-EE120/Smart_Weather_Dashboard)
The differnce between Ardunio and ESP32 and how to program the TFT screen. 

# Part 1: Voltmeter [Comming Soon] 
We use the voltage divider technique for the voltmeter. We need the Arduino’s ADC unit to read the voltage. 

### Circuit 
Here we have used 10 and 4.7 kilo-ohm resistors for the voltage division circuit. Connect the wires according to the following diagram.

[Image Here Board ]

    Warning: Since the input voltage for ESP32’s ADC is 3.3 volts, selecting these resistors will allow the measuring of voltages up to 9.9 volts. Higher voltages could damage your board.

By changing the resistors you can change the range of acceptable input voltages. The higher the input voltage, the lower the accuracy will be.

    Note: The voltmeter should be in parallel to the section for measuring its voltage.

### Equation 
Here, using the formula for voltage division rule and reading voltage by the ADC unit, we calculate the input voltage.

    Tip: To find the voltage using the ADC unit, we use the following proportion:

[Image Equations ]

# Project Overview and Helpers 

## Overview

The multimeter is an indispensable tool for any electronics project, as it helps overcome countless challenges during project completion. This project will demonstrate how to create a cost-effective digital multimeter using an Adafruit ESP32-S3 REV TFT board. This multimeter is capable of measuring voltage, current, resistance, and capacitance. Upon completing the project, you will have your own multimeter and a better understanind of Ohm's Law. 

## What You Will Learn 

- Understand the concept of a multimeter and its importance in electronics projects

- Learn how to measure voltage accurately

- Discover the techniques for measuring current effectively

- Master the art of measuring resistance with precision

- Explore the measurement of capacitance using ESP32

- Build a Multimeter (voltmeter, ammeter, ohmmeter and capacitan) with ESP32

## What Is A Multimeter?

In simple words, a multimeter is a device that converts electrical parameters such as voltage, current and so on to a language we can understand. First prototypes of this widely used device (called galvanometer) were created in 1820. Despite being only capable of measuring current, they became an essential part of any electronics projects. Knowing how to use a multimeter is essential for any electronics project

Multimeters are generally categorized as analog and digital. Analog multimeters use physical pointers to display values and are being used less and less. However, digital multimeters benefit from digital displays and are much more popular.

- An analog multimeter:

[Insert Image Here Analog]

- A digital multimeter:

[Insert Image Here Digital]


## What Parameters Does A Multimeter Measure?

Multimeters measure various parameters. However, the most important ones are voltage, current and, resistance. Other parameters include capacitance, self-inductance, frequency, diode test, connectivity test, brightness, transistor test and, so on.

For this project, we will make a multimeter that can measure voltage, current, resistance and capacitance.


## Measuring the Electrical Voltage

Various methods exist for measuring the voltage, such as using the hall effect, the simplest one is the voltage divider.

The voltage divider is a circuit that puts a fraction of the voltage between two resistors.

[Image Here Voltage Divider]

[Image Here Voltage Divider Equation]

Now if we know the R1 and R2 resistance and the Vout values, we can easily calculate the voltage using the above formula.

## Measuring the Electrical Current

The simplest method for measuring the current is using Ohm’s law. This law states the electrical current in a path is directly proportional to the voltage divided by the resistance in that path.

Another technique for measuring the current is using the hall-effect principle. The passing of the electrical current creates a magnetic field and consequently the hall voltage. By measuring the hall voltage, you can calculate the magnetic field intensity and therefore the passing electrical current.

## Measuring the Resistance

The same voltage divider technique can be used to measure the resistance. The only difference compared to measuring the voltage is that here, we know the input voltage, the resistance of R1 and the output voltage. R2 is the unknown variable.

[Image Here Voltage Divider Equation]

## Measuring the Capacitance

An effective method for measuring the capacitance is the capacitor charge and discharge rule.

[Image Here CAP Divider]

Below you can find the charging time for a capacitor.

[Image Here CAP Time]

It takes a specific amount of time for the capacitor to charge to 63.2%. This is calculated using the following formula:

τ^(second)=R×C

So if we know the resistance and the time it takes for the capacitor to charge to 63.2% of its capacitance, we can calculate the capacitance.

