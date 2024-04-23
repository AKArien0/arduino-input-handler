#include "Input.hpp"

namespace Input{

	Button::Button(int set_pin){
		pin = set_pin;
		current_state = false;
		last_state = false;
	}

	void Button::begin(int mode, int debounce){
		pinMode(pin, mode);
		debounce_time = debounce;
		attachInterruptArg(digitalPinToInterrupt(pin), interrupt_change_handler, this, CHANGE);

	}

	void Button::interrupt_change(){
		if (millis() - debounce_last_measure > debounce_time){
			last_state = current_state;
			current_state = !digitalRead(pin);
		}
		debounce_last_measure = millis();
	}

	bool Button::is_pressed(){
		return current_state;
	}

	bool Button::is_just_pressed(){
		if (last_state == false){
			last_state = current_state;
			return is_pressed();
		}
		return false;
	}

	bool Button::is_just_released(){
		if (last_state == true){
			last_state = current_state;
			return !is_pressed();
		}
		return false;
	}

	Button::~Button(){
		detachInterrupt(pin);
	}

	void IRAM_ATTR interrupt_change_handler(void *p){
		Button *bt = (Button*) p;
		bt->interrupt_change();
	}

}
