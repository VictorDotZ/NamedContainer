#include <NamedContainer/NamedContainer.hpp>

NamedContainer::NamedContainer(
    std::initializer_list<std::string> l)
    : m_keys(l)
{
}

NamedContainer::Container
NamedContainer::create()
{
	auto container = Container();

	for (auto it = m_keys.begin(); it != m_keys.end(); ++it) {
		container.m_dict[*it] = "";
	}

	return container;
}

NamedContainer::Container::Container()
    : m_dict(std::unordered_map<std::string, std::string>())
{
}

std::string&
NamedContainer::Container::operator[](const std::string& key)
{
	if (!m_dict.contains(key)) {
		throw std::logic_error(key);
	}

	return m_dict[key];
}

NamedContainer::Container::Iterator
NamedContainer::Container::begin()
{
	return m_dict.begin();
}

NamedContainer::Container::Iterator
NamedContainer::Container::end()
{
	return m_dict.end();
}

NamedContainer::Container::Iterator::Iterator(
    NamedContainer::Container::KeyValuePairs::iterator it)
    : m_mapIt(it)
{
}

NamedContainer::Container::Iterator::pointer
NamedContainer::Container::Iterator::operator->() const
{
	return m_mapIt.operator->();
}

NamedContainer::Container::Iterator::reference
NamedContainer::Container::Iterator::operator*() const
{
	return m_mapIt.operator*();
}

NamedContainer::Container::Iterator&
NamedContainer::Container::Iterator::operator++()
{
	m_mapIt++;
	return *this;
}

NamedContainer::Container::Iterator
NamedContainer::Container::Iterator::operator++(int)
{
	NamedContainer::Container::Iterator tmp = *this;
	++(*this);
	return tmp;
}

bool operator==(
    const NamedContainer::Container::Iterator& lhs,
    const NamedContainer::Container::Iterator& rhs)
{
	return lhs.m_mapIt == rhs.m_mapIt;
}

bool operator!=(
    const NamedContainer::Container::Iterator& lhs,
    const NamedContainer::Container::Iterator& rhs)
{
	return lhs.m_mapIt != rhs.m_mapIt;
};