
#ifndef TR_Value_Testing_hpp
	#define TR_Value_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Pointer.hpp"
	#include "Variable.hpp"
	#include "Value.hpp"

	namespace pankey{

		namespace HolderSystem{
		
			Base::TestResult TR_Value_Testing_1(){
				Base::TestResult result;

				val<int> i_value;

				result.assertTrue("allocator shouldnt be null", !i_value.isManagerNull());
				result.assertTrue("holder shouldnt be null", i_value.isHolderNull());
				result.assertTrue("pointer has to be null", i_value.isNull());

				return result;
			}
			
			Base::TestResult TR_Value_Testing_2(){
				Base::TestResult result;

				val<int> i_value = 15;

				result.assertTrue("allocator shouldnt be null", !i_value.isManagerNull());
				result.assertTrue("holder shouldnt be null", !i_value.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_value.isNull());
				result.assertEqual("value has to be 15", i_value.getValue(), 15);

				return result;
			}
			
			Base::TestResult TR_Value_Testing_3(){
				Base::TestResult result;

				val<int> i_value = 15;
				val<int> i_value_2 = i_value;

				result.assertEqual("value has to be 15", i_value.getValue(), 15);
				result.assertEqual("value 2 has to be 15", i_value_2.getValue(), 15);

				return result;
			}
			
			Base::TestResult TR_Value_Testing_4(){
				Base::TestResult result;

				val<int> i_value = 15;
				var i_value_2 = i_value;

				result.assertEqual("value has to be 15", i_value.getValue(), 15);
				result.assertEqual("value 2 has to be 15", i_value_2.getValue<int>(), 15);

				return result;
			}

			void TR_Value_Testing(Base::TestRunner& a_test_runner){
				createMemoryManager();

				a_test_runner.add("Value Simple Constructor", TR_Value_Testing_1);
				a_test_runner.add("Value Contructor", TR_Value_Testing_2);
				a_test_runner.add("Copy Constructor", TR_Value_Testing_3);
				a_test_runner.add("val to var", TR_Value_Testing_4);
			}

		}

	}

#endif
