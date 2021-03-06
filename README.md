# SeriArduino

## Install

### For Arduino

* [See here](./seriarduino_cpp/README.md)

### For Python

* [See here](./seriarduino_py/README.md)

## Usage

The following sample is linking an Arduino with a Raspberry Pi:

### Arduino side
```cpp
#include <SeriArduino.h>

SeriArduino raspberry;

String input;
float value;

void setup() {
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

### Python side (Raspberry Pi)

```python
from seriarduino import SeriArduino

arduino = SeriArduino(bauds = 9600)

while True:
	# We ask what value to send
	val = input("Value to send: ")
	
	# We send to Arduino this value
	arduino.write(val)
 	print ("Value sent: ", val)
	
	# We wait for the answer
	answer = arduino.read()
	
	print ("The Arduino answer is: ", answer)
```

> By default, SeriArduino will try to find the serial address, but you can also manually specify it by using the address argument on the constructor (e.g. `SeriArduino(address = "/dev/ttyACM0")`)