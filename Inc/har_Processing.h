/**
  ******************************************************************************
  * @file    har_Processing.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    12-April-2019
  * @brief   API defined on har_Processing.c file
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
#ifndef _HAR_PROCESSING_H_
#define _HAR_PROCESSING_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  __INT16_TYPE__ x;
  __INT16_TYPE__ y;
  __INT16_TYPE__ z;
} MOTION_SENSOR_Axes;


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#if defined(STM32_SENSORTILE)
  #include "SensorTile_motion_sensors.h"

#elif defined(USE_STM32L475E_IOT01)
  #include "stm32l475e_iot01_motion_sensors.h"
#endif /* STM32_SENSORTILE */

#include "SENSING1_config.h"

/* Exported define ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
 typedef struct
{
  float AccX;           /*  acc x axes [g]  */
  float AccY;           /*  acc y axes [g]  */
  float AccZ;           /*  acc z axes [g]  */
} HAR_input_t;  

typedef enum 
{
    HAR_NOACTIVITY          = 0x00,  
    HAR_STATIONARY          = 0x01,
    HAR_WALKING             = 0x02,
    HAR_FASTWALKING         = 0x03,
    HAR_JOGGING             = 0x04,
    HAR_BIKING              = 0x05,
    HAR_DRIVING             = 0x06,
    HAR_STAIRS              = 0x07
} HAR_output_t;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#if (defined(NN_IGN))
#define AR_ID_STATIONARY  (uint8_t)(0x03)
#define AR_ID_WALKING     (uint8_t)(0x04)
#define AR_ID_JOGGING     (uint8_t)(0x02)
#define AR_ID_BIKING      (uint8_t)(0x00)
#define AR_ID_DRIVING     (uint8_t)(0x01)
#elif (defined (NN_IGN_WSDM)) 
#define AR_ID_STATIONARY  (uint8_t)(0x02)
#define AR_ID_WALKING     (uint8_t)(0x03)
#define AR_ID_JOGGING     (uint8_t)(0x00)
#define AR_ID_STAIRS      (uint8_t)(0x01)
#elif (defined (NN_GMP))  
#define AR_ID_STATIONARY  (uint8_t)(0x00)
#define AR_ID_WALKING     (uint8_t)(0x01)
#define AR_ID_JOGGING     (uint8_t)(0x02)
#define AR_ID_BIKING      (uint8_t)(0x03)
#define AR_ID_DRIVING     (uint8_t)(0x04)
#endif
#define AR_ID_NONE        (uint8_t)(0xFF)

/** @defgroup NN_AR_Exported_Functions NN_AR_Exported_Functions
 * @{
 */

/* Exported functions ------------------------------------------------------- */


/**
 * @brief  Initialize the MotionAR engine
 * @param  None
 * @retval 0 in case of success, a negative code otherwise
 */
int8_t  HAR_Initialize(void);

/**
 * @brief  deInitialize the MotionAR engine
 * @param  None
 * @retval None
 */
void HAR_DeInitialize(void);

/**
 * @brief  Run Activity Recognition Algorithm
 * @param  data_in: pointer to the HAR_input_t structure
 * @retval activity index
 */
HAR_output_t HAR_run(MOTION_SENSOR_Axes ACC_Value_Raw);

/**
 * @brief  get latest activity code computes by Recognition Algorithm
 * @param  None
 * @retval activity index
 */
HAR_output_t HAR_get_Activity_Code(void);

/**
 * @brief  Get the library version
 * @param  version pointer to an array of 35 char
 * @retval Number of characters in the version string
 */
uint8_t HAR_GetLibVersion(char *version);


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* HAR_PROCESSING */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
