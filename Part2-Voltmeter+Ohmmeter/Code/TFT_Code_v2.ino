#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_NeoPixel.h>


// TFT display setup (No CS pin needed for Feather TFT)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

//Define Global Variables 
int Sensor_Value = 0;
float V_ref = 3.3;
float V = 0;
float C = 0;

void setup() 
{
    pinMode(TFT_BACKLITE, OUTPUT);   // TFT backlight control
    pinMode(TFT_I2C_POWER, OUTPUT);  // Power supply control for TFT/I2C

    setup_TFT();                     // Initialize TFT display

    // Draw initial graphics on TFT
    drawThermometerIcon();

    // NeoPixel setup
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    // TODO: Insert code to read the incoming analog temperature value and convert it to floating point temperature value
    V = Sensor_Value * (V_ref / 4096.0);
    C = (V - 0.5) * 100;

    // TODO: Insert logic to update the LED

    // Clear screen section and redraw thermometer
    tft.fillScreen(ST77XX_BLACK);
    drawThermometerIcon();

    char tempBuffer[10];
    dtostrf(C, 4, 1, tempBuffer); // Convert float to string

    // TODO: Insert code to update the TFT display with the temperature value and change ThermometerIcon color
    drawText("Testing...", 0, 0, ST77XX_WHITE);
    changeThermometerColor(C);

    // Refresh every 500ms
    delay(1000);
}

// Function to draw a simple thermometer icon on the TFT screen
void drawThermometerIcon() {
    tft.fillRect(20, 50, 40, 80, ST77XX_BLUE); // Thermometer body
    tft.fillRect(30, 45, 20, 10, ST77XX_BLUE); // Top
    tft.fillRect(30, 130, 20, 10, ST77XX_BLUE); // Bottom
}

void changeThermometerColor(float temp) {
    uint16_t color;
    if (temp >= 30) {
        color = ST77XX_RED;
    }
    else if (temp >= 20) {
        color = ST77XX_YELLOW;
    }
    else {
        color = ST77XX_BLUE;
    }
    tft.fillRect(20, 50, 40, 80, color); // Change thermometer color
}

// Function to set up the TFT display
void setup_TFT()
{
    // turn on backlite
    digitalWrite(TFT_BACKLITE, HIGH);

    // turn on the TFT / I2C power supply
    digitalWrite(TFT_I2C_POWER, HIGH);
    delay(10);

    tft.init(135, 240); // Init ST7789 240x135
    tft.setRotation(3);
    tft.fillScreen(ST77XX_BLACK);

    Serial.println(F("Initialized"));

    tft.fillScreen(ST77XX_BLACK);
    
    delay(1000);
}

// Function to draw text on the TFT display
void drawText(const char* text, int x, int y, uint16_t color) 
{
    tft.setCursor(x, y);
    tft.setTextSize(2);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
}
