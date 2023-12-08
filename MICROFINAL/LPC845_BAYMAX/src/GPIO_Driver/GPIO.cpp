#include "Defines.h"

Gpio *Gpio::vectorGpios[35] = {};

Gpio::Gpio()
{
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);								// 7 = SWM
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20) | (1 << 18);		// 6 = GPIO0	20 = GPIO1	18 = IOCON
}

Gpio::Gpio(uint32_t _port, uint32_t _pin, uint32_t _direccion)
{
	portpin = _port * 32 + _pin;
	if(vectorGpios[portpin] != nullptr)
		delete vectorGpios[portpin];

	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);								// 7 = SWM
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20) | (1 << 18);		// 6 = GPIO0	20 = GPIO1	18 = IOCON

	port = _port;
	pin = _pin;
	direccion = _direccion;
	estado = 0;
	Dir(direccion);
	vectorGpios[portpin] = this;
}

void Gpio::Set(uint32_t status)
{
	estado = status;
	if(status)
		GPIO->SET[port] = (1 << pin);
	else
		GPIO->CLR[port] = (1 << pin);
}

void Gpio::Dir(uint32_t status)
{
	if(status)
		GPIO->DIRSET[port] = (1 << pin);
	else
		GPIO->DIRCLR[port] = (1 << pin);
}

uint32_t Gpio::Read(void)
{
	if(GPIO->PIN[port] & (1 << pin))
		return 1;
	else
		return 0;
}



int32_t Gpio::IOCON_config_io(uint32_t Indice_PortPin, IOCON_config_t *pin_config)
{
	IOCON_PIO_reg_t *pio_reg;
	IOCON_PIO_reg_t pio_reg_to_write;

	// Mantengo configuraciones de DAC/IIC de haberlas
	pio_reg = (IOCON_PIO_reg_t *)&IOCON->PIO[Indice_PortPin];

	pio_reg_to_write = *pio_reg;

	if(pin_config->iic_mode > 0)
		pio_reg_to_write.I2CMODE = pin_config->iic_mode;

	if(pin_config->dac_mode > 0)
		pio_reg_to_write.DACMODE = pin_config->dac_mode;

	if(pin_config->mode != 0xff)
		pio_reg_to_write.MODE = pin_config->mode & 0x03;

	pio_reg_to_write.HYS = pin_config->hysteresis;
	pio_reg_to_write.INV = pin_config->invert_input;
	pio_reg_to_write.OD = pin_config->open_drain;
	pio_reg_to_write.S_MODE = pin_config->sample_mode;
	pio_reg_to_write.CLK_DIV = pin_config->clk_sel;

	*pio_reg = pio_reg_to_write;

	return IOCON_CONFIG_SUCCESS;
}
