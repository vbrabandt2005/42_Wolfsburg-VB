# Push_Swap Visualizer-Forked

This is a Fork of [Emmanuel Ruaud (o-reo)'s ](https://github.com/o-reo) [Push_Swap_Visualizer](https://github.com/o-reo/push_swap_visualizer) intended for incorperated testing and demonstration of Push_Swap.

## Usage

- If you've relocated your push_swap program, simply update the visualizer's menu directory from "../../push_swap" to the new path of your push_swap program. For instance, "../../new_directory/push_swap".

- In the **Values** window
  - Choose the size of the push swap input with the slider [Optional]
  - **Shuffle** the input [Optional]
  - The space separated values should be filled automatically, you can also put your own values
  - Set the Push Swap program path (Absolute or relative path).
  - **Compute** the sort commands, it will display OK when done.
- In the **Controls** window
  - **Load** the commands in the visualizer
  - **Start** the animation
  - Adjust the **Speed** as needed
  - **Pause** and go **Step** by step to see the details of your algorithm.
  - **Load** to restart the animation

![Push_Swap_Visualizer](https://i.imgur.com/zqcsZfY.png)

## Requirements

This project uses C++17, cmake, SFML and ImGui.

- Install required packages (if not already installed)
  For Debian-based systems, you can install the necessary packages using the following commands:

```bash
sudo apt-get update
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install clang
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
sudo apt-get install libx11-dev libxrandr-dev
sudo apt-get install libudev-dev
sudo apt-get install libfreetype-dev
```

## License

[Emmanuel Ruaud (o-reo)'s ](https://github.com/o-reo) [Push_Swap_Visualizer](https://github.com/o-reo/push_swap_visualizer) was originally licensed as GPL-3.0, as my 42_Wolfsburg-VB is also GPL-3.0, that means these two projects should be compatible.

