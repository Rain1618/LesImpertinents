# TARTOKK

Built for HackUPC `25 🔥🔥🔥

## Inspiration
Canada experienced its most devastating wildfire season in 2023, with over 6,700 fires burning approximately 18.5 million hectares of land. This unprecedented event led to the evacuation of more than 230,000 people and resulted in eight firefighter fatalities. The fires' impact extended beyond Canada's borders, with smoke affecting air quality across the United States and even reaching Europe. 

In terms of residential fire safety, the presence of sprinkler systems significantly enhances survival rates. Data indicates that 97% of residential fires occurred in homes without sprinkler protection, accounting for 99.2% of fire-related deaths. Conversely, homes equipped with sprinklers had a death rate of 0.9 per 1,000 fires, compared to 3.3 in non-sprinklered homes. 

In reality, wildfires spread not only through the trees but also on the ground and even in the soil. An effective way to mitigate further propagation of wildfire is to increase the humidity of the ground fuels.

Sources: LeMonde.fr, Reuters, CPSCJR

## What it does
TARTOKK is an automated sprinkler system made to protect infrastructure located in wildfire prone areas. It uses various sensors and machine learning to detect a fire and trigger a system of sprinklers which aim to increase the humidity content of the soil around the structure as well as the structure itself. 
Information input is made through a humidity sensor, a thermometer, a gas detector, a smoke detector as well as a camera that recognizes flammes through machine learning to trigger the sprinkler system.


## How we built it
_Mechanical Prototype_

Our mechanical prototype is a representation of a pump-driven sprinkler system uses a single motor to pressurize and distribute water through a network of pipes to sprinkler heads. Our prototype is made up of pieces of a Arduino Kit and various recycled materials we collected at this event which include: soda can, stickers, and cardboard. Our prototype uses mentos/hard candies as a representation of water. The prototype collects the "water" in the top reservoir passes through the system getting directed into the sprinkler system. The pump is made with one DC motor directs the "water" through the reservoir. It's then released into our "sprinkler system" consisting of a track that aims the "water" at the fire threat. 

_Electrical Architecture_ 
Our system controlled by an Arduino 101 is connecting every component of our circuit through a breadboard and simple wiring. Most sensors that are at the center of the system allow for simple functionning needing to be only linked up in parallel between our voltage source and the ground. All 4 sensors are using analog transmission to transmit the data collected to the arduino that will use this situational informations to take better decision for fire prevention. The circuit is also powering a DC motor which simulates what would a sprinkler do in the case of detecting a fire. Proper wiring was added through diode, multiple resistive load and transistor to ensure proper power was given to the motor while still mainting a control on voltage and current passing through the microcontroller to ensure the Arduino's functionning. A simple button acting as an emergency break is also added to simulate the owner of the system that could notice either a misread from the model or anything of the sort to avoid unnecessary water damage to a strucuture. Finally, the Bluetooth module which is already incorporated within the microcontroller is also used for effective wireless communication between a machine-learning computer that is helping to detect visual possibilities of fire and the arduino who will receive those informations and combined them with its sensors to decide on the better mode of action going forward.

_Software_
We built an end-to-end wildfire detection system by fine-tuning a custom YOLOv8-nano model on a public Roboflow dataset, combining real-time camera feeds with multi-sensor fusion (temperature, smoke, and air quality sensors) to achieve high accuracy with low latency. We chose the nano since it is lightweight and due to our lack of nice GPUs it would have taken a few hours to train the other models. The system triggers an Arduino-controlled water pump via Bluetooth. Looking ahead, we aim to incorporate satellite imagery and weather data to predict fire risk zones, shifting from reactive firefighting to proactive prevention.

## Challenges we ran into
Because our project uses quite a lot of robotics and hardware (by hackathon standards), the materials available to us were very limited so we had to get creative and recycle with what was available to us such as an aluminium can, an old tape roll, stickers used as tape, a recycled plastic bottle and more. We faced a lot of problems when it came to the programming of our Arduino. Initially, our system was not able to properly upload any types of code we were builiding to our Arduino unit due to flashing time delays. However, through proper resetting of our microcontroller as well as more efficient organisations, the problem was resolved allowing us to upload working component of our code to the system. The bluetooth component of our system also faced some issues that we assumed was somewhat related to the interferences and the amount of people coding at the same time as us but we were still able to make something out of it.

## Accomplishments that we're proud of
Being able to successfully recognize flames with a machine learning model as well as compiling that data with the input from the arduino sensors to more accurately trigger sprinkler kits and get less false positives. This was our first time working with arduinos and it was incredibly fun to integrate hardware, embedded systems with machine learning in our hack. It did also come with its own host of challenges 


## What's next for TARTOKK
Considering wildfires are an increasingly relevant issue, TARTOKK could expand by adding a hose to the kit, and using the same machine learning, point the hose in the direction of the blaze, helping fire fighters and limiting property damage.
