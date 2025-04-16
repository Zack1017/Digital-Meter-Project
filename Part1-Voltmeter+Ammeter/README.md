# Part 1 - Voltmeter + Ohmmeter

## Background 

### Measuring Voltage

Various methods exist for measuring the voltage, such as using the hall effect, the simplest one is the voltage divider.

The voltage divider is a circuit that puts a fraction of the voltage between two resistors.

![Voltage Divider Voltage](/assets/images/voltage_div.png)

![Voltage Divider Equation](/assets/images/voltage_eq.png)

Now if we know the R1 and R2 resistance and the Vout values, we can easily calculate the voltage using the above formula.


### Measuring Resistance 

The same voltage divider technique can be used to measure the resistance. The only difference compared to measuring the voltage is that here, we know the input voltage, the resistance of R1 and the output voltage. R2 is the unknown variable.

![Voltage Divider Resistnace](/assets/images/voltage_div_2.png)

## Pre-Lab

### TinkerCAD

#### Part A 
Using TinkerCad we will use the voltage divider technique for the voltmeter. We need the Arduino’s ADC unit to read the voltage. There is already a template in the Class Folder labled "DMM 2.2 -Voltage and Resistance Measurements".

To keep it simple we will use a 10k and 4.7k resistor(Note in simulation these behave idealy) for the voltage division circuit.

Connect the wires according to the following diagram.

![Voltmeter Circuit](/assets/images/P1A_circuit.png)

Connect a voltage supply to the input.  Write the code to print to the screen using this Helper.  

Test the following Voltages:

- 1 V

- 5 V

- 10 V

- 15 V

- 20 V



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

## Voltmeter (Part A)
This project involves creating a digital voltmeter using the Reverse Feather TFT S3 microcontroller. The voltmeter will utilize a voltage divider circuit to safely scale down input voltages for ADC (Analog-to-Digital Converter) measurement. The S3’s ADC will read the divided voltage and convert it into a digital value, which will be processed and displayed on the onboard TFT screen in real-time. This setup allows for accurate voltage monitoring in a compact, user-friendly format, ideal for educational and prototyping purposes.

## Ohmmeter (Part B)

The simplest method for measuring the current is using Ohm’s law. This law states the electrical current in a path is directly proportional to the voltage divided by the resistance in that path.

Another technique for measuring the current is using the hall-effect principle. The passing of the electrical current creates a magnetic field and consequently the hall voltage. By measuring the hall voltage, you can calculate the magnetic field intensity and therefore the passing electrical current.

## Helper

### Voltmeter Code 

#### Objective:
This program reads an analog voltage through a voltage divider, calculates the actual voltage using known resistor values, and displays it on an LCD. It also prints raw analog readings to the serial monitor.

#### Steps to Implement:

1. Define Variables:

    - Create a variable to store the calculated voltage.

    - Declare the analog input pin connected to the voltage divider.

2. Create a Voltage Calculation Function:

    - Define the resistor values used in the voltage divider.

    - Set the reference voltage for the ADC.

    - Read the analog value multiple times (e.g., 20 samples) to average out noise.

    - Convert the average analog reading into a voltage using the ADC resolution (See Below).


        voltage = (((adc_value+.5) * v_ref) / 1024);

        Where adc_value is the average value of the pin and v_ref is the logic voltage. 

    - Use the voltage divider formula to scale the voltage back up to the real input voltage.

3. Set Up the System:

    - Print a label (like "Voltage:") to the first row of the display.

4. In the Loop Function:

    - Call your voltage calculation function.(See Below)


        lcd_.print( calculate_voltage(),1);

    - Display the result with 1 decimal precision on the second row of the LCD.
