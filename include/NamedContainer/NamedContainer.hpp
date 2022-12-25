#pragma once
#include <initializer_list>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>

class NamedContainer {
public:
	using KeyPool = std::multiset<std::string>;

	class Container {
		friend class NamedContainer;

	public:
		using KeyValuePairs = std::unordered_map<std::string, std::string>;

		class Iterator {
			friend class Container;

		public:
			using iterator_category = std::forward_iterator_tag;
			using value_type = std::pair<const std::string, std::string>;
			using pointer = value_type*;
			using reference = value_type&;

			pointer operator->() const;
			reference operator*() const;

			Iterator& operator++();
			Iterator operator++(int);

			friend bool operator==(const Iterator& lhs, const Iterator& rhs);
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs);

		private:
			Iterator(KeyValuePairs::iterator it);

			KeyValuePairs::iterator m_mapIt;
		};

		std::string& operator[](const std::string& key);

		Iterator begin();
		Iterator end();

	private:
		Container();

		KeyValuePairs m_dict;
	};

	NamedContainer(std::initializer_list<std::string> l);

	Container create();

private:
	KeyPool m_keys;
};