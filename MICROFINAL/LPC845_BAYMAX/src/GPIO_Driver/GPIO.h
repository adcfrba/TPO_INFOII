#ifndef GPIO_DRIVER_GPIO_H_
#define GPIO_DRIVER_GPIO_H_

#define CANT_GPIOS			35
#define	GPIO_INPUT			0
#define	GPIO_OUTPUT			1
#define	GPIO_ON				0
#define	GPIO_OFF			1

#define		ESTADO_1			1
#define		ESTADO_0			0
#define		ESTADO_AMBOS		2
#define		ESTADO_DESACTIVADO	0xFF

#define		IOCON_CONFIG_SUCCESS					0
#define		IOCON_CONFIG_IOCON_NOT_CLOCKED			-1
#define		IOCON_CONFIG_INVALID_PORT				-2
#define		IOCON_CONFIG_INVALID_PIN				-3
#define		IOCON_CONFIG_INVALID_PORTPIN			-4



/* IOCON - Peripheral instance base addresses */
/** Peripheral IOCON base address */
#define IOCON_BASE                               (0x40044000u)
/** Peripheral IOCON base pointer */
#define IOCON                                    ((IOCON_Type *)IOCON_BASE)
/** Array initializer of IOCON peripheral base addresses */
#define IOCON_BASE_ADDRS                         { IOCON_BASE }
/** Array initializer of IOCON peripheral base pointers */
#define IOCON_BASE_PTRS                          { IOCON }

#define    IOCON_INDEX_PIO0_17       ( 0)
#define    IOCON_INDEX_PIO0_13       ( 1)
#define    IOCON_INDEX_PIO0_12       ( 2)
#define    IOCON_INDEX_PIO0_5        ( 3)
#define    IOCON_INDEX_PIO0_4        ( 4)
#define    IOCON_INDEX_PIO0_3        ( 5)
#define    IOCON_INDEX_PIO0_2        ( 6)
#define    IOCON_INDEX_PIO0_11       ( 7)
#define    IOCON_INDEX_PIO0_10       ( 8)
#define    IOCON_INDEX_PIO0_16       ( 9)
#define    IOCON_INDEX_PIO0_15       (10)
#define    IOCON_INDEX_PIO0_1        (11)
#define    IOCON_INDEX_PIO0_9        (13)
#define    IOCON_INDEX_PIO0_8        (14)
#define    IOCON_INDEX_PIO0_7        (15)
#define    IOCON_INDEX_PIO0_6        (16)
#define    IOCON_INDEX_PIO0_0        (17)
#define    IOCON_INDEX_PIO0_14       (18)
#define    IOCON_INDEX_PIO0_28       (20)
#define    IOCON_INDEX_PIO0_27       (21)
#define    IOCON_INDEX_PIO0_26       (22)
#define    IOCON_INDEX_PIO0_25       (23)
#define    IOCON_INDEX_PIO0_24       (24)
#define    IOCON_INDEX_PIO0_23       (25)
#define    IOCON_INDEX_PIO0_22       (26)
#define    IOCON_INDEX_PIO0_21       (27)
#define    IOCON_INDEX_PIO0_20       (28)
#define    IOCON_INDEX_PIO0_19       (29)
#define    IOCON_INDEX_PIO0_18       (30)
#define    IOCON_INDEX_PIO1_8        (31)
#define    IOCON_INDEX_PIO1_9        (32)
#define    IOCON_INDEX_PIO1_12       (33)
#define    IOCON_INDEX_PIO1_13       (34)
#define    IOCON_INDEX_PIO0_31       (35)
#define    IOCON_INDEX_PIO1_0        (36)
#define    IOCON_INDEX_PIO1_1        (37)
#define    IOCON_INDEX_PIO1_2        (38)
#define    IOCON_INDEX_PIO1_14       (39)
#define    IOCON_INDEX_PIO1_15       (40)
#define    IOCON_INDEX_PIO1_3        (41)
#define    IOCON_INDEX_PIO1_4        (42)
#define    IOCON_INDEX_PIO1_5        (43)
#define    IOCON_INDEX_PIO1_16       (44)
#define    IOCON_INDEX_PIO1_17       (45)
#define    IOCON_INDEX_PIO1_6        (46)
#define    IOCON_INDEX_PIO1_18       (47)
#define    IOCON_INDEX_PIO1_19       (48)
#define    IOCON_INDEX_PIO1_7        (49)
#define    IOCON_INDEX_PIO0_29       (50)
#define    IOCON_INDEX_PIO0_30       (51)
#define    IOCON_INDEX_PIO1_20       (52)
#define    IOCON_INDEX_PIO1_21       (53)
#define    IOCON_INDEX_PIO1_11       (54)
#define    IOCON_INDEX_PIO1_10       (55)


typedef enum
{
	PULL_NONE = 0,
	PULL_DOWN,
	PULL_UP,
	PULL_REPEATER
}IOCON_pull_mode_en;

typedef enum
{
	SAMPLE_MODE_BYPASS = 0,
	SAMPLE_MODE_1_CLOCK,
	SAMPLE_MODE_2_CLOCK,
	SAMPLE_MODE_3_CLOCK
}IOCON_sample_mode_en;

typedef enum
{
	IOCON_CLK_DIV_0 = 0,
	IOCON_CLK_DIV_1,
	IOCON_CLK_DIV_2,
	IOCON_CLK_DIV_3,
	IOCON_CLK_DIV_4,
	IOCON_CLK_DIV_5,
	IOCON_CLK_DIV_6
}IOCON_clk_sel_en;

typedef enum
{
	IIC_MODE_STANDARD = 0,
	IIC_MODE_GPIO,
	IIC_MODE_FAST_MODE
}IOCON_iic_mode_en;

typedef struct
{
	IOCON_pull_mode_en mode;
	uint8_t hysteresis;
	uint8_t invert_input;
	uint8_t open_drain;
	IOCON_sample_mode_en sample_mode;
	IOCON_clk_sel_en clk_sel;
	uint8_t dac_mode;
	IOCON_iic_mode_en iic_mode;
}IOCON_config_t;

typedef struct
{
	uint32_t RESERVED_1 : 3;
	uint32_t MODE : 2;
	uint32_t HYS : 1;
	uint32_t INV : 1;
	uint32_t I2CMODE : 2;
	uint32_t RESERVED_2 : 1;
	uint32_t OD : 1;
	uint32_t S_MODE : 2;
	uint32_t CLK_DIV : 3;
	uint32_t DACMODE : 1;
	uint32_t RESERVED_3 : 15;
}IOCON_PIO_reg_t;


class Gpio {

public:
	Gpio();
	Gpio(uint32_t port, uint32_t pin, uint32_t direccion);
	void Set(uint32_t status);
	void Dir(uint32_t direccion);
	uint32_t Read(void);
	int32_t IOCON_config_io(uint32_t Indice_PortPin, IOCON_config_t *pin_config);
	static Gpio *vectorGpios[CANT_GPIOS];

protected:
	uint32_t port, pin, direccion, estado, portpin;

};

#endif /* GPIO_DRIVER_GPIO_H_ */
