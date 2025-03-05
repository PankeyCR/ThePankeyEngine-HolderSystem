
#ifndef TR_TypeArrayMap_Testing_hpp
	#define TR_TypeArrayMap_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	namespace pankey{

		namespace HolderSystem{
		
			Base::TestResult TR_TypeArrayMap_Testing_1(){
				Base::TestResult result;

				TMap<int,int> i_map;
				
				result.assertTrue("storage has to be null", i_map.isEmpty());
				return result;
			}
			
			Base::TestResult TR_TypeArrayMap_Testing_2(){
				Base::TestResult result;

				TMap<int,int> i_map;

				val<int> i_key = 15;
				val<int> i_value = 20;

				i_map.add(i_key, i_value);

				var i_search = 20;

				var i_p = i_map.getKeyByPointer(i_search);
				var i_v = i_map.getKeyByValue(i_search);
				
				result.assertNotEqual("key shouldnt be found by pointer", i_p.getValue<int>(), 15);
				result.assertEqual("key should be found by value", i_v.getValue<int>(), 15);
				return result;
			}
			
			Base::TestResult TR_TypeArrayMap_Testing_3(){
				Base::TestResult result;

				TMap<int,int> i_map;

				val<int> i_key = 15;
				val<int> i_value = 20;

				i_map.add(i_key, i_value);

				var i_search = 15;

				var i_p = i_map.getValueByPointer(i_search);
				var i_v = i_map.getValueByValue(i_search);
				
				result.assertNotEqual("value shouldnt be found by pointer", i_p.getValue<int>(), 20);
				result.assertEqual("value should be found by value", i_v.getValue<int>(), 20);
				return result;
			}

			void TR_TypeArrayMap_Testing(Base::TestRunner& a_test_runner){
				createMemoryManager();

				a_test_runner.add("TypeArrayMap Constructor", TR_TypeArrayMap_Testing_1);
				a_test_runner.add("TypeArrayMap add, getKeyByValue", TR_TypeArrayMap_Testing_2);
				a_test_runner.add("TypeArrayMap add, getValueByValue", TR_TypeArrayMap_Testing_3);
			}

		}

	}

#endif
