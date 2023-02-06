# INC272-2022

> News, Documents, Videos and other resources for INC272 will be provided in this repository.

## Software tools

> All software tools here support only `Windows`.

:computer: [C Compiler for PIC24](https://drive.google.com/file/d/1mMRK2yP8aUkJyvaFYC1r-UxZSfdNbHAL/view?usp=share_link)

:computer: [Command-line tools](https://drive.google.com/file/d/1HcptLDm1Jr9C3ZcTUZ0xkA6xwmZQu60E/view?usp=share_link)

:computer: [Proteus Circuit Simulator](https://drive.google.com/file/d/1JCoA_VTgSp8Er2W_zXdOwLt-b_kVwz9U/view?usp=share_link)

:computer: [Visual Studio Code](https://code.visualstudio.com/)

:computer: [virtual Serial Port Driver](https://drive.google.com/file/d/1BsssBKRG_kqiGHPEpUDhb4jEUfrJd4vf/view?usp=share_link)

---

## Application tools

:computer: [Node-Red](https://drive.google.com/file/d/1p_d-0ay0PSBeXJrkVHCsbGQLnF2-KLK6/view?usp=share_link)

---

## Installation

> Using the instructions in the following documents to install the program

:page_facing_up: [Circuit Simulator Software installation](https://github.com/nitikorn20/INC272-2022/blob/main/Doc/Circuit%20Simulator%20Software%20installation.pdf)

:page_facing_up: [Application Software Installation](https://github.com/nitikorn20/INC272-2022/blob/main/Doc/Application%20Software%20Installation.pdf)

---

## Activation

After the three software tools are installed, the activation process is required.

1. go to `C:\ecc-lab\tools`.

2. run the `ecc-tools-manager-gui.exe` (run it using `run as administrator`), then click `Activate` button.

---

## Code Compilation

To compile the `main.c` to `firmware.hex`, the following steps are required:

1. Right-click on the `main.c` and choose `Open in Integrated Terminal`.

2. Run the command `ecc-pic24-cli -build`.

> The `firmware.hex` will be saved in the `./output` directory.

---

## Simulation

1. Run the `Proteus` using `Run as administrator`.

2. Open the `pic24_board_circuit.pdsprj` saved in the `circuit` directory.

3. Double-click on the MCU, and browse to the `firmware.hex`.

4. Run the simulator and check the result.
