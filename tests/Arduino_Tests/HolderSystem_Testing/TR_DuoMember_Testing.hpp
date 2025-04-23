
#ifndef TR_DuoMember_Testing_hpp
	#define TR_DuoMember_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "DuoMember.hpp"
	#include "Variable.hpp"

	namespace pankey{

		namespace HolderSystem{

			Base::TestResult<String> TR_DuoMember_Testing_1(){
				Base::TestResult<String> result;

				duo i_duo;

				result.assertNotNull("manager shouldnt be null", i_duo.getManager());

				result.assertTrue("holder has to be null", i_duo.isHolderNull());
				result.assertTrue("holder has to be null", i_duo.isDuoHolderNull());

				result.assertTrue("pointer has to be null", i_duo.isMemoryNull());
				result.assertTrue("pointer has to be null", i_duo.isDuoMemoryNull());

				result.assertTrue("pointers has to be null", i_duo.isNull());
				return result;
			}
			
			Base::TestResult<String> TR_DuoMember_Testing_2(){
				Base::TestResult<String> result;

				var i_var_0 = 15;
				var i_var_1 = 20;

				duo i_duo;

				i_duo.copyMember(i_var_0);
				i_duo.copyDuoMember(i_var_1);

				result.assertTrue("holder shouldnt be null", !i_duo.isHolderNull());
				result.assertTrue("holder shouldnt be null", !i_duo.isDuoHolderNull());

				result.assertTrue("holder shouldnt be null", !i_duo.isMemoryNull());
				result.assertTrue("holder shouldnt be null", !i_duo.isDuoMemoryNull());

				result.assertTrue("pointer shouldnt be null", !i_duo.isNull());
				return result;
			}
			
			Base::TestResult<String> TR_DuoMember_Testing_3(){
				Base::TestResult<String> result;

				var i_var_0 = 15;
				var i_var_1 = 20;

				duo i_duo;

				i_duo.copyMember(i_var_0);
				i_duo.copyDuoMember(i_var_1);

				var i_var_00 = i_duo.getMember();
				var i_var_11 = i_duo.getDuoMember();

				result.assertEqual("value should be: 15", i_var_00.getValue<int>(), 15);
				result.assertEqual("value should be: 20", i_var_11.getValue<int>(), 20);

				return result;
			}
			
			Base::TestResult<String> TR_DuoMember_Testing_4(){
				Base::TestResult<String> i_result;

				var i_var_0 = 15;
				var i_var_1 = 20;

				duo i_duo = duo(i_var_0, i_var_1);

				var i_var_00 = i_duo.getMember();
				var i_var_11 = i_duo.getDuoMember();

				i_result.assertEqual("value should be: 15", i_var_00.getValue<int>(), 15);
				i_result.assertEqual("value should be: 20", i_var_11.getValue<int>(), 20);

				return i_result;
			}
			

			void TR_DuoMember_Testing(Base::TestRunner<String>& a_test_runner){
				createMemoryManager();

				a_test_runner.add("duo Constructor", TR_DuoMember_Testing_1);
				a_test_runner.add("duo copyMember, copyDuoMember", TR_DuoMember_Testing_2);
				a_test_runner.add("duo getMember, getDuoMember", TR_DuoMember_Testing_3);
				a_test_runner.add("duo Constructor with both Members", TR_DuoMember_Testing_4);
			}		

		}	

	}

#endif
