
#ifndef TemplateMemoryAllocator_hpp
	#define TemplateMemoryAllocator_hpp

	#include "MemoryAllocator.hpp"
	#include "MemorySize.hpp"

	#if defined(pankey_Log) && (defined(TemplateMemoryAllocator_Log) || defined(pankey_Global_Log) || defined(pankey_HolderSystem_Log))
		#include "Logger_status.hpp"
        #define TemplateMemoryAllocatorLog(status,method,mns) pankey_Log(status,"TemplateMemoryAllocator",method,mns)
    #else
        #define TemplateMemoryAllocatorLog(status,method,mns)
    #endif

	namespace pankey{

		namespace HolderSystem{

			template<class T>
			class TemplateMemoryAllocator : public MemoryAllocator{
				public:
					TemplateMemoryAllocator(){}
					virtual ~TemplateMemoryAllocator(){}

					virtual void* create(memory_size a_size){
						TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "create", "");
						if(a_size != MemorySize(T)){
							return nullptr;
						}
						TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "create", "");
						return new T();
					}

					virtual void* create(){
						TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "create", "");
						TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "create", "");
						return new T();
					}
					
					virtual void destroy(memory_size a_size, void* a_destroy){
						TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "");
						if(a_destroy == nullptr){
							return;
						}
						if(a_size != MemorySize(T)){
							return;
						}
						T* i_var = (T*)a_destroy;
						delete i_var;
						TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "");
					}
					
					virtual void destroy(void* a_destroy){
						TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "");
						if(a_destroy == nullptr){
							return;
						}
						T* i_var = (T*)a_destroy;
						delete i_var;
						TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "");
					}
			};

		}

	}

#endif