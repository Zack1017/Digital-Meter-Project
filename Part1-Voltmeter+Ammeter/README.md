# Part 1 - Voltmeter + Ammeter

## Voltmeter (Part A)
This project involves creating a digital voltmeter using the Reverse Feather TFT S3 microcontroller. The voltmeter will utilize a voltage divider circuit to safely scale down input voltages for ADC (Analog-to-Digital Converter) measurement. The S3’s ADC will read the divided voltage and convert it into a digital value, which will be processed and displayed on the onboard TFT screen in real-time. This setup allows for accurate voltage monitoring in a compact, user-friendly format, ideal for educational and prototyping purposes.


## Background 

### Measuring the Electrical Voltage

Various methods exist for measuring the voltage, such as using the hall effect, the simplest one is the voltage divider.

The voltage divider is a circuit that puts a fraction of the voltage between two resistors.

[Image Here Voltage Divider]

[Image Here Voltage Divider Equation]

Now if we know the R1 and R2 resistance and the Vout values, we can easily calculate the voltage using the above formula.


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


## Ammeter (Part B)

The simplest method for measuring the current is using Ohm’s law. This law states the electrical current in a path is directly proportional to the voltage divided by the resistance in that path.

Another technique for measuring the current is using the hall-effect principle. The passing of the electrical current creates a magnetic field and consequently the hall voltage. By measuring the hall voltage, you can calculate the magnetic field intensity and therefore the passing electrical current.