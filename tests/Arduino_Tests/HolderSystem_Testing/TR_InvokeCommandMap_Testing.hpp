
#ifndef TR_InvokeCommandMap_Testing_hpp
	#define TR_InvokeCommandMap_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeCommandMap.hpp"
	#include "CharArray.hpp"

	namespace pankey{

		namespace HolderSystem{

			class TestCommandMap : Base::Command<Base::TestResult<String>&>{
				void execute(Base::TestResult<String>& a_result){
					a_result.assertTrue("executing method", true);
				}
			};

			class TestCommandMap_2 : Base::Command<Base::TestResult<String>&>{
				void execute(Base::TestResult<String>& a_result){
					a_result.assertEqual("executing method", 1,1);
				}
			};

			class TestCommandMapWithError : Base::Command<Base::TestResult<String>&>{
				void execute(Base::TestResult<String>& a_result){
					a_result.assertTrue("executing method with error", false);
				}
			};
			
			Base::TestResult<String> TR_InvokeCommandMap_Testing_1(){
				Base::TestResult<String> result;

				CommandMap<Base::CharArray> i_map;

				result.assertTrue("list has to be empty", i_map.isEmpty());
				
				return result;
			}
			
			Base::TestResult<String> TR_InvokeCommandMap_Testing_2(){
				Base::TestResult<String> result;

				CommandMap<Base::CharArray,float> i_map;

				result.assertTrue("list has to be empty", i_map.isEmpty());
				
				return result;
			}
			/*
			Base::TestResult<String> TR_InvokeCommandMap_Testing_3(){
				Base::TestResult<String> result;

				CommandMap<Note,Base::TestResult<String>&> i_map;

				command<Base::TestResult<String>&> i_obj = TestCommandMap();

				i_map.add("", i_obj);

				Base::invoke<Base::TestResult<String>&>(i_map, 0, result);
				
				return result;
			}
			
			Base::TestResult<String> TR_InvokeCommandMap_Testing_4(){
				Base::TestResult<String> result;

				CommandMap<Note,Base::TestResult<String>&> i_map;

				command<Base::TestResult<String>&> i_obj = TestCommandMap();
				command<Base::TestResult<String>&> i_obj_2 = TestCommandMap_2();

				i_map.add(i_obj);
				i_map.add(i_obj_2);

				invokeAll<Base::TestResult<String>&>(i_map, result);
				
				return result;
			}

			class TestCommandMapReturn : Base::CommandReturn<bool,bool>{
				bool execute(bool a_bool){
					return a_bool;
				}
			};

			class TestCommandMapReturn_2 : Base::CommandReturn<bool,bool,Base::TestResult<String>&>{
				bool execute(bool a_bool, Base::TestResult<String>& a_result){
					a_result.assertTrue("bool parameter has to be true", a_bool);
					return a_bool;
				}
			};

			class TestCommandMapReturn_3 : Base::CommandReturn<bool,bool,Base::TestResult<String>&>{
				bool execute(bool a_bool, Base::TestResult<String>& a_result){
					a_result.assertEqual("bool parameter has to be true", a_bool, true);
					return a_bool;
				}
			};

			Base::TestResult<String> TR_InvokeCommandMap_Testing_5(){
				Base::TestResult<String> result;

				CommandReturnMap<Note,bool,bool> i_map;

				commandReturn<bool,bool> i_obj = TestCommandMapReturn();

				i_map.add(i_obj);

				result.assertTrue("command has to return true", invoke(i_map, 0, true));
				
				return result;
			}
			
			Base::TestResult<String> TR_InvokeCommandMap_Testing_6(){
				Base::TestResult<String> result;

				CommandReturnMap<Note,bool,bool,Base::TestResult<String>&> i_map;

				commandReturn<bool,bool,Base::TestResult<String>&> i_obj = TestCommandMapReturn_2();
				commandReturn<bool,bool,Base::TestResult<String>&> i_obj_2 = TestCommandMapReturn_3();

				i_map.add(i_obj);
				i_map.add(i_obj_2);

				invokeAll<bool,bool,Base::TestResult<String>&>(i_map, true, result);
				
				return result;
			}
	*/
			void TR_InvokeCommandMap_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("CommandMap Constructor with no arguments", TR_InvokeCommandMap_Testing_1);
				a_test_runner.add("CommandMap Constructor with 1 float arguments", TR_InvokeCommandMap_Testing_2);
				// a_test_runner.add("CommandMap invoke with Base::TestResult<String>& argument", TR_InvokeCommandMap_Testing_3);
				// a_test_runner.add("CommandMap invokeAll with Base::TestResult<String>& argument", TR_InvokeCommandMap_Testing_4);
				// a_test_runner.add("CommandMap invoke class with Base::TestResult<String>& argument", TR_InvokeCommandMap_Testing_5);
				// a_test_runner.add("CommandMap invokeAll class with Base::TestResult<String>& argument", TR_InvokeCommandMap_Testing_6);
			}

		}

	}

#endif
