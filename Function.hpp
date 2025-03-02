
#ifndef Function_hpp
	#define Function_hpp
	
	#include "Object.hpp"
	#include "InvokeMethod.hpp"
	#include "ClassFunction.hpp"

	#if defined(pankey_Log) && (defined(Function_Log) || defined(pankey_Global_Log) || defined(pankey_MemoryManager_Log))
		#include "Logger_status.hpp"
		#define FunctionLog(status,method,mns) pankey_Log(status,"Function",method,mns)
	#else
		#define FunctionLog(status,method,mns)
	#endif

	namespace pankey{

		template<class T, class H, class M, class... Args>
		class Function{
			protected:
				Object<ClassFunction<T,Args...>,H,M> m_function;

			public:
				Function(){}

				template<class O>
				Function(const O& a_obj){
					FunctionLog(pankey_Log_StartMethod, "Constructor", "const ClassFunction<T,Args...>&");
					m_function = a_obj;
					FunctionLog(pankey_Log_EndMethod, "Constructor", "");
				}

				virtual ~Function(){
					FunctionLog(pankey_Log_StartMethod, "Destructor", "");
					FunctionLog(pankey_Log_EndMethod, "Destructor", "");
				}

			public:
				T run(Args... a_args){
					FunctionLog(pankey_Log_StartMethod, "run", "");
					if(m_function.isNull()){
						FunctionLog(pankey_Log_EndMethod, "run", "m_function.isNull()");
						return T();
					}
					FunctionLog(pankey_Log_EndMethod, "run", "");
					return m_function->run(a_args...);
				}

				bool fit(T a_result, Args... a_args){
					FunctionLog(pankey_Log_StartMethod, "fit", "");
					if(m_function.isNull()){
						FunctionLog(pankey_Log_EndMethod, "fit", "m_function.isNull()");
						return false;
					}
					FunctionLog(pankey_Log_EndMethod, "fit", "");
					return m_function->fit(a_result, a_args...);
				}

				template<class V>
				void operator=(const V& a_value){
					m_function = a_value;
				}
				
				template<class V>
				bool operator==(const V& a_value){
					if(m_function.isNull()){
						return false;
					}
					if(m_function.template isValidObject<V>()){
						V& i_valid = m_function.template getReference<V>();
						return i_valid == a_value ;
					}
					ClassFunction<T,Args...>& i_value = m_function.template getReference<ClassFunction<T,Args...>>();
					return i_value == a_value ;
				}
				
				template<class V>
				bool operator!=(const V& a_value){
					if(m_function.isNull()){
						return false;
					}
					if(m_function.template isValidObject<V>()){
						V& i_valid = m_function.template getReference<V>();
						return i_valid != a_value ;
					}
					ClassFunction<T,Args...>& i_value = m_function.template getReference<ClassFunction<T,Args...>>();
					return i_value != a_value ;
				}
		};

	}

#endif