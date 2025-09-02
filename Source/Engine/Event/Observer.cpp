#include "Observer.h"

namespace blood {
	blood::IObserver::~IObserver() {
		EventManager::Instance().RemoveObserver(*this);
	}
}