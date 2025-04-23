
#ifndef TR_InvokeList_Testing_hpp
	#define TR_InvokeList_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeList.hpp"

	namespace pankey{

		namespace HolderSystem{

			class TestListInvoker{
				public:
				void run(Base::TestResult<String>& a_result){
					a_result.assertTrue("executing method", true);
				}
				bool won(Base::TestResult<String>& a_result){
					a_result.assertTrue("executing method", true);
					return true;
				}
			};
			
			Base::TestResult<String> TR_InvokeList_Testing_1(){
				Base::TestResult<String> i_result;

				InvokerList<TestListInvoker> i_list;

				i_result.assertTrue("list has to be empty", i_list.isEmpty());
				
				return i_result;
			}
			
			Base::TestResult<String> TR_InvokeList_Testing_2(){
				Base::TestResult<String> i_result;

				invoking<TestListInvoker> i_class = TestListInvoker();

				invoke<TestListInvoker,Base::TestResult<String>&>(i_class, &TestListInvoker::run, i_result);
				
				return i_result;
			}
			
			Base::TestResult<String> TR_InvokeList_Testing_3(){
				Base::TestResult<String> i_result;

				InvokerList<TestListInvoker> i_list;

				invoking<TestListInvoker> i_class = TestListInvoker();

				i_list.add(i_class);

				invoke<TestListInvoker,Base::TestResult<String>&>(i_list, 0, &TestListInvoker::run, i_result);
				
				return i_result;
			}
			
			Base::TestResult<String> TR_InvokeList_Testing_4(){
				Base::TestResult<String> i_result;

				InvokerList<TestListInvoker> i_list;

				invoking<TestListInvoker> i_class_1 = TestListInvoker();
				invoking<TestListInvoker> i_class_2 = TestListInvoker();
				invoking<TestListInvoker> i_class_3 = TestListInvoker();

				i_list.add(i_class_1);
				i_list.add(i_class_2);
				i_list.add(i_class_3);

				invokeAll<TestListInvoker,Base::TestResult<String>&>(i_list, &TestListInvoker::run, i_result);
				
				return i_result;
			}

			void TR_InvokeList_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("List Constructor with no arguments", TR_InvokeList_Testing_1);
				a_test_runner.add("invoking class method", TR_InvokeList_Testing_2);
				a_test_runner.add("List invoking class method", TR_InvokeList_Testing_3);
				a_test_runner.add("List invoking all class method", TR_InvokeList_Testing_4);
			}

		}

	}

#endif
