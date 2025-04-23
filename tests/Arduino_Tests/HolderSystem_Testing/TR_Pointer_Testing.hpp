
#ifndef TR_Pointer_Testing_hpp
	#define TR_Pointer_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Pointer.hpp"
	#include "Variable.hpp"

	namespace pankey{

		namespace HolderSystem{
		
			Base::TestResult<String> TR_Pointer_Testing_1(){
				Base::TestResult<String> result;

				pointer<int> i_pointer;

				result.assertTrue("allocator shouldnt be null", !i_pointer.isManagerNull());
				result.assertTrue("holder has to be null", i_pointer.isHolderNull());
				result.assertTrue("pointer has to be null", i_pointer.isNull());

				return result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_2(){
				Base::TestResult<String> result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				result.assertTrue("allocator shouldnt be null", !i_pointer.isManagerNull());
				result.assertTrue("holder shouldnt be null", !i_pointer.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

				return result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_3(){
				Base::TestResult<String> result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

				if(i_pointer.isNull()){
					result.catchError(100, "Fail test");
					return result;
				}

				int* i_value = i_pointer.get();

				result.assertTrue("pointer value shouldnt be null", i_value != nullptr);

				if(i_value == nullptr){
					result.catchError(101, "Fail test");
					return result;
				}

				*i_value = 5;

				result.assertEqual("pointer value should be 5", *i_value, 5);
				
				pointer<int> i_pointer_2 = i_pointer;

				result.assertTrue("pointer 2 shouldnt be null", !i_pointer_2.isNull());

				if(i_pointer_2.isNull()){
					result.catchError(102, "Fail test");
					return result;
				}

				int* value_2 = i_pointer_2.get();

				result.assertTrue("pointer 2 value shouldnt be null", value_2 != nullptr);

				if(value_2 == nullptr){
					result.catchError(103, "Fail test");
					return result;
				}

				result.assertEqual("pointer 2 value should be 5", *value_2, 5);

				return result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_4(){
				Base::TestResult<String> result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

				if(i_pointer.isNull()){
					result.catchError(100, "Fail test");
					return result;
				}

				int* i_value = i_pointer.get();

				result.assertTrue("pointer value shouldnt be null", i_value != nullptr);

				if(i_value == nullptr){
					result.catchError(101, "Fail test");
					return result;
				}

				*i_value = 5;

				result.assertEqual("pointer value should be 5", *i_value, 5);
				
				var i_holder = i_pointer;

				pointer<int> i_pointer_2 = i_holder;

				result.assertTrue("pointer 2 shouldnt be null", !i_pointer_2.isNull());

				if(i_pointer_2.isNull()){
					result.catchError(102, "Fail test");
					return result;
				}

				int* value_2 = i_pointer_2.get();

				result.assertTrue("pointer 2 value shouldnt be null", value_2 != nullptr);

				if(value_2 == nullptr){
					result.catchError(103, "Fail test");
					return result;
				}

				result.assertEqual("pointer 2 value should be 5", *value_2, 5);

				return result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_5(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				member i_member = i_pointer;

				pointer<int> i_pointer_2 = i_member;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_6(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				member i_member = i_pointer;

				pointer<int> i_pointer_2;

				i_pointer_2 = i_member;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_7(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				var i_var = i_pointer;

				pointer<int> i_pointer_2 = i_var;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_8(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				var i_var = i_pointer;

				pointer<int> i_pointer_2;

				i_pointer_2 = i_var;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_9(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				data i_var = i_pointer;

				pointer<int> i_pointer_2 = i_var;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test, i_value_2 == nullptr");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_10(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer;

				i_pointer.create();

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test");return i_result;}

				*i_value = 15;
				
				data i_var = i_pointer;

				pointer<int> i_pointer_2;

				i_pointer_2 = i_var;

				int* i_value_2 = i_pointer_2.get();

				if(i_value_2 == nullptr){i_result.catchError(101, "Fail test, i_value_2 == nullptr");return i_result;}

				i_result.assertEqual("pointer 2 value should be 15", *i_value_2, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_11(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer = new int(15);

				int* i_value = i_pointer.get();

				if(i_value == nullptr){i_result.catchError(101, "Fail test, i_value == nullptr");return i_result;}

				i_result.assertEqual("pointer value should be 15", *i_value, 15);

				return i_result;
			}
			
			Base::TestResult<String> TR_Pointer_Testing_12(){
				Base::TestResult<String> i_result;
				
				pointer<int> i_pointer = new int(15);

				var i_var_1 = i_pointer;
				var i_var_2 = i_var_1;
				var i_var_3 = i_var_2;

				int i_value = i_var_3.getValue<int>();

				i_result.assertEqual("pointer value should be 15", i_value, 15);

				return i_result;
			}

			void TR_Pointer_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("Pointer Simple Constructor", TR_Pointer_Testing_1);
				a_test_runner.add("Pointer create", TR_Pointer_Testing_2);
				a_test_runner.add("Pointer copy Constructor", TR_Pointer_Testing_3);
				a_test_runner.add("Pointer Memory Holder Constructor", TR_Pointer_Testing_4);
				a_test_runner.add("Pointer to Member to Pointer Constructor", TR_Pointer_Testing_5);
				a_test_runner.add("Pointer to Member to Pointer operator==", TR_Pointer_Testing_6);
				a_test_runner.add("Pointer to Variable to Pointer Constructor", TR_Pointer_Testing_7);
				a_test_runner.add("Pointer to Variable to Pointer operator==", TR_Pointer_Testing_8);
				a_test_runner.add("Pointer to Data to Pointer Constructor", TR_Pointer_Testing_9);
				a_test_runner.add("Pointer to Data to Pointer operator==", TR_Pointer_Testing_10);
				a_test_runner.add("Pointer Contructor with new P()", TR_Pointer_Testing_11);
				a_test_runner.add("Pointer Contructor with new P() and passing it to severals vars", TR_Pointer_Testing_12);
			}

		}

	}

#endif
