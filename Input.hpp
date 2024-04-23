#include <Arduino.h>

namespace Input{

	class Button{
		private:
			volatile int pin;
			volatile bool current_state, last_state;
			volatile unsigned int debounce_time, debounce_last_measure;

		public:
			Button(int set_pin);
			void interrupt_change();
			void begin(int mode, int debounce);
			bool is_pressed();
			bool is_just_pressed();
			bool is_just_released();
			~Button();
	};

	static void interrupt_change_handler(void *p);

}
