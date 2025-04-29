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

    Note: To measure the current, the ammeter has to be in series with the intended section to measure the current.

## Code 

### 1. Choose the Analog Input Pin
- Decide which analog pin (e.g., `A2`) you will use to read from the current sensor.

### 2. Understand Sensor Sensitivity
- Know the **sensitivity** of your sensor in millivolts per ampere (e.g., `185 mV/A` for an ACS712-5A sensor).

### 3. Know Your System Voltage Reference
- Define your system's reference voltage (`v_ref`), which might be close to `4.94V` or `5.0V` depending on your board.

### 4. Account for Zero-Current Offset Voltage
- Current sensors output a voltage even when no current is flowing (e.g., around `2.47V`). 
- You must subtract this *offset voltage* from the measured voltage later.

### 5. Average Multiple ADC Readings
- Take multiple analog readings (e.g., `40` samples) to reduce noise.
- Add the readings together and divide by the number of samples to get an average.

### 6. Convert ADC Value to Voltage
- Use the formula:

voltage = (average_ADC_value × v_ref) / 1024

### 7. Calculate the Pure Voltage
- Subtract the offset voltage:

pure_voltage = voltage - offset_voltage

### 8. Convert Pure Voltage to Millivolts
- Multiply the pure voltage by `1000` to convert it from volts to millivolts:

pure_voltage_mV = pure_voltage × 1000

### 9. Calculate the Current
- Divide the millivolt value by the sensor's sensitivity:

current (A) = pure_voltage_mV / sensitivity

### 10. Return the Current
- Return the calculated current value from the function so it can be used elsewhere.