#include "EnginePCH.h"
#include "EventManager.h"
#include "Source/Core/StringHelper.h"
#include "Event/Observer.h"

#define OBSERVER_ADD(event_id)				blood::EventManager::Instance().AddObserver(#event_id, *this)
#define OBSERVER_REMOVE_SELF				blood::EventManager::Instance().RemoveObserver(*this)
#define EVENT_NOTIFY_DATA(event_id, data)	blood::EventManager::Instance().Notify({ #event_id, data })
#define EVENT_NOTIFY(event_id)				blood::EventManager::Instance().Notify({ #event_id, true })

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
		/*else {
			Logger::Warning("could not find event: {}", event);
		}*/
	}
}
