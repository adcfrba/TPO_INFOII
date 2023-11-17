#include "Defines.h"

uint8_t data[192];
uint8_t buffer[50];
uint8_t SpO2;
uint32_t red = 0, ir = 0;

uint8_t MAX30102( void )
{
	static uint8_t estado = 0;
	uint8_t rd, wr, i, ov, status1, status2;
	int32_t samples;


	switch( estado )
	{
	case 0:
		//Init
		if( MAX30102InitialConfig() == 0 )
		{
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 1;
		}

		break;

	case 1:
		if( !GetDemora_IIC() )
		{

		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_INT_STATUS_1);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		status1 = IIC_Read(NO_ACK);
		IIC_Stop();

		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_INT_STATUS_2);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		status2 = IIC_Read(NO_ACK);
		IIC_Stop();

		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_WR_PTR);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		wr = IIC_Read(NO_ACK);
		IIC_Stop();

		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_OV_PTR);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		ov = IIC_Read(NO_ACK);
		IIC_Stop();

		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_RD_PTR);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		rd = IIC_Read(NO_ACK);
		IIC_Stop();

		samples = rd - wr;
		if( ov >= 0xF )
		{
			ov = 0;
		}
		if(samples < 0)
			samples +=MAX30102_SAMPLE_LEN_MAX;
/*
		if( wr == 0xFF )
			samples = 0;

 	 	//Lectura de toda la FIFO
 		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_DATA);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		if( samples )
		{	for(i = 0; i < samples*MAX30102_BYTES_PER_SAMPLE; i ++ )	//cada muestra es de 6 bytes
			{
				data[i] = IIC_Read(ACK);
			}
		}
		else
		{
			for(i = 0; i < 6; i ++ )	//cada muestra es de 6 bytes
			{
				data[i] = IIC_Read(ACK);
			}
		}
		IIC_Stop();

		if( samples )
		{
			for(i = 0; i < samples; i ++ )
			{
				red += (data[(i*MAX30102_BYTES_PER_SAMPLE)]<<16) | (data[(i*MAX30102_BYTES_PER_SAMPLE)+1]<<8) | data[(i*MAX30102_BYTES_PER_SAMPLE)+2];
				ir += (data[(i*MAX30102_BYTES_PER_SAMPLE)+3]<<16) | (data[(i*MAX30102_BYTES_PER_SAMPLE)+4]<<8) | data[(i*MAX30102_BYTES_PER_SAMPLE)+5];
			}
		}
		else
		{
			//red = (data[0]<<16) | (data[1]<<8) | data[2];      // Last IR reflectance datapoint
			//ir = (data[3]<<16) | (data[4]<<8) | data[5];     // Last Red reflectance datapoint
			//red &= 0x03FFFF;
			//ir &= 0x03FFFF;
			red = 0;
			ir = 0;
		}

		if( samples )
		{
			red /= samples;
			ir /= samples;
			red &= 0x03FFFF;
			ir &= 0x03FFFF;
		}

*/

		//Lectura macaca
 		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_DATA);
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS | 1);
		for(i = 0; i < 6; i ++ )	//cada muestra es de 6 bytes
		{
			data[i] = IIC_Read(ACK);
		}
		IIC_Stop();

		red = (data[0]<<16) | (data[1]<<8) | data[2];      // Last IR reflectance datapoint
		ir = (data[3]<<16) | (data[4]<<8) | data[5];     // Last Red reflectance datapoint
		red &= 0x03FFFF;
		ir &= 0x03FFFF;

		SpO2 = update(ir,red);
        /*
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_FIFO_RD_PTR);
		IIC_Write(0);	//Ver esto
		IIC_Stop();
		*/
		/*if( samples )
		{
			sprintf((char *)buffer, "RED: %d - IR: %d wr=%d rd=%d ov=%d st1=%d st2=%d\n", red, ir, wr, rd, ov, status1, status2);
			UART1_Send(buffer, strlen((char *)buffer));
		}*/




		estado = 2;
		}
		break;
	case 2:
		if( GetFlagLecturaMAX30102( ) )
		{
			SetFlagLecturaMAX30102( 0 );
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 1;
		}
		break;
	case 3:

		break;
	case 4:

		break;
	default:
		break;
	}
	return SpO2;
}

void MAX30102ResetPointers( void )
{
	IIC_Start();
	IIC_Write(MAX30102_PHY_ADDRESS);
	IIC_Write(MAX30102_FIFO_WR_PTR);
	IIC_Write(0);
	IIC_Stop();

	IIC_Start();
	IIC_Write(MAX30102_PHY_ADDRESS);
	IIC_Write(MAX30102_FIFO_OV_PTR);
	IIC_Write(0);
	IIC_Stop();

	IIC_Start();
	IIC_Write(MAX30102_PHY_ADDRESS);
	IIC_Write(MAX30102_FIFO_RD_PTR);
	IIC_Write(0);
	IIC_Stop();
}

uint8_t MAX30102InitialConfig( void )
{
	static uint8_t estado = 0;

	switch( estado )
	{
	case 0:
		IIC_Start();
		IIC_Write(MAX30102_PHY_ADDRESS);
		IIC_Write(MAX30102_MODE_CONFIG);
		IIC_Write(0x40);		//Reset
		IIC_Stop();
		SetDemora_IIC(IIC_DELAY_30ms);
		estado = 1;
		break;

	case 1:
		if( !GetDemora_IIC() )
		{
			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_INT_EN_1);
			IIC_Write(0x80);		//Almost full enable
			IIC_Stop();

			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_INT_EN_2);
			IIC_Write(0x00);		//
			IIC_Stop();

			MAX30102ResetPointers( );
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 2;
		}
		break;

	case 2:
		if( !GetDemora_IIC() )
		{
			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_MODE_CONFIG);
			IIC_Write(0x03);		//SpO2 Red and IR
			IIC_Stop();
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 3;
		}
		break;


	case 3:
		if( !GetDemora_IIC() )
		{
			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_SPO2_CONFIG);
			//IIC_Write(0x7);	//ADC resolution 18 bits, 100 samples per second, pulse 411us, fullscale 2048
			IIC_Write(0x00);	//ADC resolution 15 bits, 50 samples per second, pulse 69us, fullscale 2048
			//IIC_Write(0x0F);	//ADC resolution 18 bits, 400 samples per second, pulse 411us
			IIC_Stop();
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 4;
		}
		break;

	case 4:
		if( !GetDemora_IIC() )
			{
				IIC_Start();
				IIC_Write(MAX30102_PHY_ADDRESS);
				IIC_Write(MAX30102_LED1_PA);
				IIC_Write(MAX30102_LED_PA_10mA);
				IIC_Stop();
				SetDemora_IIC(IIC_DELAY_ms);
				estado = 5;
			}
			break;



	case 5:
		if( !GetDemora_IIC() )
		{
			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_LED2_PA);
			IIC_Write(MAX30102_LED_PA_10mA);
			IIC_Stop();
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 6;
		}
		break;

	case 6:
		if( !GetDemora_IIC() )
		{
			IIC_Start();
			IIC_Write(MAX30102_PHY_ADDRESS);
			IIC_Write(MAX30102_FIFO_CONFIG);
			IIC_Write(0xE0);	//32 muestras promedio, rollover on
			//IIC_Write(0);	//
			IIC_Stop();
			SetDemora_IIC(IIC_DELAY_ms);
			estado = 7;
		}
		break;

	case 7:
		estado = 0;
		break;


	default:
		estado = 0;
		break;


	}

	return estado;
}
