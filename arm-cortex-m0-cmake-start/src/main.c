//
// Created by infohoschie on 09.12.24.
//

#include "random.h"
#include "uart.h"

int main(void)
{
  uart_init();
  rng_init();

  uart_writeLine("Printing number received from rng device...");
  for (;;)
  {
    uint8_t readByte = uart_readByte();
    if (readByte == 0)
    {
      continue;
    } else
    {
      uart_writeByte(readByte);
    }
    // const uint8_t randomNumber = rng_getRandomValue_waiting();
    // uart_writeUint8(randomNumber);
  }
}
