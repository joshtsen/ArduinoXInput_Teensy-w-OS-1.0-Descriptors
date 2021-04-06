#ifndef _usb_os_desc_h_
#define _usb_os_desc_h_

#include <stdint.h>

// More information on these definitions can be found in the Microsoft OS 1.0 Descriptor Specification
// https://docs.microsoft.com/en-us/windows-hardware/drivers/usbcon/microsoft-os-1-0-descriptors-specification

typedef struct usb_os_string_descriptor{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint8_t qwSignature[14]; // should probably be uint16_t [7] since the string is utf16
  uint8_t bMS_VendorCode;
  uint8_t bPad; 
} usb_os_string_descriptor;

typedef struct usb_extended_compat_id_function_block{
  uint8_t bFirstInterfaceNumber;
  uint8_t bRESERVED0;
  uint8_t compatibleID[8];
  uint8_t subCompatibleID[8];
  uint8_t bRESERVED1[6];
} usb_extended_compat_id_function_block;

typedef struct usb_extended_compat_id_descriptor{
  uint32_t dwLength;
  uint16_t bcdVersion;
  uint16_t wIndex;
  uint8_t bCount;
  uint8_t reserved[7];
  usb_extended_compat_id_function_block function_blocks[];
} usb_extended_compat_id_descriptor;

extern const usb_extended_compat_id_descriptor usb_extended_compat_id_desc;

// I have not fully tested the extended properties descriptor yet but
// some people may find need for them

typedef struct usb_extended_propert_name{
  uint16_t bPropertyNameLength;
  uint8_t bPropertyName[];
} usb_extended_property_name;

typedef struct usb_extended_property_data{
  uint32_t dwPropertyDataLength;
  uint8_t bPropertyData[];
} usb_extended_property_data;

typedef struct usb_extended_property_section{
  uint32_t dwSize;
  uint32_t dwPropertyDataType;
  usb_extended_property_name bPropertyName;
  usb_extended_property_data bPropertyData;
} usb_extended_property_section;

typedef struct usb_extended_properties_descriptor{
  uint32_t dwLength;
  uint16_t bcdVersion;
  uint16_t wIndex;
  uint16_t wCount;
  usb_extended_property_section custom_properties;
} usb_extended_properties_descriptor;

extern const usb_extended_properties_descriptor usb_extended_properties_desc;

// Should not be used unless the device supports high speed mode
// Teensy3 devices do not support high speed mode
typedef struct usb_device_qualifier_descriptor{
  uint8_t bLength;
  uint8_t bDescriptorType;
  uint16_t bcdUSB;
  uint8_t bDeviceClass;
  uint8_t bDeviceSubClass;
  uint8_t bDeviceProtocol;
  uint8_t bMaxPacketSize;
  uint8_t bNumConfigurations;
  uint8_t bReserved;
} usb_device_qualifier_descriptor;

#endif // _usb_os_desc_h_


