# SERAPH

**Seraph – Open-Source Teensy MIDI Controller Platform**  
Welcome to Seraph!

Seraph is an open platform for developing Teensy-based MIDI controllers and interactive musical interfaces. This repository provides a PCB design and sample demo code to help you build and customize your own MIDI devices.

---

### What's Inside?

This repository includes:

- **Seraph PCB design** – A hardware platform for connecting various sensors and controls.  
- **Demo code** – Examples showcasing how to interface different sensors with the Seraph PCB.  
- **Customization support** – Easily modify the code to suit your specific project needs.  

---

### Quick Start

1. **Solder your Teensy to the board**  
   ◦ Use headers instead of soldering the Teensy directly to the PCB.  
   ◦ This allows you to easily remove and reuse your Teensy for future projects.  

2. **Install the required library**  
   ◦ Most of our demo code uses the Teensy USBMIDI library.  
   ◦ Download it via the Arduino Library Manager before running the code.  

3. **Set your board mode**  
   ◦ Ensure your Teensy is in Serial + MIDI mode in the Arduino IDE.  
   ◦ This allows your computer to recognize it as a MIDI device.  

4. **Upload and experiment!**  
   ◦ Flash the code to your Teensy and start exploring interactive MIDI control.  

---

### Get Creative!

Seraph is designed to be flexible and open-ended. Whether you're building a MIDI controller, sound-reactive installation, or experimental music interface, this platform is here to support your creativity.

**Have fun and make something amazing!**

![Seraph Screenshot](https://i.imgur.com/n9ZP12J.png)
