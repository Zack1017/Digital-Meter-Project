float calculate_resistor()
{
    float v_ref = ; //Update this to the correct value
    float r1 = 0.00;
    float r_ref1 = ; //Update this to the correct value
    float adc_value1 = 0.00;
    float voltage1 = 0.00;
    float r2 = 0.00;
    float r_ref2 = ; //Update this to the correct value
    float adc_value2 = 0.00;
    float voltage2 = 0.00;
    float r3 = 0.00;
    float r_ref3 = ; //Update this to the correct value
    float adc_value3 = 0.00;
    float voltage3 = 0.00;


    pinMode(R1, OUTPUT);
    pinMode(R2, INPUT);
    pinMode(R3, INPUT);
    digitalWrite(R1, HIGH);


    for (int i = 0; i < 20; i++)
    {
        adc_value1 = adc_value1 + analogRead(OhmMeter);
        delay(3);
    }

    adc_value1 = adc_value1 / 20;

    if (adc_value1 < 1022.90)
    {
        voltage1 = ((adc_value1 * v_ref) / 1024);
        r1 = (voltage1 * r_ref1) / (v_ref - voltage1);
    }

    /* 
        Write the code for each range after. 

        Range 10K 
        1. Define you Pin modes

        2. Read the ADC value

        3. Check the range 
        
        4. Conver ADC to Voltage and Use the formula: R = (V * Rref) / (Vref - V)

        Range 100K
        1. Define you Pin modes

        2. Read the ADC value

        3. Check the range

        4. Conver ADC to Voltage and Use the formula: R = (V * Rref) / (Vref - V)
      */

    r1 = r1 / 1000;

    r2 = r2 / 1000;

    r3 = r3 / 1000;
    if (r1 < 2 && r2 < 101 && r3 < 1001) R = r1 * 1000;
    else if (r1 > 2 && r2 < 101 && r3 < 1001) R = r2;
    else if (r1 > 2 && r2 > 101 && r3 < 2000) R = r3;
    else R = 0.00;

    return R;
}