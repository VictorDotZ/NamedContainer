#include <NamedContainer/NamedContainer.hpp>

#include <gtest/gtest.h>

TEST(NamedContainerDictIntegration, IterateThrough)
{
	NamedContainer myC { "field1", "field2", "field3" };

	auto c1 = myC.create();

	c1["field1"] = "value1";
	c1["field2"] = "value2";
	c1["field3"] = "value3";

	std::unordered_map<std::string, std::string> dict {};

	for (auto it = c1.begin(); it != c1.end(); ++it) {
		dict.insert({ it->first, it->second });
	}

	ASSERT_EQ(dict.size(), 3);
	ASSERT_TRUE(dict.contains("field1"));
	ASSERT_TRUE(dict.contains("field2"));
	ASSERT_TRUE(dict.contains("field3"));
	ASSERT_EQ(dict["field1"], "value1");
	ASSERT_EQ(dict["field2"], "value2");
	ASSERT_EQ(dict["field3"], "value3");
}

TEST(NamedContainerDictIntegration, IterateNoKey)
{
	NamedContainer myC { "field1", "field2", "field3" };

	auto c1 = myC.create();

	EXPECT_EQ(c1["field1"], "");
	EXPECT_EQ(c1["field2"], "");
	EXPECT_EQ(c1["field3"], "");

	c1["field1"] = "val1";

	EXPECT_EQ(c1["field1"], "val1");
	EXPECT_EQ(c1["field2"], "");
	EXPECT_EQ(c1["field3"], "");

	EXPECT_THROW(c1["FIELD"], std::logic_error);
}