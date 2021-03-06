/*******************************************************************************
Copyright (C) 2017 Marvell International Ltd.

Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

* Neither the name of Marvell nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/
#ifndef __MV_PCA953X_H__
#define __MV_PCA953X_H__

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

#include <Protocol/Gpio.h>

#include <Uefi/UefiBaseType.h>

#define GPIO_SIGNATURE           SIGNATURE_32 ('I', 'O', 'E', 'X')

#define PCA_INT                  0x0100
#define MAX_BANK                 5
#define BANK_SZ                  8
#define PCA_GPIO_MASK            0x00FF

#define READ                     0x1
#define WRITE                    0x0

#define PCA95XX_INPUT            0
#define PCA95XX_OUTPUT           1
#define PCA95XX_INVERT           2
#define PCA95XX_DIRECTION        3

#define MVHW_MAX_IOEXPANDER_DEVS 2

#define PCA95XX_MASK             0x1

/*
 * I2C_FLAG_NORESTART is not part of PI spec, it allows to continue
 * transmission without repeated start operation.
 * FIXME: This flag is also defined in Drivers/I2c/MvI2cDxe/MvI2cDxe.h
 * and it's important to have both version synced. This solution is
 * temporary and shared flag should be used by both files.
 */
#define I2C_FLAG_NORESTART      0x00000002

#define I2C_DEVICE_INDEX(bus, address) (((address) & 0xffff) | (bus) << 16)

typedef struct {
  UINTN  ID;
  UINT16 data;
} IOEXPANDER_INFO;

typedef enum {
  PCA95XX_DIRECTION_IN  = 0x00,
  PCA95XX_DIRECTION_OUT = 0x01
} IOEXPANDER_DIRECTION;

typedef enum {
  NXP_PCA9505 = 0x00,
  NXP_PCA9534 = 0x01,
  NXP_PCA9535 = 0x02,
  NXP_PCA9536 = 0x03,
  NXP_PCA9537 = 0x04,
  NXP_PCA9538 = 0x05,
  NXP_PCA9539 = 0x06,
  NXP_PCA9554 = 0x07,
  NXP_PCA9555 = 0x08,
  NXP_PCA9556 = 0x09,
  NXP_PCA9557 = 0x0A
} MARVELL_IOEXPANDER_ID;

typedef struct {
  BOOLEAN                 Enabled;
  UINTN                   IOExpanderI2CAddress;
  UINTN                   IOExpanderI2CBuses;
  UINTN                   PinCount;
  UINTN                   Invert;
  UINTN                   BankCount;
  MARVELL_IOEXPANDER_ID   ChipId;
} MV_IOEXPANDER_CONTROLLER_DESC;

typedef struct {
  MARVELL_GPIO_PROTOCOL         IOExpanderProtocol;
  EFI_I2C_IO_PROTOCOL           *I2cIo;
  MV_IOEXPANDER_CONTROLLER_DESC IOExpanderControllerDesc[MVHW_MAX_IOEXPANDER_DEVS];
  UINTN                         Signature;
  EFI_HANDLE                    ControllerHandle;
  EFI_LOCK                      Lock;
} MV_IOEXPANDER;

#endif
