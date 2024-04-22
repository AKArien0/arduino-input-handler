# arduino-input-handler
Script to handle physical input with boards using arduino compilers

Aims to provide an easy way to handle input from physical components.
Currently has :
- A button object
  ```
  Input::Button my_button(int pin);
  my_button.Begin(PINMODE, int debouncing_timer); // I strongly reccomend using INPUT_PULLUP for PINMODE if your board has pins that support it. If you do not, invert the result of the button's interrogating methods.
  my_button.is_pressed();
  my_button.is_just_pressed();
  my_button.is_just_released();
  ```
