/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "Os.h"
#include "hal.h"
#include "Led.h"

/*
 * Application entry point.
 */
void main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */
  halInit();

  /*
     * Activates the serial driver 2 using the driver default configuration.
     */
  palSetPadMode(GPIOC, 10, PAL_MODE_ALTERNATE(7));	/* USART3_TX */
  palSetPadMode(GPIOC, 11, PAL_MODE_ALTERNATE(7));	/* USART3_RX */

  Led_Init(10u);
  Led_HeartBeat(LED_ID_USER0, 100u, 2u, 500u);

  /*
   * Creates the threads.
   */
  Os_Init();
  Os_StartTasks();

  chThdExit(0);
}
