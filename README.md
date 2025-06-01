<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Arduino Project Suite – Embedded Systems in Practice</title>
</head>
<body style="font-family: Arial, sans-serif; line-height: 1.6; padding: 20px; max-width: 900px; margin: auto;">

  <h1>Arduino Project Suite – Embedded Systems in Practice</h1>

  <p>
    A curated collection of practical <strong>Arduino-based embedded systems projects</strong> demonstrating core principles of real-time control, sensor integration, and state-based logic.
    This repository serves as a hands-on reference for students, hobbyists, and professionals interested in embedded programming, IoT development, and Arduino prototyping.
  </p>

  <p>
    Each project in this suite is modular, well-commented, and ideal for learning, experimentation, and adaptation to custom needs.
  </p>

  <hr>

  <h2>🔧 Included Projects</h2>

  <h3>1. Traffic Signal Automation with Pedestrian Crossing</h3>
  <p>
    A real-world simulation of a smart traffic light controller using LEDs and a push-button. Features include:
  </p>
  <ul>
    <li>Car and pedestrian light sequencing (Stop, Ready, Go)</li>
    <li>Debounced pedestrian button handling</li>
    <li>Minimum time window enforcement between button presses</li>
    <li>State-based light transition and LED flashing for walk countdown</li>
  </ul>
  <p><strong>Concepts Covered:</strong> Finite state machines, user input debouncing, timing constraints, real-time task sequencing</p>

  <h3>2. Stepper Motor Control with Button Toggle</h3>
  <p>
    A project demonstrating how to control a stepper motor with precise steps using the <code>Stepper</code> library. Includes:
  </p>
  <ul>
    <li>Toggle control via a button press (start/stop)</li>
    <li>Debounced button input</li>
    <li>Visual status indication using an LED (flashing when idle, solid when running)</li>
  </ul>
  <p><strong>Concepts Covered:</strong> Stepper motor interfacing, button debouncing, feedback indication, simple toggling logic</p>

  <h3>3. Multi-Sensor Temperature Monitoring (1-Wire)</h3>
  <p>
    An advanced example of environmental sensing using multiple DS18B20 digital temperature sensors with the <code>OneWire</code> and <code>DallasTemperature</code> libraries:
  </p>
  <ul>
    <li>Supports up to 2 sensors</li>
    <li>Automatically retrieves and displays sensor addresses</li>
    <li>Detects and displays temperature changes only when values change</li>
    <li>Celsius/Fahrenheit display toggle ready for expansion</li>
  </ul>
  <p><strong>Concepts Covered:</strong> 1-Wire communication, sensor enumeration, change detection, modular sensor handling</p>

  <hr>

  <h2>📚 Key Learnings</h2>
  <ul>
    <li>Embedded control using state machines</li>
    <li>Input handling with software debouncing</li>
    <li>Motor control and real-time task management</li>
    <li>Sensor communication via digital protocols (1-Wire)</li>
    <li>Serial output for debugging and feedback</li>
  </ul>

  <hr>

  <h2>🧰 Requirements</h2>
  <ul>
    <li>Arduino Uno or compatible board</li>
    <li>Arduino IDE</li>
    <li>Common components: LEDs, push-buttons, resistors, DS18B20 sensors, ULN2003 + stepper motor</li>
    <li>Libraries:
      <ul>
        <li><a href="https://www.arduino.cc/en/Reference/Stepper" target="_blank">Stepper</a></li>
        <li><a href="https://www.arduino.cc/reference/en/libraries/onewire/" target="_blank">OneWire</a></li>
        <li><a href="https://www.arduino.cc/reference/en/libraries/dallastemperature/" target="_blank">DallasTemperature</a></li>
      </ul>
    </li>
  </ul>

  <hr>

  <h2>🚀 Getting Started</h2>
  <ol>
    <li>Clone the repository:
      <pre><code>git clone https://github.com/yourusername/arduino-embedded-projects.git
cd arduino-embedded-projects</code></pre>
    </li>
    <li>Open any project <code>.ino</code> file in the Arduino IDE.</li>
    <li>Connect your Arduino board and upload the code.</li>
    <li>Follow the circuit diagrams (to be added soon) for each project.</li>
  </ol>

  <hr>

  <h2>📎 License</h2>
  <p>
    This repository is licensed under the <strong>MIT License</strong>. Feel free to use, modify, and distribute for educational or personal purposes.
  </p>

  <hr>

  <h2>👨‍💻 Contributions</h2>
  <p>
    Pull requests are welcome! If you have improvements, bug fixes, or new project ideas, feel free to contribute.
  </p>

</body>
</html>
