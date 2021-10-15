# CO2VOCMonitoring
CO2 AND VOC Monitoring through Nuclio Serverless platform
the best way to address the previously mentioned problem is to detect and monitor those environmental factors which triggers these diseases , therefore the purpose of this project is to detect and sense carbondioxide and Volatile Organic Compound Values from the environment and monitor those values on an independent platform since such a system will allow doctors and clinicians to correlate potential asthma symptoms and exacerbation reports from patients with environmental factors without having to personally be present.

CO2VOCMonitoring is a simple function made for  [Nuclio](https://nuclio.io/), an open source and managed serverless platform that we can run on our home server. It uses  [RabbitMQ](https://www.rabbitmq.com/)  as broker to share MQTT messages around. It also consist of Mobile Application  [MQTIZER](https://play.google.com/store/apps/details?id=com.sanyamarya.mqtizermqtt_client&hl=en&gl=US)  to check Mqtt messages on Mobile Application for the Web based application we install [MQTTLENS](https://chrome.google.com/webstore/detail/mqttlens/hemojaaeigabkbcookmlgmdigohjobjm)   the CO2 and VOC values can now be viewed  on web app as well.



Prerequisite

-   [Docker](https://www.docker.com/)
-   [Nuclio](https://nuclio.io/)
-   [RabitMQ](https://www.rabbitmq.com/)
-   [Arduino IDE](https://www.arduino.cc/en/software)
-   MQTIZER
- MQTTLENS

Instructions

 Clone this repository, then you need to start a Docker to start up a docker instance of Nuclio, use this command on nuclio:

`$ sudo docker run -p 8070:8070 -v /var/run/docker.sock:/var/run/docker.sock -v /tmp:/tmp nuclio/dashboard:stable-amd64`

And to start up a docker instance of RabbitMQ, use the following command:

`$ sudo docker run -p 9000:15672 -p 1883:1883 -p 5672:5672 cyrilix/rabbitmq-mqtt`

MQTIZER is a mobile MQTT client that can connect to any broker which shares the network with your phone, and to any broker on the cloud as well To show Message on Mobile App download Mobile App MQTIZER than Add the Broker on the app having same Ip as RabbitMQ. Now you will be able to see messages on Mobile Application and for the Web APP Download the Google Chrome extension called "MQTT Lens" add the host ip , username and password subscribe to it then it will show the notifications of the CO2 AND VOC values

### [](https://github.com/Sarmad302/-Smoke-Detection-Serverless-Computing/blob/main/README.md#technologies-used)Technologies used

-   [Docker](https://www.docker.com/)
-   [Nuclio](https://nuclio.io/)
-   [RabitMQ](https://www.rabbitmq.com/)
-   [Arduino IDE](https://www.arduino.cc/en/software)
-   MQTIZER
- MQTTLENS

### [](https://github.com/Sarmad302/-Smoke-Detection-Serverless-Computing/blob/main/README.md#libraries--used)Libraries used

[ESP8266WiFi]

The ESP8266WiFi library provides a wide collection of C++ methods (functions) and properties to configure and operate an ESP8266 module in station and / or soft access point mode.

[Pubsub Client]

A client library for MQTT messaging. MQTT is a lightweight messaging protocol ideal for small devices. This library allows you to send and receive MQTT messages

CCS811 Sensor Library 
This is an Arduino library. It implements a driver for the CCS811. This chip is a indoor air quality sensor module with an I2C interface.
