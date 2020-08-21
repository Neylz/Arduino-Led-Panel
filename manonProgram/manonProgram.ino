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
    //  pixel type : NEO_GRB, NEO_RGB, NEO_RGBW

void setup() {
    #if defined(__AVR_ATtiniy85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif

    strip.begin();          // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();           // Turn OFF all pixels ASAP
    strip.setBrightness(35); // Set BRIGHTNESS (max = 255)

}

void loop() {
    rainbow(10);
}


void rainbow(int wait) {
    int manon[61] = {1, 2, 3, 4, 5, 9, 15, 16, 17, 18, 19, 29, 30, 31, 32, 33, 36, 38, 43, 44, 45, 46, 47, 57, 58, 59, 60, 61, 65, 72, 73, 78, 79, 80, 81, 82, 92, 93, 94, 95, 96, 99, 103, 106, 107, 108, 109, 110, 120, 121, 122, 123, 124, 130, 136, 137, 141, 142, 143, 144, 145};

    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
        for(int i=0; i<strip.numPixels(); i++) {
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            
            // strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));

            int test = false;
            for (int x=0; x < 61; x++) {
                if (manon[x] == i) {
                    test = true;
                }
            };
            if (test != true) {
                strip.setPixelColor(i, 255, 130, 0);
            } else {
                strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
            };
        };

        strip.show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
    }
}

