# crypto_display
Displaying ETC on an Arduino

## Preparation
Add your API key to crypto_display.ino, then upload to your arduino!

With the arduino CLI, you can simply use ```make all```.

We create a fully functioning, responsive chess system.

## Setting up Arduino in VS Code (for Macs only)

I followed the instructions from [here](https://create.arduino.cc/projecthub/B45i/getting-started-with-arduino-cli-7652a5) and in [this video](https://www.youtube.com/watch?v=J-qGn1eEidA).

1. Run ```brew install arduino-cli``` in terminal
2. Check if the ```arduino-cli is``` accessible from theterminal by typing: ```arduino-cli```.
3. Run ```arduino-cli core update-index``` in the terminal
4. Next, you need to identify the port that the arduino is on. You can do this by running ```arduino-cli board list``` and plugging / unplugging the arduino. For me the port is ```/dev/cu.SLAB_USBtoUART```.

And you're basically done setting up! To compile your program you need to run:

```arduino-cli compile --fqbn esp32:esp32:esp32 YOUR_INO_FILE```

Following this command you should see something like the following:

```
Sketch uses 240060 bytes (18%) of program storage space. Maximum is 1310720 bytes.
Global variables use 14504 bytes (4%) of dynamic memory, leaving 313176 bytes for local variables. Maximum is 327680 bytes.
```

Finally, to upload to the ESP, you will need the port from step 4 of above. To upload run the following command:

```arduino-cli upload -p YOUR_PORT_FROM_STEP_4 --fqbn esp32:esp32:esp32 YOUR_INO_FILE```

Which, if everything works correctly should upload it to the Arduino and show the usual output you see.

TO view the serial monitor run ```screen YOUR_PORT_FROM_STEP_4 115200```. To exit, use ctrl-A then ctrl-D.

