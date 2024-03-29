/**
  ******************************************************************************
  * @file    SENSING1_config.h
  * @author  Central LAB
  * @version V2.2.0
  * @date    12-April-2019
  * @brief   FP-AI-SENSING1 configuration
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
#ifndef __SENSING1_CONFIG_H
#define __SENSING1_CONFIG_H

/* Exported define ------------------------------------------------------------*/

#define STM32_NUCLEO
#define NN_GMP

/* For enabling SD card Log feature */
#ifndef STM32_NUCLEO
  #define SENSING1_ENABLE_DATA_LOGGING
#endif /* STM32_NUCLEO */

/**************************************
 *      Debug section defines         *
***************************************/

/* For enabling the printf on UART */
#ifdef STM32_SENSORTILE

  /* Enabling this define for SensorTile..
   * it will introduce a delay of 10Seconds before starting the application
   * for having time to open the Terminal
   * for looking the SENSING1 Initialization phase */
  #ifndef SENSING1_ENABLE_DATA_LOGGING
    //#define SENSING1_ENABLE_PRINTF
  #endif /* SENSING1_ENABLE_DATA_LOGGING */

#else /* STM32_SENSORTILE */

  /* For Nucleo&IoT01A1 it's enabled by default */
  #define SENSING1_ENABLE_PRINTF

#endif /* STM32_SENSORTILE */


/* Uncomment the following define for disabling power management for debug */
#ifdef USE_STM32L475E_IOT01
  #define DISABLE_PM
#endif /* USE_STM32L475E_IOT01 */

/**************************************
 *  Lab/Experimental section defines  *
***************************************/

/* For enabling connection and notification subscriptions debug */
//#define SENSING1_DEBUG_CONNECTION

/* Define the SENSING1 MAC address, otherwise it will create a Unique MAC */
//#define MAC_SENSING1 0xFF, 0xEE, 0xAA, 0xAA, 0xAA, 0xAA

#ifndef MAC_SENSING1
/* For creating one MAC related to STM32 UID, Otherwise the BLE will use it's random MAC */
  //#define MAC_STM32UID_SENSING1
#endif /* MAC_SENSING1 */

#ifdef NN_IGN_WSDM
   /* For HAR_IGN_WSDM play back mode (use test vectors instead of sensors) */
  // #define TEST_IGN_WSDM
#endif /* NN_IGN_WSDM */

#ifdef STM32_NUCLEO
  #ifdef NN_ASC
    /* For using USB Audio in instead of Microphones */
    // #define ASC_USE_USB_AUDIO
  #endif /* NN_ASC */
#endif /* STM32_NUCLEO */

/* Uncomment the following define for changing the default BLE Advertise Interval
 * This define will reduce the Power Consumption but will increase the board discovery section.
 * It's necessary to use the latest Android/iOS application. */
#ifndef SENSING1_BlueNRG2 
  /* For BlueNRG-1 must be defined */
  #define BLE_CHANGE_ADV_INTERVAL
#endif /* SENSING1_BlueNRG2 */

/* Uncomment the following define for forcing a full BLE rescan for the Android/iOS "ST BLE Sensor" application*/
#define BLE_FORCE_RESCAN

/* Uncomment the following define for reading the Environmental sensors with a Single shot 
 * modality instead of Continuous mode */
#define ONE_SHOT

//#define BLE_LINK_ADAPT

/**************************************
 * Don't Change the following defines *
***************************************/

/* Package Version only numbers 0->9 */
#define SENSING1_VERSION_MAJOR '2'
#define SENSING1_VERSION_MINOR '2'
#define SENSING1_VERSION_PATCH '0'

/* Define The transmission interval [mSec] for Microphones dB Values */
#define MICS_DB_UPDATE_MS 50

/* Define The transmission interval [mSec] for Environmental Measures and Battery Informations */
#define ENV_UPDATE_MS 500

/* Define The transmission interval [mSec] for Inertial Measures */
#define INERTIAL_UPDATE_MS 50

/* Define Inertial Acquisition interval [mSec] for Activity Recognition */
#if (defined(NN_GMP) || defined(NN_IGN) || defined (NN_IGN_WSDM))
  #define NN_HAR
#endif
#if (defined(NN_GMP)) 
  #define HAR_ALG_ID                (1)
  #define INERTIAL_ACQ_ACTIVITY_MS  (38) /*26Hz*/
#elif (defined(NN_IGN))
  #define HAR_ALG_ID                (1)
  #define INERTIAL_ACQ_ACTIVITY_MS  (38) /*26Hz*/
#elif (defined (NN_IGN_WSDM))            
  #define HAR_ALG_ID                (2)
  #define INERTIAL_ACQ_ACTIVITY_MS  (50) /*20Hz*/
#endif


/* Define the SENSING1 Name MUST be 7 char long */
#if defined(STM32_SENSORTILE)
  #define NAME_BLUEMS 'T','A','I','_',SENSING1_VERSION_MAJOR,SENSING1_VERSION_MINOR,SENSING1_VERSION_PATCH  
#elif defined(STM32_NUCLEO)
  #define NAME_BLUEMS 'N','A','I','_',SENSING1_VERSION_MAJOR,SENSING1_VERSION_MINOR,SENSING1_VERSION_PATCH
#elif defined(USE_STM32L475E_IOT01)
  #define NAME_BLUEMS 'I','A','I','_',SENSING1_VERSION_MAJOR,SENSING1_VERSION_MINOR,SENSING1_VERSION_PATCH
#else
#error "Write Something here"
#endif /* STM32_SENSORTILE */

/* Package Name */
#define SENSING1_PACKAGENAME "AI-SENSING1"

#if defined(STM32_NUCLEO)
  #define AUDIO_VOLUME_VALUE       64

#elif defined(STM32_SENSORTILE)
 /* for having the AUDIO_SAMPLING_FREQUENCY */
  #include "SensorTile_conf.h"
  #define AUDIO_VOLUME_VALUE       32
#elif defined(USE_STM32L475E_IOT01)
 /* for having the AUDIO_SAMPLING_FREQUENCY */
  #include "stm32l475e_iot01_conf.h"
  #define AUDIO_VOLUME_VALUE       32
#else
  #error "Define the right platform"
#endif /* STM32_NUCLEO */
  #define PCM_AUDIO_IN_SAMPLES     AUDIO_SAMPLING_FREQUENCY/1000

#ifdef SENSING1_ENABLE_PRINTF
  #ifdef STM32_SENSORTILE
    extern char PrintfBufferToWrite[256];
    #include "usbd_cdc_interface.h"
    #define SENSING1_PRINTF(...) {\
      int32_t TmpBytesToWrite;\
      TmpBytesToWrite = sprintf( PrintfBufferToWrite, __VA_ARGS__);\
      CDC_Fill_Buffer(( uint8_t * )PrintfBufferToWrite, TmpBytesToWrite);\
    }
  #else /* STM32_SENSORTILE */
    #define SENSING1_PRINTF(...) printf(__VA_ARGS__)
  #endif /* STM32_SENSORTILE */
#else /* SENSING1_ENABLE_PRINTF */
  #define SENSING1_PRINTF(...)  
#endif /* SENSING1_ENABLE_PRINTF */

#ifdef USE_STM32L475E_IOT01
#define USE_USB_MSC
#endif /* USE_STM32L475E_IOT01 */

/* STM32 Unique ID */
#define STM32_UUID ((uint32_t *)0x1FFF7590)

/* STM32 MCU_ID */
#define STM32_MCU_ID ((uint32_t *)0xE0042000)



#endif /* __SENSING1_CONFIG_H */

/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
