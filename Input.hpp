#include <Arduino.h>

namespace Input{

	static void interrupt_change_handler(void *p);

	class Button{
		private:
			volatile int pin;
			volatile bool current_state, last_state;

		public:
			Button(int set_pin);
			void interrupt_change();
			void begin();
			bool is_pressed();
			bool is_just_pressed();
			bool is_just_released();
			~Button();
	};

}
