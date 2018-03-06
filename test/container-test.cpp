#include <iostream>
#include "gtest/gtest.h"
#include "myvector.h"
#include <algorithm>

class VectorTest : public::testing::Test{
				protected:
                void SetUp() {}
                void TearDown() {}
};


TEST_F(VectorTest, should_create_an_empty_vector) {
		myvector<int> _myvector();
		ASSERT_TRUE(1);
}

TEST_F(VectorTest, should_create_a_vector_containing_1_element) {
		myvector<int> _myvector(1);
		ASSERT_TRUE(1);
}

TEST_F(VectorTest, should_create_a_vector_containing_1_element_equal_to_0) {
		myvector<int> _myvector(1,0);
		ASSERT_TRUE(1);
		ASSERT_EQ(_myvector[0],0);
}

TEST_F(VectorTest, should_create_a_vector_containing_1_element_equal_to_0_and_push_3_to_vector) {
		myvector<int> _myvector(1,0);
		_myvector.push_back(3);
		ASSERT_EQ(_myvector[0],0);
		ASSERT_EQ(_myvector[1],3);
}


TEST_F(VectorTest, should_create_a_vector_containing_1_element_equal_to_0_and_push_3_to_vector_size_equals_to_2_and_capacity_is_2) {
		myvector<int> _myvector(1,0);
		_myvector.push_back(3);
		ASSERT_EQ(_myvector[0],0);
		ASSERT_EQ(_myvector[1],3);
		ASSERT_EQ(_myvector.size(),2);
		ASSERT_EQ(_myvector.capacity(),2);
}


TEST_F(VectorTest, should_pop_back_last_element_and_back_value_has_to_be_equal_to_4) {
		myvector<int> _myvector(1,0);
		_myvector.push_back(2);
		_myvector.push_back(3);
		_myvector.push_back(4);
		_myvector.push_back(5);
		_myvector.pop_back();
		ASSERT_EQ(_myvector.size(),4);
		ASSERT_EQ(_myvector.back(),4);
}

TEST_F(VectorTest, should_insert_an_element_equal_to_100_in_the_beginning) {
		myvector<int> _myvector(1,0);
		_myvector.push_back(2);
		_myvector.push_back(3);
		_myvector.push_back(4);
		_myvector.push_back(5);
		_myvector.insert(_myvector.begin(),100);
		ASSERT_EQ(_myvector.front(),100);
		ASSERT_EQ(_myvector.back(),5);
		ASSERT_EQ(_myvector.size(),6);
}

TEST_F(VectorTest, should_insert_an_element_equal_to_100_in_the_second_position) {
		myvector<int> _myvector(1,0);
		_myvector.push_back(2);
		_myvector.push_back(3);
		_myvector.push_back(4);
		_myvector.push_back(5);
		_myvector.insert(_myvector.begin()+1,100);
		ASSERT_EQ(_myvector[1],100);
		ASSERT_EQ(_myvector.back(),5);
		ASSERT_EQ(_myvector.size(),6);
}

TEST_F(VectorTest, should_insert_a_range_equal_to_100_200_in_the_second_position) {
		myvector<int> _myvector(4);
		_myvector[0] = 0;
		_myvector[1] = 1;
		_myvector[2] = 2;
		_myvector[3] = 3;
		myvector<int> _myvector2(2);
		_myvector2[0] = 100;
		_myvector2[1] = 200;


		_myvector.insert(_myvector.begin()+1,_myvector2.begin(), _myvector2.end());
		ASSERT_EQ(_myvector[1],100);
		ASSERT_EQ(_myvector[2],200);
}

TEST_F(VectorTest, should_erase_two_elements_from_second_position) {
			myvector<int> _myvector(4);
			_myvector[0] = 0;
			_myvector[1] = 1;
			_myvector[2] = 2;
			_myvector[3] = 3;


			_myvector.erase(_myvector.begin()+1,_myvector.begin()+2);
			ASSERT_EQ(_myvector[0],0);
			ASSERT_EQ(_myvector[1],3);
			ASSERT_EQ(_myvector.size(),2);
}

TEST_F(VectorTest, should_clean_the_vector_and_set_size_to_zero) {
			myvector<int> _myvector(4);
			_myvector[0] = 0;
			_myvector[1] = 1;
			_myvector[2] = 2;
			_myvector[3] = 3;


			_myvector.clear();
			ASSERT_EQ(_myvector.size(),0);
}

TEST_F(VectorTest, should_sort_the_vector_ascending) {
			myvector<int> _myvector(4);
			_myvector[0] = 3;
			_myvector[1] = 2;
			_myvector[2] = 1;
			_myvector[3] = 0;


			std::sort(_myvector.begin(), _myvector.end());
			ASSERT_EQ(_myvector[0],0);
			ASSERT_EQ(_myvector[3],3);
}

TEST_F(VectorTest, should_pop_back_one_element) {
			myvector<int> _myvector(4);
			_myvector[0] = 3;
			_myvector[1] = 2;
			_myvector[2] = 1;
			_myvector[3] = 0;


			_myvector.pop_back();
			ASSERT_EQ(_myvector[2],1);
			ASSERT_EQ(_myvector.size(),3);
}
