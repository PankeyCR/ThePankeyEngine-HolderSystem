
#ifndef TR_Object_Testing_hpp
	#define TR_Object_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Object.hpp"

	namespace pankey{

		namespace HolderSystem{

			class BaseExample{};
			class Example : public BaseExample{
				public:
				int m_num = 0;
			};

			Base::TestResult TR_Object_Testing_1(){
				Base::TestResult result;

				obj<BaseExample> i_obj;

				result.assertNotNull("allocator shouldnt be null", i_obj.getManager());
				result.assertTrue("holder has to be null", i_obj.isHolderNull());
				result.assertTrue("pointer has to be null", i_obj.isNull());
				return result;
			}

			Base::TestResult TR_Object_Testing_2(){
				Base::TestResult result;

				obj<BaseExample> i_obj = Example();

				result.assertNotNull("allocator shouldnt be null", i_obj.getManager());
				result.assertTrue("holder has to be null", !i_obj.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_obj.isNull());
				return result;
			}

			Base::TestResult TR_Object_Testing_3(){
				Base::TestResult result;

				var i_var = Example();
				obj<BaseExample> i_obj = i_var;

				result.assertNotNull("allocator shouldnt be null", i_obj.getManager());
				result.assertTrue("holder has to be null", i_obj.isHolderNull());
				result.assertTrue("pointer shouldnt be null", i_obj.isNull());
				return result;
			}

			Base::TestResult TR_Object_Testing_4(){
				Base::TestResult result;

				obj<BaseExample> i_obj = Example();
				var i_var = i_obj;

				result.assertNotNull("allocator shouldnt be null", i_var.getManager());
				result.assertTrue("holder has to be null", !i_obj.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_var.isNull());
				result.assertTrue("pointer base type should be BaseExample", i_var.getBaseType() == Base::ClassCount<BaseExample>::get());
				return result;
			}

			Base::TestResult TR_Object_Testing_5(){
				Base::TestResult result;

				obj<BaseExample> i_obj = Example();
				var i_var = i_obj;
				
				if(!i_obj.isValidObject<Example>()){
					result.catchError("null error, not valid object");
					return result;
				}
				
				Example& i_example_1 = i_obj.getReference<Example>();
				i_example_1.m_num = 5;
				
				if(i_var.isNull()){
					result.catchError("null error, var is null");
					return result;
				}
				
				Example i_example_2 = i_var.getValue<Example>();

				result.assertEqual("value should be 5", i_example_2.m_num, 5);

				return result;
			}

			Base::TestResult TR_Object_Testing_6(){
				Base::TestResult result;

				obj<BaseExample> i_obj = Example();
				obj<BaseExample> i_obj_2;
				i_obj_2 = i_obj;

				result.assertNotNull("allocator shouldnt be null", i_obj_2.getManager());
				result.assertTrue("holder has to be null", !i_obj.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_obj_2.isNull());
				result.assertTrue("pointer base type should be BaseExample", i_obj_2.getBaseType() == Base::ClassCount<BaseExample>::get());
				result.assertTrue("pointer type should be Example", i_obj_2.getType() == Base::ClassCount<Example>::get());
				return result;
			}

			Base::TestResult TR_Object_Testing_7(){
				Base::TestResult result;

				obj<BaseExample> i_obj = Example();
				obj<BaseExample> i_obj_2 = i_obj;

				result.assertNotNull("allocator shouldnt be null", i_obj_2.getManager());
				result.assertTrue("holder has to be null", !i_obj.isHolderNull());
				result.assertTrue("pointer shouldnt be null", !i_obj_2.isNull());
				result.assertTrue("pointer base type should be BaseExample", i_obj_2.getBaseType() == Base::ClassCount<BaseExample>::get());
				result.assertTrue("pointer type should be Example", i_obj_2.getType() == Base::ClassCount<Example>::get());
				return result;
			}

			Base::TestResult TR_Object_Testing_8(){
				Base::TestResult result;

				obj<BaseExample> i_obj = BaseExample();

				result.assertTrue("holder shouldnt be null", !i_obj.isHolderNull());
				result.assertTrue("pointer base type should be BaseExample", i_obj.getBaseType() == Base::ClassCount<BaseExample>::get());
				result.assertTrue("pointer type should be BaseExample", i_obj.getType() == Base::ClassCount<BaseExample>::get());
				return result;
			}

			void TR_Object_Testing(Base::TestRunner& a_test_runner){
				createMemoryManager();

				a_test_runner.add("obj Constructor", TR_Object_Testing_1);
				a_test_runner.add("obj Constructor with P type inference", TR_Object_Testing_2);
				a_test_runner.add("var Constructor to obj", TR_Object_Testing_3);
				a_test_runner.add("obj Constructor to var", TR_Object_Testing_4);
				a_test_runner.add("obj to var and changing values", TR_Object_Testing_5);
				a_test_runner.add("obj to obj operator=", TR_Object_Testing_6);
				a_test_runner.add("obj to obj Constructor", TR_Object_Testing_7);
				a_test_runner.add("obj with base object", TR_Object_Testing_8);
			}

		}

	}

#endif
