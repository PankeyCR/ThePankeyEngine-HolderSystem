
#ifndef FreeFunction_hpp
	#define FreeFunction_hpp

	#include "InvokeMethod.hpp"
	#include "ClassFunction.hpp"

	#if defined(pankey_Log) && (defined(FreeFunction_Log) || defined(pankey_Global_Log) || defined(pankey_MemoryManager_Log))
		#include "Logger_status.hpp"
		#define FreeFunctionLog(status,method,mns) pankey_Log(status,"FreeFunction",method,mns)
	#else
		#define FreeFunctionLog(status,method,mns)
	#endif
	
	namespace pankey{

		template<class T, class... Args>
		class FreeFunction : public ClassFunction<T,Args...>{
			public:
				InvokeMethodReturn<T,Args...> m_method = nullptr;
				InvokeMethodReturn<bool,T,Args...> m_fit = nullptr;

				FreeFunction(){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "");
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "");
				}

				FreeFunction(const FreeFunction<T,Args...>& a_freefunction){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "");
					m_method = a_freefunction.m_method;
					m_fit = a_freefunction.m_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "");
				}

				FreeFunction(InvokeMethodReturn<T,Args...> a_method){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "InvokeMethodReturn<T,Args...>");
					m_method = a_method;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "");
				}

				FreeFunction(InvokeMethodReturn<T,Args...> a_method, InvokeMethodReturn<bool,T,Args...> a_fit){
					FreeFunctionLog(pankey_Log_StartMethod, "Constructor", "InvokeMethodReturn<T,Args...>, InvokeMethodReturn<bool,T,Args...>");
					m_method = a_method;
					m_fit = a_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "Constructor", "");
				}
				virtual ~FreeFunction(){
					FreeFunctionLog(pankey_Log_StartMethod, "Destructor", "");
					FreeFunctionLog(pankey_Log_EndMethod, "Destructor", "");
				}
				
				virtual T run(Args... a_args){
					FreeFunctionLog(pankey_Log_StartMethod, "run", "");
					FreeFunctionLog(pankey_Log_EndMethod, "run", "");
					return invoke<T,Args...>(m_method, a_args...);
				}
				virtual bool fit(T a_result, Args... a_args){
					FreeFunctionLog(pankey_Log_StartMethod, "fit", "");
					FreeFunctionLog(pankey_Log_EndMethod, "fit", "");
					return invoke<bool,T,Args...>(m_fit, a_result, a_args...);
				}
				virtual void operator=(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "");
					m_method = a_fn.m_method;
					m_fit = a_fn.m_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "");
				}
				virtual void operator=(InvokeMethodReturn<T,Args...> a_method){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "");
					m_method = a_method;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "");
				}
				virtual void operator=(InvokeMethodReturn<bool,T,Args...> a_fit){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "");
					m_fit = a_fit;
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "");
				}

				virtual bool operator==(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "");
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "");
					return a_fn.m_method == m_method && a_fn.m_fit == m_fit;
				}

				virtual bool operator!=(const FreeFunction<T,Args...>& a_fn){
					FreeFunctionLog(pankey_Log_StartMethod, "operator=", "");
					FreeFunctionLog(pankey_Log_EndMethod, "operator=", "");
					return a_fn.m_method != m_method || a_fn.m_fit != m_fit;
				}
		};

	}

#endif