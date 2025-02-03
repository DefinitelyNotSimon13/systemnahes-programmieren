#include "devices/random.h"
#include "devices/uart.h"
#include "devices/timer.h"

#include <stdbool.h>


static void timerTest( void );

int main( void )
{

  uart_init();
  uart_writeLine( "Hello World!\n" );

  timerTest();
}

static void timerTest( void )
{
  timer_init( TIMER0 );

  timer_captureCompareSet( TIMER0, CC0, 0, false );

  timer_start( TIMER0 );

  timer_capture( TIMER0, CC0 );

  const uint32_t captureValue = timer_captureCompareGet( TIMER0, CC0 );

  uart_writeUint8( captureValue );
}
