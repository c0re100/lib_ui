// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include "ui/platform/linux/ui_window_linux.h"

#include "ui/platform/linux/ui_linux_wayland_integration.h"

namespace Ui {
namespace Platform {

std::unique_ptr<BasicWindowHelper> CreateSpecialWindowHelper(
		not_null<RpWidget*> window) {
	return nullptr;
}

bool NativeWindowFrameSupported() {
	const auto waylandIntegration = WaylandIntegration::Instance();
	if (waylandIntegration) {
		waylandIntegration->waitForInterfaceAnnounce();
		return waylandIntegration->xdgDecorationSupported();
	}
	return true;
}

} // namespace Platform
} // namespace Ui
