/**
  ******************************************************************************
  * @file    TargetFeatures.h 
  * @author  Central LAB
  * @version V2.2.0
  * @date    12-April-2019
  * @brief   Specification of the HW Features for each target platform
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/  
#ifndef _TARGET_FEATURES_H_
#define _TARGET_FEATURES_H_

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"

#include "SENSING1_config.h"

#ifndef STM32_NUCLEO
#define STM32_NUCLEO

#endif

#if defined(STM32_NUCLEO)

  #include "stm32f4xx_hal_conf.h"
  #include "stm32f4xx_hal_uart.h"
 // #include "stm32f4xx_periph_conf.h"
 // #include "iks01a2_env_sensors.h"
  #ifdef ONE_SHOT
   // #include "iks01a2_env_sensors_ex.h"
  #endif /* ONE_SHOT */
  /*#include "iks01a2_motion_sensors.h"
  #include "iks01a2_motion_sensors_ex.h"
  #include "x_nucleo_cca02m1_audio_patch.h"*/
#elif defined(STM32_SENSORTILE)

  #include "SensorTile.h"
  #include "stm32l4xx_hal_conf.h"
  #include "stm32l4xx_hal_def.h"
  #include "hci_tl_interface.h"
  #include "SensorTile_env_sensors.h"
  #ifdef ONE_SHOT
    #include "SensorTile_env_sensors_ex.h"
  #endif /* ONE_SHOT */
  #include "SensorTile_motion_sensors.h"
  #include "SensorTile_motion_sensors_ex.h"
  #include "SensorTile_gg.h"
  #include "SensorTile_audio.h"
  #include "SensorTile_sd.h"

#elif defined(USE_STM32L475E_IOT01)

  #include "stm32l475e_iot01.h"
  #include "stm32l475e_iot01_audio.h"
  #include "stm32l4xx_hal_conf.h"
  #include "stm32l4xx_hal_def.h"
  #include "hci_tl_interface.h"
  #ifdef SENSING1_ENABLE_PRINTF
     extern UART_HandleTypeDef hcom_uart[COMn];
     #define UartHandle (hcom_uart[COM1])
  #endif /* SENSING1_ENABLE_PRINTF */
  #include "stm32l475e_iot01_env_sensors.h"
  #ifdef ONE_SHOT
    #include "stm32l475e_iot01_env_sensors_ex.h"
  #endif /* ONE_SHOT */
  #include "stm32l475e_iot01_motion_sensors.h"
#else 
  #error "Define the right platform"
#endif /* STM32_NUCLEO */

//#include "MetaDataManager.h"

#include "har_Processing.h"
//#include "asc.h"

/* Exported defines ------------------------------------------------------- */
#define MAX_TEMP_SENSORS 2
/* @brief  Scale factor. It is used to scale acceleration from mg to g */ 
#define FROM_MG_TO_G    (0.001F)
/* @brief  Scale factor. It is used to scale acceleration from g to m/s2 */ 
#define FROM_G_TO_MS_2   (9.800655F)

/* @brief  Check Values for understanding if one MEMS Sensor is present or Not */ 
#define SENSING1_SNS_NOT_VALID 9999

/* Exported macros ------------------------------------------------------- */

/* Exported types ------------------------------------------------------- */
/**
 * @brief  Target type data definition
 */
typedef enum
{
  TARGET_NUCLEO,
  TARGET_SENSORTILE,
  TARGET_IOT01A1,
  TARGETS_NUMBER
} TargetType_t;

/**
 * @brief  Target's Features data structure definition
 */
typedef struct
{
  TargetType_t BoardType;
  int32_t NumTempSensors;

  uint32_t HandleTempSensors[MAX_TEMP_SENSORS];
  uint32_t HandlePressSensor;
  uint32_t HandleHumSensor;

  uint32_t HandleAccSensor;
  uint32_t HandleGyroSensor;
  uint32_t HandleMagSensor;

  float DefaultAccODR;
  float DefaultGyroODR;
  float DefaultMagODR;

  float AccSensiMultInG;

  int32_t NumMicSensors;

#ifdef STM32_SENSORTILE
  void *HandleGGComponent;
#endif /* STM32_SENSORTILE */

  uint32_t AudioVolume;
  uint8_t EnvSensorEnabled;
} TargetFeatures_t;

/* Exported variables ------------------------------------------------------- */
extern TargetFeatures_t TargetBoardFeatures;

/* Exported functions ------------------------------------------------------- */
extern void InitTargetPlatform(TargetType_t BoardType);

extern void InitMics(uint32_t AudioFreq);
extern void DeInitMics(void);

extern void InitUSBAudio(void);
extern void DeInitUSBAudio(void);

extern void InitUSBMSC(void);
extern void DeInitUSBMSC(void);

extern void LedOnTargetPlatform(void);
extern void LedOffTargetPlatform(void);
extern void LedToggleTargetPlatform(void);

extern void EnableEnvSensors (void);
extern void DisableEnvSensors (void);
extern void EnableMotionSensors (void);
extern void DisableMotionSensors (void);

extern uint32_t GetPage(uint32_t Address);
extern uint32_t GetBank(uint32_t Address);

#ifdef __cplusplus
}
#endif

#endif /* _TARGET_FEATURES_H_ */

/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

