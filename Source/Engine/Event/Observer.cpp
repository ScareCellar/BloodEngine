#include "Observer.h"

namespace sc {
	sc::IObserver::~IObserver() {
		EventManager::Instance().RemoveObserver(*this);
	}
}