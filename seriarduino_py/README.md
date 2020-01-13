# SeriArduino: Python library

## Install from releases (easiest)

* Open the terminal
* Execute `pip install seriarduino`

## Install from repo

* Clone the repo
* Open the `seriarduino_py` folder in a terminal
* In the terminal, enter `pip install .`


## Usage

> You will need to also use the [SeriArduino C++ library](https://github.com/norech/SeriArduino/tree/master/seriarduino_cpp/README.md) in order to use this library.

The following sample is linking a Raspberry Pi (Python) with an an Arduino. [Both the Python and Arduino sides of this code are available here.](https://github.com/norech/SeriArduino#usage)

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