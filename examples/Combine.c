// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

struct list {
    uint8_t size;
    void* values;
};

static void input_pin12();

static void input_timer();

static void stream_1(uint8_t arg, void* value);

static void stream_5(uint8_t arg, void* value);

static void stream_2(uint8_t arg, void* value);

static void stream_3(uint8_t arg, void* value);

static void stream_4(uint8_t arg, void* value);

static void stream_6(uint8_t arg, void* value);

static void stream_8(uint8_t arg, void* value);

static void stream_7(uint8_t arg, void* value);

static void stream_9(uint8_t arg, void* value);

static void stream_10(uint8_t arg, void* value);

static void input_pin12() {
  bool temp0;
  temp0 = (PINB & (1 << PB4)) == 0U;
  stream_5(0, (void*)(&temp0));
  stream_6(0, (void*)(&temp0));
  stream_9(0, (void*)(&temp0));
}

static void input_timer() {
  uint16_t temp1;
  temp1 = TCNT1;
  TCNT1 = 0;
  stream_1(0, (void*)(&temp1));
}

static void stream_1(uint8_t arg, void* value) {
  static uint16_t input_1 = 0;
  uint16_t temp2;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  if (input_1 > 10000) {
    temp2 = input_1 - 10000 + input_0;
  } else {
    temp2 = input_1 + input_0;
  }
  input_1 = temp2;
  stream_2(0, (void*)(&input_1));
}

static void stream_5(uint8_t arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB5);
  } else {
    PORTB &= ~(1 << PB5);
  }
}

static void stream_2(uint8_t arg, void* value) {
  bool temp3;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  temp3 = false;
  if (input_0 > 10000) {
    temp3 = true;
  }
  if (temp3) {
    stream_3(0, (void*)(&input_0));
  }
}

static void stream_3(uint8_t arg, void* value) {
  static uint16_t input_1 = 0;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  input_1 = input_1 + 1;
  stream_4(0, (void*)(&input_1));
}

static void stream_4(uint8_t arg, void* value) {
  bool temp4;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  temp4 = (input_0) % 2 == 0;
  stream_6(1, (void*)(&temp4));
  stream_8(0, (void*)(&temp4));
}

static void stream_6(uint8_t arg, void* value) {
  bool temp5;
  static bool input_0;
  static bool input_1;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
    case 1:
      input_1 = *((bool*)value);
      break;
  }
  if (input_0) {
    temp5 = input_1;
  } else {
    temp5 = false;
  }
  stream_7(0, (void*)(&temp5));
}

static void stream_8(uint8_t arg, void* value) {
  bool temp6;
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  temp6 = !(input_0);
  stream_9(1, (void*)(&temp6));
}

static void stream_7(uint8_t arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB3);
  } else {
    PORTB &= ~(1 << PB3);
  }
}

static void stream_9(uint8_t arg, void* value) {
  bool temp7;
  static bool input_0;
  static bool input_1;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
    case 1:
      input_1 = *((bool*)value);
      break;
  }
  if (input_0) {
    temp7 = input_1;
  } else {
    temp7 = false;
  }
  stream_10(0, (void*)(&temp7));
}

static void stream_10(uint8_t arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB2);
  } else {
    PORTB &= ~(1 << PB2);
  }
}

int main(void) {
  DDRB &= ~(1 << PB4);
  PORTB |= (1 << PB4);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  DDRB |= (1 << PB2);
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB3);
  while (1) {
    input_pin12();
    input_timer();
  }
  return 0;
}
