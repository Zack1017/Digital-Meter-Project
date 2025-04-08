# Setting Up the Project 

## Software: 

This tutorial assumes that that you already have Ardunio IDE installed on your device.  If you do not please go to this [link](http://www.arduino.cc/en/Main/Software) and install or contact your TA or Professor. 

## Setting up the Enviroment 


### Getting Board Manager 
Open Ardunio IDE and navigate to **File** in the top left corner.  Then select Preference 

![IDE Screen](/assets/images/IDE_File.png)

A dialog will pop up just like the one shown below.

![IDE Preference](/assets/images/IDE_Preference.png)

We will be adding a URL to the new **Additional Boards Manager URLs** option. 

     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

![IDE Preference URL](/assets/images/IDE_Preference_URL.png)

Once done click **OK** to save the new preference settings.

### Installing Board Manager 

The next step is to actually install the Board Support Package. Go to the **Tools** → **Board** → **Board Manager** submenu. A dialog should come up with various BSPs. Search for **esp32**.

![IDE Board](/assets/images/IDE_Board.png)

Click the **Install** button and wait for it to finish. Once it is finished, you can close the dialog.

### Selecting Board  

In the **Tools** → **Board** submenu you should see **ESP32 Arduino** and in that dropdown it should contain the ESP32 boards along with all the latest ESP32-S2/S3 boards.

Look for the board called **Adafruit Feather ESP32-S3 Reverse TFT**.

![IDE Board Select](/assets/images/IDE_Board_Select.png)

### Launch ESP32 ROM Bootloader 

Look for the Reset button and a second DFU / BOOT0 button

![Board Buttons](/assets/images/Board_Bootloader.png)

**HOLD down the DFU/Boot0 button while you click Reset. Then release DFU/Boot0 button**

It should appear under **Tools** -> **Port** as **ESP32 Family Device**. 

![IDE Port Select](/assets/images/IDE_Port.png)

In the **Port** menu, select the serial port that is labelled **ESP32 Family Device**

     (Note this is the Port menu, not the Board menu. In the Board menu choose the exact board you are using.)

## Loading Blink Sketch Code  

Download the code in Gitlab found in **TestCode/Blink/Blink.ino"

Once downloaded double click and press the checkmark in the top left corner to build the code. Once the code has built the click the arrow to upload the code.

     Note that we use LED_BUILTIN not pin 13 for the LED pin. That's because we don't always use pin 13 for the LED on boards. For example, on the Metro ESP32-S3 the LED is on pin 42!

After uploading, you may see something warning you that we could not get out of reset. This is normal! **Press the RESET button on your board to launch the sketch**

That's it, you will be able to see the red LED blink. You will also see a new serial port created.

You may call <code>Serial.begin();</code> in your sketch to create the serial port so don't forget it.

![IDE Port New](/assets/images/IDE_New_Port.png)

You can now select the **new serial port** name which will be different than the bootloader serial port. Arduino IDE will try to use auto-reset to automatically put the board into bootloader mode when you ask it to upload new code

**If you ever DON'T see a serial port, or something is not working out with upload you can always manually enter bootloader mode:**

<ol>
  <li>Reset board into ROM bootloader with DFU/BOOT0 + Reset buttons</li>
  <li>Select the ESP32S2/S3 Dev Board ROM bootloader serial port in Tools->Port menu</li>
  <li>Upload sketch</li>
  <li>Click reset button to launch code</li>
</ol>