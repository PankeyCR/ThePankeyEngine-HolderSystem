
#ifndef TR_ObjectList_Testing_hpp
	#define TR_ObjectList_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "TypeList.hpp"

	namespace pankey{

		namespace HolderSystem{

			class BaseTestExample{
				public: int num = 0;
				bool operator==(const BaseTestExample& a_test){
					return a_test.num == num;
				}
				bool operator!=(const BaseTestExample& a_test){
					return a_test.num != num;
				}
			};
			class TestExample : public BaseTestExample{
				public:
				TestExample(){}
				TestExample(int x){num = x;}
			};
			
			Base::TestResult<String> TR_ObjectList_Testing_1(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;
				
				result.assertTrue("storage has to be null", i_list.isEmpty());
				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_2(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample();
				obj<BaseTestExample> i_var_1 = TestExample();
				obj<BaseTestExample> i_var_2 = TestExample();
				obj<BaseTestExample> i_var_3 = TestExample();
				obj<BaseTestExample> i_var_4 = TestExample();
				obj<BaseTestExample> i_var_5 = TestExample();

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);
				i_list.add(i_var_4);
				i_list.add(i_var_5);

				result.assertEqual("index should be the same", i_list.length(), 6);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_3(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(15);
				obj<BaseTestExample> i_var_1 = TestExample();

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.replace(0, 1);

				obj<BaseTestExample> i_var_10 = i_list.get(1);

				if(!i_var_0.isValidObject<TestExample>()){
					result.catchError("not a valid object 0");
					return result;
				}

				if(!i_var_10.isValidObject<TestExample>()){
					result.catchError("not a valid object 1");
					return result;
				}

				TestExample i_var_00 = i_var_0.getValue<TestExample>();
				TestExample i_var_01 = i_var_10.getValue<TestExample>();

				result.assertEqual("value should be the same", i_var_00.num, i_var_01.num);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_4(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				obj<BaseTestExample> i_var_11 = i_list.getByPointer(i_var_1);
				TestExample i_val_1 = i_var_11.getValue<TestExample>();

				result.assertEqual("index should be the same", i_val_1.num, 1);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_5(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				result.assertTrue("OList contain var", i_list.containByPointer(i_var_1));

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_6(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				result.assertEqual("var index should be 1", i_list.getIndexByPointer(i_var_1), 1);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_7(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.removeByPointer(i_var_0);

				result.assertEqual("var index should be 0", i_list.getIndexByPointer(i_var_1), 0);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_8(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);

				i_list.add(i_var_0);
				i_list.add(i_var_1);

				i_list.remove(0);

				result.assertEqual("var index should be 0", i_list.getIndexByPointer(i_var_1), 0);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_9(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);

				i_list.removeFirstIndex(2);

				result.assertEqual("var index should be 1", i_list.length(), 1);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_10(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);

				i_list.removeLastIndex(2);

				result.assertEqual("var index should be 1", i_list.length(), 1);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_11(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removePart(1, 2);

				result.assertEqual("var index should be 2", i_list.length(), 2);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_12(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removeFirst();

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_13(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.removeLast();

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_14(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.clear();

				result.assertEqual("var index should be 3", i_list.length(), 0);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_15(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				result.assertEqual("value should be the same", i_var_0.getValue<TestExample>().num, 0);
				result.assertEqual("value should be the same", i_var_1.getValue<TestExample>().num, 1);

				result.assertEqual("var index should be 3", i_list.length(), 4);

				for(int x = 0; x < i_list.length(); x++){
					obj<BaseTestExample> i_var = i_list.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue<TestExample>().num, x);
				}

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_16(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);

				i_list.put(i_var_0);
				i_list.put(i_var_1);
				i_list.put(i_var_1);
				i_list.put(i_var_2);

				result.assertEqual("var index should be 3", i_list.length(), 3);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_17(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				val<int> i_var_0 = 0;
				val<int> i_var_1 = 1;
				val<int> i_var_2 = 2;

				i_list.put(i_var_0);
				i_list.put(i_var_1);
				i_list.put(i_var_1);
				i_list.put(i_var_2);

				result.assertEqual("var index should be 0", i_list.length(), 0);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_18(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);
				obj<BaseTestExample> i_var_4 = TestExample(4);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_2);
				i_list.add(i_var_3);

				i_list.set(2, i_var_4);

				var i_var_11 = i_list.get(2);
				TestExample i_val_1 = i_var_11.getValue<TestExample>();

				result.assertEqual("var index should be 4", i_val_1.num, 4);

				result.assertEqual("var index should be 4", i_list.length(), 4);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_19(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

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
				TestExample i_val_1 = i_var_11.getValue<TestExample>();

				result.assertEqual("var value should be 0", i_val_1.num, 0);

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_20(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

				obj<BaseTestExample> i_var_0 = TestExample(0);
				obj<BaseTestExample> i_var_1 = TestExample(1);
				obj<BaseTestExample> i_var_2 = TestExample(2);
				obj<BaseTestExample> i_var_3 = TestExample(3);
				obj<BaseTestExample> i_var_4 = TestExample(4);

				i_list.add(i_var_0);
				i_list.add(i_var_1);
				i_list.add(i_var_3);
				i_list.add(i_var_4);

				i_list.insert(2, i_var_2);

				result.assertEqual("OList index should be 5", i_list.length(), 5);

				for(int x = 0; x < i_list.length(); x++){
					val<BaseTestExample> i_var = i_list.get(x);
					result.assertEqual("storage value should be the same as the index", i_var.getValue().num, x);
				}

				return result;
			}
			
			Base::TestResult<String> TR_ObjectList_Testing_21(){
				Base::TestResult<String> result;

				OList<BaseTestExample> i_list;

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

				result.assertEqual("OList index should be 0", i_list.length(), 0);

				return result;
			}

			void TR_ObjectList_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("OList Constructor", TR_ObjectList_Testing_1);
				a_test_runner.add("OList add and length", TR_ObjectList_Testing_2);
				a_test_runner.add("OList replace and get", TR_ObjectList_Testing_3);
				a_test_runner.add("OList get by obj", TR_ObjectList_Testing_4);
				a_test_runner.add("OList contain", TR_ObjectList_Testing_5);
				a_test_runner.add("OList getIndex", TR_ObjectList_Testing_6);
				a_test_runner.add("OList remove member", TR_ObjectList_Testing_7);
				a_test_runner.add("OList remove index", TR_ObjectList_Testing_8);
				a_test_runner.add("OList removeFirstIndex", TR_ObjectList_Testing_9);
				a_test_runner.add("OList removeLastIndex", TR_ObjectList_Testing_10);
				a_test_runner.add("OList removePart", TR_ObjectList_Testing_11);
				a_test_runner.add("OList removeFirst", TR_ObjectList_Testing_12);
				a_test_runner.add("OList removeLast", TR_ObjectList_Testing_13);
				a_test_runner.add("OList clear", TR_ObjectList_Testing_14);
				a_test_runner.add("OList add value", TR_ObjectList_Testing_15);
				a_test_runner.add("OList put var", TR_ObjectList_Testing_16);
				a_test_runner.add("OList put value", TR_ObjectList_Testing_17);
				a_test_runner.add("OList set var", TR_ObjectList_Testing_18);
				a_test_runner.add("OList set value", TR_ObjectList_Testing_19);
				a_test_runner.add("OList insert var", TR_ObjectList_Testing_20);
				a_test_runner.add("OList insert value", TR_ObjectList_Testing_21);
			}

		}

	}

#endif
