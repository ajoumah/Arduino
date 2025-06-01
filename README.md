<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Arduino Project Suite – Embedded Systems in Practice</title>
  <meta name="description" content="A curated collection of Arduino-based embedded systems projects demonstrating real-time control, sensor integration, and state-based logic." />
  <style>
    body {
      font-family: Arial, sans-serif;
      line-height: 1.6;
      max-width: 900px;
      margin: 20px auto;
      padding: 0 20px;
      color: #222;
    }
    h1, h2, h3 {
      color: #333;
    }
    hr {
      margin: 2em 0;
      border: none;
      border-top: 1px solid #ccc;
    }
    pre {
      background-color: #f4f4f4;
      padding: 10px;
      overflow-x: auto;
    }
    a {
      color: #0066cc;
      text-decoration: none;
    }
    a:hover {
      text-decoration: underline;
    }
  </style>
</head>
<body>
  <h1>Arduino Project Suite – Embedded Systems in Practice</h1>

  <p>
    A curated collection of practical <strong>Arduino-based embedded systems projects</strong> demonstrating real-time control, sensor integration, and state-based logic.
    Ideal for learning, prototyping, and showcasing foundational embedded programming techniques.
  </p>

  <hr />

  <h2>Included Projects</h2>

  <section>
    <h3>1. Traffic Signal Automation with Pedestrian Crossing</h3>
    <p>This project simulates a smart traffic light controller using LEDs and a push-button. Features include:</p>
    <ul>
      <li>Car and pedestrian light sequencing (Stop, Ready, Go)</li>
      <li>Debounced pedestrian button handling</li>
      <li>Minimum time window between button presses</li>
      <li>State-based light transitions and LED flashing countdown</li>
    </ul>
    <p><strong>Concepts Covered:</strong> Finite state machines, debouncing, timing constraints, real-time sequencing</p>
  </section>

  <section>
    <h3>2. Stepper Motor Control with Button Toggle</h3>
    <p>Control a stepper motor using the <code>Stepper</code> library with button toggling:</p>
    <ul>
      <li>Start/stop control via button press</li>
      <li>Debounced button input</li>
      <li>LED status indicator (flashing when idle, solid when running)</li>
    </ul>
    <p><strong>Concepts Covered:</strong> Stepper motor interfacing, input debouncing, status indication, toggle logic</p>
  </section>

  <section>
    <h3>3. Multi-Sensor Temperature Monitoring (1-Wire)</h3>
    <p>Use multiple DS18B20 temperature sensors with the <code>OneWire</code> and <code>DallasTemperature</code> libraries:</p>
    <ul>
      <li>Supports up to 2 sensors</li>
      <li>Automatic sensor address retrieval and display</li>
      <li>Change detection to update temperature readings</li>
      <li>Ready for Celsius/Fahrenheit toggle extension</li>
    </ul>
    <p><strong>Concepts Covered:</strong> 1-Wire protocol, sensor enumeration, change detection, modular sensor handling</p>
  </section>

  <hr />

  <h2>Key Learnings</h2>
  <ul>
    <li>State machine based embedded control</li>
    <li>Software input debouncing techniques</li>
    <li>Stepper motor and real-time task management</li>
    <li>Digital sensor communication (1-Wire)</li>
    <li>Serial communication for debugging and feedback</li>
  </ul>

  <hr />

  <h2>Requirements</h2>
  <ul>
    <li>Arduino Uno or compatible board</li>
    <li>Arduino IDE</li>
    <li>Components: LEDs, push-buttons, resistors, DS18B20 sensors, ULN2003 driver board, stepper motor</li>
    <li>Libraries:
      <ul>
        <li><a href="https://www.arduino.cc/en/Reference/Stepper" target="_blank" rel="noopener noreferrer">Stepper</a></li>
        <li><a href="https://www.arduino.cc/reference/en/libraries/onewire/" target="_blank" rel="noopener noreferrer">OneWire</a></li>
        <li><a href="https://www.arduino.cc/reference/en/libraries/dallastemperature/" target="_blank" rel="noopener noreferrer">DallasTemperature</a></li>
      </ul>
    </li>
  </ul>

  <hr />

  <h2>Getting Started</h2>
  <ol>
    <li>Clone this repository:
      <pre><code>git clone https://github.com/ajoumah/Arduino.git
cd Arduino</code></pre>
    </li>
    <li>Open the desired <code>.ino</code> file in Arduino IDE.</li>
    <li>Connect your Arduino board and upload the sketch.</li>
    <li>Refer to the circuit diagrams (coming soon) for wiring details.</li>
  </ol>

  <hr />

  <h2>License</h2>
  <p>This project is licensed under the <strong>MIT License</strong>. Feel free to use, modify, and distribute for personal or educational purposes.</p>

  <hr />

  <h2>Contributions</h2>
  <p>Contributions are welcome! Please submit pull requests with bug fixes, improvements, or new project ideas.</p>
</body>
</html>
