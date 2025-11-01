# Communication System Design  

## Overview
This project demonstrates a simple **communication system design** between two microcontroller units (MCUs) using **IEEE 802.15.4 RF communication**.  
It is designed for a charging network that includes:
- Multiple **Robots (MCU A)** moving around, and  
- Multiple **Charging Stations (MCU B)** that remain stationary.

Robots communicate with stations only when charging is required.  
The system ensures that robots can find available stations, perform a handshake, and exchange real-time data at intervals of less than 100 ms.

## System Procedure
1. Robot and Station do not exchange data when idle.  
2. When charging is required, the Robot searches for an available Station.  
3. The Robot moves to the Station and initiates communication.  
4. Both exchange a **100-byte handshake message** to confirm the session.  
5. They continuously exchange **50-byte real-time messages** every <100 ms.  
6. When charging is complete, the Robot disconnects and the Station becomes available again.
