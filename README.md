**AquaGuardian: Smart Water Drinking Reminder System**

**📌 Overview**

AquaGuardian is an ARM7/LPC21xx-based embedded system designed to remind users to drink water at regular intervals and track daily water intake.

The system uses the LPC21xx internal RTC to maintain time, a 16×2 LCD for displaying information, a 4×4 matrix keypad for user configuration, and a drink-detection switch to record water intake by using LEDs confirmation.

The system keeps track of the user's:

- Water drinking target
- Water consumed
- Remaining quantity
- Missed reminders
- Completion percentage

---

**🎯 Objective**

The main objective of AquaGuardian is to develop a simple embedded water reminder system that combines:

- RTC-based time management
- Periodic drinking reminders
- User-configurable settings
- Water intake detection
- LCD-based status monitoring
- Keypad-based user interaction
- Visual with LEDs and audible using BUZZER notifications

---

**⚙️ Key Features**

| Feature | Description |
|---|---|
| RTC Clock | Displays the current time and date using the LPC21xx internal RTC |
| Water Reminder | Generates a reminder when the configured reminder time is reached |
| Water Detection | Detects whether the user has taken water using a switch |
| Target Setting | Allows the user to configure the required water target |
| Intake Tracking | Maintains the amount of water consumed |
| Remaining Count | Displays the remaining amount required to reach the target |
| Missed Count | Records reminders that were not answered |
| Percentage | Displays the percentage of the target completed |
| Keypad Menu | Provides user interaction and configuration |
| External Interrupt | Opens the configuration/menu interface |
| LCD Display | Displays time, date, reminder and water statistics |
| Buzzer | Provides an audible reminder |
| LEDs | Indicates the status of water intake/reminder events |

---

**🧩 System Architecture**

The main controller of the system is the ARM7/LPC21xx microcontroller.

Inputs

- LPC21xx Internal RTC
- 4×4 Matrix Keypad
- External Interrupt Button
- Drink Detection Button

Outputs

- 16×2 LCD
- Buzzer
- Yellow LED
- Green LED
- Red LED

The overall working flow is:

RTC → Reminder Check → User Notification → Drink Detection → Update Statistics → LCD Display

---

**🔌 Hardware Connections**

**LCD Interface**

The 16×2 LCD uses an 8-bit data interface.

| LCD Signal| LPC21xx Connection|
|---|---|
|D0| P0.8|
|D1| P0.9|
|D2| P0.10|
|D3| P0.11|
|D4| P0.12|
|D5| P0.13|
|D6| P0.14|
|D7| P0.15|
|RS| P0.16|
|EN| P0.17|

---

**4×4 Matrix Keypad**

The keypad uses four row lines and four column lines.

|Keypad Signal| LPC21xx Connection|
|---|---|
|Row 1| P1.16|
|Row 2| P1.17|
|Row 3| P1.18|
|Row 4| P1.19|
|Column 1| P1.20|
|Column 2| P1.21|
|Column 3| P1.22|
|Column 4| P1.23|

---

**Control and Indicator Connections**

|Device| LPC21xx Pin| Function |
|---|---|---|
|External Interrupt Button| P0.1| Opens the configuration/menu interface|
|Drink Detection Button| P0.20| Detects water intake|
|Buzzer| P0.21| Audible reminder|
|Yellow LED| P0.4| Reminder/status indication|
|Green LED| P0.22| Successful water intake indication|
|Red LED| P0.23| Missed reminder indication|

The external interrupt button and drink detection button are active-low inputs.

---

**🖥️ Display Information**

The LCD is used to present both real-time information and water-drinking statistics.

The system can display:

Information| Purpose|
|---|---|
|Time| Current RTC time|
|Date| Current RTC date|
|Day| Current day of the week|
|Completion %| Percentage of target completed|
|Taken| Quantity of water consumed|
|Target| Configured water target|
|Remaining| Quantity still required|
|Missed| Number of missed reminders|
|Reminder Message| Notification when it is time to drink water|

---

**🔄 Working Principle**

1. The LPC21xx initializes the RTC, LCD, keypad, GPIO and external interrupt.
2. The RTC continuously maintains the current time and date.
3. The main program monitors the configured reminder condition.
4. When a reminder is due, the system activates the reminder indication.
5. The LCD displays a water-drinking reminder.
6. The user operates the drink detection button after taking water.
7. If water intake is detected, the consumed quantity is updated.
8. If the reminder is not answered, the missed count is incremented.
9. The LCD continuously updates the water-drinking statistics.
10. The keypad and external interrupt provide access to the configuration/menu interface.

---

**## 🧩 Block Diagram**

```
                    ┌───────────────────────┐
                    │    ARM7 / LPC21xx     │
                    │    Microcontroller    │
                    │                       │
                    │     Internal RTC      │
                    └───────────┬───────────┘
                                │
              ┌─────────────────┼─────────────────┐
              │                 │                 │
              ▼                 ▼                 ▼
      ┌──────────────┐  ┌──────────────┐  ┌──────────────┐
      │     4×4      │  │  External    │  │    Drink     │
      │    Keypad    │  │  Interrupt   │  │  Detection   │
      │              │  │    Button    │  │    Button    │
      └──────┬───────┘  └──────┬───────┘  └──────┬───────┘
             │                 │                 │
             └─────────────────┼─────────────────┘
                               │
                               ▼
                    ┌───────────────────────┐
                    │   System Processing   │
                    │                       │
                    │ Reminder Management   │
                    │ Water Intake Tracking │
                    │ Target / Remaining    │
                    │ Missed Count          │
                    └───────────┬───────────┘
                                │
              ┌─────────────────┼─────────────────┐
              │                 │                 │
              ▼                 ▼                 ▼
      ┌──────────────┐   ┌──────────────┐  ┌──────────────┐
      │   16×2 LCD   │   │    Buzzer    │  │ Status LEDs  │
      │              │   │              │  │              │
      │ Time / Date  │   │  Reminder    │  │ Yellow       │
      │ Target       │   │ Notification │  │ Green        │
      │ Taken        │   └──────────────┘  │ Red          │
      │ Remaining    │                     └──────────────┘
      │ Missed       │
      │ Completion % │
      └──────────────┘
---
