#include "EnginePCH.h"
#include "EventManager.h"
#include "Source/Core/StringHelper.h"
#include "Event/Observer.h"

namespace blood {
	void EventManager::AddObserver(const Event::id_t& id, IObserver& observer) {
		m_observers[toLower(id)].push_back(&observer);
	}
	void EventManager::RemoveObserver(IObserver& observer) {
		IObserver* observerPtr = &observer;

		for (auto& eventType : m_observers) {
			auto& observers = eventType.second;
			std::erase_if(observers, [observerPtr](auto observer) {
				return (observer == observerPtr);
			});
		}
	}
	void EventManager::Notify(const Event& event) {
		auto iter = m_observers.find(event.id);
		if (iter != m_observers.end()) {
			auto& observers = iter->second;
			for (auto& observer : observers) {
				observer->OnNotify(event);
			}
		}
		else {
			Logger::Warning("could not find event: {}", event);
		}
	}
}
