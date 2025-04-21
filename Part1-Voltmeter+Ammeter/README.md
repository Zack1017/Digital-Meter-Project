# Part 2.2A - Voltmeter + Ohmmeter in TinkerCAD

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

## Building TinkerCAD Circuits

### Voltmeter  
Using TinkerCad we will use the voltage divider technique for the voltmeter. We need the Arduino’s ADC unit to read the voltage. There is already a template in the Class Folder labled "DMM 2.2 -Voltage and Resistance Measurements".

To keep it simple we will use a 10k and 4.7k resistor(Note in simulation these behave idealy) for the voltage division circuit.

Connect the wires according to the following diagram.

![Voltmeter Circuit](/assets/images/P1A_circuit.png)

Connect a voltage supply to the input.  Write the code to print to the screen using this [Helper](https://github.com/SDSMT-EE120/Digital-Meter-Project/tree/main/Part1-Voltmeter%2BAmmeter#voltmeter-code).  

Test the following Voltages:

- 1 V

- 5 V

- 10 V

- 15 V

- 20 V

### Ohmmeter

Using TinkerCad we will use the voltage divider technique again but for the Ohmmeter. We need the Arduino’s ADC unit to read the voltage. There is already a template in the Class Folder labled "DMM 2.2 -Voltage and Resistance Measurements".

To keep it simple we will use a 1k, 10k, and 100k resistor(Note in simulation these behave idealy) for the voltage division circuit.

Connect the wires according to the following diagram.

![Ohmmeter Circuit](/assets/images/P1B_circuit.png)

Connect a resistor to the input.  Write the code to print to the screen using this [Helper](https://github.com/SDSMT-EE120/Digital-Meter-Project/tree/main/Part1-Voltmeter%2BAmmeter#voltmeter-code). 

Test the following Voltages:

- 1 Ohm

- 100 Ohm

- 1 k Ohm

- 5 k Ohm

- 10 k Ohm



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


    ```
    voltage = (((adc_value+.5) * v_ref) / 1024);
    ```

    Where adc_value is the average value of the pin and v_ref is the logic voltage. 

    - Use the voltage divider formula to scale the voltage back up to the real input voltage.

4. Set Up the System:

    - Print a label (like "Voltage:") to the first row of the display.

5. In the Loop Function:

    - Call your voltage calculation function.(See Below)


    lcd_.print( calculate_voltage(),1);

    - Display the result with 1 decimal precision on the second row of the LCD.

### Ohmmeter Code

#### Objective:
Create an automatic-range ohmmeter using an Arduino that determines an unknown resistor's value by switching between three different known reference resistors. The result is printed over the serial monitor.

#### Steps to Implement:
1. Set Up Pins:
    - Connect a known reference resistor to each of three digital output pins.

    - One analog input pin is used to read the voltage across the unknown resistor.

2. Initialize Variables:

    - Define your known resistors (e.g., 1kΩ, 10kΩ, and 100kΩ).

    - Use variables to store analog readings, voltages, and calculated resistance values.

3. Measure Resistance in Three Ranges:

    - First Range (Low Resistor):

        - Set the first digital pin to output and high; others to input.

        - Take multiple analog readings to smooth the signal.

        - Convert average ADC reading into voltage.

        - Use the voltage divider formula to compute the unknown resistance.

    - Second Range (Medium Resistor):

        - Repeat the process using the second resistor.

    - Third Range (High Resistor):

        - Repeat again with the third resistor.

4. Select the Appropriate Range:

    - Based on the results, choose which resistance estimate to use.

    - Apply thresholds to select the best range depending on the value of the unknown resistor.

5. Print the Result:

    - Output the calculated resistance to the Display in ohms or kilo-ohms depending on range.

6. Repeat:

    - In the main loop, continuously perform the measurement with a delay between each cycle.
