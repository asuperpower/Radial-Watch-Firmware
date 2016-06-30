/*+===================================================================
  File:     pins.c

  Summary:  Pin Interface for the ARM Freescale K20.
            View ""PeripheralsPart1.pdf" in docs folder for more
            info.

            Ports are Memory Mapped starting at address 0x400FF000

  Author:   Quaker762

  Revision History:
            29/6/16: Intial Revision

----------------------------------------------------------------------
  Copyright 2016 Radial Technologies, Pty Ltd
===================================================================+*/
#include <stdint.h>

// This is here so we don't have to pass around variables and constants everywhere.
// Much neater have access to everything in one convenient struct
typedef struct
{
    // IO Port A
    uint32_t GPIOA_PDOR;    // Port Data Output Register
    uint32_t GPIOA_PSOR;    // Port Set Output Register
    uint32_t GPIOA_PCOR;    // Port Clear Output Register
    uint32_t GPIOA_PTOR;    // Port Toggle Output Reigster
    uint32_t GPIOA_PDIR;    // Port Data Input Reigster
    uint32_t GPIOA_PDDR;    // Port Data Output Register

    // IO Port B
    uint32_t GPIOB_PDOR;    // Port Data Output Register
    uint32_t GPIOB_PSOR;    // Port Set Output Register
    uint32_t GPIOB_PCOR;    // Port Clear Output Register
    uint32_t GPIOB_PTOR;    // Port Toggle Output Reigster
    uint32_t GPIOB_PDIR;    // Port Data Input Reigster
    uint32_t GPIOB_PDDR;    // Port Data Output Register

    // IO Port C
    uint32_t GPIOC_PDOR;    // Port Data Output Register
    uint32_t GPIOC_PSOR;    // Port Set Output Register
    uint32_t GPIOC_PCOR;    // Port Clear Output Register
    uint32_t GPIOC_PTOR;    // Port Toggle Output Reigster
    uint32_t GPIOC_PDIR;    // Port Data Input Reigster
    uint32_t GPIOC_PDDR;    // Port Data Output Register

    // IO Port D
    uint32_t GPIOD_PDOR;    // Port Data Output Register
    uint32_t GPIOD_PSOR;    // Port Set Output Register
    uint32_t GPIOD_PCOR;    // Port Clear Output Register
    uint32_t GPIOD_PTOR;    // Port Toggle Output Reigster
    uint32_t GPIOD_PDIR;    // Port Data Input Reigster
    uint32_t GPIOD_PDDR;    // Port Data Output Register

    // IO Port E
    uint32_t GPIOE_PDOR;    // Port Data Output Register
    uint32_t GPIOE_PSOR;    // Port Set Output Register
    uint32_t GPIOE_PCOR;    // Port Clear Output Register
    uint32_t GPIOE_PTOR;    // Port Toggle Output Reigster
    uint32_t GPIOE_PDIR;    // Port Data Input Reigster
    uint32_t GPIOE_PDDR;    // Port Data Output Register
} GPIO;

static GPIO* pins = (GPIO*)0x400FF000;

