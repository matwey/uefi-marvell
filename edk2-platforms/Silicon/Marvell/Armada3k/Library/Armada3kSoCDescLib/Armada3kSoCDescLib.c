/**
*
*  Copyright (C) 2018, Marvell International Ltd. and its affiliates.
*  Copyright (C) 2019, Matwey V. Kornilov <matwey.kornilov@gmail.com>
*
*  This program and the accompanying materials are licensed and made available
*  under the terms and conditions of the BSD License which accompanies this
*  distribution. The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#include <Uefi.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/BoardDesc.h>


EFI_STATUS
EFIAPI
ArmadaSoCDescApBaseGet (
  IN OUT UINT64  *ApBase,
  IN UINT8        ApNr
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescComPhyGet (
  IN OUT MV_SOC_COMPHY_DESC  **ComPhyDesc,
  IN OUT UINT8                *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

UINTN
EFIAPI
ArmadaSoCDescCpBaseGet (
  IN UINTN        CpIndex
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescFuseGet (
  IN OUT MV_SOC_FUSE_DESC  **FuseDesc,
  IN OUT UINTN              *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescGpioGet (
  IN OUT MVHW_GPIO_DESC **GpioDesc
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescI2cGet (
  IN OUT MV_SOC_I2C_DESC  **I2cDesc,
  IN OUT UINT8             *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescIcuGet (
  IN OUT MV_SOC_ICU_DESC  **IcuDesc
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescMdioGet (
  IN OUT MV_SOC_MDIO_DESC  **MdioDesc,
  IN OUT UINT8             *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescAhciGet (
  IN OUT MV_SOC_AHCI_DESC  **AhciDesc,
  IN OUT UINT8             *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

//
// Platform description of SDMMC controllers
//
#define MV_SOC_MAX_SDMMC_COUNT     2
#define MV_SOC_SDMMC_BASE(Index)   ((Index) == 0 ? 0xD00D8000 : 0xD00D0000)

EFI_STATUS
EFIAPI
ArmadaSoCDescSdMmcGet (
  IN OUT MV_SOC_SDMMC_DESC  **SdMmcDesc,
  IN OUT UINT8               *DescCount
  )
{
  MV_SOC_SDMMC_DESC *Desc;
  UINT8 Index;

  Desc = AllocateZeroPool (MV_SOC_MAX_SDMMC_COUNT * sizeof (MV_SOC_SDMMC_DESC));
  if (Desc == NULL) {
    DEBUG ((DEBUG_ERROR, "%a: Cannot allocate memory\n", __FUNCTION__));
    return EFI_OUT_OF_RESOURCES;
  }

  for (Index = 0; Index < MV_SOC_MAX_SDMMC_COUNT; Index++) {
    Desc[Index].SdMmcBaseAddress = MV_SOC_SDMMC_BASE (Index);
    Desc[Index].SdMmcMemSize = SIZE_1KB;
    Desc[Index].SdMmcDmaType = NonDiscoverableDeviceDmaTypeNonCoherent;
  }

  *SdMmcDesc = Desc;
  *DescCount = MV_SOC_MAX_SDMMC_COUNT;

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescXhciGet (
  IN OUT MV_SOC_XHCI_DESC  **XhciDesc,
  IN OUT UINT8              *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescPp2Get (
  IN OUT MV_SOC_PP2_DESC  **Pp2Desc,
  IN OUT UINT8             *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescUtmiGet (
  IN OUT MV_SOC_UTMI_DESC  **UtmiDesc,
  IN OUT UINT8              *DescCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
ArmadaSoCDescPcieGet (
  IN OUT UINT8    *DevCount,
  IN OUT UINTN   **PcieRegBase
  )
{
  return EFI_UNSUPPORTED;
}
