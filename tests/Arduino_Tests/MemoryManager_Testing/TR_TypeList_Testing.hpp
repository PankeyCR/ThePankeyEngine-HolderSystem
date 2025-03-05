
#ifndef TR_TypeList_Testing_hpp
	#define TR_TypeList_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "TypeList.hpp"
	#include "CharArray.hpp"

	namespace pankey{

		namespace HolderSystem{
		
			Base::TestResult TR_TypeList_Testing_1(){
				Base::TestResult result;

				TList<int> i_list;
				
				result.assertTrue("storage has to be null", i_list.isEmpty());
				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_2(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;
				var i_var_4 = 4;
				var i_var_5 = 5;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);
				i_list.add(i_var_4);
				i_list.add(i_var_5);

				result.assertEqual("index should be the same", i_list.length(), 6);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_3(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.replace(0, 1);

				var i_var_10 = i_list.get(0);
				int i_val_0 = i_var_10.getValue<int>();

				result.assertEqual("index should be the same", i_val_0, 1);

				var i_var_11 = i_list.get(1);
				int i_val_1 = i_var_11.getValue<int>();

				result.assertEqual("index should be the same", i_val_1, 0);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_4(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				var i_var_11 = i_list.getByPointer(i_var_1);
				int i_val_1 = i_var_11.getValue<int>();

				result.assertEqual("index should be the same", i_val_1, 1);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_5(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				result.assertTrue("list contain var", i_list.containByPointer(i_var_1));

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_6(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				result.assertEqual("var index should be 1", i_list.getIndexByPointer(i_var_1), 1);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_7(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.removeByPointer(i_var_0);

				result.assertEqual("var index should be 0", i_list.getIndexByPointer(i_var_1), 0);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_8(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.remove(0);

				result.assertEqual("var index should be 0", i_list.getIndexByPointer(i_var_1), 0);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_9(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);

				i_list.removeFirstIndex(2);

				result.assertEqual("var index should be 1", i_list.length(), 1);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_10(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);

				i_list.removeLastIndex(2);

				result.assertEqual("var index should be 1", i_list.length(), 1);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_11(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removePart(1, 2);

				result.assertEqual("var index should be 2", i_list.length(), 2);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_12(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removeFirst();

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_13(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removeLast();

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_14(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.clear();

				result.assertEqual("var index should be 3", i_list.length(), 0);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_15(){
				Base::TestResult result;

				TList<int> i_list;

				val<int> i_var_0 = 0;
				val<int> i_var_1 = 1;
				val<int> i_var_2 = 2;
				val<int> i_var_3 = 3;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				result.assertEqual("value should be the same", i_var_0.getValue(), 0);
				result.assertEqual("value should be the same", i_var_1.getValue(), 1);

				result.assertEqual("var index should be 3", i_list.length(), 4);

				for(int x = 0; x < i_list.length(); x++){
					val<int> i_var = i_list.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue(), x);
				}

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_16(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;

				i_list.put(i_var_0);
				i_list.put(i_var_1);
				i_list.put(i_var_1);
				i_list.put(i_var_2);

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_17(){
				Base::TestResult result;

				TList<int> i_list;

				val<int> i_var_0 = 0;
				val<int> i_var_1 = 1;
				val<int> i_var_2 = 2;

				i_list.put(i_var_0);
				i_list.put(i_var_1);
				i_list.put(i_var_1);
				i_list.put(i_var_2);

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_18(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;
				var i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.set(2, i_var_4);

				var i_var_11 = i_list.get(2);
				int i_val_1 = i_var_11.getValue<int>();

				result.assertEqual("var index should be 4", i_val_1, 4);

				result.assertEqual("var index should be 4", i_list.length(), 4);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_19(){
				Base::TestResult result;

				TList<int> i_list;

				val<int> i_var_0 = 0;
				val<int> i_var_1 = 1;
				val<int> i_var_2 = 2;
				val<int> i_var_3 = 3;
				val<int> i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.set(2, i_var_4);

				var i_var_11 = i_list.get(2);
				int i_val_1 = i_var_11.getValue<int>();

				result.assertEqual("var index should be 4", i_val_1, 4);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_20(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;
				var i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_3);
				i_list.add(i_var_4);

				i_list.insert(2, i_var_2);

				for(int x = 0; x < i_list.length(); x++){
					val<int> i_var = i_list.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue(), x);
				}

				result.assertEqual("list index should be 5", i_list.length(), 5);

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_21(){
				Base::TestResult result;

				TList<int> i_list;

				val<int> i_var_0 = 0;
				val<int> i_var_1 = 1;
				val<int> i_var_2 = 2;
				val<int> i_var_3 = 3;
				val<int> i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_3);
				i_list.add(i_var_4);

				i_list.insert(2, i_var_2);

				result.assertEqual("list index should be 5", i_list.length(), 5);

				for(int x = 0; x < i_list.length(); x++){
					val<int> i_var = i_list.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue(), x);
				}

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_22(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;
				var i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);
				i_list.add(i_var_4);

				TList<int> i_list_2;

				i_list_2.move(i_list);

				result.assertEqual("list index should be 5", i_list_2.length(), 5);
				result.assertTrue("list should be empty", i_list.isEmpty());

				for(int x = 0; x < i_list_2.length(); x++){
					val<int> i_var = i_list_2.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue(), x);
				}

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_23(){
				Base::TestResult result;

				TList<int> i_list;

				var i_var_0 = 0;
				var i_var_1 = 1;
				var i_var_2 = 2;
				var i_var_3 = 3;
				var i_var_4 = 4;

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);
				i_list.add(i_var_4);

				TList<int> i_list_2;

				i_list_2.duplicate(i_list);

				result.assertEqual("list index should be 5", i_list.length(), 5);
				result.assertEqual("list index should be 5", i_list_2.length(), 5);

				for(int x = 0; x < i_list_2.length(); x++){
					val<int> i_var = i_list_2.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue(), x);
				}

				return result;
			}
			
			Base::TestResult TR_TypeList_Testing_24(){
				Base::TestResult result;

				TList<Base::CharArray> i_list;

				val<Base::CharArray> i_var_0 = Base::CharArray("hellow");
				val<Base::CharArray> i_var_1 = Base::CharArray("world");

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				val<Base::CharArray> i_var_00 = i_list.get(0);
				val<Base::CharArray> i_var_01 = i_list.get(1);

				result.assertEqual("value 0 should be hellow", i_var_00.getValue(), Base::CharArray("hellow"));
				result.assertEqual("value 1 should be world", i_var_01.getValue(), Base::CharArray("world"));

				return result;
			}

			void TR_TypeList_Testing(Base::TestRunner& a_test_runner){
				createMemoryManager();

				a_test_runner.add("List Constructor", TR_TypeList_Testing_1);
				a_test_runner.add("List add and getIndex", TR_TypeList_Testing_2);
				a_test_runner.add("List replace and get", TR_TypeList_Testing_3);
				a_test_runner.add("List get by Member", TR_TypeList_Testing_4);
				a_test_runner.add("List contain", TR_TypeList_Testing_5);
				a_test_runner.add("List getIndex", TR_TypeList_Testing_6);
				a_test_runner.add("List remove member", TR_TypeList_Testing_7);
				a_test_runner.add("List remove index", TR_TypeList_Testing_8);
				a_test_runner.add("List removeFirstIndex", TR_TypeList_Testing_9);
				a_test_runner.add("List removeLastIndex", TR_TypeList_Testing_10);
				a_test_runner.add("List removePart", TR_TypeList_Testing_11);
				a_test_runner.add("List removeFirst", TR_TypeList_Testing_12);
				a_test_runner.add("List removeLast", TR_TypeList_Testing_13);
				a_test_runner.add("List clear", TR_TypeList_Testing_14);
				a_test_runner.add("List add value", TR_TypeList_Testing_15);
				a_test_runner.add("List put var", TR_TypeList_Testing_16);
				a_test_runner.add("List put value", TR_TypeList_Testing_17);
				a_test_runner.add("List set var", TR_TypeList_Testing_18);
				a_test_runner.add("List set value", TR_TypeList_Testing_19);
				a_test_runner.add("List insert var", TR_TypeList_Testing_20);
				a_test_runner.add("List insert value", TR_TypeList_Testing_21);
				a_test_runner.add("List move", TR_TypeList_Testing_22);
				a_test_runner.add("List duplicate", TR_TypeList_Testing_23);
				a_test_runner.add("List Base::CharArray", TR_TypeList_Testing_24);
			}

		}

	}

#endif
