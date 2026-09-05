AquaGuardian: Smart Water Drinking Reminder System

-> Project Overview:
    AquaGuardian is an embedded-based smart water drinking reminder system developed using an ARM7/LPC21xx microcontroller.
    The system helps the user maintain regular water-drinking habits by providing reminders at configured intervals. It uses an RTC to keep track of time and provides information to the user through an LCD display. A keypad is used for user interaction and configuration.
    The system also keeps track of the number of glasses consumed, remaining glasses, and missed reminders.

-> Objective:
    The main objective of AquaGuardian is to develop a simple embedded system that:
    - Reminds the user to drink water at regular intervals.
    - Allows the user to configure water consumption targets.
    - Tracks the number of glasses consumed.
    - Tracks missed drinking opportunities.
    - Displays the current status clearly on an LCD.
    - Provides a simple keypad-based user interface for editing and also for configuring.

-> Hardware Used:
    - ARM7/LPC21xx - Microcontroller
    - 16×2 LCD
    - Matrix Keypad
    - Buzzer
    - LEDs
    - Switchs

-> Software:
    - Embedded C
    - ARM7/LPC21xx

-> Features:
    1. RTC-Based Time Display
        The RTC provides:
        - Hours
        - Minutes
        - Seconds
        - Date
        - Day of the week
        The current time and date are displayed on the LCD.
    2. Water Drinking Reminder
        - AquaGuardian generates a reminder when the configured drinking interval is reached.
        - The reminder uses the system's notification hardware such as the buzzer and LED indicators.
    3. Water Intake Tracking
        - The system keeps track of the number of glasses consumed by the user.
        - The LCD displays the current consumption status.
    4. Target Glass Configuration
        - The user can configure a target number of glasses using the keypad.
    5. Remaining Glass Count
        - The system calculates the number of glasses remaining to reach the configured target.
    6. Missed Reminder Count
        - If the user does not take water during a reminder opportunity, the system records the reminder as missed.
    7. Keypad-Based User Interface
        The keypad is used to:
        - Navigate through the menu.
        - Enter numeric values.
        - Configure the target.
        - Configure reminder-related settings.
        - Edit selected values.
    8. External Interrupt
        - An external interrupt is used to enter the configuration/menu mode from the normal display operation.

->LCD Information:
    During normal operation, the LCD provides information such as:
      - Current time
      - Date
      - Day
      - Percentage of target completed
      - Number of glasses taken
      - Target number of glasses
      - Remaining glasses
      - Missed reminders

-> "src":
    - Contains the C source files implementing the project functionality.

-> "include":
    - Contains the header files, declarations, macros, and project definitions used by the source files.

-> Main Modules:
    Module - Purpose
    - "project_main.c"| Main program entry point and initialization
    - "display_mode.c"| Normal LCD display and reminder checking
    - "remainder.c"| Water reminder and drink/missed handling
    - "Init_RTC.c"| RTC initialization
    - "Init_block.c"| GPIO/output initialization
    - "Init_int.c"| External interrupt initialization
    - "Init_mode_isr.c"| Menu/configuration handling
    - "KPM.c"| Keypad scanning and numeric input.

-> Future Improvements:
    Possible future improvements include:
    - User-configurable reminder duration.
    - Pre-reminder notification.
    - Improved menu navigation.
    - More robust reminder scheduling.
    - Daily statistics and automatic daily reset.
    - Improved power management.
    - Additional user settings.
    - Improved non-blocking interrupt/state-machine design.

-> Project Purpose:
    This project was developed as an embedded systems project to practice and demonstrate:
    - Embedded C programming
    - ARM7/LPC21xx microcontroller programming
    - GPIO interfacing
    - LCD interfacing
    - Keypad interfacing
    - RTC programming
    - External interrupt handling
    - Modular embedded software development.

->  Project:
    - AquaGuardian: Smart Water Drinking Reminder System
    - Developed as an embedded systems project using ARM7/LPC21xx.
