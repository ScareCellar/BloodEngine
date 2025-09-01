#pragma once

namespace blood {
	class IObserver {
		virtual ~IObserver() = default;
	
		virtual void OnNotify() = 0;
	};
}