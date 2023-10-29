/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */


#include <cr_section_macros.h>

#include <stdio.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) //1.2 led rojo
{
	unsigned int *p;
	unsigned int i;

    p = (unsigned int *)0x40048080; //SYSAHBCLKCTRL0
    *p |= (1 << 6) | (1 << 20);

    p = (unsigned int *)0x40044098;	//IOCON P1_2
    *p = 0;

    p = (unsigned int *)0xA0002384;	//DIR P1_2
    *p = (1 << 2);

    while(1)
    {
        //
    	p = (unsigned int *)0xA0002204;	//SET P1_2
    	*p = (1 << 2);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    	p = (unsigned int *)0xA0002284;	//CLR P1_2
    	*p = (1 << 2);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    }
    return 0 ;
}
