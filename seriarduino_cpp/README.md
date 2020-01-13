# SeriArduino: C++ Arduino library

## Install from releases (easiest)

* Download `seriarduino_cpp.zip` from [releases](https://github.com/norech/SeriArduino/releases) 
* Open the Arduino IDE
* Go into `Sketch` > `Include a library` and add the library from the `seriarduino_cpp.zip` file

## Install from repo

* Clone the repo
* Compress the `seriarduino_cpp` folder into `seriarduino_cpp.zip`
* Open the Arduino IDE
* Go into `Sketch` > `Include a library` and add the library from the `seriarduino_cpp.zip` file

## Usage

> You will need to also use the [SeriArduino Python library](https://github.com/norech/SeriArduino/tree/master/seriarduino_py/README.md) in order to use this library.

The following sample is linking an Arduino with a Raspberry Pi. [Both the Python and Arduino sides of this code are available here.](https://github.com/norech/SeriArduino#usage)

```cpp
#include <SeriArduino.h>

SeriArduino raspberry;

String input;
float value;

void setup () {
    // We set the serial to 9600 bauds (be sure to use the same on the Python side)
    Serial.begin(9600);
}

void loop() {
    // If raspberry gets any data
    if(raspberry.available()) {
        // We read the data and save it into the "input" variable
        input = raspberry.read();

        // We convert the input into a float,
        // to do some computations later
        value = input.toFloat();

        Serial.println("We got a " + String(value));

        // A simple computation
        value = value * 2;

        // We send the new data to the Raspberry Pi
        raspberry.write(value);
    }
  
    delay(100);
}
```