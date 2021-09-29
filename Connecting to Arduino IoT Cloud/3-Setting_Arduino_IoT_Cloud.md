1) Create an account on Arduino IoT Cloud.
2) Connect your board to your computer using a USB port. 

3) Create a new 'Thing' and configure your Arduino Board following these instructions: 
  https://docs.arduino.cc/cloud/iot-cloud/tutorials/iot-cloud-getting-started

4) Set 4 variables:
    *OnHourIoT: Integer number type, Read & Write permission.
    *OnMinuteIoT: Integer number type, Read & Write permission.
    *Valve: Boolean type, Read & Write permission.
    *volume: Floating point number type, Read & Write permission. 

<img src= "https://user-images.githubusercontent.com/91575651/135295010-2b179edb-41c1-45a9-aacb-0c2b623da31e.PNG" width="450" height="300">

5) Create a dashboard (https://docs.arduino.cc/cloud/iot-cloud/tutorials/iot-cloud-getting-started#8-creating-a-dashboard). Setup the following 'widgets':
  *1 chart linked to the volume variable.
  *1 switch linked to the valve variable.
  *1 slider with a 0-24 range linked to the OnHourIoT variable.
  *1 slider with a 0-60 range linked to the OnMinuteIoT variable.

  
<img src= "https://user-images.githubusercontent.com/91575651/135301813-a4767004-dad1-4dfc-af19-9819ff3b08d0.PNG" width="450" height="300">

6) Editing the sketch (https://docs.arduino.cc/cloud/iot-cloud/tutorials/iot-cloud-getting-started#7-editing-the-sketch). Place and uploud the Arduino code from https://github.com/aba1mar/Runoff-Automatic-Valve/tree/main/Code to your board.
