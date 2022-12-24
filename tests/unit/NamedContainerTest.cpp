#include <NamedContainer/NamedContainer.hpp>

#include <gtest/gtest.h>

class TestNamedContainer : public ::testing::Test {
};

TEST_F(TestNamedContainer, EmptyKeys)
{
	NamedContainer myC {};

	auto c1 = myC.create();

	ASSERT_EQ(c1.begin(), c1.end());
}

TEST_F(TestNamedContainer, IteratorIncrement)
{
	NamedContainer myC { "field1" };

	auto c1 = myC.create();

	ASSERT_NE(c1.begin(), c1.end());
	ASSERT_TRUE(c1.begin() != c1.end());

	auto it = c1.begin();
	it++;
	ASSERT_EQ(it, c1.end());
	ASSERT_TRUE(it == c1.end());

	ASSERT_EQ(++(c1.begin()), c1.end());
	ASSERT_TRUE(++(c1.begin()) == c1.end());
}

TEST_F(TestNamedContainer, IteratorAllKeys)
{
	NamedContainer myC { "field1", "field2", "field3" };

	auto c1 = myC.create();

	std::multiset<std::string> keys {};

	for (auto it = c1.begin(); it != c1.end(); ++it) {
		keys.insert(it->first);
	}

	ASSERT_EQ(keys.size(), 3);
	ASSERT_TRUE(keys.contains("field1"));
	ASSERT_TRUE(keys.contains("field2"));
	ASSERT_TRUE(keys.contains("field3"));
}

TEST_F(TestNamedContainer, IteratorAllValues)
{
	NamedContainer myC { "field1", "field2", "field3" };

	auto c1 = myC.create();

	c1["field1"] = "value1";
	c1["field2"] = "value2";
	c1["field3"] = "value3";

	std::multiset<std::string> values {};

	for (auto it = c1.begin(); it != c1.end(); ++it) {
		values.insert(it->second);
	}

	ASSERT_EQ(values.size(), 3);
	ASSERT_TRUE(values.contains("value1"));
	ASSERT_TRUE(values.contains("value2"));
	ASSERT_TRUE(values.contains("value3"));
}

TEST_F(TestNamedContainer, NoKey)
{
	NamedContainer myC { "field1", "field2" };

	auto c1 = myC.create();

	ASSERT_NE(c1.begin(), c1.end());

	EXPECT_EQ(c1["field1"], "");
	EXPECT_EQ(c1["field2"], "");

	EXPECT_THROW(c1["FIELD"], std::logic_error);
}