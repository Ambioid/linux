/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef __LINUX_ACTUATOR_H
#define __LINUX_ACTUATOR_H
#include <linux/hid.h>

#define APPLE_HP_WAVEFORMDEEPCLICK	0x000e2001


#if IS_ENABLED(CONFIG_HID_APPLE_HAPTIC)
int apple_taptic_send(struct hid_device *hdev, u16 effect_type, u8 strength, u8 softness);
int apple_taptic_switch_modes(struct hid_device *hdev, bool currently_host_controlled);

#else
static inline int apple_taptic_send(struct hid_device *hdev, u16 effect_type,
				    u8 strength, u8 softness) { return -ENODEV; }
static inline int apple_taptic_switch_modes(struct hid_device *hdev,
				     bool enable_host_controlled) { return -ENODEV; }
#endif
#endif /* __LINUX_ACTUATOR_H */
