1) Create an account on 

2) Create a new 'Thing' and configure your Arduino Board following these instructions: 
  https://docs.arduino.cc/cloud/iot-cloud/tutorials/iot-cloud-getting-started

3) Set 4 variables:
    *OnHourIoT: Integer number type, Read & Write permission.
    *OnMinuteIoT: Integer number type, Read & Write permission.
    *Valve: Boolean type, Read & Write permission.
    *volume: Floating point number type, Read & Write permission. 

<img src= "https://user-images.githubusercontent.com/91575651/135295010-2b179edb-41c1-45a9-aacb-0c2b623da31e.PNG" width="450" height="300">

4) Create a dashboard (https://docs.arduino.cc/cloud/iot-cloud/tutorials/iot-cloud-getting-started#8-creating-a-dashboard). Setup the following 'widgets':
  *1 chart linked to the volume variable.
  *1 switch linked to the valve variable.
  *1 slider with a 0-24 range linked to the OnHourIoT variable.
  *1 slider with a 0-60 range linked to the OnMinuteIoT variable.

  
<img src= "https://user-images.githubusercontent.com/91575651/135301813-a4767004-dad1-4dfc-af19-9819ff3b08d0.PNG" width="450" height="300">

