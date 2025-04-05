
#ifndef TR_ObjectArrayMap_Testing_hpp
	#define TR_ObjectArrayMap_Testing_hpp
	
	#include "pankey_HolderSystem.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	namespace pankey{

		namespace HolderSystem{

			class TR_ObjectArrayMap_Testing_Example{
				public:
				TR_ObjectArrayMap_Testing_Example();
				bool operator==(const TR_ObjectArrayMap_Testing_Example& a_ex){return false;}
			};
			
			Base::TestResult TR_ObjectArrayMap_Testing_1(){
				Base::TestResult result;

				OMap<int,int> i_map;
				
				result.assertTrue("storage has to be null", i_map.isEmpty());
				return result;
			}
			
			Base::TestResult TR_ObjectArrayMap_Testing_2(){
				Base::TestResult result;

				OMap<TR_ObjectArrayMap_Testing_Example,TR_ObjectArrayMap_Testing_Example> i_map;

				obj<TR_ObjectArrayMap_Testing_Example> i_key = 15;
				obj<TR_ObjectArrayMap_Testing_Example> i_value = 20;

				i_map.add(i_key, i_value);

				var i_search = 20;

				var i_p = i_map.getKeyByPointer(i_search);
				
				var i_v = i_map.getKeyByValue(i_search);

				result.assertTrue("storage shouldnt be null", !i_map.isEmpty());
				result.assertNotEqual("key shouldnt be found by pointer", i_p.getValue<int>(), 15);
				result.assertEqual("key should be found by value", i_v.getValue<int>(), 15);
				return result;
			}

			void TR_ObjectArrayMap_Testing(Base::TestRunner& a_test_runner){
				createMemoryManager();

				a_test_runner.add("ObjectArrayMap Constructor", TR_ObjectArrayMap_Testing_1);
				// a_test_runner.add("ObjectArrayMap add, getKeyByValue", TR_ObjectArrayMap_Testing_2);
			}

		}

	}

#endif
