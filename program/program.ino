#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
    #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    6    //Led Pin output
#define LED_COUNT 147   //Number of Led connected

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
//  arg1 = number of leds
//  arg2 = pin output on arduino
//  arg3 = pixel type + frequence
//    pixel type : NEO_GRB, NEO_RGB, NEO_RGBW

void setup() {
    #if defined(__AVR_ATtiniy85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif

    strip.begin();          // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();           // Turn OFF all pixels ASAP
    strip.setBrightness(20); // Set BRIGHTNESS (max = 255)

}

void loop() {
    rainbow(10);
}

void rainbow(int wait) {
    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 128) {
        for(int i=0; i<strip.numPixels(); i++) {
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));

        }

        strip.show();
        delay(wait);
    }
}