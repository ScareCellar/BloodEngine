#pragma once

namespace blood {
	class IObserver {
	public:
		virtual ~IObserver();
	
		virtual void OnNotify(const Event& event) = 0;
	};
}