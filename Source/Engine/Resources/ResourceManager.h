#pragma once
#include "../Core/StringHelper.h"
#include "../Resources/Resource.h"
#include <map>
#include <iostream>


namespace blood {
	class ResourceManager {
	public:
		template<typename T, typename ... TArgs>
		res_t<T> Get(const std::string& name, TArgs&& ... args);



	private:
		std::map<std::string, res_t<Resource>> m_resources;
	};


	template<typename T, typename ... TArgs>
	inline res_t<T> ResourceManager::Get(const std::string& name, TArgs&& ... args)
	{
		std::string key = toLower(name);

		auto iter = m_resources.find(key);
		if (iter != m_resources.end()) {
			auto base = iter->second;
			auto derived = std::dynamic_pointer_cast<T>(base);
			if (!derived) {
				std::cerr << "Resource type mismatch: " << key << std::endl;
				return res_t<T>();
			}

			return derived;
		}

		//load resource
		res_t<T> resource = std::make_shared<T>();
		if (!resource->Load(key, std::forward<TArgs>(args)...)) {
			std::cerr << "Could not load resource: " << key << std::endl;//why is this line not auto formatting?
			return res_t<T>();
		}

		//add resource to resource manager
		m_resources[key] = resource;

		return resource;
	}
}