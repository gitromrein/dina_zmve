#pragma once

#define CSEEP_Pin GPIO_PIN_13
#define CSEEP_GPIO_Port GPIOC
#define CSANZ1_Pin GPIO_PIN_14
#define CSANZ1_GPIO_Port GPIOC
#define CSANZ2_Pin GPIO_PIN_15
#define CSANZ2_GPIO_Port GPIOC
#define X0_Pin GPIO_PIN_0
#define X0_GPIO_Port GPIOH
#define X1_Pin GPIO_PIN_1
#define X1_GPIO_Port GPIOH
#define FM_ADR_OUT_Pin GPIO_PIN_10
#define FM_ADR_OUT_GPIO_Port GPIOE
#define SPI_SCK_Pin GPIO_PIN_10
#define SPI_SCK_GPIO_Port GPIOB
#define FM_ADR_IN_Pin GPIO_PIN_11
#define FM_ADR_IN_GPIO_Port GPIOB
#define SPI_MISO_Pin GPIO_PIN_14
#define SPI_MISO_GPIO_Port GPIOB
#define SPI_MOSI_Pin GPIO_PIN_15
#define SPI_MOSI_GPIO_Port GPIOB
#define DBG_TX_Pin GPIO_PIN_8
#define DBG_TX_GPIO_Port GPIOD
#define DBG_RX_Pin GPIO_PIN_9
#define DBG_RX_GPIO_Port GPIOD
#define IPK_SYNC_Pin GPIO_PIN_15
#define IPK_SYNC_GPIO_Port GPIOD
#define CONP_TX_Pin GPIO_PIN_9
#define CONP_TX_GPIO_Port GPIOA
#define CONP_RX_Pin GPIO_PIN_10
#define CONP_RX_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define TDI_Pin GPIO_PIN_15
#define TDI_GPIO_Port GPIOA
#define V24_TX_Pin GPIO_PIN_10
#define V24_TX_GPIO_Port GPIOC
#define V24_RX_Pin GPIO_PIN_11
#define V24_RX_GPIO_Port GPIOC
#define TDO_Pin GPIO_PIN_3
#define TDO_GPIO_Port GPIOB
#define TRST_Pin GPIO_PIN_4
#define TRST_GPIO_Port GPIOB
#define IPK_RX_Pin GPIO_PIN_5
#define IPK_RX_GPIO_Port GPIOB
#define IPK_TX_Pin GPIO_PIN_6
#define IPK_TX_GPIO_Port GPIOB

void MX_GPIO_Init();
void MX_FDCAN1_Init();
void MX_FDCAN2_Init();
void MX_SPI2_Init();
void MX_UART4_Init();
void MX_UART5_Init();
void MX_USART1_UART_Init();
void MX_USART3_UART_Init();

void BoardInit();

