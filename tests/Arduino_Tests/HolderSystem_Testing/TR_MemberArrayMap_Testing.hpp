
#ifndef TR_MemberArrayMap_Testing_hpp
	#define TR_MemberArrayMap_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "MemberArrayMap.hpp"

	namespace pankey{

		namespace HolderSystem{
		
			Base::TestResult<String> TR_MemberArrayMap_Testing_1(){
				Base::TestResult<String> result;

				Map i_map;
				
				result.assertTrue("storage has to be null", i_map.isEmpty());
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_2(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key = 15;
				var i_value = 20;

				i_map.add(i_key, i_value);

				var i_v = i_map.getValueByPointer(i_key);
				
				result.assertEqual("with a 15 key a 20 value should apear", i_v.getValue<int>(), 20);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_3(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key = 15;
				var i_value = 20;

				var i_key_1 = 15;
				var i_value_1 = 20;

				i_map.add(i_key, i_value);
				i_map.add(i_key_1, i_value_1);
				
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_4(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);

				i_map.replace(0, 1);

				var i_value_11 = i_map.getValue(0);
				var i_value_22 = i_map.getValue(1);
				
				result.assertEqual("value should be 40", i_value_11.getValue<int>(), 40);
				result.assertEqual("value should be 20", i_value_22.getValue<int>(), 20);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_5(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				i_map.add(i_key_1, i_value_1);
				
				result.assertTrue("map should contain var", i_map.containByPointer(i_key_1));
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_6(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				int i_index = i_map.getIndexByPointer(i_key_2);
				
				result.assertEqual("map index should be 1", i_index, 1);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_7(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				bool i_removed = i_map.removeByPointer(i_key_2);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_8(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				var i_value = i_map.remove(1);
				
				result.assertEqual("var should be 40", i_value.getValue<int>(), 40);
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_9(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				bool i_removed = i_map.removeFirstIndex(2);

				var i_value = i_map.getValue(0);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("var should be 70", i_value.getValue<int>(), 70);
				result.assertEqual("map length should be 1", i_map.length(), 1);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_10(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				bool i_removed = i_map.removeLastIndex(2);

				var i_value = i_map.getValue(0);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("var should be 70", i_value.getValue<int>(), 20);
				result.assertEqual("map length should be 1", i_map.length(), 1);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_11(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				var i_key_4 = 85;
				var i_value_4 = 90;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);
				i_map.add(i_key_4, i_value_4);

				bool i_removed = i_map.removePart(1, 2);

				var i_value_00 = i_map.getValue(0);
				var i_value_11 = i_map.getValue(1);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("var should be 20", i_value_00.getValue<int>(), 20);
				result.assertEqual("var should be 90", i_value_11.getValue<int>(), 90);
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_12(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				bool i_removed = i_map.removeFirst();

				var i_value_00 = i_map.getValue(0);
				var i_value_11 = i_map.getValue(1);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("var should be 20", i_value_00.getValue<int>(), 40);
				result.assertEqual("var should be 90", i_value_11.getValue<int>(), 70);
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_13(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);

				bool i_removed = i_map.removeLast();

				var i_value_00 = i_map.getValue(0);
				var i_value_11 = i_map.getValue(1);
				
				result.assertEqual("should be true", i_removed, true);
				result.assertEqual("var should be 20", i_value_00.getValue<int>(), 20);
				result.assertEqual("var should be 90", i_value_11.getValue<int>(), 40);
				result.assertEqual("map length should be 2", i_map.length(), 2);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_14(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				var i_key_2 = 35;
				var i_value_2 = 40;

				var i_key_3 = 65;
				var i_value_3 = 70;

				var i_key_4 = 85;
				var i_value_4 = 90;

				i_map.add(i_key_1, i_value_1);
				i_map.add(i_key_2, i_value_2);
				i_map.add(i_key_3, i_value_3);
				i_map.add(i_key_4, i_value_4);

				bool i_removed = i_map.clear();
				
				result.assertEqual("should be true", i_removed, true);
				result.assertTrue("it should be empty", i_map.isEmpty());
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_15(){
				Base::TestResult<String> result;

				Map i_map;

				var i_key_1 = 15;
				var i_value_1 = 20;

				i_map.put(i_key_1, i_value_1);
				i_map.put(i_key_1, i_value_1);
				i_map.put(i_key_1, i_value_1);
				i_map.put(i_key_1, i_value_1);
				
				result.assertEqual("lenght should be 1", i_map.length(), 1);
				return result;
			}
			
			Base::TestResult<String> TR_MemberArrayMap_Testing_16(){
				Base::TestResult<String> result;

				Map i_map;

				duo i_duo = duo(var(10), var(20));

				i_map.put(i_duo);

				var i_value = i_map.getValueByPointer(i_duo.getMember());
				
				result.assertEqual("lenght should be 1", i_map.length(), 1);
				result.assertEqual("var should be 20", i_value.getValue<int>(), 20);
				return result;
			}

			void TR_MemberArrayMap_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("MemberArrayMap Constructor", TR_MemberArrayMap_Testing_1);
				a_test_runner.add("MemberArrayMap add, getByPointer", TR_MemberArrayMap_Testing_2);
				a_test_runner.add("MemberArrayMap add, length", TR_MemberArrayMap_Testing_3);
				a_test_runner.add("MemberArrayMap replace, get int", TR_MemberArrayMap_Testing_4);
				a_test_runner.add("MemberArrayMap contain", TR_MemberArrayMap_Testing_5);
				a_test_runner.add("MemberArrayMap getIndex", TR_MemberArrayMap_Testing_6);
				a_test_runner.add("MemberArrayMap remove", TR_MemberArrayMap_Testing_7);
				a_test_runner.add("MemberArrayMap remove", TR_MemberArrayMap_Testing_8);
				a_test_runner.add("MemberArrayMap removeFirstIndex", TR_MemberArrayMap_Testing_9);
				a_test_runner.add("MemberArrayMap removeLastIndex", TR_MemberArrayMap_Testing_10);
				a_test_runner.add("MemberArrayMap removePart", TR_MemberArrayMap_Testing_11);
				a_test_runner.add("MemberArrayMap removeFirst", TR_MemberArrayMap_Testing_12);
				a_test_runner.add("MemberArrayMap removeLast", TR_MemberArrayMap_Testing_13);
				a_test_runner.add("MemberArrayMap clear", TR_MemberArrayMap_Testing_14);
				a_test_runner.add("MemberArrayMap put", TR_MemberArrayMap_Testing_15);
				a_test_runner.add("MemberArrayMap put duo", TR_MemberArrayMap_Testing_16);
			}

		}

	}

#endif
