# Teensy XInput + Composite Devices

This is an extension of Dave Madison's [ArduinoXInput library](https://github.com/dmadison/ArduinoXInput) which supports the [Microsoft OS 1.0 Descriptors](https://docs.microsoft.com/en-us/windows-hardware/drivers/usbcon/microsoft-os-1-0-descriptors-specification). This specification defines three new descriptors: the Extended Compat ID OS Descriptor, Extended Properties OS Descriptor and the Genre Descriptor (not used here).

The Extended Compat ID OS Descriptor allows defining a specific compatibleID for each interface or function group of a device. When there is no VID:PID driver match, the compatibleID is used to find a potential match. In the context of XInput, this allows assignment of the XUSB driver without the need for hijacking the VID:PID of an official Microsoft controller. It also allows assignment of the XUSB driver to a specific interface or group of interfaces. Thus, XInput + Keyboard, XInput + Serial, or XInput + DirectInput composite devices are possible.

There are also compatibleIDs to match WINUSB, LIBUSB0, LIBUSBK and more. Additionally, the Extended Properties descriptor can be used to define properties of various types including REG_SZ, REG_LINK, and REG_MULTI_SZ. These can reflect any device specific property such as a DeviceInterfaceGUID or an icon. The Extended Properties Descriptor is implemented here but not used.

See these links to find out more about the driver selection process:

 * [Enumeration of USB Devices](https://techcommunity.microsoft.com/t5/microsoft-usb-blog/how-does-usb-stack-enumerate-a-device/ba-p/270685)
 * [Enumeration of Composite Devices](https://docs.microsoft.com/en-us/windows-hardware/drivers/usbcon/enumeration-of-the-composite-parent-device)
 
Simpler explanation of Windows Compatible ID (WCID):

 * [https://github.com/pbatard/libwdi/wiki/WCID-Devices](https://github.com/pbatard/libwdi/wiki/WCID-Devices)
 
## Installation

See [original repository](https://github.com/dmadison/ArduinoXInput) and then replace the necessary files.

## Customization

#### Creating Your Own Composite Device

TODO

#### Adjusting the CompatID Descriptor

TODO

## License

The original Teensy core files and their modified versions are licensed under a modified version of the permissive [MIT license](https://opensource.org/licenses/MIT). Newly contributed files are licensed under the MIT license with no additional stipulations.

See the [LICENSE](LICENSE.txt) file for more information.
