# Mad Max Self Driving Competition Start Lights

Simple starter light setup for self driving car competition.  Uses a red/yellow/green tower
light stack with buzzer that you can get from adafruit https://www.adafruit.com/product/2993

![Tower Example](/pic.jpg)

More information about the Mad Max Self Driving competition can be found on the OpenGarages.org mailing list.
This competition is scheduled for Defcon 2018 at the Car Hacking Village.

## To Build

Need some NPN transitors or N-Channel Mosfets (4 of them).  Arduino.  12 volt power supply
and a button.  Wire the tower light as described in the source constants.

## To User

When you power on the device it will do a test of each light and the buzzer for one second.
This is to ensure everything is wired and working.

Once you press the butotn the yellow light will show for 2 seconds follwed by the green light
and buzzer.  The buzzer lasts for 1 second.

After the countdown press the button again to reset.
