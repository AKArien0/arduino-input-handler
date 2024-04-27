# arduino-input-handler
Script to handle physical input with boards using arduino compilers

Aims to provide an easy way to handle input from physical components.
Currently has :
- A button object
  ```
  Input::Button my_button(int pin);
  my_button.Begin(PINMODE, int debouncing_timer); /* I strongly reccomend using INPUT_PULLUP for PINMODE
                                                  if your board has pins that support it or make the
                                                  pullup circuit yourself. If you do not, the result
                                                  of the button's interrogating methods are inverted.
                                        Example : bool real_state = !my_buttton.is_pressed();
                                                  bool actually_just_pressed = my_button.is_just_released();
                                                  bool actually_just_released = my_button.is_just_pressed();
  my_button.is_pressed();
  my_button.is_just_pressed();
  my_button.is_just_released();
  ```
