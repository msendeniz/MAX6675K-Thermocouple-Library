This is the readme for m6675k library

It uses SPI(Serial Peripheral Interface) communication to return and print out the temperature in Kelvin,Celsius and Fahrenheit.
To obtain the temperature data, SPI was used manually by toggling LOW and HIGH for Chip select pin.
The temperature reading is stored in an array and converted to decimal from binary.
After converting, the output is divided by 4.001 as it was suggested in the datasheet.
Then, the functions convert the temperature to Kelvin and Fahrenheit.


